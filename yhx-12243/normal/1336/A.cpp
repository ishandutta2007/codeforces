#include <bits/stdc++.h>

typedef std::pair <int, int> pr;
const int N = 200054, M = N * 2;

int n, E = 0, K;
int to[M], first[N], next[M], deg[N];
int p[N], dep[N], size[N];
std::priority_queue <pr> pq;

inline void addedge(int u, int v) {
	to[++E] = v, next[E] = first[u], first[u] = E;
	to[++E] = u, next[E] = first[v], first[v] = E;
}

void dfs(int x) {
	int i, y; size[x] = 1;
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != p[x])
			++deg[x], p[y] = x, dep[y] = dep[x] + 1, dfs(y), size[x] += size[y];
}

int main() {
	int i, u, v; long long ans = 0;
	scanf("%d%d", &n, &K);
	for (i = 1; i < n; ++i) scanf("%d%d", &u, &v), addedge(u, v);
	dfs(1);
	for (i = 1; i <= n; ++i) dep[i] -= size[i] - 1;
	std::sort(dep + 1, dep + (n + 1), std::greater <int> ());
	for (i = 1; i <= K; ++i) ans += dep[i];
	printf("%lld\n", ans);
	return 0;
}