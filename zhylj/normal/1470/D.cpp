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
const int kN = 5e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, m, col[kN]; bool vis[kN];
std::vector <int> E[kN];
void Add(int u, int v) {
	E[u].push_back(v);
	E[v].push_back(u);
}
void Dfs(int u) {
	bool flag = false;
	vis[u] = true;
	for(auto v : E[u]) if(col[v]) flag = true;
	if(!flag) {
		col[u] ^= 1;
	}
	for(auto v : E[u]) if(!vis[v]) Dfs(v);
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		rd(n, m);
		for(int i = 1; i <= n; ++i) E[i].clear(), col[i] = vis[i] = 0;
		for(int i = 1; i <= m; ++i) {
			int u, v; rd(u, v);
			Add(u, v); Add(v, u);
		}
		Dfs(1);
		bool flag = true;
		for(int i = 1; i <= n; ++i) {
			if(!vis[i]) flag = false;
		}
		if(!flag) printf("NO\n");
		else {
			printf("YES\n");
			int cnt = 0;
			for(int i = 1; i <= n; ++i) if(col[i]) ++cnt;
			printf("%d\n", cnt);
			for(int i = 1; i <= n; ++i) if(col[i]) printf("%d ", i);
			printf("\n");
		}
	} return 0;
}