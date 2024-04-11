#include <bits/stdc++.h>
using namespace std;

const int N = 21, mod = 31607;

int n, g[N][1<<N], S, b[1<<N];

int fpow_(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = 1ll*a*a%mod) {
		if (b&1) {
			res = 1ll*res*a%mod;
		}
	}

	return res;
}

int main() {
	scanf("%d", &n), S = (1<<n) - 1;

	int val = fpow_(10000, mod - 2);

	for (int i = 0; i < n; i++) {
		g[i][0] = 1;

		for (int j = 0; j < n; j++) {
			scanf("%d", &g[i][1<<j]);
			g[i][1<<j] = g[i][1<<j]*val%mod;
		}

		for (int j = 1; j <= S; j++) {
			g[i][j] = g[i][j&(j - 1)]*g[i][j^(j&(j - 1))]%mod;
		}
	}

	int ans = 0;

	for (int i = 1; i <= S; i++) {
		b[i] = b[i>>1] + (i&1);
	}

	for (int c = 0; c < 4; c++) {
		for (int i = 0; i <= S; i++) {
			int f = (b[c] + b[i])&1 ? -1 : 1;

			for (int j = 0; j < n; j++) {
				int t = i;

				if (c&1) {
					t |= 1<<j;
				}

				if (c&2) {
					t |= 1<<n - j - 1;
				}

				f = f*(g[j][t] - g[j][S])%mod;
			}

			ans = (ans + f)%mod;
		}
	}

	ans = (1 - ans)%mod;

	printf("%d\n", (ans%mod + mod)%mod);
}