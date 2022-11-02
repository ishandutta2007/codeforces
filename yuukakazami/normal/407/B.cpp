/*
 * B.cpp
 *
 *  Created on: 2014330
 *      Author: wjmzbmr
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
const int MAX_N = 1000 + 10, MOD = int(1e9) + 7;
int dp[MAX_N][MAX_N];
int p[MAX_N], n;

int calc(int i, int j) {
	if (i == j)
		return 0;
	int&ret = dp[i][j];
	if (ret != -1)
		return ret;
	ret = (1 + calc(p[i], i) + 1 + calc(i + 1, j)) % MOD;
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p[i], --p[i];
	}
	memset(dp, -1, sizeof dp);
	cout << calc(0, n) << endl;
}