/*
 * b.cpp
 *
 *  Created on: 2011-11-10
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
string s;

typedef long long HASH;
typedef char CHAR;

struct Suffix;

const HASH SEED = 133331;

struct Hash {
	static vector<HASH> pow;
	vector<HASH> h;
	vector<CHAR> str;
	int n;

	Hash() {
	}

	static void reqPow(int n) {
		for (int i = pow.size(); i <= n; i++) {
			if (!i)
				pow.push_back(1);
			else
				pow.push_back(pow.back() * SEED);
		}
	}

	template<class V> Hash(V s) :
			str(s.begin(), s.end()) {
		n = s.size();
		h.resize(n + 1);
		reqPow(n);
		for (int i = 0; i < n; ++i) {
			h[i + 1] = h[i] * SEED + s[i];
		}
	}
	HASH ask(int l, int r) const { //[l,r)
		return h[r] - h[l] * pow[r - l];
	}

	Suffix getSuffix(int l) const;

	vector<Suffix> getSuffixArray() const;
};

vector<HASH> Hash::pow;

struct Suffix {
	const Hash*h;
	int l;

	Suffix() {
	}

	Suffix(const Hash*_h, int _l) :
			h(_h), l(_l) {
	}

	int size() const {
		return h->n - l;
	}

	HASH hash(int len) const {
		return h->ask(l, l + len);
	}

	CHAR charAt(int at) const {
		if (at < size())
			return h->str[l + at];
		else
			return LONG_LONG_MIN;
	}

	int lcp(const Suffix&o) const {
		int left = 0, right = min(size(), o.size()) + 1;
		while (left + 1 < right) {
			int mid = (left + right) / 2;
			if (hash(mid) == o.hash(mid)) {
				left = mid;
			} else {
				right = mid;
			}
		}
		return left;
	}

	bool operator<(const Suffix&o) const {
		int com = lcp(o);
		return charAt(com) < o.charAt(com);
	}
};

Suffix Hash::getSuffix(int l) const {
	return Suffix(this, l);
}

vector<Suffix> Hash::getSuffixArray() const {
	vector<Suffix> sufs(n);
	for (int i = 0; i < n; ++i) {
		sufs[i] = getSuffix(i);
	}
	sort(sufs.begin(), sufs.end());
	return sufs;
}

int main() {
	cin >> s;
	Hash h(s);
	vector<Suffix> suf(s.size());
	for (int i = 0; i < s.size(); ++i) {
		suf[i] = h.getSuffix(i);
	}
	int n = s.size();
	vector<int> am(n);
	for (int i = 1; i < n; ++i) {
		am[i] = suf[0].lcp(suf[i]);
		if (i - 1 > 0)
			am[i] = max(am[i], am[i - 1]);
	}
	for (int i = n - 2; i >= 1; --i) {
		if (h.ask(0, i) == h.ask(n - i, n)) {
			if (am[n - 1 - i] >= i) {
				cout << s.substr(0, i) << endl;
				return 0;
			}
		}
	}
	puts("Just a legend");
	return 0;
}