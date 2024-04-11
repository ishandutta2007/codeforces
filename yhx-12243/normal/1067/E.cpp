#include <bits/stdc++.h>

typedef long long ll;
const int N = 510000, M = N * 2;
const ll mod = 998244353, inv2 = (mod + 1) / 2;

int n, E = 0;
int to[M], first[N], next[M];
int cnt = 0, id[N], f[N];
ll ans = 0;

ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

inline void addedge(int u, int v) {
	to[++E] = v; next[E] = first[u]; first[u] = E;
	to[++E] = u; next[E] = first[v]; first[v] = E;
}

void dfs(int x, int px = 0) {
	int i, y; ll cur = 1;
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != px)
			dfs(y, x), cur = cur * (1 + f[y]) % mod * inv2 % mod;
	ans += f[x] = mod + 1 - cur;
}

int main() {
	int i, u, v;
	scanf("%d", &n);
	for (i = 1; i < n; ++i) scanf("%d%d", &u, &v), addedge(u, v);
	dfs(1); ans %= mod;
	printf("%lld\n", PowerMod(2, n, ans + (ans >> 63 & mod)));
	return 0;
}