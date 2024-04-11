#include <bits/stdc++.h>

const int N = 100054, M = N * 2;

int n, E = 0, ans;
int to[M], first[N], next[M], deg[N];
int p[N], f[N], g[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}

inline void addedge(int u, int v) {
	to[++E] = v, next[E] = first[u], first[u] = E, ++deg[u];
	to[++E] = u, next[E] = first[v], first[v] = E, ++deg[v];
}

void dfs(int x) {
	int i, y;
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != p[x])
			p[y] = x, dfs(y),
			up(ans, f[x] + f[y]),
			up(ans, f[x] + g[y] + 1),
			up(ans, g[x] + f[y] + 1),
			up(f[x], deg[x] - 2 + f[y]),
			up(f[x], deg[x] - 1 + g[y]),
			up(g[x], f[y]);
}

int main() {
	int i, u, v;
	scanf("%d", &n);
	for (i = 1; i < n; ++i) scanf("%d%d", &u, &v), addedge(u, v);
	dfs(1), printf("%d\n", ans);
	return 0;
}