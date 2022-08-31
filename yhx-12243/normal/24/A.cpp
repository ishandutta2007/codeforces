#include <bits/stdc++.h>

const int N = 254;

struct edge {
	int u, v, w;
	edge (int u0 = 0, int v0 = 0, int w0 = 0) : u(u0), v(v0), w(w0) {}
} e[N];

int n, E = 0, A[2];
int first[N], next[N];
bool used[N];

inline void addedge(int u, int v, int w) {
	e[++E] = edge(u, v, w), next[E] = first[u], first[u] = E;
	e[++E] = edge(v, u, w), next[E] = first[v], first[v] = E;
}

void dfs(int x) {
	int i, y; used[x] = true;
	for (i = first[x]; i; i = next[i])
		if (!used[y = e[i].v]) {
			A[i & 1] += e[i].w, dfs(y); return;
		}
	for (i = first[x]; i; i = next[i])
		if ((y = e[i].v) == 1) A[i & 1] += e[i].w;
}

int main() {
	int i, u, v, w;
#ifndef ONLINE_JUDGE
	freopen("huan.in", "r", stdin);
	freopen("huan.out", "w", stdout);
#endif
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) scanf("%d%d%d", &u, &v, &w), addedge(u, v, w);
	dfs(1);
	printf("%d\n", std::min(A[0], A[1]));
	return 0;
}