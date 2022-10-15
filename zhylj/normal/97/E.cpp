#include <bits/stdc++.h>

template <typename T> inline void rd(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 5e5 + 5, B = 20, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, m, q;
std::vector <int> E[N], T[N];
void Add(int u, int v, std::vector <int> G[]) {
	G[u].push_back(v); G[v].push_back(u);
}

int dfn[N], low[N], st_v[N], bcc, top_v, top_e, dfv;
pii st_e[N];
std::vector <int> bcc_v[N];
std::vector <pii> bcc_e[N];
void Tarjan(int u, int p) {
	dfn[u] = low[u] = ++dfv;
	st_v[++top_v] = u;
	for(int v : E[u]) {
		if(!dfn[v]) {
			st_e[++top_e] = mkp(u, v);
			Tarjan(v, u);
			low[u] = std::min(low[u], low[v]);
			if(low[v] == dfn[u]) {
				++bcc;
				for(int x = 0; x != v; --top_v) {
					x = st_v[top_v];
					bcc_v[bcc].push_back(x);
					Add(n + bcc, x, T);
				}
				bcc_v[bcc].push_back(u);
				Add(n + bcc, u, T);
				for(pii x = mkp(0, 0); x != mkp(u, v); --top_e) {
					x = st_e[top_e];
					bcc_e[bcc].push_back(x);
				}
			}
		} else {
			if(dfn[u] > dfn[v]) st_e[++top_e] = mkp(u, v);
			low[u] = std::min(low[u], dfn[v]);
		}
	}
}

int fa[N][B], dsu_fa[N], dep[N], d[N], d_xor[N];
int Find(int u) { return u == dsu_fa[u] ? u : dsu_fa[u] = Find(dsu_fa[u]); }
void Merge(int u, int v) { dsu_fa[Find(u)] = Find(v); }
void Dfs(int u, int p) {
	dep[u] = dep[p] + 1;
	if(u > n) {
		dsu_fa[p] = p; dsu_fa[p + n] = p + n;
		for(pii i : bcc_e[u - n]) {
			Merge(i.fi, i.se + n);
			Merge(i.fi + n, i.se);
		}
		for(int i : bcc_v[u - n])
			if(Find(i) == Find(i + n)) {
				d[u] = 1;
				break;
			}
		if(!d[u]) {
			for(int i : bcc_v[u - n])
				d_xor[i] = d_xor[p] ^ (Find(i) != Find(p));
		}
	}
	for(int v : T[u]) if(v != p) Dfs(v, u);
}
void Dfs2(int u, int p) {
	fa[u][0] = p;
	dep[u] = dep[p] + 1;
	d[u] += d[p];
	for(int v : T[u]) if(v != p) Dfs2(v, u);
}
void Init() {
	for(int i = 1; i <= n << 1; ++i) dsu_fa[i] = i;
	for(int i = 1; i <= n; ++i)
		if(!dfn[i]) {
			Tarjan(i, 0);
			Dfs(i, 0);
			Dfs2(i, 0);
		}
	for(int i = 1; i < B; ++i)
		for(int j = 1; j <= n; ++j)
			fa[j][i] = fa[fa[j][i - 1]][i - 1];
}
int GetLca(int u, int v) {
	if(dep[u] < dep[v]) std::swap(u, v);
	int dlt = dep[u] - dep[v];
	for(int i = 0; i < B; ++i)
		if((dlt >> i) & 1) {
			u = fa[u][i];
		}
	if(u == v) return u;
	for(int i = B - 1; ~i; --i)
		if(fa[u][i] != fa[v][i])
			u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}
bool Query(int u, int v) {
	int lca = GetLca(u, v);
	if(!lca) return false;
	if(d[u] + d[v] - d[lca] - d[fa[lca][0]])
		return true;
	return d_xor[u] ^ d_xor[v];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m);
		for(int i = 1; i <= m; ++i) {
			int u, v; rd(u, v);
			Add(u, v, E);
		}
		Init();
		rd(q);
		while(q--) {
			int u, v; rd(u, v);
			printf(Query(u, v) ? "Yes\n" : "No\n");
		}
	} return 0;
}