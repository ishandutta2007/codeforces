#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e5;
int n, k, r, q, d[maxn + 3], b[maxn + 3], fa[maxn + 3], dep[maxn + 3], go[20][maxn + 3];
vector<int> G[maxn + 3];

void add(int u, int v) {
	G[u].push_back(v), G[v].push_back(u);
}

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void dfs(int u, int f = 0) {
	for (int i = 0, v; i < G[u].size(); i++) {
		if ((v = G[u][i]) == f) continue;
		go[0][v] = u, dep[v] = dep[u] + 1, dfs(v, u);
	}
}

int jump(int u, int x) {
	for (int i = 0; i <= 18; i++) if (x >> i & 1) u = go[i][u];
	return u;
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	u = jump(u, dep[u] - dep[v]);
	if (u == v) return u;
	for (int i = 18; ~i; i--) if (go[i][u] != go[i][v]) u = go[i][u], v = go[i][v];
	return go[0][u];
}

int main() {
	scanf("%d %d %d", &n, &k, &r);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d %d", &u, &v);
		add(u, i + n), add(v, i + n);
	}
	for (int i = 1; i <= n * 2; i++) fa[i] = i;
	memset(d, -1, sizeof(d));
	queue<int> Q;
	for (int i = 1, x; i <= r; i++) {
		scanf("%d", &x);
		d[x] = 0, b[x] = x, Q.push(x);
	}
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		if (d[u] == k) break;
		for (int i = 0, v; i < G[u].size(); i++) {
			v = G[u][i];
			if (d[v] == -1) {
				d[v] = d[u] + 1, b[v] = b[u];
				Q.push(v);
			} else if (d[u] + 1 <= k) {
				fa[find(b[u])] = find(b[v]);
			}
		}
	}
	dfs(1);
	for (int k = 1; k <= 18; k++) {
		for (int i = 1; i <= n * 2; i++) {
			go[k][i] = go[k - 1][go[k - 1][i]];
		}
	}
	scanf("%d", &q);
	for (int x, y, z, d; q --> 0; ) {
		scanf("%d %d", &x, &y);
		z = lca(x, y), d = dep[x] + dep[y] - dep[z] * 2;
		if (d <= k * 2) { puts("YES"); continue; }
		int u = dep[x] - dep[z] >= k ? jump(x, k) : jump(y, d - k);
		int v = dep[y] - dep[z] >= k ? jump(y, k) : jump(x, d - k);
		puts(b[u] && b[v] && find(b[u]) == find(b[v]) ? "YES" : "NO");
	}
	return 0;
}