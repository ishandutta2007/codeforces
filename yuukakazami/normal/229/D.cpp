/*
 * d.cpp
 *
 *  Created on: 2012-10-1
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

const int MAX_N = 5000 + 10;
const int INF = ~0U >> 1;

int h[MAX_N], n, S[MAX_N];
int dp[MAX_N][MAX_N]; //k,i
int val[MAX_N];
int perm[MAX_N];

bool cmp(int a, int b) {
	return val[a] < val[b];
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}
//	n = 5000;
//	for (int i = 0; i < n; ++i) {
//		h[i] = i + 1;
//	}
	partial_sum(h, h + n, S);
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			dp[i][j] = INF;
		}
	}
	for (int i = 0; i < n; ++i) {
		dp[1][i] = S[i];
	}
	for (int k = 2; k <= n; ++k) {
		//dpk,j+Sj
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			if (dp[k - 1][j] != INF) {
				val[j] = dp[k - 1][j] + S[j];
				perm[cnt++] = j;
			}
		}
		sort(perm, perm + cnt, cmp);
		int at = 0, mx = -1;
		for (int j = 0; j < n; ++j) {
			while (at < cnt && val[perm[at]] <= S[j]) {
				mx = max(mx, perm[at]);
				++at;
			}
			if (mx == -1) {
				dp[k][j] = INF;
			} else {
				dp[k][j] = S[j] - S[mx];
			}
		}
		if (dp[k][n - 1] == INF)
			break;
	}
	for (int i = n; i >= 0; --i) {
		if (dp[i][n - 1] != INF) {
			cout << n - i << endl;
			break;
		}
	}

	return 0;
}