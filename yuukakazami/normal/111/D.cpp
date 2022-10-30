/*
 * d.cpp
 *
 *  Created on: 2011-9-3
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

const int MAX_N = 1000 + 10;
const int MOD = int(1e9) + 7;
int n, m, k;
typedef long long int64;
const int MAX_K = int(1e6) + 10;
int64 fact[MAX_K];
int64 invFact[MAX_K];
int64 dp[MAX_N][MAX_N] = { };

int64 powMemo[MAX_N];

int64 powMod(int64 x, int e) {
	if (!e)
		return 1;
	return (e & 1) ? powMod(x, e - 1) * x % MOD : powMod(x * x % MOD, e >> 1);
}

int64 comb(int n, int m) {
	return fact[n] * invFact[m] % MOD * invFact[n - m] % MOD;
}

int main() {
	for (int i = 0; i < MAX_K; ++i) {
		if (!i)
			fact[i] = 1;
		else
			fact[i] = (i * fact[i - 1]) % MOD;
		invFact[i] = powMod(fact[i], MOD - 2);
	}
	dp[0][0] = 1;
	for (int i = 1; i < MAX_N; ++i) {
		for (int j = 1; j <= i; ++j) {
			dp[i][j] = (dp[i - 1][j - 1] + j * dp[i - 1][j]) % MOD;
		}
	}
	cin >> n >> m >> k;
	if (m == 1) {
		cout << powMod(k, n) << endl;
		return 0;
	}
	int64 ans = 0;
	int free = (m - 2) * n;
	for (int i = 0; i < MAX_N; ++i) {
		powMemo[i] = powMod(i, free);
	}
	for (int nC = 1; nC <= min(n, k); ++nC) {
		for (int nSame = 0; nSame <= nC; ++nSame) {
			if (nC * 2 - nSame > k)
				continue;
			int64 tmp = comb(k, nSame) * comb(k - nSame, nC - nSame) % MOD;
			(tmp *= comb(k - nC, nC - nSame)) %= MOD;
			(tmp *= dp[n][nC] * dp[n][nC] % MOD * fact[nC] % MOD * fact[nC] % MOD) %= MOD;
			(tmp *= powMemo[nSame]) %= MOD;
			(ans += tmp) %= MOD;
		}
	}
	cout << ans << endl;
	return 0;
}