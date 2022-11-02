/*
 * b.cpp
 *
 *  Created on: 2011-9-15
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

char map[300][300];
int n, m;
int L[300], R[300];
int dp[300][300][2];

int main() {
	cin >> n >> m;
	for (int r = 0; r < n; ++r) {
		scanf(" ");
		scanf("%s", map[r]);
		L[r] = INT_MAX;
		R[r] = -1;
		for (int c = 0; c < m; ++c) {
			if (map[r][c] == 'W') {
				if (L[r] == INT_MAX) {
					L[r] = c;
				}
				R[r] = c;
			}
		}
	}
	L[n] = INT_MAX;
	R[n] = -1;
	for (int r = 0; r <= n; ++r) {
		for (int c = 0; c < m; ++c) {
			for (int d = 0; d < 2; ++d) {
				dp[r][c][d] = INT_MAX / 2;
			}
		}
	}
	dp[0][0][1] = 0;
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c + 1 < m; ++c) {
			dp[r][c + 1][1] = min(dp[r][c + 1][1], dp[r][c][1] + 1);
		}
		for (int c = m - 1; c >= 1; --c) {
			dp[r][c - 1][0] = min(dp[r][c - 1][0], dp[r][c][0] + 1);
		}
		for (int c = 0; c < m; ++c) {
			if (c >= R[r] && c >= R[r + 1]) {
				dp[r + 1][c][0] = min(dp[r + 1][c][0], dp[r][c][1] + 1);
			}
			if (c <= L[r] && c <= L[r + 1]) {
				dp[r + 1][c][1] = min(dp[r + 1][c][1], dp[r][c][0] + 1);
			}
		}
	}
	int at = -1;
	for (int i = n - 1; i >= 0; --i) {
		if (L[i] != INT_MAX) {
			at = i;
			break;
		}
	}
	if (at == -1) {
		cout << 0 << endl;
		return 0;
	}
	int ans = INT_MAX;
	for (int c = 0; c < m; ++c) {
		ans = min(ans, dp[at + 1][c][0]);
		ans = min(ans, dp[at + 1][c][1]);
	}
	cout << ans - 1 << endl;
	return 0;
}