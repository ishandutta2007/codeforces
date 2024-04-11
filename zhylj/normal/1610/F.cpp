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
const int N = 3e6 + 5;

int n, m, U[N], V[N], W[N], dg[N], cur_ed[N], ans[N], st[N];
std::vector <pii> E[N];
void Add(int u, int v, int idx) {
	dg[u] ^= 1; dg[v] ^= 1;
	E[u].push_back(mkp(v, idx));
	E[v].push_back(mkp(u, idx));
}
void Dfs(int u) {
	for(int &i = cur_ed[u]; i < E[u].size(); ++i) {
		int v = E[u][i].fi, idx = E[u][i].se;
		if(!ans[idx]) {
			ans[idx] = (u < v == st[idx] ? 1 : 2);
			Dfs(v);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m);
		int cnt = 0, t = (n << 1 | 1);
		for(int i = 1; i <= m; ++i) {
			int u, v, w; rd(u, v, w);
			st[i] = u < v;
			if(w == 1) Add(u, v, i);
			else Add(u + n, v + n, i);
		}
		for(int i = 1; i <= n; ++i)
			if(dg[i]) ++cnt;
		for(int i = 1; i <= n; ++i) {
			if(dg[i] && dg[i + n]) {
				Add(i, i + n, m + i);
			} else if(dg[i]) Add(t, i, m + i);
			else if(dg[i + n]) Add(t, i + n, m + i);
		}
		for(int i = 1; i <= (n << 1 | 1); ++i) 
			Dfs(i);
		printf("%d\n", cnt);
		for(int i = 1; i <= m; ++i)
			printf("%d", ans[i]);
		printf("\n");
	} return 0;
}