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
const int N = 2e3 + 5, MOD = 1e9 + 7;

int d, n, a[N], f[N][2];
std::vector <int> E[N];
void Add(int u, int v) {
	E[u].push_back(v);
	E[v].push_back(u);
}
bool vis[N];
void Dfs(int u, int mx) {
	vis[u] = true;
	if(a[u] == mx) f[u][1] = 1;
	else f[u][0] = 1;
	for(int v : E[u])
		if(!vis[v]) {
			Dfs(v, mx);
			f[u][1] = (1LL * f[u][0] * f[v][1] + 1LL * f[u][1] * (f[v][0] + f[v][1] + 1)) % MOD;
			f[u][0] = 1LL * f[u][0] * (f[v][0] + 1) % MOD;
		}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(d, n);
		int a_mx = 0;
		for(int i = 1; i <= n; ++i) {
			rd(a[i]);
			a_mx = std::max(a_mx, a[i]);
		}
		for(int i = 1; i < n; ++i) {
			int u, v; rd(u, v);
			Add(u, v);
		}
		int ans = 0;
		for(int i = 1; i <= a_mx; ++i) {
			memset(f, 0, sizeof(f));
			memset(vis, false, sizeof(vis));
			for(int j = 1; j <= n; ++j)
				if(a[j] < i - d || a[j] > i) vis[j] = true;
			for(int j = 1; j <= n; ++j)
				if(!vis[j]) Dfs(j, i);
			for(int j = 1; j <= n; ++j)
				ans = (ans + f[j][1]) % MOD;
		}
		printf("%d\n", ans);
	} return 0;
}