#include <bits/stdc++.h>

const int N = 254, M = 200054;

inline void down(int &x, const int y) {x > y ? x = y : 0;}

namespace Graph {
	#define ad(x) ((x - 1 ^ 1) + 1)
	const int N = 508, M = 2000000;

	struct edge {
		int u, v;
		edge (int u0 = 0, int v0 = 0) : u(u0), v(v0) {}
	} e[M], ee[M];

	int V, E = 0, V1;
	int first[N], next[M], Fi[N], Ni[M];
	int cnt = 0, id[N], low[N];
	int stc = 0, stack[N], top[N];
	bool in_stack[N];
	int col[N], conflict[N];
	int deg[N], que[N];

	inline void addedge(int u, int v) {e[++E] = edge(u, v), next[E] = first[u], first[u] = E;}
	inline void deledge(int end) {for (; E > end; --E) first[e[E].u] = next[E];}
	inline void implies(int u, int v) {addedge(u, v), addedge(ad(v), ad(u));}
	inline void must(int x) {addedge(ad(x), x);}

	void dfs(int x) {
		int i, y; id[x] = low[x] = ++cnt, in_stack[x] = true, stack[stc++] = x;
		for (i = first[x]; i; i = next[i])
			if (!id[y = e[i].v])
				dfs(y), down(low[x], low[y]);
			else if (in_stack[y])
				down(low[x], id[y]);
		if (id[x] == low[x])
			for (y = 0; y != x; y = stack[--stc], in_stack[y] = false, top[y] = x);
	}

	void shrink() {
		int i, u, v;
		for (i = 1; i <= E; ++i)
			if ((u = top[e[i].u]) != (v = top[e[i].v]))
				++deg[u], Ni[i] = Fi[v], Fi[v] = i, ee[i] = edge(u, v);
	}

	void toposort() {
		int h, t = 0, x, i;
		for (i = 1; i <= V; ++i) if (i == top[i] && !deg[i]) que[t++] = i;
		for (h = 0; h < t; ++h)
			for (i = Fi[x = que[h]]; i; i = Ni[i])
				if (!--deg[ee[i].u]) que[t++] = ee[i].u;
		V1 = t;
	}

	void final() {
		for (int x, i = 0; i < V1; ++i)
			if (!col[x = que[i]]) col[x] = 1, col[conflict[x]] = -1;
	}

	inline bool _2_SAT() {
		int i, u, v; cnt = stc = 0;
		memset(Fi, 0, (V + 1) << 2);
		memset(id, 0, (V + 1) << 2);
		memset(col, 0, (V + 1) << 2);
		memset(conflict, 0, (V + 1) << 2);
		memset(deg, 0, (V + 1) << 2);
		for (i = 1; i <= V; ++i) if (!id[i]) dfs(i);
		for (i = 1; i <= V; i += 2) {
			if ((u = top[i]) == (v = top[i + 1])) return false;
			conflict[u] = v, conflict[v] = u;
		}
		return shrink(), toposort(), final(), true;
	}
}

int n, m, charset, Estd;
char type[30], s[N], ss[N];

inline bool check(int len) {
	Graph::deledge(Estd);
	for (int i = 0; i < len; ++i) Graph::must(i * 2 + type[ss[i]] + 1);
	return Graph::_2_SAT();
}

inline bool dfs(int dep, bool border = true) {
	if (dep >= n) return true;
	int i, u = INT_MAX, v = INT_MAX;
	if (border) {
		for (i = charset - 1; i > s[dep]; --i) type[i] ? v = i : (u = i);
		if (u > v) std::swap(u, v);
		if (ss[dep] = s[dep], check(dep + 1) && dfs(dep + 1, true)) return true;
		if (u == INT_MAX) return false;
	} else {
		for (i = charset - 1; i >= 0; --i) type[i] ? v = i : (u = i);
		if (u > v) std::swap(u, v);
	} 
	if (ss[dep] = u, check(dep + 1) && dfs(dep + 1, false)) return true;
	if (v == INT_MAX) return false;
	return ss[dep] = v, dfs(dep + 1, false);
}

int main() {
	int i, u, v; char *_p, $[6];
	scanf("%s%d%d", type, &n, &m);
	for (_p = type; *_p; ++_p) *_p &= 1; charset = _p - type;
	for (i = 0; i < m; ++i)
		scanf("%d%s%d%s", &u, $, &v, $ + 3), --u, --v, *$ &= 1, $[3] &= 1,
		Graph::implies(u * 2 + *$ + 1, v * 2 + $[3] + 1);
	Graph::V = 2 * n, Estd = Graph::E;
	if (!check(0)) return puts("-1"), 0;
	for (scanf("%s", s), _p = s; *_p; ++_p) *_p -= 97; assert(_p - s == n);;
	if (dfs(0)) {for (i = 0; i < n; ++i) ss[i] += 97; puts(ss);}
	else puts("-1");
	return 0;
}