#include <bits/stdc++.h>
#define EB emplace_back

typedef std::vector <int> vector;
const int N = 50054;

struct edge {
	int u, v, c, t;
	edge (int u0 = 0, int v0 = 0, int c0 = 0, int t0 = 0) : u(u0), v(v0), c(c0), t(t0) {}
	edge * read() {return scanf("%d%d%d%d", &u, &v, &c, &t), this;}
} e[N];

int V, E, T, Estd;
int cnt = 0, ans[N];
vector G[N];

inline void down(int &x, const int y) {x > y ? x = y : 0;}

namespace DC {
	typedef std::pair <int, int> pr;
	int F[N]; pr D[N];

	int Discretize(int n) {
		int i, cnt = 0;
		std::sort(D, D + n);
		for (i = 0; i < n; ++i)
			F[D[i].second] = (i && D[i].first == D[i - 1].first ? cnt - 1 : (D[cnt] = D[i], cnt++));
		return cnt;
	}
}

namespace Graph {
	#define ad(x) ((x - 1 ^ 1) + 1)
	const int N = ::N * 10, M = ::N * 50;

	struct edge {
		int u, v;
		edge (int u0 = 0, int v0 = 0) : u(u0), v(v0) {}
	} e[M], ee[M];

	int V, E = 0, V1;
	int first[N], next[M];
	int Fi[N], Ni[M];
	int cnt = 0, id[N], low[N];
	int stc = 0, stack[N], top[N];
	bool in_stack[N];
	int col[N], conflict[N];
	int deg[N], que[N];

	inline void addedge(int u, int v) {e[++E] = edge(u, v), next[E] = first[u], first[u] = E;}

	inline void deledge(int end) {for (; E > end; --E) first[e[E].u] = next[E];}

	inline void implies(int u, int v) {addedge(u, v), addedge(ad(v), ad(u));}

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
		int i, x;
		for (i = 0; i < V1; ++i)
			if (!col[x = que[i]])
				col[x] = 1, col[conflict[x]] = -1;
	}

	inline bool _2_SAT() {
		int i, u, v;
		cnt = stc = 0;
		memset(Fi, 0, (V + 1) << 2);
		memset(id, 0, (V + 1) << 2);
		memset(col, 0, (V + 1) << 2);
		memset(conflict, 0, (V + 1) << 2);
		memset(deg, 0, (V + 1) << 2);
		for (i = 1; i <= V; ++i) if (!id[i]) dfs(i);
		for (i = 1; i <= V; i += 2) {
			if ((u = Graph::top[i]) == (v = Graph::top[i + 1])) return false;
			conflict[u] = v, conflict[v] = u;
		}
		return shrink(), toposort(), final(), true;
	}
}

inline bool check(int time_limit) {
	Graph::deledge(Estd);
	for (int i = 0; i < E; ++i) if (e[i].t > time_limit) Graph::addedge(i * 2 + 1, i * 2 + 2);
	return Graph::_2_SAT();
}

int main() {
	int i, j, k, l, n, L, R, M, &c = Graph::V;
	scanf("%d%d", &V, &E), c = E * 2;
	for (i = 0; i < E; ++i) DC::D[i] = DC::pr(e[i].read()->t, i), G[e[i].u].EB(i), G[e[i].v].EB(i);
	T = DC::Discretize(E);
	for (i = 0; i < E; ++i) e[i].t = DC::F[i];
	for (i = 1; i <= V; ++i) if (n = G[i].size()) {
		vector &t = G[i];
		std::sort(t.begin(), t.end(), [] (const int x, const int y) {return e[x].c < e[y].c;});
		for (j = 0; j < n; ++j)
			Graph::implies(c + j * 2 + 2, t[j] * 2 + 2);
		for (j = 1; j < n; ++j)
			Graph::implies(t[j] * 2 + 1, c + j * 2),
			Graph::implies(c + j * 2 + 2, c + j * 2);
		for (k = j = 0; j < n; j = k) {
			for (; k < n && e[t[j]].c == e[t[k]].c; ++k);
			for (l = j; l < k; ++l)
				Graph::implies(c + n * 2 + l * 2 + 1, t[l] * 2 + 1);
			for (l = j + 1; l < k; ++l)
				Graph::implies(         t[l] * 2 + 2, c + n * 2 + l * 2 - 1),
				Graph::implies(c + n * 2 + l * 2 + 1, c + n * 2 + l * 2 - 1);
		}
		c += n * 4;
	}
	Estd = Graph::E;
	if (check(-1)) return puts("Yes\n0 0"), 0;
	if (!check(T - 1)) return puts("No"), 0;
	for (L = 0, R = T - 1; L < R; check(M = (L + R) / 2) ? R = M : (L = M + 1));
	assert(check(L));
	for (i = 1; i <= E; ++i)
		if (Graph::col[ Graph::top[i * 2 - 1] ] == 1) ans[cnt++] = i;
	printf("Yes\n%d %d\n", DC::D[L].first, cnt);
	for (i = 0; i < cnt; ++i)
		printf("%d%c", ans[i], i == cnt - 1 ? 10 : 32);
	return 0;
}