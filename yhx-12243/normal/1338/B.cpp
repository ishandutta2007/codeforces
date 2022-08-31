#include <bits/stdc++.h>

const int N = 100054, M = N * 2;

int n, E = 0;
int to[M], first[N], next[M], deg[N];
int p[N], dep[N];
int cnt = 0, z[N];

inline void addedge(int u, int v) {
	to[++E] = v, next[E] = first[u], first[u] = E, ++deg[u];
	to[++E] = u, next[E] = first[v], first[v] = E, ++deg[v];
}

void dfs(int x) {
	int i, y;
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != p[x])
			p[y] = x, dep[y] = dep[x] + 1, dfs(y);
}

int main() {
	int i, u, v, dd, s[2] = {0}, min, max;
	scanf("%d", &n);
	for (i = 1; i < n; ++i) scanf("%d%d", &u, &v), addedge(u, v);
	dfs(1);
	for (i = 1; i <= n; ++i)
		if (deg[i] == 1) ++s[dep[i] & 1], z[cnt++] = to[first[i]];
	min = (s[0] && s[1] ? 3 : 1);
	std::sort(z, z + cnt), dd = std::unique(z, z + cnt) - z;
	max = n - 1 - (cnt - dd);
	printf("%d %d\n", min, max);
	return 0;
}