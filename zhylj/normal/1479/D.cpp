#include <bits/stdc++.h>

#define gc() getchar()
template <typename T> inline void rd(T& x) {
	int si = 1; char c = gc(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = gc();
	while(isdigit(c)) x = x * 10 + c - 48, c = gc();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 3e5 + 5;

int n, m, B, a[N];
std::vector <int> E[N];

int fa[N], b_idx[N], b_mx[N], dep[N], siz[N], hvy[N], dfn[N], b_cnt, dfv;
void Dfs1(int u, int p) {
	dfn[u] = ++dfv;
	fa[u] = p; dep[u] = dep[p] + 1;
	siz[u] = 1;
	for(int v : E[u]) if(v != p) {
		Dfs1(v, u);
		siz[u] += siz[v];
		if(siz[v] > siz[hvy[u]]) hvy[u] = v;
		b_mx[u] = std::max(b_mx[u], b_mx[v] + 1);
	}
	if(b_mx[u] >= B) {
		b_mx[u] = 0;
		b_idx[u] = ++b_cnt;
	}
}

int top[N];
void Dfs2(int u, int p, int t) {
	if(!b_idx[u]) b_idx[u] = b_idx[p];
	top[u] = t;
	if(hvy[u]) Dfs2(hvy[u], u, t);
	for(int v : E[u]) if(v != p && v != hvy[u])
		Dfs2(v, u, v);
}

int GetLca(int u, int v) {
	while(top[u] != top[v]) {
		if(dep[top[u]] < dep[top[v]]) std::swap(u, v);
		u = fa[top[u]];
	}
	return dep[u] < dep[v] ? u : v;
}

struct Ask {
	int u, v, l, r, i;
} Q[N];
int ans[N], buk[N], vis[N];
std::vector <int> st[N];
void Modify(int u) {
	if(vis[u]) {
		vis[u] = 0;
		--buk[a[u]];
		if(buk[a[u]] & 1)
			st[a[u] / B].push_back(a[u]);
	} else {
		vis[u] = 1;
		++buk[a[u]];
		if(buk[a[u]] & 1)
			st[a[u] / B].push_back(a[u]);
	}
}
void Mov(int u, int v) {
	int lca = GetLca(u, v);
	for(; u != lca; u = fa[u]) Modify(u);
	for(; v != lca; v = fa[v]) Modify(v);
}
int Query(int l, int r) {
	if(l / B != r / B) {
		for(int i = l / B + 1; i < r / B; ++i) {
			for(; !st[i].empty() && (~buk[st[i].back()] & 1); st[i].pop_back());
			if(!st[i].empty()) return st[i].back();
		}
		for(int i = l; i / B == l / B; ++i)
			if(buk[i] & 1) return i;
		for(int i = r; i / B == r / B; --i)
			if(buk[i] & 1) return i;
	} else {
		for(int i = l; i <= r; ++i)
			if(buk[i] & 1) return i;
	}
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m); B = ceil(sqrt(n)) + 0.5;
		for(int i = 1; i <= n; ++i) rd(a[i]);
		for(int i = 1; i < n; ++i) {
			int u, v; rd(u, v);
			E[u].push_back(v);
			E[v].push_back(u);
		}
		Dfs1(1, 0);
		Dfs2(1, 0, 1);
		for(int i = 1; i <= m; ++i) {
			int u, v, l, r; rd(u, v, l, r);
			if(dfn[u] > dfn[v]) std::swap(u, v);
			Q[i] = (Ask) { u, v, l, r, i };
		}
		std::sort(Q + 1, Q + m + 1, [&](const Ask &x, const Ask &y) {
			return b_idx[x.u] != b_idx[y.u] ? b_idx[x.u] < b_idx[y.u] :
				((b_idx[x.u] & 1) ? dfn[x.v] > dfn[y.v] : dfn[x.v] < dfn[y.v]);
		});
		for(int i = 1, u = 1, v = 1; i <= m; ++i) {
			Mov(u, Q[i].u); Mov(v, Q[i].v);
			u = Q[i].u; v = Q[i].v;
			int lca = GetLca(u, v);
			Modify(lca);
			ans[Q[i].i] = Query(Q[i].l, Q[i].r);
			Modify(lca);
		}
		for(int i = 1; i <= m; ++i)
			printf("%d\n", ans[i]);
	} return 0;
}