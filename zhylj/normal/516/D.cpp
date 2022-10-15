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
const int N = 2e5 + 5;

int fa[N], tot_w[N];
int Find(int x) { return fa[x] == x ? x : fa[x] = Find(fa[x]); }
void Merge(int x, int y) {
	x = Find(x); y = Find(y);
	if(x != y) {
		fa[x] = y;
		tot_w[y] += tot_w[x];
	}
}

int n; ll _d[N], f[N];
std::vector <pii> E[N];
void Add(int u, int v, int w) {
	E[u].push_back(mkp(v, w));
	E[v].push_back(mkp(u, w));
}
void Dfs(int u, int p, ll cur_d) {
	_d[u] = cur_d;
	for(pii e : E[u]) {
		int v = e.fi, w = e.se;
		if(v != p) Dfs(v, u, cur_d + w);
	}
}

int idx[N];
int Query(ll k) {
	for(int i = 1; i <= n; ++i) {
		fa[i] = i; fa[n + i] = n + i;
		tot_w[i] = 1; tot_w[n + i] = -1;
	}
	int ret = 0;
	for(int i = 1, j = 1; i <= n; ++i) {
		int u = idx[i];
		for(pii e : E[u]) {
			int v = e.fi;
			if(f[v] > f[u] || (f[u] == f[v] && v < u)) {
				Merge(u, v);
			}
		}
		for(; j <= n && f[idx[j]] > f[u] + k; ++j)
			Merge(idx[j], n + idx[j]);
		ret = std::max(ret, tot_w[Find(u)]);
	}
	return ret;
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
			int u, v, w; rd(u, v, w);
			Add(u, v, w);
		}
		Dfs(1, 0, 0);
		int mx_p = 1;
		for(int i = 1; i <= n; ++i)
			if(_d[mx_p] < _d[i]) mx_p = i;
		Dfs(mx_p, 0, 0);
		for(int i = 1; i <= n; ++i) f[i] = std::max(f[i], _d[i]);
		mx_p = 1;
		for(int i = 1; i <= n; ++i)
			if(_d[mx_p] < _d[i]) mx_p = i;
		Dfs(mx_p, 0, 0);
		for(int i = 1; i <= n; ++i) f[i] = std::max(f[i], _d[i]);
		for(int i = 1; i <= n; ++i) idx[i] = i;
		std::stable_sort(idx + 1, idx + n + 1,
			[&](const int &x, const int &y) { return f[x] > f[y]; }
		);
		int q; rd(q);
		while(q--) {
			ll k; rd(k);
			printf("%d\n", Query(k));
		}
	} return 0;
}