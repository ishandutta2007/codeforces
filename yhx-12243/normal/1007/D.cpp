#include <bits/stdc++.h>
#define EB emplace_back

typedef std::vector <int> vector;
const int N = 100054, M = N * 2;

int n, m, V, E = 0;
int to[M], first[N], next[M];
int p[N], dep[N], size[N];
int cnt = 0, o[N], id[N], prf[N], len[N], top[N];
int tmp[N], dak[N];
int ant[N];
vector mc[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void down(int &x, const int y) {x > y ? x = y : 0;}

namespace G {
	#define Not(x) ((((x) - 1) ^ 1) + 1)
	#define True(x) (2 * (x) - 1)
	#define False(x) (2 * (x))

	const int N = 2333333, M = 6666666;

	struct edge {
		int u, v;
		edge (int u0 = 0, int v0 = 0) : u(u0), v(v0) {}
	} e[M];

	int V, E = 0, V1;
	int first[N], next[N];
	int cnt = 0, id[N], low[N], topo[N];
	int stc = 0, stack[N], top[N];
	bool in_stack[N];
	int col[N], conflict[N];

	inline void addedge(int u, int v) {e[++E] = edge(u, v), next[E] = first[u], first[u] = E;}
	inline void implies(int u, int v) {addedge(u, v), addedge(Not(v), Not(u));}
	inline void must(int x) {addedge(Not(x), x);}

	void dfs(int x) {
		int i, y; id[x] = low[x] = ++cnt, in_stack[x] = true, stack[stc++] = x;
		for (i = first[x]; i; i = next[i])
			if (!id[y = e[i].v])
				dfs(y), down(low[x], low[y]);
			else if (in_stack[y])
				down(low[x], id[y]);
		if (id[x] == low[x]) {
			for (y = 0; y != x; y = stack[--stc], in_stack[y] = false, top[y] = x);
			topo[V1++] = x;
		}
	}

	inline bool _2_SAT() {
		int i, u, v; cnt = stc = 0;
		for (i = 1; i <= V; ++i) if (!id[i]) dfs(i);
		for (i = 1; i <= V; i += 2) {
			if ((u = top[i]) == (v = top[i + 1])) return false;
			conflict[u] = v, conflict[v] = u;
		}
		for (i = 0; i < V1; ++i)
			if (!col[v = topo[i]]) col[v] = 1, col[conflict[v]] = -1;
		for (i = 1; i <= V; ++i) col[i] = col[top[i]];
		return true;
	}
}

namespace ST {
	struct node {int p, lc, rc, L, R;} x[M];
	vector ps[M];

	int cnt = 0;

	int build(int L, int R) {
		int id = ++cnt; x[id].L = L, x[id].R = R;
		if (L == R) return id;
		int M = (L + R - 1) >> 1;
		x[id].lc = build(L, M), x[id].rc = build(M + 1, R);
		G::implies(True(x[id].lc), True(id));
		G::implies(True(x[id].rc), True(id));
		return x[id].lc[x].p = x[id].rc[x].p = id;
	}

	void locate(int id, int L, int R, int ql, int qr, int vertex) {
		if (ql <= L && R <= qr) {
			if (x[id].p) G::implies(vertex, True(x[id].p));
			ps[id].EB(vertex);
			return;
		}
		int M = (L + R - 1) >> 1;
		if (ql <= M) locate(x[id].lc, L, M, ql, qr, vertex);
		if (qr > M) locate(x[id].rc, M + 1, R, ql, qr, vertex);
	}

	void relink() {
		int i, j, l, L, R;
		for (i = 1; i <= cnt; ++i) if ((l = ps[i].size())) {
			G::implies(True(i), True(V + 1));
			for (j = 1; j < l; ++j)
				G::implies(True(V + j), True(V + j + 1)),
				G::implies(ps[i][j - 1], True(V + j + 1));
			for (j = 0; j < l; ++j) G::implies(True(V + j + 1), Not(ps[i][j]));
			L = x[i].L, R = x[i].R, assert(L[o][top] == R[o][top]);
			if (dak[L]) G::implies(False(V + 1), True(dak[L]));
			V += l;
		}
	}
}

inline void addedge(int u, int v) {
	to[++E] = v, next[E] = first[u], first[u] = E;
	to[++E] = u, next[E] = first[v], first[v] = E;
}

void dfs(int x) {
	int i, y, &z = prf[x]; size[x] = !next[first[x]];
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != p[x])
			p[y] = x, dep[y] = dep[x] + 1,
			dfs(y), size[x] += size[y],
			size[y] > size[z] ? z = y : 0;
}

void dfs_hld(int x, int r) {
	int i, y; o[++cnt] = x, id[x] = cnt, top[x] = r;
	if (!prf[x]) {len[r] = id[x] - id[r] + 1; return;}
	dfs_hld(prf[x], r);
	for (i = first[x]; i; i = next[i])
		if (!top[y = to[i]]) dfs_hld(y, y);
}

void solve(int u, int v, int vertex) {
	int x = top[u], y = top[v];
	for (; x != y; u = p[x], x = top[u]) {
		if (dep[x] < dep[y]) std::swap(u, v), std::swap(x, y);
		mc[u].EB(vertex);
	}
	if (dep[u] > dep[v]) std::swap(u, v);
	if (u != v) ST::locate(1, 2, n, id[u] + 1, id[v], vertex);
}

int main() {
	int i, j, k, u, v, uu, vv, top;
	scanf("%d", &n);
	for (i = 1; i < n; ++i) scanf("%d%d", &u, &v), addedge(u, v);
	dfs(1), dfs_hld(1, 1);
	ST::build(2, n), assert(ST::cnt == 2 * n - 3);
	scanf("%d", &m), V = 2 * n + m - 3;
	for (i = 0; i < m; ++i) {
		scanf("%d%d%d%d", &u, &v, &uu, &vv),
		solve(u, v, True(2 * n - 2 + i));
		solve(uu, vv, False(2 * n - 2 + i));
	}
	for (i = 1; i <= n; i = j + 1) {
		v = o[i], j = i + len[v] - 1, top = 0;
		for (k = i; k <= j; ++k) {
			dak[k] = V + top + 1;
			for (int x : mc[ o[k] ]) tmp[top++] = x;
		}
		for (k = 1; k < top; ++k)
			G::implies(True(V + k), True(V + k + 1)),
			G::implies(tmp[k - 1], True(V + k + 1));
		for (k = 0; k < top; ++k) G::implies(True(V + k + 1), Not(tmp[k]));
		V += top;
		for (k = i; k <= j; ++k) if (dak[k] > V) dak[k] = 0;
	}
	ST::relink(), G::V = 2 * V;
	if (G::_2_SAT())
		for (puts("YES"), i = 0; i < m; ++i)
			putchar(G::col[True(2 * n - 2 + i)] == 1 ? 49 : 50), putchar(10);
	else puts("NO");
	return 0;
}