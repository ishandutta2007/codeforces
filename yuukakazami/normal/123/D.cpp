/*
 * code3.cpp
 *
 *  Created on: 2011-11-3
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

const int SEED = 133331;
typedef long long int64;
int n;

struct Hash {
	vector<int64> pow, h;
	Hash() {
	}
	Hash(string s) {
		int n = s.size();
		h.resize(n + 1);
		pow.resize(n + 1);
		h[0] = 0;
		pow[0] = 1;
		for (int i = 0; i < n; ++i) {
			h[i + 1] = h[i] * SEED + s[i];
			pow[i + 1] = pow[i] * SEED;
		}
	}
	int64 ask(int l, int r) const { //[l,r)
		return h[r] - h[l] * pow[r - l];
	}
};

int getLcp(const Hash&a, int ia, const Hash&b, int ib) {
	int left = 0, right = n + 1;
	while (left + 1 < right) {
		int m = left + right >> 1;
		if (ia + m <= n && ib + m <= n) {
			if (a.ask(ia, ia + m) == b.ask(ib, ib + m)) {
				left = m;
				continue;
			}
		}
		right = m;
	}
	return left;
}

string s;
Hash h;

bool cmp(int a, int b) {
	int lcp = getLcp(h, a, h, b);
	if (a + lcp < n && b + lcp < n)
		return s[a + lcp] < s[b + lcp];
	return a > b;
}

int main() {
	cin >> s;
	n = s.size();
	h = Hash(s);
	vector<int> suf(n);
	for (int i = 0; i < n; ++i) {
		suf[i] = i;
	}
	vector<int64> cnt(n + 1, 0);
	sort(suf.begin(), suf.end(), cmp);
	vector<pair<int, int> > ps;
	int add = 0;
	int sum = 0;
	for (int i = 0; i < suf.size(); ++i) {
		int id = suf[i], len = n - id;
		int com;
		if (i == 0)
			com = 0;
		else
			com = getLcp(h, suf[i - 1], h, id);
		while (sum > com) {
			while (ps.back().second == 0)
				ps.pop_back();
			int by = min(ps.back().second, sum - com);
			ps.back().second -= by;
			cnt[ps.back().first + add] += by;
			sum -= by;
		}
		++add;
		ps.push_back(make_pair(-add + 1, len - com));
		sum = len;
	}
	while (!ps.empty()) {
		cnt[ps.back().first + add] += ps.back().second;
		ps.pop_back();
	}

	int64 ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += cnt[i] * i * (i + 1) / 2;
	}
	cout << ans << endl;
	return 0;
}