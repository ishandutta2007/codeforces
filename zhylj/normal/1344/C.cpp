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

int n, m, dg[kN], f[kN], g[kN]; char ans[kN];
std::vector <int> E[kN], rE[kN];
void Add(int u, int v) {
	E[u].push_back(v);
	rE[v].push_back(u);
	++dg[v];
}
std::vector <int> t;
bool vis[kN];
void TopSort(int u) {
	t.push_back(u); vis[u] = true;
	for(auto v : E[u]) if(!vis[v]) {
		--dg[v];
		if(!dg[v]) {
			TopSort(v);
		}
	}
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		memset(f, 0x3f, sizeof(f));
		memset(g, 0x3f, sizeof(g));
		rd(n, m);
		for(int i = 1; i <= m; ++i) {
			int u, v; rd(u, v);
			Add(u, v);
		}
		for(int i = 1; i <= n; ++i) if(!dg[i])
			Add(0, i);
		TopSort(0);
		if(t.size() <= n) {
			printf("-1\n");
			return 0;
		}
		for(auto u : t) {
			g[u] = u;
			if(u == 0) g[u] = kInf;
			for(auto v : rE[u]) {
				g[u] = std::min(g[v], g[u]);
			}
		}
		std::reverse(t.begin(), t.end());
		int cnt = 0;
		for(auto u : t) {
			f[u] = u;
			for(auto v : E[u]) {
				f[u] = std::min(f[u], f[v]);
			}
			if(g[u] == f[u] && g[u] == u) ans[u] = 'A', ++cnt;
			else ans[u] = 'E';
		}
		printf("%d\n", cnt);
		printf("%s\n", ans + 1);
	} return 0;
}