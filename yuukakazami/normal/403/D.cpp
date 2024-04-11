#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

const int MOD = int(1e9) + 7;
const int MAX_N = 1000 + 10;
int n, k;
int F[MAX_N][MAX_N]; //k distinct number , sum to s
int C[MAX_N][MAX_N];
int ans[MAX_N][MAX_N];
int fact[MAX_N];

int main() {
	F[0][0] = 1;

	for (int i = 1; i < MAX_N; ++i) {
		for (int j = 0; j < MAX_N; ++j) {
			//have 0
			if (j - i + 1 >= 0)
				F[i][j] = F[i - 1][j - i + 1];
			if (j - i >= 0)
				F[i][j] += F[i][j - i];
//			F[i][j] = F[i - 1][j - i + 1] + F[i][j - i];
			if (F[i][j] >= MOD)
				F[i][j] -= MOD;
		}
	}
	for (int i = 0; i < MAX_N; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (i == 0 || j == 0)
				C[i][j] = 1;
			else
				C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
		}
	}

	fact[0] = 1;
	for (int i = 1; i < MAX_N; ++i) {
		fact[i] = (1LL * fact[i - 1] * i) % MOD;
	}

	for (int n = 1; n < MAX_N; ++n) {
		for (int k = 1; k < MAX_N; ++k) {
			if (k * (k - 1) / 2 > n)
				break;
			int t = 0;
			for (int s = k * (k - 1) / 2; s <= n; ++s) {
				t = t + 1LL * F[k][s] * C[n - s][k] % MOD;
				if (t >= MOD)
					t -= MOD;
			}
			ans[n][k] = 1LL * t * fact[k] % MOD;
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		printf("%d\n", ans[n][k]);
	}
}