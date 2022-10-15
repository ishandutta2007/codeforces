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

bool flag; int dg[N], f[N], vis[N], dfv, ans;
std::vector <int> E[N];

void Dfs(int u) {
	vis[u] = true;
	f[u] = std::max(f[u], 1);
	ans = std::max(ans, f[u]);
	for(int v : E[u]) {
		f[v] = std::max(f[v], f[u] + (u > v));
		--dg[v];
		if(!dg[v]) Dfs(v);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		dfv = 0;
		int n; rd(n); flag = true;
		for(int i = 1; i <= n; ++i) {
			E[i].clear(); vis[i] = false; dg[i] = 0;
			f[i] = 0;
		}
		for(int i = 1; i <= n; ++i) {
			int k; rd(k);
			dg[i] = k;
			while(k--) {
				int v; rd(v);
				E[v].push_back(i);
			}
		}
		ans = 0;
		for(int i = 1; i <= n; ++i) {
			if(!dg[i] && !vis[i]) {
				Dfs(i);
			}
		}
		for(int i = 1; i <= n; ++i)
			if(!vis[i]) flag = false;
		if(!flag) printf("-1\n");
		else printf("%d\n", ans);
	} return 0;
}