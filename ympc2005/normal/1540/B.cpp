#include <bits/stdc++.h>
using namespace std;

const int N = 205, mod = 1e9 + 7;

int n, fa[N], d[N], ans, f[N][N][2], inv[N], sz[N];

vector <int> e[N];

void dfs_(int u) {
	d[u] = d[fa[u]] + 1, sz[u] = 1;

	for (int v : e[u]) {
		if (v == fa[u]) {
			continue;
		}

		fa[v] = u, dfs_(v);
		sz[u] += sz[v];
	}
}

int main() {
	scanf("%d", &n);

	for (int u, v, i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}

	inv[0] = inv[1] = 1;

	for (int i = 2; i <= n; i++) {
		inv[i] = -1ll*inv[mod%i]*(mod/i)%mod;
	}

	f[0][0][0] = 1;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k < 2; k++) {
				f[i + 1][j][0] = (f[i + 1][j][0] + 1ll*inv[2]*f[i][j][k])%mod;
				f[i][j + 1][1] = (f[i][j + 1][1] + 1ll*inv[2]*f[i][j][k])%mod;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			f[i][j][0] = (f[i][j][0] + f[i][j - 1][0])%mod;
		}
	}

	for (int i = 1; i < n; i++) {
		fa[i] = 0, dfs_(i);

		for (int j = i + 1; j <= n; j++) {
			ans = (ans + sz[j])%mod;

			for (int k = fa[j], x = j; k != i; x = k, k = fa[k]) {
				ans = (ans + 1ll*(sz[k] - sz[x])*f[d[j] - d[k]][d[k] - 2][0])%mod;
			}
		}
	}

	ans = 1ll*ans*inv[n]%mod;

	printf("%d\n", (ans%mod + mod)%mod);
}