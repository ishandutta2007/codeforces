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
const int N = 5e5 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, m, q, bcc_cnt, w[N];
std::multiset <int> S[N];
std::vector <int> T[N];
void TreeAdd(int u, int v) {
	T[u].push_back(v);
	T[v].push_back(u);
}

namespace BuildTree {

std::vector <int> E[N];
void Add(int u, int v) {
	E[u].push_back(v);
	E[v].push_back(u);
}

int dfv, top, dfn[N], low[N], st[N];
bool vis[N];
void Tarjan(int u) {
	dfn[u] = low[u] = ++dfv;
	st[++top] = u;
	int c_siz = 0;
	for(auto v : E[u]) {
		if(!dfn[v]) {
			++c_siz;
			Tarjan(v);
			low[u] = std::min(low[u], low[v]);
			if(dfn[u] == low[v]) {
				++bcc_cnt;
				while(st[top] != v) {
					TreeAdd(n + bcc_cnt, st[top]);
					--top;
				}
				--top;
				TreeAdd(n + bcc_cnt, v);
				TreeAdd(n + bcc_cnt, u);
			}
		} else low[u] = std::min(low[u], dfn[v]);
	}
}

};

struct Sgt {
	int seg[N << 3];
	void Update(int o) { seg[o] = std::min(seg[o << 1], seg[o << 1 | 1]); }
	int Query(int o, int l, int r, int ql, int qr) {
		if(ql <= l && r <= qr) return seg[o];
		int mid = (l + r) >> 1, ret = Inf;
		if(ql <= mid) ret = std::min(ret, Query(o << 1, l, mid, ql, qr));
		if(qr > mid) ret = std::min(ret, Query(o << 1 | 1, mid + 1, r, ql, qr));
		return ret;
	}
	void Modify(int o, int l, int r, int p, int v) {
		if(l == r) seg[o] = v;
		else {
			int mid = (l + r) >> 1;
			if(p <= mid) Modify(o << 1, l, mid, p, v);
			else Modify(o << 1 | 1, mid + 1, r, p, v);
			Update(o);
		}
	}
} M;

int dfv, d[N], dfn[N], top[N], hvy[N], siz[N], fa[N];
void GetHvy(int u) {
	siz[u] = 1; d[u] = d[fa[u]] + 1;
	for(auto v : T[u]) if(v != fa[u]) {
		if(u > n) S[u].insert(w[v]);
		fa[v] = u; GetHvy(v);
		siz[u] += siz[v];
		if(siz[v] > siz[hvy[u]]) {
			hvy[u] = v;
		}
	}
}
void GetTop(int u, int t) {
	dfn[u] = ++dfv;
	if(u > n) M.Modify(1, 1, n + bcc_cnt, dfn[u], *S[u].begin());
	else M.Modify(1, 1, n + bcc_cnt, dfn[u], w[u]);
	top[u] = t;
	if(hvy[u]) GetTop(hvy[u], t);
	for(auto v : T[u]) if(v != fa[u] && v != hvy[u])
		GetTop(v, v);
}
void Modify(int x, int v) {
	M.Modify(1, 1, n + bcc_cnt, dfn[x], v);
	if(fa[x]) {
		int f = fa[x];
		S[f].erase(S[f].find(w[x]));
		S[f].insert(v);
		M.Modify(1, 1, n + bcc_cnt, dfn[f], *S[f].begin());
	}
	w[x] = v;
}
int Query(int u, int v) {
	int ret = Inf;
	while(top[u] != top[v]) {
		if(d[top[u]] < d[top[v]]) std::swap(u, v);
		ret = std::min(ret, M.Query(1, 1, n + bcc_cnt, dfn[top[u]], dfn[u]));
		u = fa[top[u]];
	}
	if(d[u] < d[v]) std::swap(u, v);
	ret = std::min(ret, M.Query(1, 1, n + bcc_cnt, dfn[v], dfn[u]));
	if(v > n) ret = std::min(ret, w[fa[v]]);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m, q);
		for(int i = 1; i <= n; ++i) rd(w[i]);
		for(int i = 1; i <= m; ++i) {
			int u, v; rd(u, v);
			BuildTree::Add(u, v);
		}
		BuildTree::Tarjan(1);
		GetHvy(1); GetTop(1, 1);
		while(q--) {
			char s[3]; int x, y;
			scanf("%s", s + 1);
			rd(x, y);
			if(s[1] == 'A') {
				printf("%d\n", Query(x, y));
			} else {
				Modify(x, y);
			}
		}
	} return 0;
}