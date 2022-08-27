#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 100054, M = N * 2, LN = 18;

struct edge {
	int u, v, w;
	edge (int u0 = 0, int v0 = 0, int w0 = 0) : u(u0), v(v0), w(w0) {}
} e[M];

int n, q, E = 0, root;
int first[N], next[M];
int p[N], dep[N], f[N], prf[N], top[N];
int Q[LN][N];
int cnt_chain, chain[N], len[N], sum[N], rank[N], grd[N];

inline void addedge(int u, int v, int w) {
	e[++E] = edge(u, v, w), next[E] = first[u], first[u] = E;
	e[++E] = edge(v, u, w), next[E] = first[v], first[v] = E;
}

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline int min(const int x, const int y) {return x < y ? x : y;}

void dfs_diam(int x, int px = 0) {
	int i, y;
	if (dep[x] > dep[root]) root = x;
	for (i = first[x]; i; i = next[i])
		if ((y = e[i].v) != px)
			dep[y] = dep[x] + e[i].w, dfs_diam(y, x);
}

void dfs_len(int x) {
	int i, y, &z = prf[x], best = -1;
	for (i = first[x]; i; i = next[i])
		if ((y = e[i].v) != p[x])
			p[y] = x, dep[y] = dep[x] + e[i].w,
			dfs_len(y), up(f[x], f[y] + e[i].w),
			f[y] + e[i].w > best && (z = y, best = f[y] + e[i].w);
}

void dfs_lsd(int x, int r) {
	int i, y; top[x] = r;
	if (x == r)
		for (Q[0][x] = top[p[x]], i = 0; Q[i][x]; ++i) Q[i + 1][x] = Q[i][ Q[i][x] ];
	grd[x] = (r == root ? x : grd[ p[x] ]);
	if (!prf[x]) {len[r] += dep[x] - dep[r]; return;}
	dfs_lsd(prf[x], r);
	for (i = first[x]; i; i = next[i])
		if (!top[y = e[i].v])
			len[y] = e[i].w, dfs_lsd(y, y);
} 

int jump_until(int x, int r) {
	for (int i = LN - 1; i >= 0; --i)
		if (Q[i][x] && rank[Q[i][x]] >= r) x = Q[i][x];
	return x;
}

int main() {
	int i, u, v, w, m, ans = 0;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> q;
	for (i = 1; i < n; ++i) cin >> u >> v >> w, addedge(u, v, w);
	dfs_diam(1), dep[root] = 0,	dfs_len(root), dfs_lsd(root, root);
	for (i = 1; i <= n; ++i) if (top[i] == i) chain[cnt_chain++] = i;
	std::sort(chain, chain + cnt_chain, [] (const int x, const int y) {return len[x] > len[y];});
	for (i = 0; i < cnt_chain; ++i) rank[ chain[i] ] = i, sum[i + 1] = sum[i] + len[ chain[i] ];
	for (; q; --q) {
		cin >> v >> m, ans %= n;
		v = (v + ans - 1) % n + 1, m = (m + ans - 1) % n * 2 + 1;
		if (rank[ top[v] ] < m) ans = sum[min(m, cnt_chain)];
		else
			u = p[ jump_until(top[v], m) ],
			up(ans = sum[m - 1], sum[m] - min(f[u], dep[ grd[u] ])),
			ans += dep[v] - dep[u] + f[v];
		cout << ans << '\n';
	}
	return 0;
}