/*
 * e.cpp
 *
 *  Created on: 2012-8-31
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
const int MAX_N = (int) 1e5 + 10;

typedef long long int64;

int n;
int a[MAX_N];

template<class T>
struct Index: public vector<T> {
	using vector<T>::erase;
	using vector<T>::begin;
	using vector<T>::end;
	void doit() {
		sort(begin(), end());
		erase(unique(begin(), end()), end());
	}
	int get(T x) {
		return lower_bound(begin(), end(), x) - begin();
	}
};

Index<int> idx;

struct TA {
	int a[MAX_N], n;
	int all;
	void init(int _n) {
		n = _n;
		memset(a, 0, sizeof a);
		all = 0;
	}
	void add(int p, int x) {
		for (p++; p <= n; p += p & -p)
			a[p - 1] += x;
		all += x;
	}
	int sum(int p) {
		int r = 0;
		for (p++; p; p -= p & -p)
			r += a[p - 1];
		return r;
	}
	int lower(int x) { //<x
		return sum(x - 1);
	}
	int upper(int x) { //>x
		return all - sum(x);
	}
};

int64 k;

TA tL, tR;
int64 cntInv;
void addR(int i) { //make i -> tR
	int x = a[i];
	cntInv += tR.lower(x);
	cntInv += tL.upper(x);
	tR.add(x, 1);
}
void addL(int i) {
	int x = a[i];
	cntInv += tL.upper(x);
	cntInv += tR.lower(x);
	tL.add(x, 1);
}
void subR(int i) {
	int x = a[i];
	cntInv -= tR.lower(x);
	cntInv -= tL.upper(x);
	tR.add(x, -1);
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		idx.push_back(a[i]);
	}
	idx.doit();
	for (int i = 0; i < n; ++i) {
		a[i] = idx.get(a[i]);
	}
	tL.init(idx.size());
	tR.init(idx.size());
	cntInv = 0;
	int R = n;
	while (R > 0) {
		addR(R - 1);
		if (cntInv > k) {
			subR(R - 1);
			break;
		}
		--R;
	}
	int64 ans = 0;
	for (int L = 0; L < n; ++L) {
		//make R>L
		while (R <= L) {
			subR(R);
			++R;
		}
		addL(L);
		while (R < n && cntInv > k) {
			subR(R);
			R++;
		}
		ans += n - R;
	}
	cout << ans << endl;
	return 0;
}