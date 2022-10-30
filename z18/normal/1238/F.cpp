#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5;
int T, n, deg[maxn + 3], f[maxn + 3], g[maxn + 3];
vector<int> G[maxn + 3];

void add(int u, int v) {
	G[u].push_back(v), deg[u]++;
}

void dfs(int u, int pa = 0) {
	f[u] = 0, g[u] = deg[u];
	for (int i = 0, v; i < G[u].size(); i++) {
		v = G[u][i];
		if (v == pa) continue;
		dfs(v, u);
		f[u] = max(f[u], max(f[v], g[u] + g[v]));
		g[u] = max(g[u], g[v] + deg[u]);
	}
}

int main() {
	scanf("%d", &T);
	while (T --> 0) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			vector<int>().swap(G[i]), deg[i] = -1;
		}
		for (int i = 1, u, v; i < n; i++) {
			scanf("%d %d", &u, &v);
			add(u, v), add(v, u);
		}
		dfs(1);
		printf("%d\n", f[1] + 2);
	}
	return 0;
}