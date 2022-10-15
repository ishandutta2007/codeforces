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
const int N = 1000 + 5, MOD = 998244353;

void Plus(ll &x, ll y) {
	x += y;
	if(x >= MOD * 2)
		x = (x - MOD) % MOD + MOD;
}
void Mul(ll &x, ll y) {
	x *= y;
	if(x >= MOD * 2)
		x = (x - MOD) % MOD + MOD;
}

ll f[N][N], a[N];

int n, m, t, dg[N]; bool vis[N];
std::vector <int> E[N];
void Add(int u, int v) {
	E[u].push_back(v);
	++dg[v];
}
void Dfs(int u) {
	vis[u] = true;
	f[u][0] = a[u];
	for(int v : E[u]) {
		for(int i = 0; i < n; ++i)
			Plus(f[v][i + 1], f[u][i]);
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
		for(int i = 1; i <= n; ++i) {
			E[i].clear();
			dg[i] = vis[i] = a[i] = 0;
			memset(f[i], 0, sizeof(f[i]));
		}
		rd(n, m);
		for(int i = 1; i <= n; ++i) rd(a[i]);
		for(int i = 1; i <= m; ++i) {
			int u, v; rd(u, v);
			Add(u, v);
		}
		for(int i = 1; i <= n; ++i)
			if(E[i].empty()) t = i;
		for(int i = 1; i <= n; ++i)
			if(!dg[i] && !vis[i]) { Dfs(i); }
		ll cur = 0;
		for(int i = 0; i <= n; ++i) {
			if(!f[t][i]) continue;
			if(cur < i) cur = i + f[t][i];
			else cur += f[t][i];
		}
		cur %= MOD;
		printf("%lld\n", cur);
	} return 0;
}