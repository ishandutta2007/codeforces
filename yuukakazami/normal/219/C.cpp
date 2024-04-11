/*
 * c.cpp
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
#include <string>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

int n, k;
string s;
const int MAX_N = int(5e5) + 10;
int dp[MAX_N][26];
int prev[MAX_N][26];

int main() {
	cin >> n >> k;
	cin >> s;
	for (int i = 0; i < k; ++i) {
		dp[0][i] = (s[0] == 'A' + i) ? 0 : 1;
	}

	for (int i = 1; i < n; ++i) {
		int mi1 = 0, mi2 = 1;
		int*p = dp[i - 1];
		if (p[mi2] < p[mi1])
			swap(mi1, mi2);
		for (int j = 2; j < k; ++j) {
			if (p[j] < p[mi2]) {
				mi2 = j;
				if (p[mi2] < p[mi1]) {
					swap(mi2, mi1);
				}
			}
		}
		for (int j = 0; j < k; ++j) {
			dp[i][j] = (j == mi1 ? p[mi2] : p[mi1]) + (('A' + j == s[i]) ? 0 : 1);
			prev[i][j] = (j == mi1 ? mi2 : mi1);
		}
	}

	int fc = 0;
	for (int i = 1; i < k; ++i) {
		if (dp[n - 1][i] < dp[n - 1][fc])
			fc = i;
	}
	cout << dp[n - 1][fc] << endl;
	string ret = "";
	for (int i = n - 1; i >= 0; --i) {
		ret += 'A' + fc;
		if (i > 0)
			fc = prev[i][fc];
	}
	reverse(ret.begin(), ret.end());
	cout << ret << endl;

	return 0;
}