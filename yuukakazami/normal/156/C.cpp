/*
 * c.cpp
 *
 *  Created on: 2012-3-1
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

const int MAX_N = 100 + 10;
const int MOD = int(1e9) + 7;

int dp[MAX_N][MAX_N * 26];

int main() {

	int N = 100;
	memset(dp, 0, sizeof dp);
	dp[0][0] = 1;
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= N * 26; ++j) {
			int c = dp[i][j];
			if (c != 0) {
				for (int k = 0; k < 26; ++k) {
					dp[i + 1][j + k] += c;
					if (dp[i + 1][j + k] >= MOD)
						dp[i + 1][j + k] -= MOD;
				}
			}
		}
	}
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		static char buf[1000];
		scanf(" ");
		scanf("%s", buf);
		int l = strlen(buf);
		int sum = 0;
		for (int j = 0; j < l; ++j) {
			sum += buf[j] - 'a';
		}
		cout << (dp[l][sum] + MOD - 1) % MOD << endl;
	}
	return 0;
}