/*
 * e.cpp
 *
 *  Created on: 2012-3-4
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

const int MAX_N = 4000 + 10;
const int TIME = 86400;

int dp[MAX_N][MAX_N];
int n, k;
int t[MAX_N], dur[MAX_N];

const int INF = ~0U >> 2;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> t[i] >> dur[i];
		--t[i];
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= k; ++j) {
			dp[i][j] = INF;
		}
	}
	dp[0][0] = -1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= k; ++j) {
			int c = dp[i][j];
			if (c == INF)
				continue;
			//ignore one
			dp[i][j + 1] = min(dp[i][j + 1], c);
			//remove it
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], c);
			//keep it
			if (t[i] >= c)
				dp[i + 1][j] = min(dp[i + 1][j], t[i] + dur[i]);
			else
				dp[i + 1][j] = min(dp[i + 1][j], c + dur[i]);
		}
	}
	int r = 0;
	int p = 0;
	int ans = 0;
	t[n] = TIME;
	for (int l = 0; l < TIME; ++l) {
		//[l,t[r])
		while (r < n) {
			++r;
			int need = r - p;
			if (need <= k) {
				if (dp[p][k - need] <= l) {
					continue;
				}
			}
			--r;
			break;
		}
		ans = max(ans, t[r] - l);
		if (p < n && t[p] == l) {
			++p;
		}
	}
	cout << ans << endl;
	return 0;
}