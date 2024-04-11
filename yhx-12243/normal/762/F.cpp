#include <bits/stdc++.h>

typedef long long ll;
const int N1 = 1040, N2 = 14, M = (N1 + N2) * 2, Z = 4100;
const ll mod = 1000000007;

int n, K, E = 0, ALL;
int to[M], F1[N1], F2[N2], next[M];
int p[N2], G[N2], H[N2];
int f[N1][Z], *g[N1];

ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

inline void addedge(int u, int v, int *first) {
	to[++E] = v; next[E] = first[u]; first[u] = E;
	to[++E] = u; next[E] = first[v]; first[v] = E;
}

void predfs(int x, int *first) {
	int i, y;
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != p[x]) p[y] = x, predfs(y, first);
}

void dfs(int x, int px, int *first) {
	int i, j, k, y, la = 0; f[0][0] = 1;
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != px) {
			dfs(y, x, first);
			memcpy(f[y], f[la], ALL + 1 << 2);
			for (j = 1; j <= K; ++j) if (g[y][G[j]])
				for (k = 0; k <= ALL; ++k) if (k >> j - 1 & 1)
					f[y][k] = (f[y][k] + (ll)f[la][k ^ 1 << j - 1] * g[y][G[j]]) % mod;
			la = y;
		}
	g[x] = f[la];
}

int main() {
	int i, j, u, v; ll ans = 0, rep = 0;
	scanf("%d", &n);
	for (i = 1; i < n; ++i) scanf("%d%d", &u, &v), addedge(u, v, F1);
	scanf("%d", &K); ALL = ~(-1 << K);
	for (i = 1; i < K; ++i) scanf("%d%d", &u, &v), addedge(u, v, F2), H[u] |= 1 << v - 1, H[v] |= 1 << u - 1;;
	for (j = 1; j <= K; ++j) {
		memset(p, 0, K + 1 << 2); predfs(j, F2);
		for (v = 1; v <= K; ++v) G[v] = H[v] ^ (v == j ? 0 : 1 << p[v] - 1);
		dfs(1, 0, F1); for (i = 1; i <= n; ++i) ans += g[i][G[j]];
		ans %= mod;
	}
	for (j = 1; j <= K; ++j) {
		memset(p, 0, K + 1 << 2); predfs(j, F2);
		for (v = 1; v <= K; ++v) G[v] = H[v] ^ (v == j ? 0 : 1 << p[v] - 1);
		dfs(1, 0, F2); rep += g[1][G[j]];
		rep %= mod;
	}
	printf("%lld\n", PowerMod(rep, mod - 2, ans));
	return 0;
}