/*
 * cd2.cpp
 *
 *  Created on: 2012-12-17
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
const int MAX_N = 77777 + 10;
const int MOD = 777777777;

int n, nQ;
int w[3][3];

typedef long long int64;

struct Tree {
	int c[3][3];
	Tree*pl, *pr;
	int l, r;

	void update() {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				int64 k = 0;
				for (int pi = 0; pi < 3; ++pi) {
					for (int pj = 0; pj < 3; ++pj)
						if (w[pi][pj]) {
							k += 1LL * pl->c[i][pi] * pr->c[pj][j];
						}
				}
				c[i][j] = k % MOD;
			}
		}
	}

	Tree(int l, int r) :
			l(l), r(r) {
		memset(c, 0, sizeof c);
		if (l + 1 == r) {
			for (int i = 0; i < 3; ++i) {
				c[i][i] = 1;
			}
			return;
		}
		pl = new Tree(l, l + r >> 1);
		pr = new Tree(l + r >> 1, r);
		update();
	}

	void change(int i, int x) {
		if (i < l || i >= r)
			return;
		if (l + 1 == r) {
			if (x == 0) {
				memset(c, 0, sizeof c);
				for (int j = 0; j < 3; ++j) {
					c[j][j] = 1;
				}
			} else {
				memset(c, 0, sizeof c);
				c[x - 1][x - 1] = 1;
			}
			return;
		}
		pl->change(i, x);
		pr->change(i, x);
		update();
	}
}*root;

int main() {
	cin >> n >> nQ;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> w[i][j];
		}
	}
	root = new Tree(0, n);
	for (int i = 0; i < nQ; ++i) {
		int a, x;
		scanf("%d%d", &a, &x);
		--a;
		root->change(a, x);
		int ans = 0;
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				ans += root->c[j][k];
				ans %= MOD;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}