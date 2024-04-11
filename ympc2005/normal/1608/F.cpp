#include <bits/stdc++.h>
using namespace std;

const int N = 2005, M = 55, mod = 998244353;

int n, m, b[N], st[N], ed[N], f[M<<1][N], g[M<<1][N], sum[N<<1], fac[N], inv[N];

int fpow_(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = 1ll*a*a%mod) {
		if (b&1) {
			res = 1ll*res*a%mod;
		}
	}

	return res;
}

int main() {
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		st[i] = max(b[i] - m, 0), ed[i] = min(b[i] + m, i);
	}

	fac[0] = 1;

	for (int i = 1; i <= n; i++) {
		fac[i] = 1ll*i*fac[i - 1]%mod;
	}

	inv[n] = fpow_(fac[n], mod - 2);

	for (int i = n; i; i--) {
		inv[i - 1] = 1ll*i*inv[i]%mod;
	}

	f[0][0] = 1;

	for (int i = 1; i <= n; i++) {
		memcpy(g, f, sizeof(f));
		memset(f, 0, sizeof(f));
		memset(sum, 0, sizeof(sum));

		for (int j = st[i], p = st[i - 1] - 1; j <= ed[i]; j++) {
			while (p < ed[i - 1] && p < j - 1) {
				p++;
				
				for (int k = 0; k < i; k++) {
					sum[p + k] = (sum[p + k] + 1ll*fac[k]*g[p - st[i - 1]][k])%mod;
				}
			}

			for (int k = 0; k <= i; k++) {
				int x = j - st[i];
				f[x][k] = 1ll*sum[j + k - 1]*inv[k]%mod;

				if (st[i - 1] <= j && j <= ed[i - 1]) {
					f[x][k] = (f[x][k] + g[j - st[i - 1]][k - 1])%mod;
					f[x][k] = (f[x][k] + 1ll*g[j - st[i - 1]][k]*(j + k))%mod;
				}
			}
		}		
	}

	int ans = 0;

	for (int i = st[n]; i <= ed[n]; i++) {
		for (int j = 0; i + j <= n; j++) {
			ans = (ans + 1ll*f[i - st[n]][j]*fac[n - i]%mod*inv[n - i - j])%mod;
		}
	}

	printf("%d\n", (ans%mod + mod)%mod);
}