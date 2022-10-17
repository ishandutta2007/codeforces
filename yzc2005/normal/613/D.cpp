#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, q, k, a[N], stk[N], tp;
vector<int> G[N], g[N];
int tot, dfn[N], sz[N], son[N], fa[N], dep[N], top[N];
bool f[N], chosen[N];

void dfs1(int u) {
	sz[u] = 1;
	dfn[u] = ++tot;
	for(auto v : G[u]) {
		if(v == fa[u]) continue;
		fa[v] = u;
		dep[v] = dep[u] + 1;
		dfs1(v);
		sz[u] += sz[v];
		if(sz[son[u]] < sz[v]) son[u] = v;
	}
}
void dfs2(int u, int tp) {
	top[u] = tp;
	if(son[u]) dfs2(son[u], tp);
	for(auto v : G[u]) {
		if(v == fa[u] || v == son[u]) continue;
		dfs2(v, v);
	}
}
inline int LCA(int u, int v) {
	while(top[u] != top[v]) {
		if(dep[top[u]] < dep[top[v]]) swap(u, v);
		u = fa[top[u]];
	}
	return dep[u] > dep[v] ? v : u;
}

inline bool cmp(int &u, int &v) {
	return dfn[u] < dfn[v];
}
inline void ins(int u) {
	if(u == 1) return;
	int lca = LCA(u, stk[tp]);
	if(lca == stk[tp]) return stk[++tp] = u, void();
	for(; tp > 1 && dep[lca] < dep[stk[tp - 1]]; --tp) 
		g[stk[tp - 1]].push_back(stk[tp]);
	if(lca != stk[tp - 1]) {
		g[lca].clear();
		g[lca].push_back(stk[tp]);
		stk[tp] = lca;
	}
	else g[lca].push_back(stk[tp--]);
	stk[++tp] = u;
}
inline void build() {
	scanf("%d", &k);
	for(int i = 1; i <= k; ++i) scanf("%d", &a[i]), g[a[i]].clear();
	sort(a + 1, a + k + 1, cmp);
	stk[tp = 1] = 1, g[1].clear();
	for(int i = 1; i <= k; ++i) ins(a[i]);
	for(int i = 1; i < tp; ++i) g[stk[i]].push_back(stk[i + 1]);
}

int dp(int u) {
	int sum = 0, res = 0;
	for(auto v : g[u]) {
		res += dp(v);
		sum += f[v]; 
	}
	if(chosen[u]) return f[u] = 1, res + sum;
	else if(sum > 1) return f[u] = 0, res + 1;
	return f[u] = sum, res;
} 

int main() {
	scanf("%d", &n);
	for(int i = 1, u, v; i < n; ++i) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1), dfs2(1, 1);
	for(scanf("%d", &q); q; --q) {
		build();
		for(int i = 1; i <= k; ++i) chosen[a[i]] = 1;
		bool ok = 1;
		for(int i = 1; i <= k; ++i) if(chosen[fa[a[i]]]) ok = 0;
		printf("%d\n", ok ? dp(1) : -1);
		for(int i = 1; i <= k; ++i) chosen[a[i]] = 0;
	}
}