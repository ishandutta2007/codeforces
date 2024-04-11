#include <bits/stdc++.h>
#define ad(x) ((x - 1 ^ 1) + 1)

const int N = 100054, M = N * 5;

int V, E, Es = 0;
int to[M], first[N], next[M], deg[N];
int cnt = 0, euler[M];
bool used[M];

inline void addedge(int u, int v) {
	to[++Es] = v, next[Es] = first[u], first[u] = Es, ++deg[u];
	to[++Es] = u, next[Es] = first[v], first[v] = Es, ++deg[v];
}

void dfs(int x) {
	for (int &i = first[x]; i; i = next[i])
		if (!used[i])
			used[ad(i)] = used[i] = true, dfs(to[i]);
	euler[cnt++] = x;
}

int main() {
	int i, u, v, la = 0;
	scanf("%d%d", &V, &E);
	for (i = 0; i < E; ++i) scanf("%d%d", &u, &v), addedge(u, v);
	for (i = 1; i <= V; ++i) if (deg[i] & 1) la ? addedge(la, i), la = 0 : la = i;
	assert(!la), dfs(1), --cnt;
	assert(cnt * 2 == Es);
	if (cnt & 1) euler[cnt] = euler[cnt - 1], ++cnt;
	euler[cnt] = u = *euler, v = euler[1];
	printf("%d\n", cnt);
	for (i = 1; i <= cnt; ++i, (i & 1 ? v : u) = euler[i])
		printf("%d %d\n", u, v);
	return 0;
}