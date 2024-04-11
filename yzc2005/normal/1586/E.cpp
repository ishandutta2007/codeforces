#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int n, m, q, x[N], y[N];
int dep[N], par[N], cnt[N];
bool vis[N]; 
vector<int> g[N], g1[N], g2[N];
void dfs1(int u) {
	vis[u] = true;
	for (auto i : g[u]) {
		int v = (u == x[i]) ? y[i] : x[i];
		if (!vis[v]) {
			dep[v] = dep[u] + 1;
			par[v] = i;
			dfs1(v);
		}
	}
}
int ans;
void dfs2(int u, bool type) {
	for (auto i : g[u]) {
		int v = (u == x[i]) ? y[i] : x[i];
		if (par[v] != i) continue;
		if (cnt[par[v]]) {
			if (type) {
				type = 0;
				dfs2(v, true);
			} else {
				++ans;
				type = true;
				dfs2(v, true);
			}
		} else {
			dfs2(v, false);
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> x[i] >> y[i];
		g[x[i]].emplace_back(i);
		g[y[i]].emplace_back(i);
	}
	dfs1(1);
	cin >> q;
	for (int i = 1; i <= q; ++i) {
		int u, v;
		cin >> u >> v;
		while (u != v) {
			if (dep[u] > dep[v]) {
				g1[i].emplace_back(u);
				cnt[par[u]] ^= 1;
				u = (x[par[u]] == u) ? y[par[u]] : x[par[u]];
			} else {
				g2[i].emplace_back(v);
				cnt[par[v]] ^= 1;
				v = (x[par[v]] == v) ? y[par[v]] : x[par[v]];
			}
		}
		g1[i].emplace_back(u);
	}
	if (count(cnt + 1, cnt + m + 1, true)) {
		puts("NO");
		dfs2(1, false);
		printf("%d\n", ans);
	} else {
		puts("YES");
		for (int i = 1; i <= q; ++i) {
			printf("%d\n", int(g1[i].size() + g2[i].size()));
			reverse(g2[i].begin(), g2[i].end());
			for (auto x : g1[i])
				printf("%d ", x);
			for (auto x : g2[i])
				printf("%d ", x);
			puts("");
		}
	}
	return 0;
}