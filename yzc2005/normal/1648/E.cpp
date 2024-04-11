#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
const int inf = 0x3f3f3f3f;
struct edge {
	int u, v, w;
	edge(int x = 0, int y = 0, int z = 0) : u(x), v(y), w(z) {}
	inline bool operator<(const edge &rhs) const { return w < rhs.w; }
} e[N];
int n, m, x[N], y[N], nxt[N], prv[N], fa[N], id[N], rev[N], dfn;
vector<int> banned[N], bel[N];
array<int, 3> choice[N];
bool mark[N];
int get_nxt(int x) { return x == nxt[x] ? x : nxt[x] = get_nxt(nxt[x]); }
int get_prv(int x) { return x == prv[x] ? x : prv[x] = get_prv(prv[x]); }
inline void update(int x, int c) {
	if (x > 1 && fa[rev[x - 1]] == c) nxt[x - 1] = x, prv[x] = x - 1;
	if (x < n && fa[rev[x + 1]] == c) nxt[x] = x + 1, prv[x + 1] = x;
}
void merge(int u, int v, int w) {
	int x = fa[u], y = fa[v];
	if (x == y) return;
	e[++m] = {u, v, w};
	if (bel[x].size() < bel[y].size()) swap(x, y);
	for (auto z : bel[y]) update(id[z], x);
	for (auto z : bel[y]) bel[x].emplace_back(z), fa[z] = x;
	bel[y].clear();
}
struct Tree {
	int par[N], tot, val[N], dep[N], to[N][20];
	vector<int> g[N];
	int find(int x) { return x == par[x] ? x : par[x] = find(par[x]); }
	void dfs(int u) {
		if (u <= n) rev[id[u] = ++dfn] = u;
		for (auto v : g[u]) {
			dep[v] = dep[u] + 1, to[v][0] = u;
			for (int i = 1; i < 20; ++i) to[v][i] = to[to[v][i - 1]][i - 1];
			dfs(v);
		}
	}
	void build() {
		iota(par + 1, par + n + 1, 1), tot = n;
		for (int i = 1; i < 2 * n; ++i) g[i].clear();
		sort(e + 1, e + m + 1);
		for (int i = 1; i <= m; ++i) {
			int u = find(e[i].u), v = find(e[i].v), w = e[i].w;
			if (u == v) continue;
			int x = ++tot;
			par[x] = par[u] = par[v] = x;
			g[x].emplace_back(u), g[x].emplace_back(v);
			val[x] = w;
		}
		dep[tot] = 1, memset(to[tot], 0, sizeof to[tot]);
		dfn = 0, dfs(tot);
	}
	int get(int u, int v) {
		if (dep[u] < dep[v]) swap(u, v);
		for (int i = 19; ~i; --i)
			if (dep[to[u][i]] >= dep[v]) u = to[u][i];
		if (u == v) return val[u];
		for (int i = 19; ~i; --i)
			if (to[u][i] != to[v][i]) u = to[u][i], v = to[v][i];
		return val[to[u][0]];
	}
	void solve() {
		for (int i = 1; i <= n; ++i) nxt[i] = prv[i] = fa[i] = i, bel[i] = {i};
		for (m = 0; m < n - 1; ) {
			for (int i = 1; i <= n; ++i) choice[i] = {inf, inf, inf};
			for (int i = 1; i <= n; ++i) {
				int u = rev[i];
				for (auto v : banned[u]) mark[v] = true;
				for (int j = i + 1; j <= n; ++j) {
					int v = rev[j];
					if (mark[v]) continue;
					if (fa[u] != fa[v]) { choice[fa[u]] = min(choice[fa[u]], {get(u, v), u, v}); break; }
					j = get_nxt(j);
				}
				for (int j = i - 1; j; --j) {
					int v = rev[j];
					if (mark[v]) continue;
					if (fa[u] != fa[v]) { choice[fa[u]] = min(choice[fa[u]], {get(u, v), u, v}); break; }
					j = get_prv(j);
				}
				for (auto v : banned[u]) mark[v] = false;
			}
			for (int i = 1; i <= n; ++i)
				if (choice[i][0] != inf) merge(choice[i][1], choice[i][2], choice[i][0]);
		}
	}
} t1, t2;
void solve() {
	scanf("%d%d", &n, &m);
	int tmp_m = m;
	for (int i = 1; i <= m; ++i)
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w), x[i] = e[i].u, y[i] = e[i].v;
	t1.build();
	for (int i = 1; i <= n; ++i) banned[i].clear();
	for (int i = 1; i <= m; ++i) banned[x[i]].emplace_back(y[i]), banned[y[i]].emplace_back(x[i]);
	t1.solve(), t2.build();
	for (int i = 1; i <= tmp_m; ++i)
		printf("%d%c", t2.get(x[i], y[i]), " \n"[i == tmp_m]);
}
int main() {
	int t; scanf("%d", &t);
	while (t--) solve();	
	return 0;
}