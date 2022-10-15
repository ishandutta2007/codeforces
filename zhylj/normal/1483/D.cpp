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
const int N = 6e2 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, m, q;
ll g[N][N], d[N][N], t[N][N], M[N];
bool vis[N][N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		memset(g, 0x3f, sizeof(g));
		memset(d, 0x3f, sizeof(d));
		memset(t, ~0x3f, sizeof(t));
		rd(n, m);
		int cnt = 0;
		for(int i = 1; i <= n; ++i) d[i][i] = 0;
		for(int i = 1; i <= m; ++i) {
			int u, v, w; rd(u, v, w);
			g[u][v] = g[v][u] = d[u][v] = d[v][u] = w;
		}
		rd(q);
		for(int i = 1; i <= q; ++i) {
			int u, v, w; rd(u, v, w);
			t[u][v] = t[v][u] = w;
		}
		for(int k = 1; k <= n; ++k)
			for(int i = 1; i <= n; ++i)
				for(int j = 1; j <= n; ++j)
					d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
		for(int u = 1; u <= n; ++u) {
			memset(M, 0x3f, sizeof(M));
			for(int v = 1; v <= n; ++v) {
				for(int b = 1; b <= n; ++b)
					M[b] = std::min(M[b], d[v][b] - t[u][v]);
			}
			for(int a = 1; a <= n; ++a)
				for(int b = 1; b <= n; ++b) {
					if(g[a][b] >= InfLL || d[u][a] >= InfLL || M[b] >= InfLL) continue;
					if(g[a][b] + d[u][a] + M[b] <= 0)
						vis[a][b] = vis[b][a] = true;
				}
		}
		for(int a = 1; a <= n; ++a)
			for(int b = a + 1; b <= n; ++b) 
				if(vis[a][b]) ++cnt;
		printf("%d\n", cnt);
	} return 0;
}