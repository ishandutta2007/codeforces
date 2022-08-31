#include <bits/stdc++.h>
#define ad(x) (((x - 1) ^ 1) + 1)
#define lg2 std::__lg

const int N = 200054, M = N * 2, LN = 19;

int V, E, q;

struct edge {
	int u, v;
	edge (int u0 = 0, int v0 = 0) : u(u0), v(v0) {}
};

inline void down(int &x, const int y) {x > y ? x = y : 0;}

namespace Tree {
	edge e[M];
	int V, E = 0, first[N], next[M];
	int B, p[N], dep[N], bel[N], stack[N];
	int cnt = 0, id[N], st[LN][M], *ord = *st;
	int ui[N], di[N];

	inline int dmin(const int x, const int y) {return dep[x] < dep[y] ? x : y;}
	inline bool idcmp(const int x, const int y) {return id[x] < id[y];}

	inline void addedge(int u, int v) {
		e[++E] = edge(u, v), next[E] = first[u], first[u] = E;
		e[++E] = edge(v, u), next[E] = first[v], first[v] = E;
	}

	void dfs(int x) {
		int i, y; ord[cnt] = x, id[x] = cnt++, bel[x] = B;
		for (i = first[x]; i; i = next[i])
			if ((y = e[i].v) != p[x]) p[y] = x, dep[y] = dep[x] + 1, dfs(y), ord[cnt++] = x;
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

	inline void add_chain(int x, int y) {int lca = LCA(x, y); ++ui[x], ++di[y], --ui[lca], --di[lca];}

	bool check() {
		int i, v;
		for (i = cnt - 1; i >= 0; --i) if (v = ord[i], p[v] && id[v] == i) ui[p[v]] += ui[v], di[p[v]] += di[v];
		for (i = 1; i <= V; ++i) if (ui[i] && di[i]) return false;
		return true;
	}

	void main() {
		memset(id, -1, (V + 1) << 2);
		for (int i = 1; i <= V; ++i) if (!~id[i]) B = cnt, dfs(i);
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

int main() {
	int i, u, v;
	scanf("%d%d%d", &V, &E, &q);
	for (i = 0; i < E; ++i) scanf("%d%d", &u, &v), Graph::addedge(u, v);
	for (Graph::V = V, Graph::main(), Tree::main(); q; --q) {
		scanf("%d%d", &u, &v), u = Graph::bel[u], v = Graph::bel[v];
		if (!Tree::conn(u, v)) return puts("No"), 0;
		Tree::add_chain(u, v);
	}
	return puts(Tree::check() ? "Yes" : "No"), 0;
}