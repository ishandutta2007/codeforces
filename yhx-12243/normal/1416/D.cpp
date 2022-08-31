#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 500054, M = 300054;

struct edge {
	int u, v;
	edge (int u0 = 0, int v0 = 0) : u(u0), v(v0) {}
} e[M];

int n, q, V, E;
int P[N], perm[N];
int p[N], fc[N], nc[N];
int cnt = 0, o[N], id[N], eid[N];
int ev[N], tag[M];
int ans[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline int max(const int x, const int y) {return x < y ? y : x;}
inline void link(int x, int px) {p[x] = px, nc[x] = fc[px], fc[px] = x;}
int ancestor(int x) {return P[x] == x ? x : (P[x] = ancestor(P[x]));}

inline int connect(int x, int y) {
	if ((x = ancestor(x)) == (y = ancestor(y))) return 0;
	return ++V, link(x, V), link(y, V), P[x] = P[y] = P[V] = V;
}

void dfs(int x) {
	int y; o[++cnt] = x, id[x] = cnt;
	for (y = fc[x]; y; y = nc[y]) dfs(y);
	eid[x] = cnt;
}

namespace ST {
	#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1
	int x[N];

	void build(int id, int L, int R) {
		if (L == R) {x[id] = (o[L] <= n ? o[L] : 0); return;}
		segc; build(lc, L, M), build(rc, M + 1, R);
		x[id] = max(x[lc], x[rc]);
	}

	void adj(int id, int L, int R, int h, int v) {
		if (L == R) {x[id] = v; return;}
		segc; h <= M ? adj(lc, L, M, h, v) : adj(rc, M + 1, R, h, v);
		x[id] = max(x[lc], x[rc]);
	}

	int range(int id, int L, int R, int ql, int qr) {
		if (ql <= L && R <= qr) return x[id];
		segc, s = 0;
		if (ql <= M) up(s, range(lc, L, M, ql, qr));
		if (qr > M) up(s, range(rc, M + 1, R, ql, qr));
		return s;
	}
}

int main() {
	int i, j, u, v;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> E >> q, V = n;
	for (i = 1; i <= V; ++i) cin >> perm[i];
	for (i = 1; i <= E; ++i)
		cin >> u >> v, e[i] = edge(perm[u], perm[v]);
	for (i = 0; i < q; ++i)
		cin >> u >> v, ev[i] = (u == 1 ? perm[v] : (tag[v] = i + 1, -v));
	std::iota(P, P + (V + 1), 0);
	for (i = 1; i <= E; ++i)
		if (!tag[i]) connect(e[i].u, e[i].v);
	for (i = q - 1; i >= 0; --i)
		if (ev[i] > 0) ev[i] = ancestor(ev[i]);
		else j = -ev[i], connect(e[j].u, e[j].v);
	for (i = 1; i <= V; ++i) if (!p[i]) dfs(i);	
	assert(cnt == V), ST::build(1, 1, V);
	for (i = 0; i < q; ++i) if (ev[i] > 0) {
		v = ev[i], u = ST::range(1, 1, V, id[v], eid[v]), cout << u << '\n';
		if (u) ST::adj(1, 1, V, id[u], 0);
	}
	return 0;
}