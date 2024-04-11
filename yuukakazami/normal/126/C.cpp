/*
 * c.cpp
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
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
int M[2002][2002];

struct TA {
	int a[2002], n;
	void init(int _n) {
		n = _n;
		memset(a, 0, sizeof a);
	}

	int get(int p) {
		int ret = 0;
		for (p++; p > 0; p -= p & -p)
			ret ^= a[p - 1];
		return ret;
	}

	void change(int l) {
		for (l++; l <= n; l += l & -l)
			a[l - 1] ^= 1;
	}

	void change(int l, int r) {
		change(l);
		change(r + 1);
	}
} R[2002], C[2002];

void put(int r, int c) {
	R[r].change(min(r, c), max(r, c));
	C[c].change(min(r, c), max(r, c));
	M[r][c] ^= 1;
}

int get(int r, int c) {
	return R[r].get(c) ^ C[c].get(r) ^ M[r][c];
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		scanf(" ");
		for (int j = 0; j < n; ++j) {
			M[i][j] = getchar() == '1';
		}
		R[i].init(n);
		C[i].init(n);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int r = n - 1; r > i; --r) {
			if (get(r, i)) {
				++ans;
				put(r, i);
			}
		}
		for (int c = n - 1; c > i; --c) {
			if (get(i, c)) {
				++ans;
				put(i, c);
			}
		}
		if (get(i, i)) {
			++ans;
			put(i, i);
		}
	}
	cout << ans << endl;
	return 0;
}