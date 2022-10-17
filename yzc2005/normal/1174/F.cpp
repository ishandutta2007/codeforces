#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, sz[N], son[N], dep[N], fa[N], butt[N], depx;
int hd[N], to[N << 1], nxt[N << 1], cnt;

void pre(int u) {
	sz[u] = 1;
	for(int i = hd[u], v = to[i]; i; i = nxt[i], v = to[i]) {
		if(v == fa[u]) continue;
		fa[v] = u, dep[v] = dep[u] + 1;
		pre(v);
		sz[u] += sz[v];
		if(sz[v] > sz[son[u]]) son[u] = v;
	}
}

void pre(int u, int tp) {
	butt[tp] = u;
	if(son[u]) pre(son[u], tp);
	for(int i = hd[u], v = to[i]; i; i = nxt[i], v = to[i]) {
		if(v == fa[u] || v == son[u]) continue;
		pre(v, v);
	}
}

void dfs(int u) {
	cout << "d " << butt[u] << '\n', fflush(stdout);
	int d; cin >> d;
	int dep_lca = (depx + dep[butt[u]] - d) >> 1;
	while(dep[u] != dep_lca) u = son[u];
	if(dep[u] == depx) cout << "! " << u << '\n', fflush(stdout), exit(0);
	cout << "s " << u << '\n', fflush(stdout);
	int v; cin >> v; dfs(v);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		to[++cnt] = v, nxt[cnt] = hd[u], hd[u] = cnt;
		to[++cnt] = u, nxt[cnt] = hd[v], hd[v] = cnt;
	}
	pre(1), pre(1, 1);
	cout << "d " << 1 << '\n', fflush(stdout);
	cin >> depx, dfs(1);
}