#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5, maxm = 3e3, mod = 998244353;
int n, m, a[maxn + 3], w[maxn + 3], P, N, dp[maxm + 3][maxm + 3];

void add(int &x, int y) {
	x += y, x < mod ? 0 : x -= mod;
}

int qpow(int a, int b) {
	int c = 1;
	for (; b; b >>= 1, a = 1ll * a * a % mod) {
		if (b & 1) c = 1ll * a * c % mod;
	}
	return c;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		if (a[i]) {
			P += w[i];
		} else {
			N += w[i];
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j <= i; j++) {
			int a = P + j, b = N - (i - j);
			if (b < 0) continue;
			int inv = qpow(a + b, mod - 2);
			add(dp[i + 1][j + 1], 1ll * dp[i][j] * a % mod * inv % mod);
			add(dp[i + 1][j], 1ll * dp[i][j] * b % mod * inv % mod);
		}
	}
	int E_P = 0, E_N = 0;
	for (int i = 0; i <= m; i++) {
		int a = P + i, b = N - (m - i);
		if (b < 0) continue;
		add(E_P, 1ll * a * dp[m][i] % mod);
		add(E_N, 1ll * b * dp[m][i] % mod);
	}
	int I_P = qpow(P, mod - 2), I_N = qpow(N, mod - 2);
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			printf("%lld\n", 1ll * E_P * I_P % mod * w[i] % mod);
		} else {
			printf("%lld\n", 1ll * E_N * I_N % mod * w[i] % mod);
		}
	}
	return 0;
}