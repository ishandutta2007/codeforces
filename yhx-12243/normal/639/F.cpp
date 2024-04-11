#include <bits/stdc++.h>
#define ad(x) (((x - 1) ^ 1) + 1)
#define lg2 std::__lg

const int N = 300054, M = N * 2, LN = 20;

int V, E, kV, kE, q, mask;
int v[N], vcheck[N];
int cnt_vir, vir[N], virp[N];

struct edge {
	int u, v;
	edge (int u0 = 0, int v0 = 0) : u(u0), v(v0) {}
} es[N];

inline void down(int &x, const int y) {x > y ? x = y : 0;}

namespace Tree { // Forest
	edge e[M];
	int V, E = 0, first[N], next[M];
	int B, dep[N], bel[N], stack[N];
	int cnt = 0, id[N], st[LN][M], *ord = *st;

	inline int dmin(const int x, const int y) {return dep[x] < dep[y] ? x : y;}
	inline bool idcmp(const int x, const int y) {return id[x] < id[y];}

	inline void addedge(int u, int v) {
		e[++E] = edge(u, v), next[E] = first[u], first[u] = E;
		e[++E] = edge(v, u), next[E] = first[v], first[v] = E;
	}

	void dfs(int x, int px = 0) {
		int i, y; ord[cnt] = x, id[x] = cnt++, bel[x] = B;
		for (i = first[x]; i; i = next[i])
			if ((y = e[i].v) != px) dep[y] = dep[x] + 1, dfs(y, x), ord[cnt++] = x;
	}

	void build_sparse_table() {
		int *f, *g = ord, i, j, k = cnt;
		for (j = 0; 1 << (j + 1) <= cnt; ++j) {
			f = g, g = st[j + 1], k -= 1 << j;
			for (i = 0; i < k; ++i) g[i] = dmin(f[i], f[i + (1 << j)]);
		}
	}

	inline bool conn(int x, int y) {return bel[x] == bel[y];}

	inline int LCA(int x, int y) {
		int L, R, c; std::tie(L, R) = std::minmax(id[x], id[y]), c = lg2(++R - L);
		return dmin(st[c][L], st[c][R - (1 << c)]);
	}

	void DSA(int n, int *v) {
		#define ins(x) (virp[x] = stack[top], stack[++top] = vir[cnt_vir++] = x)
		int i, x, y, top = 0; cnt_vir = 0;
		for (i = 0; i < n; ++i)
			if (x = v[i], !(top && conn(stack[top], x))) {
				for (; top; --top) stack[top] = 0; ins(x);
			} else {
				stack[top + 1] = 0;
				for (y = LCA(stack[top], x); dep[ stack[top] ] > dep[y]; --top);
				virp[ stack[top + 1] ] = y;
				if (stack[top] != y) ins(y); ins(x);
			}
		for (; top; --top) stack[top] = 0;
		std::sort(vir, vir + cnt_vir, idcmp);
	}

	void main() {
		int i; memset(id, -1, (V + 1) << 2);
		for (i = 1; i <= V; ++i) if (!~id[i]) B = cnt, dfs(i);
		build_sparse_table();
	}
}

namespace Graph {
	edge e[M];
	int V, E = 0, first[N], next[M];
	int cnt = 0, id[N], low[N];
	int stc = 0, stack[N];
	int nbcc = 0, bel[N];
	bool bridge[M];

	inline void addedge(int u, int v) {
		e[++E] = edge(u, v), next[E] = first[u], first[u] = E;
		e[++E] = edge(v, u), next[E] = first[v], first[v] = E;
	}

	void dfs(int x, int px = 0) {
		int i, y; id[x] = low[x] = ++cnt, stack[stc++] = x;
		for (i = first[x]; i; i = next[i])
			if (!id[y = e[i].v]) {
				dfs(y, i), down(low[x], low[y]);
				if (id[x] < low[y]) bridge[ad(i)] = bridge[i] = true;
			} else if ((px - 1) ^ (i - 1) ^ 1)
				down(low[x], id[y]);
		if (id[x] == low[x])
			for (++nbcc, y = 0; y != x; y = stack[--stc], bel[y] = nbcc);
	}

	void main() {
		int i, u, v;
		for (i = 1; i <= V; ++i) if (!id[i]) dfs(i); Tree::V = Graph::nbcc;
		for (i = 1; i <= E; i += 2) if (bridge[i]) u = bel[e[i].u], v = bel[e[i].v], Tree::addedge(u, v);
	}
}

namespace Virtual {
	edge e[M];
	int E, first[N], next[M];
	int cnt, id[N], low[N];
	int stc, stack[N];
	int nbcc, bel[N];

	inline void addedge(int u, int v) {
		e[++E] = edge(u, v), next[E] = first[u], first[u] = E;
		e[++E] = edge(v, u), next[E] = first[v], first[v] = E;
	}

	void dfs(int x, int px = 0) {
		int i, y; id[x] = low[x] = ++cnt, stack[stc++] = x;
		for (i = first[x]; i; i = next[i])
			if (!id[y = e[i].v])
				dfs(y, i), down(low[x], low[y]);
			else if ((px - 1) ^ (i - 1) ^ 1)
				down(low[x], id[y]);
		if (id[x] == low[x])
			for (++nbcc, y = 0; y != x; y = stack[--stc], bel[y] = nbcc);
	}

	inline void init() {
		nbcc = stc = cnt = E = 0;
		for (int v, i = 0; i < cnt_vir; ++i) v = vir[i], first[v] = id[v] = 0;
	}

	inline bool main() {
		int i, v;
		for (i = 0; i < cnt_vir; ++i) if (!(id[ v = vir[i] ])) dfs(v);
		for (v = bel[*vcheck], i = 1; i < kV; ++i) if (bel[vcheck[i]] != v) return false;
		return true;
	}
}

inline int next() {int $; return scanf("%d", &$), Graph::bel[($ + mask - 1) % V + 1];}

int main() {
	int i, j, u, v, n; bool ret;
	scanf("%d%d%d", &V, &E, &q);
	for (i = 0; i < E; ++i)
		if (scanf("%d%d", &u, &v), u != v) Graph::addedge(u, v);
	for (Graph::V = V, Graph::main(), Tree::main(), j = 1; j <= q; ++j) {
		scanf("%d%d", &kV, &kE), n = kV;
		for (i = 0; i < kV; ++i) vcheck[i] = ::v[i] = next();
		for (i = 0; i < kE; ++i) {
			if ((u = next()) == (v = next())) {--i, --kE; continue;}
			::v[n++] = u, ::v[n++] = v, es[i] = edge(u, v);
		}
		std::sort(::v, ::v + n, Tree::idcmp), n = std::unique(::v, ::v + n) - ::v;
		Tree::DSA(n, ::v), Virtual::init();
		for (i = 0; i < cnt_vir; ++i) if (virp[vir[i]]) Virtual::addedge(vir[i], virp[vir[i]]);
		for (i = 0; i < kE; ++i) Virtual::addedge(es[i].u, es[i].v);
		if (ret = Virtual::main()) mask = (mask + j) % V, puts("YES");
		else puts("NO");
	}
	return 0;
}