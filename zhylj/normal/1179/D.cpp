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
const int N = 5e5 + 5, INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3fLL;

int n;
std::vector <int> E[N], e_siz[N];

int siz[N]; bool vis[N];
void GetEsiz(int u, int p) {
	siz[u] = 1;
	for(int v : E[u]) if(v != p) {
		GetEsiz(v, u);
		siz[u] += siz[v];
	}
	for(int v : E[u])
		e_siz[u].push_back(v == p ? n - siz[u] : siz[v]);
}
void GetRoot(int u, int p, int tot, int &rt, int &rt_mx) {
	int mx = 0; siz[u] = 1;
	for(int v : E[u]) if(v != p && !vis[v]) {
		GetRoot(v, u, tot, rt, rt_mx);
		siz[u] += siz[v];
		mx = std::max(mx, siz[v]);
	}
	mx = std::max(mx, tot - siz[u]);
	if(mx < rt_mx) {
		rt_mx = mx;
		rt = u;
	}
}
void GetSiz(int u, int p) {
	siz[u] = 1;
	for(int v : E[u]) if(v != p && !vis[v]) {
		GetSiz(v, u);
		siz[u] += siz[v];
	}
}
ll dep[N];
ll Sq(int x) { return 1LL * x * x; }
void Dfs(int u, int p, int c_siz, int fa_siz, std::vector <ll> &a) {
	dep[u] = dep[p] - Sq(fa_siz) + Sq(c_siz) + Sq(fa_siz - c_siz);
	if(E[u].size() <= 1) a.push_back(dep[u]);
	for(int i = 0; i < E[u].size(); ++i) {
		int v = E[u][i], s = e_siz[u][i];
		if(v != p && !vis[v]) {
			Dfs(v, u, s, c_siz, a);
		}
	}
}
struct Line {
	ll k, b;
	Line() { k = 0; b = INFLL; }
	Line(ll _k, ll _b) { k = _k; b = _b; }
	ll operator [](ll x) { return k * x + b; }
};
struct Seg {
	std::vector <Line> seg;
	void Init(int s) { seg.resize(s << 2 | 1, (Line) { 0, INFLL }); }
	void Insert(int o, int l, int r, Line L) {
		int mid = (l + r) >> 1;
		if(L[mid] < seg[o][mid]) std::swap(seg[o], L);
		if(l == r) return;
		if(L[r] < seg[o][r]) Insert(o << 1, l, mid, L);
		else if(L[l] < seg[o][l]) Insert(o << 1 | 1, mid + 1, r, L);
	}
	ll Query(int o, int l, int r, int x) {
		if(l == r) return seg[o][x];
		int mid = (l + r) >> 1;
		if(x <= mid) return std::min(seg[o][x], Query(o << 1, l, mid, x));
		else return std::min(seg[o][x], Query(o << 1 | 1, mid + 1, r, x));
	}
};
ll Div(int u) {
	int rt = 0, rt_mx = INF, tot;
	GetSiz(u, 0); tot = siz[u];
	GetRoot(u, 0, tot, rt, rt_mx);
	u = rt; vis[u] = true;
	GetSiz(u, 0); siz[u] = n;
	dep[u] = 1LL * n * n;
	ll res = dep[u];
	Seg T;
	T.Init(tot);
	for(int i = 0; i < E[u].size(); ++i) {
		int v = E[u][i], s = e_siz[u][i];
		if(!vis[v]) {
			std::vector <ll> a;
			Dfs(v, u, s, n, a);
			for(ll t : a) {
				res = std::min(res, T.Query(1, 1, tot, s) + t - 1LL * n * n);
				res = std::min(res, t);
			}
			for(ll t : a)
				T.Insert(1, 1, tot, (Line) { 2 * s, t });
		}
	}
	for(int v : E[u]) if(!vis[v])
		res = std::min(Div(v), res);
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i < n; ++i) {
			int u, v; rd(u, v);
			E[u].push_back(v);
			E[v].push_back(u);
		}
		GetEsiz(1, 0);
		ll ans = Div(1);
		ans = 1LL * n * (n - 1) / 2 + (1LL * n * n - ans) / 2;
		printf("%lld\n", ans);
	} return 0;
}