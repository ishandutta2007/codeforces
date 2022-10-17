#include <bits/stdc++.h>
using namespace std;
int n, m, par[20][300005], *fa = *par, dep[300005];
vector<int> g[300005];
vector<pair<int, int>> e[300005];
int id[300005], eid[300005], dfn;
int c[300005];
void add(int p) {
	for (; p <= n; p += p & -p)
		c[p] += 1; 
}
int query1(int p) {
	int res = 0;
	for (; p; p -= p & -p)
		res += c[p];
	return res;
}
int query(int u) {
	return query1(eid[u]) - query1(id[u] - 1);
}
int jump(int u, int d) {
	while (d) {
		int k = __builtin_ctz(d);
		u = par[k][u];
		d ^= 1 << k; 
	}
	return u;
}
int LCA(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	u = jump(u, dep[u] - dep[v]);
	if (u == v) return u;
	for (int k = 19; ~k; --k) {
		if (par[k][u] != par[k][v]) {
			u = par[k][u];
			v = par[k][v];
		}
	}
	return fa[u];
}
int ans;
void dfs(int u) {
	id[u] = ++dfn;
	for (auto v : g[u])
		dfs(v);
	eid[u] = dfn;
	for (auto p : e[u]) {
		int y = p.first, z = p.second;
		if (query(y) == query(z)) 
			add(id[z]), ++ans;
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 2; i <= n; ++i) {
		scanf("%d", &fa[i]);
		g[fa[i]].emplace_back(i);
		dep[i] = dep[fa[i]] + 1;
		for (int k = 1; k < 20; ++k) 
			par[k][i] = par[k - 1][par[k - 1][i]];
	}
	vector<pair<int, int>> v;
	for (int i = 1; i <= m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (dep[x] > dep[y]) swap(x, y);
		if (LCA(x, y) == x) {
			int z = jump(y, dep[y] - dep[x] - 1);
			if (z == y) {
				puts("-1");
				return 0;
			}
			e[x].emplace_back(y, z);
		} else {
			v.emplace_back(x, y);
		}
	}
	dfs(1);
	bool flag = false;
	for (auto p : v) 
		flag |= (query(p.first) + query(p.second) == ans);
	if (flag) ++ans;
	printf("%d\n", ans);
	return 0;
}