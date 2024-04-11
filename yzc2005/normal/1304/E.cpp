#include <bits/stdc++.h>
using namespace std;
#define rg register
#define go(u) for(rg int i = head[u], v = to[i]; i; i = nxt[i], v = to[i])

const int N = 100010;
int n, q, cnt, to[N << 1], nxt[N << 1], head[N], fa[N], siz[N], heavy[N], dep[N], top[N], id[N], tot, d[10];

inline void add(int u, int v) {
	to[++cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}

void dfs1(int u) {
	siz[u] = 1;
	go(u) {
		if(v == fa[u]) continue;
		fa[v] = u;
		dep[v] = dep[u] + 1;
		dfs1(v);
		siz[u] += siz[v];
		if(siz[heavy[u]] < siz[v]) heavy[u] = v; 
	}
}

void dfs2(int u, int tp) {
	top[u] = tp;
	id[u] = ++tot;
	if(heavy[u]) dfs2(heavy[u], tp);
	go(u) {
		if(v == fa[u] || v == heavy[u]) continue;
		dfs2(v, v);
	}
}

inline int getlca(int u, int v) {
	while(top[u] != top[v]) {
		if(dep[top[u]] < dep[top[v]]) swap(u, v);
		u = fa[top[u]];
	} 
	return dep[u] < dep[v] ? u : v;
}

inline int dis(int u, int v) {
	return dep[u] + dep[v] - (dep[getlca(u, v)] << 1);
}

int main() {
	cin >> n;
	for(int i = 1, u, v; i < n; ++i) cin >> u >> v, add(u, v), add(v, u);
	dfs1(1), dfs2(1, 1);
	cin >> q;
	for(int j = 1, x, y, u, v, k; j <= q; ++j) {
		cin >> x >> y >> u >> v >> k;
		if(min(dis(u, v), min(dis(u, x) + dis(v, y) + 1, dis(u, y) + dis(v, x) + 1)) > k) {puts("NO"); continue;}
		int D = dis(x, y) + 1;
		d[1] = k - dis(u, x) - dis(x, v), d[2] = k - dis(u, y) - dis(y, v), d[3] = k - dis(u, x) - dis(v, y) - 1, d[4] = k - dis(u, y) - dis(v, x) - 1, d[5] = k - dis(u, v);
		bool f = 0;
		for(int i = 1; i <= 5; ++i) {
			if(d[i] < 0) continue;
			if(!(d[i] & 1)) f = 1;
			if(i != 5 && d[i] >= D && !((d[i] - D) & 1)) f = 1;
		}
		puts(f ? "YES" : "NO");
	}
	return 0;
}