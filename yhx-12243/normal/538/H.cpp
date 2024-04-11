#include <bits/stdc++.h>
#define fail return puts("IMPOSSIBLE"), 0

const int N = 100054, M = N * 2;

int lb, ub, n1, n2, V, E, Es = 0;
int l[N], r[N], col[N];
int to[M], first[N], next[M];
char res[N];

inline void addedge(int u, int v) {
	to[++Es] = v, next[Es] = first[u], first[u] = Es;
	to[++Es] = u, next[Es] = first[v], first[v] = Es;
}

inline bool dfs(int x) {
	int i, y;
	for (i = first[x]; i; i = next[i])
		if (~col[y = to[i]] ? col[y] == col[x] : (col[y] = !col[x], !dfs(y))) return false;
	return true;
}

int main() {
	int i, u, v;
	scanf("%d%d%d%d", &lb, &ub, &V, &E);
	for (i = 1; i <= V; ++i) scanf("%d%d", l + i, r + i);
	n1 = *std::max_element(l + 1, l + (V + 1));
	n2 = *std::min_element(r + 1, r + (V + 1));
	if (n1 + n2 < lb) n1 = lb - n2;
	else if (n1 + n2 > ub) n2 = ub - n1;
	if (n1 < 0 || n2 < 0) fail;
	for (i = 0; i < E; ++i) scanf("%d%d", &u, &v), addedge(u, v);
	for (i = 1; i <= V; ++i)
		switch ((l[i] <= n1 && n1 <= r[i]) | (l[i] <= n2 && n2 <= r[i]) << 1) {
			case 0: fail;
			case 1: col[i] = 0; break;
			case 2: col[i] = 1; break;
			case 3: col[i] = -1; break;
		}
	for (i = 1; i <= V; ++i) if (~col[i] && !dfs(i)) fail;
	for (i = 1; i <= V; ++i) if (!(~col[i] || (col[i] = 0, dfs(i)))) fail;
	for (i = 1; i < Es; i += 2) if (col[ to[i] ] == col[ to[i + 1] ]) fail;
	for (i = 0; i < V; ++i) res[i] = col[i + 1] + 49;
	printf("POSSIBLE\n%d %d\n%s\n", n1, n2, res);
	return 0;
}