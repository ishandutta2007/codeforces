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

int n, m, dg[N], fa[N], dep[N];
pii Q[N];
std::vector <int> E[N];
void Dfs(int u) {
	for(int v : E[u]) if(!dep[v]) {
		fa[v] = u;
		dep[v] = dep[u] + 1;
		Dfs(v);
	}
}
int GetLca(int u, int v) {
	while(u != v) {
		if(dep[u] < dep[v])	std::swap(u, v);
		u = fa[u];
	}
	return u;
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
			E[u].push_back(v);
			E[v].push_back(u);
		}
		int q; rd(q);
		for(int i = 1; i <= q; ++i) {
			int u, v; rd(u, v);
			Q[i] = mkp(u, v);
			dg[u] ^= 1; dg[v] ^= 1;
		}
		int cnt = 0;
		for(int i = 1; i <= n; ++i)
			cnt += dg[i];
		if(cnt > 0) {
			printf("NO\n%d\n", cnt / 2);
			return 0;
		} else {
			printf("YES\n");
			dep[1] = 1; Dfs(1);
			for(int i = 1; i <= q; ++i) {
				int u = Q[i].fi, v = Q[i].se;
				int lca = GetLca(u, v);
				printf("%d\n", dep[u] + dep[v] - dep[lca] * 2 + 1);
				std::vector <int> tmp_a, tmp_b;
				while(u != lca) tmp_a.push_back(u), u = fa[u];
				while(v != lca) tmp_b.push_back(v), v = fa[v];
				std::reverse(tmp_b.begin(), tmp_b.end());
				for(int j : tmp_a) printf("%d ", j);
				printf("%d ", lca);
				for(int j : tmp_b) printf("%d ", j);
				printf("\n");
			}
		}
	} return 0;
}