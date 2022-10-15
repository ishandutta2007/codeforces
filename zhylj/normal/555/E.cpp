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
const int N = 2e5 + 5, Inf = 0x3f3f3f3f;
const ll Mod = 998244353, InfLL = 0x3f3f3f3f3f3f3f3fLL;

int dsu[N];
int Find(int u) { return u == dsu[u] ? u : dsu[u] = Find(dsu[u]); }
void Merge(int u, int v) { dsu[Find(u)] = Find(v); }

int n, m, q;
std::vector <pii> E[N];
void Add(int u, int v, int idx) {
	E[u].push_back(mkp(v, idx));
	E[v].push_back(mkp(u, idx));
}

int dfv, top, col_cnt, dfn[N], low[N], st[N], bcc[N];
bool vis[N], brdg[N];
void Tarjan(int u, int p_idx) {
	dfn[u] = low[u] = ++dfv;
	st[++top] = u; vis[u] = true;
	for(auto i : E[u]) {
		int v = i.fi, idx = i.se;
		if(idx != p_idx) {
			if(!dfn[v]) {
				Tarjan(v, idx);
				low[u] = std::min(low[u], low[v]);
			} else if(vis[v])
				low[u] = std::min(low[u], dfn[v]);
			if(low[v] > dfn[u])
				brdg[idx] = true;
		}
	}
	if(dfn[u] == low[u]) {
		while(st[top] != u)
			vis[st[top--]] = false;
		vis[st[top--]] = false;
	}
}
void Color(int u, int p, int col) {
	bcc[u] = col;
	for(auto i : E[u]) {
		int v = i.fi, idx = i.se;
		if(!bcc[v] && !brdg[idx]) {
			Color(v, u, col);
		}
	}
}

std::vector <int> E2[N];
void Add2(int u, int v) {
	E2[u].push_back(v);
}
int fa[N][20], d[N];
void Dfs(int u) {
	d[u] = d[fa[u][0]] + 1;
	for(auto v : E2[u]) if(v != fa[u][0]) {
		fa[v][0] = u; Dfs(v);
	}
}
void Build() {
	for(int i = 1; i <= n; ++i)
		if(!dfn[i]) Tarjan(i, 0);
	for(int i = 1; i <= n; ++i)
		if(!bcc[i]) Color(i, 0, ++col_cnt);
	for(int u = 1; u <= n; ++u)
		for(auto i : E[u]) if(bcc[u] != bcc[i.fi]) {
			Add2(bcc[u], bcc[i.fi]);
		}
	for(int i = 1; i <= col_cnt; ++i)
		if(!fa[i][0]) Dfs(i);
	for(int i = 1; i < 20; ++i)
		for(int j = 1; j <= col_cnt; ++j)
			fa[j][i] = fa[fa[j][i - 1]][i - 1];
}
int GetLca(int u, int v) {
	if(d[u] < d[v]) std::swap(u, v);
	int dlt = d[u] - d[v];
	for(int i = 0; i < 20; ++i)
		if((dlt >> i) & 1)
			u = fa[u][i];
	if(u == v) return v;
	for(int i = 19; ~i; --i)
		if(fa[u][i] != fa[v][i])
			u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}
int d_up[N], d_dn[N];
void Check(int u) {
	for(auto v : E2[u]) if(v != fa[u][0]) {
		Check(v);
		d_up[u] += d_up[v];
		d_dn[u] += d_dn[v];
	}
	if(d_up[u] != 0 && d_dn[u] != 0) {
		printf("No\n");
		exit(0);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m, q);
		for(int i = 1; i <= n; ++i) dsu[i] = i;
		for(int i = 1; i <= m; ++i) {
			int u, v; rd(u, v);
			Add(u, v, i);
			Merge(u, v);
		}
		Build();
		for(int i = 1; i <= q; ++i) {
			int u, v; rd(u, v);
			if(Find(u) != Find(v)) {
				printf("No\n");
				exit(0);
			}
			u = bcc[u]; v = bcc[v];
			int lca = GetLca(u, v);
			++d_up[u]; ++d_dn[v];
			--d_up[lca]; --d_dn[lca];
		}
		for(int i = 1; i <= col_cnt; ++i)
			if(!fa[i][0]) Check(i);
		printf("Yes\n");
	} return 0;
}