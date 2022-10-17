#include <bits/stdc++.h>
using namespace std;

const int N = 400005, K = 20;
int n, r, m, q, fa[N][K], d[N], vis[N], bel[N];
vector<int> g[N];
queue<int> qu;

inline int get(int x) {
	return x == bel[x] ? x
	: bel[x] = get(bel[x]);
}

inline void add(int u, int v) {
	g[u].push_back(v);
	g[v].push_back(u);
}

void dfs(int u) {
	for(int i = 0; i < g[u].size(); ++i) {
		int v = g[u][i];
		if(v == fa[u][0]) continue;
		fa[v][0] = u;
		d[v] = d[u] + 1;
		dfs(v);
	}
}
inline int jump(int u, int k) {
	for(int j = 0; j < K; ++j)
		if(k >> j & 1) u = fa[u][j];
	return u;
}
inline int lca(int u, int v) {
	if(d[u] < d[v]) swap(u, v);
	u = jump(u, d[u] - d[v]);
	if(u == v) return u;
	for(int j = K - 1; ~j; --j)
		if(fa[u][j] != fa[v][j]) 
			u = fa[u][j], v = fa[v][j];
	return fa[u][0];
}

int main() {
	scanf("%d%d%d", &n, &r, &m);
	for(int i = 1, u, v, nn = n; i < nn; ++i) {
		scanf("%d%d", &u, &v);
		add(++n, u), add(n, v);
	}
	dfs(1);
	for(int j = 1; j < K; ++j)
		for(int i = 1; i <= n; ++i)
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
	memset(vis, -1, sizeof(vis));	
	for(int i = 1; i <= n; ++i) bel[i] = i;
	for(int i = 1, u; i <= m; ++i) scanf("%d", &u), qu.push(u), vis[u] = 0;
	while(!qu.empty()) {
		int u = qu.front(); qu.pop();
		for(int i = 0; i < g[u].size(); ++i) {
			int v = g[u][i];
			bel[get(u)] = get(v);
			if(vis[v] == -1) {
				vis[v] = vis[u] + 1;
				if(vis[v] != r) qu.push(v);
			}
		}
	}
	for(scanf("%d", &q); q; --q) {
		int u, v, w, dis; 
		scanf("%d%d", &u, &v), w = lca(u, v);
		dis = d[u] + d[v] - 2 * d[w];
		if(dis <= 2 * r) {
			puts("YES");
		} else {
			int uu = u;
			u = d[u] - d[w] >= r ? jump(u, r) : jump(v, dis - r);
			v = d[v] - d[w] >= r ? jump(v, r) : jump(uu, dis - r);
			puts(get(u) == get(v) ? "YES" : "NO");
		}
	}
}