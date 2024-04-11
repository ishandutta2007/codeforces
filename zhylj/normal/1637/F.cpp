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
const int N = 5e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int n, h[N], dg[N];
std::vector <int> E[N];

int g[N];
ll s_sub[N], sub[N];
void Dfs(int u, int p) {
	for(int v : E[u]) if(v != p) {
		Dfs(v, u);
		s_sub[u] += sub[v];
		g[u] = std::max(g[u], g[v]);
	}
	sub[u] = s_sub[u];
	if(h[u] > g[u]) {
		sub[u] += h[u] - g[u];
		g[u] = h[u];
	}
}
ll mn_c[N];
void Dfs2(int u, int p) {
	if(dg[u] == 1) mn_c[u] = 0;
	for(int v : E[u]) if(v != p) {
		Dfs2(v, u);
		mn_c[u] = std::min(mn_c[u], mn_c[v] + s_sub[u] - sub[v]);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		memset(mn_c, 0x3f, sizeof(mn_c));
		rd(n);
		int p = 0;
		for(int i = 1; i <= n; ++i) {
			rd(h[i]);
			if(!p || h[i] > h[p]) p = i;
		}
		for(int i = 1; i < n; ++i) {
			int u, v; rd(u, v);
			E[u].push_back(v);
			E[v].push_back(u);
			++dg[u]; ++dg[v];
		}
		Dfs(p, 0);
		Dfs2(p, 0);
		ll mn = INF, s_mn = INF;
		for(int v : E[p]) {
			if(mn_c[v] - sub[v] <= mn) {
				s_mn = mn;
				mn = mn_c[v] - sub[v];
			} else s_mn = std::min(mn_c[v] - sub[v], s_mn);
		}
		if(dg[p] != 1) {
			printf("%lld\n", s_sub[p] + mn + s_mn + h[p] * 2);
		} else printf("%lld\n", s_sub[p] + mn + h[p] * 2);
	} return 0;
}