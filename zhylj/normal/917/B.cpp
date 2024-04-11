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
const int kN = 100 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, m, g[kN][kN], f[30][kN][kN], dg[kN], dfv = 0, dfn[kN];
bool vis[kN]; pii seq[kN * kN];

void TopSort(int cur) {
	vis[cur] = true;
	dfn[cur] = ++dfv;
	for(int i = 1; i <= n; ++i)
		if(!vis[i] && g[cur][i]) {
			--dg[i];
			if(!dg[i]) TopSort(i);
		}
}
void Dp(int cur_c) {
	for(int i = 1; i <= n * n; ++i) {
		int u = seq[i].fi, v = seq[i].se;
	//	printf("(u, v) = %d %d\n", u, v);
		f[cur_c][u][v] = f[cur_c + 1][u][v];
		for(int w = 1; w <= n; ++w)
			if(g[u][w] >= cur_c) {
			//	if(g[u][w] == cur_c) printf("%d %d\n", u, w);
				f[cur_c][u][v] = std::max(f[cur_c][u][v], f[cur_c][v][w] ^ 1);
			}
	}
}

bool Cmp(const pii &x, const pii &y) {
	int mn_x = std::min(dfn[x.fi], dfn[x.se]), mn_y = std::min(dfn[y.fi], dfn[y.se]),
		mx_x = std::max(dfn[x.fi], dfn[x.se]), mx_y = std::max(dfn[y.fi], dfn[y.se]);
	return mn_x != mn_y ? mn_x > mn_y : mx_x > mx_y;
}

int main() {
	int T = 1; //rd(T);
	while(T--) {
		rd(n, m);
		for(int i = 1; i <= m; ++i) {
			int u, v; char c;
			rd(u, v); scanf("%c", &c);
			g[u][v] = c - 'a' + 1;
			++dg[v];
		}
		for(int i = 1; i <= n; ++i)
			if(!vis[i] && !dg[i]) TopSort(i);
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				seq[(i - 1) * n + j] = mkp(i, j);
		sort(seq + 1, seq + n * n + 1, Cmp);
	/*	for(int i = 1; i <= n; ++i) printf("%d ", dfn[i]);
		printf("\n");
		for(int i = 1; i <= n * n; ++i) {
			printf("seq = %d %d, mn = %d, mx = %d\n", seq[i].fi, seq[i].se, std::min(dfn[seq[i].fi], dfn[seq[i].se]), std::max(dfn[seq[i].fi], dfn[seq[i].se]));
		}*/
		for(int i = 26; i; --i) {
			Dp(i);
	/*		for(int u = 1; u <= n; ++u) {
				for(int v = 1; v <= n; ++v)
					printf(f[i][u][v] ? "A" : "B");
				printf("\n");
			}
			printf("\n");*/
		}
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				printf(f[1][i][j] ? "A" : "B");
			}
			printf("\n");
		}
	} return 0;
}