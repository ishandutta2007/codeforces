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
const int N = 2e5 + 5, K = 60, MOD = 1e9 + 7;

void Update(int &x, int y) {
	x += y;
	x -= x >= MOD ? MOD : 0;
	x += x < 0 ? MOD : 0;
}

struct Edge {
	int x, y, w;
} e[K];
int n, k, c_x, c_y, d_x[K], d_y[K], fac[N];
std::vector <pii> E[K << 1], ch[K << 1];

int g[2][K << 1][K], siz[K << 1], h[K], m; Edge t_e[K];
bool vis[K << 1], usd[K << 1], e_vis[K][K];
void Dfs(int u, int p) {
	vis[u] = true;
	for(pii i : E[u]) {
		int v = i.fi, w = i.se;
		if(!vis[v]) {
			ch[u].push_back(i);
			Dfs(v, u);
		} else if(v != p) {
			int cur_x = std::max(u, v) - K, cur_y = std::min(u, v);
			if(e_vis[cur_x][cur_y]) continue;
			e_vis[cur_x][cur_y] = true;
			t_e[++m] = (Edge) { cur_x, cur_y, w };
		}
	}
}
int tmp[2][K];
void Dfs2(int u, int p) {
	memset(g[0][u], 0, sizeof(g[0][u]));
	memset(g[1][u], 0, sizeof(g[1][u]));
	siz[u] = 1;
	g[0][u][0] = 1;
	for(pii i : ch[u]) {
		int v = i.fi, w = i.se;
		Dfs2(v, u);
		memset(tmp, 0, sizeof(tmp));
		for(int j = 0; j <= siz[u] / 2; ++j)
			for(int p = 0; p <= siz[v] / 2; ++p) {
				Update(tmp[0][j + p], 1LL * g[0][u][j] * (g[0][v][p] + g[1][v][p]) % MOD);
				Update(tmp[1][j + p], 1LL * g[1][u][j] * (g[0][v][p] + g[1][v][p]) % MOD);
				if(!usd[u] && !usd[v])
					Update(tmp[1][j + p + 1], 1LL * g[0][u][j] * g[0][v][p] % MOD * w % MOD);
			}
		memcpy(g[0][u], tmp[0], sizeof(g[0][u]));
		memcpy(g[1][u], tmp[1], sizeof(g[1][u]));
		siz[u] += siz[v];
	}
}
int h_tmp[K], h_tmp_2[K];
int Solve1() {
	int ret = 0;
	h[0] = 1;
	for(int i = 1; i <= c_y; ++i) {
		if(vis[i]) continue;
		m = 0; Dfs(i, 0);
		memset(h_tmp, 0, sizeof(h_tmp));
		for(int S = 0; S < 1 << m; ++S) {
			int d = 1;
			bool flag = true;
			memset(usd, false, sizeof(usd));
			for(int j = 1; j <= m; ++j) {
				if((S >> (j - 1)) & 1) {
					if(usd[t_e[j].x + K] || usd[t_e[j].y]) { flag = false; break; }
					usd[t_e[j].x + K] = usd[t_e[j].y] = 1;
					d = 1LL * d * t_e[j].w % MOD;
				}
			}
			if(!flag) continue;
			Dfs2(i, 0);
			for(int j = 0; j <= k; ++j) {
				int x = j + __builtin_popcount(S);
				Update(h_tmp[x], 1LL * d * g[0][i][j] % MOD);
				if(!usd[i]) Update(h_tmp[x], 1LL * d * g[1][i][j] % MOD);
			}
		}
		memset(h_tmp_2, 0, sizeof(h_tmp_2));
		for(int j = 0; j <= k; ++j)
			for(int p = 0; j + p <= k; ++p)
				Update(h_tmp_2[j + p], 1LL * h[j] * h_tmp[p] % MOD);
		memcpy(h, h_tmp_2, sizeof(h));
	}
	for(int i = 0; i <= k && i <= n; ++i)
		Update(ret, 1LL * h[i] * fac[n - i] % MOD);
	//if(ret == 531272313) printf("2\n");
	return ret;
}

int f[K][N];
int Solve2() {
	int ret = 0;
	f[0][0] = 1;
	for(int i = 1; i <= c_y; ++i) {
		for(int S = 0; S < 1 << c_x; ++S) {
			for(pii j : E[i]) {
				int v = j.fi - K, w = j.se;
				if((~S >> (v - 1)) & 1)
					Update(f[i][S ^ (1 << (v - 1))], 1LL * f[i - 1][S] * w % MOD);
			}
			Update(f[i][S], f[i - 1][S]);
		}
	}
	for(int S = 0; S < 1 << c_x; ++S)
		Update(ret, 1LL * f[c_y][S] * fac[n - __builtin_popcount(S)] % MOD);
//	if(ret == 531272313) printf("1\n");
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, k);
		fac[0] = 1;
		for(int i = 1; i <= n; ++i)
			fac[i] = 1LL * fac[i - 1] * i % MOD;
		for(int i = 1; i <= k; ++i) {
			int x, y, w; rd(x, y, w);
			e[i] = (Edge) { x, y, w - 1 };
			d_x[++c_x] = x;
			d_y[++c_y] = y;
		}
		std::sort(d_x + 1, d_x + c_x + 1);
		std::sort(d_y + 1, d_y + c_y + 1);
		c_x = std::unique(d_x + 1, d_x + c_x + 1) - d_x - 1;
		c_y = std::unique(d_y + 1, d_y + c_y + 1) - d_y - 1;
		for(int i = 1; i <= k; ++i) {
			e[i].x = std::lower_bound(d_x + 1, d_x + c_x + 1, e[i].x) - d_x;
			e[i].y = std::lower_bound(d_y + 1, d_y + c_y + 1, e[i].y) - d_y;
			if(c_x > c_y) std::swap(e[i].x, e[i].y);
			E[e[i].y].push_back(mkp(K + e[i].x, e[i].w));
			E[K + e[i].x].push_back(mkp(e[i].y, e[i].w));
		}
		if(c_x > c_y) std::swap(c_x, c_y);
		if(c_x + c_y > 2 * k / 3) printf("%d\n", Solve1());
		else printf("%d\n", Solve2());
	} return 0;
}