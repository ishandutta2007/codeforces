#include <bits/stdc++.h>
#define lg2 std::__lg

typedef long long ll;
const int N = 300054, M = 600054, LN = 20;

struct edge {
	int u, v, w;
	edge (int u0 = 0, int v0 = 0, int w0 = 0) : u(u0), v(v0), w(w0) {}
} e[M];

int n, q, E = 0;
int a[N], first[N], next[M];
int p[N], dep[N];
int cnt = 0, id[N], st[LN][M], *o = *st;
ll depV[N], depE[N];
ll D[N], U[N], De[N], Dc[N], sDc[N];
// down, up, down-with-edge, down-with-complement, prefix sum of Dc

inline int dmin(const int x, const int y) {return dep[x] < dep[y] ? x : y;}
inline ll max(const ll x, const ll y) {return x < y ? y : x;}

inline void addedge(int u, int v, int w) {
	e[++E] = edge(u, v, w), next[E] = first[u], first[u] = E;
	e[++E] = edge(v, u, w), next[E] = first[v], first[v] = E;
}

void dfs(int x) {
	int i, y; o[cnt] = x, id[x] = cnt++;
	for (i = first[x]; i; i = next[i])
		if ((y = e[i].v) != p[x])
			p[y] = x, dep[y] = dep[x] + 1, depV[y] = depV[x] + a[y], depE[y] = depE[x] + e[i].w,
			dfs(y), D[x] += De[y] = max(0, -2 * e[i].w + a[y] + D[y]), o[cnt++] = x;
}

void dfs2(int x) {
	int i, y;
	for (i = first[x]; i; i = next[i])
		if (p[y = e[i].v] == x)
			Dc[y] = D[x] - De[y], sDc[y] = sDc[x] + Dc[y],
			U[y] = max(0, -2 * e[i].w + a[x] + U[x] + Dc[y]),
			dfs2(y);
}

inline ll downCompl(int x, int y) {return sDc[x] - sDc[y];}

void build_sparse_table() {
	int *f, *g = o, i, j, k = cnt;
	for (j = 0; 1 << (j + 1) <= cnt; ++j) {
		f = g, g = st[j + 1], k -= 1 << j;
		for (i = 0; i < k; ++i)
			g[i] = dmin(f[i], f[i + (1 << j)]);
	}
}

inline int LCA(int x, int y) {
	int L, R, c; std::tie(L, R) = std::minmax(id[x], id[y]), c = lg2(++R - L);
	return dmin(st[c][L], st[c][R - (1 << c)]);
}

int main() {
	int i, u, v, w; ll ans;
	scanf("%d%d", &n, &q);
	for (i = 1; i <= n; ++i) scanf("%d", a + i);
	for (i = 1; i < n; ++i) scanf("%d%d%d", &u, &v, &w), addedge(u, v, w);
	depV[1] = a[1], dfs(1), dfs2(1), build_sparse_table();
	for (; q; --q) {
		scanf("%d%d", &u, &v), w = LCA(u, v);
		ans = depV[u] + depV[v] - depV[w] - depV[p[w]]
			- depE[u] - depE[v] + 2 * depE[w];
		if (dep[u] > dep[v]) std::swap(u, v);
		if (v == w) ans += D[u] + U[u];
		else if (u == w) ans += D[v] + U[u] + downCompl(v, u);
		else ans += D[u] + D[v] + U[w] + downCompl(u, w) + downCompl(v, w) - D[w];
		printf("%lld\n", ans);
	}
	return 0;
}