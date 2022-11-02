/*
 * c.cpp
 *
 *  Created on: 2011-8-23
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

typedef long long int64;
int n, m;
int64 kth;

int w[20];
int before[20] = { };
const int MAX_N = 16;
const int MAX_S = 1 << MAX_N;

int64 eval(int p) {
	static int64 dp[20][MAX_S];
	memset(dp, 0, sizeof dp);
	int at[MAX_N] = { };
	memset(at, -1, sizeof at);
	for (int i = 0; i < p; ++i) {
		at[w[i]] = i;
	}
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < (1 << n); ++j) {
			if (dp[i][j] != 0) {
				int64 c = dp[i][j];
				for (int k = 0; k < n; ++k) {
					if (~j >> k & 1) {
						if (at[i] != -1 && at[i] != k)
							continue;
						if ((j & before[k]) == before[k]) {
							dp[i + 1][j ^ (1 << k)] += c;
						}
					}
				}
			}
		}
	}
	return dp[n][(1 << n) - 1];
}
int main() {
	cin >> n >> kth >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b, --a, --b;
		before[b] |= 1 << a;
	}
	kth -= 2001;
	if (eval(0) <= kth) {
		cout << "The times have changed" << endl;
		return 0;
	}
	int used = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (used >> j & 1)
				continue;
			w[i] = j;
			int64 tmp = eval(i + 1);
			if (tmp <= kth) {
				kth -= tmp;
			} else {
				used |= 1 << j;
				break;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << w[i] + 1 << " ";
	}
	cout << endl;
	return 0;
}