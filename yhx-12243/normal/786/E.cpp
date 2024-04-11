#include <bits/stdc++.h>
#define ad(x) ((x - 1 ^ 1) + 1)
#define eg(i) ((i) + 1) // 3, 4, 5
#define pre(i) ((i) + n) // 6, 7, 8
#define sg(i) ((i) + 2 * n) // 9 ~ 13
#define ci(i) ((i) + 4 * n - 3) // 14 ~ 18

const int N = 25400, M = N * 2;

int n, m, E = 0;
int to[M], first[N], next[M];
int p[N], dep[N], size[N];
int cnt = 0, o[N], id[N], prf[N], top[N];
int ans1[N], ans2[N];

namespace Flow {
	const int N = 100054, M = 2003731;

	struct edge {
		int u, v, f;
		edge (int u0 = 0, int v0 = 0, int f0 = 0) : u(u0), v(v0), f(f0) {}
	} e[M];

	int V = 2, E = 0, si = 1, ti = 2, flow;
	int first[N], next[M];
	int dep[N], cur[N], que[N];

	inline void addedge(int u, int v, int f = INT_MAX) {
		e[++E] = edge(u, v, f); next[E] = first[u]; first[u] = E;
		e[++E] = edge(v, u); next[E] = first[v]; first[v] = E;
	}

	bool bfs() {
		int h, t = 1, i, x, y;
		memset(dep, -1, sizeof dep);
		que[0] = si; dep[si] = 0;
		for (h = 0; h < t; h++) {
			if ((x = que[h]) == ti) return true;
			for (i = first[x]; i; i = next[i])
				if (dep[y = e[i].v] == -1 && e[i].f) {
					que[t++] = y;
					dep[y] = dep[x] + 1;
				}
		}
		return false;
	}

	int dfs(int x, int lim) {
		int a, c, f = 0;
		if (x == ti || !lim) return lim;
		for (int &i = cur[x]; i; i = next[i])
			if (dep[e[i].v] == dep[x] + 1 && e[i].f) {
				a = std::min(lim - f, e[i].f);
				c = dfs(e[i].v, a);
				e[i].f -= c; e[ad(i)].f += c;
				if((f += c) == lim) return f;
			}
		return f;
	}

	int Dinic() {
		for (flow = 0; bfs(); flow += dfs(si, INT_MAX))
			memcpy(cur, first, sizeof cur);
		return flow;
	}
}

namespace ST {
	struct node {int lc, rc;} x[M];
	int cnt = 0;

	int build(int L, int R) {
		int id = ++cnt;
		if (L == R) return Flow::addedge(sg(id), eg(o[L])), id;
		int M = (L + R - 1) >> 1;
		x[id].lc = build(L, M), x[id].rc = build(M + 1, R);
		Flow::addedge(sg(id), sg(x[id].lc)), Flow::addedge(sg(id), sg(x[id].rc));
		return id;
	}

	void locate(int id, int L, int R, int ql, int qr, int po) {
		if (ql <= L && R <= qr) return Flow::addedge(po, sg(id));
		int M = (L + R - 1) >> 1;
		if (ql <= M) locate(x[id].lc, L, M, ql, qr, po);
		if (qr > M) locate(x[id].rc, M + 1, R, ql, qr, po);
	}
}

inline void addedge(int u, int v) {
	to[++E] = v, next[E] = first[u], first[u] = E;
	to[++E] = u, next[E] = first[v], first[v] = E;
}

void dfs(int x) {
	int i, y, &z = prf[x]; size[x] = !next[first[x]];
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != p[x]) {
			p[y] = x, dep[y] = dep[x] + 1;
			dfs(y), size[x] += size[y];
			size[y] > size[z] ? z = y : 0;
		}
}

void dfs_hld(int x, int r) {
	int i, y; o[++cnt] = x, id[x] = cnt, top[x] = r;
	if (!prf[x]) return;
	dfs_hld(prf[x], r);
	for (i = first[x]; i; i = next[i])
		if (!top[y = to[i]]) dfs_hld(y, y);
}

void solve(int u, int v, int po) {
	int x = top[u], y = top[v]; Flow::addedge(1, po, 1);
	for (; x != y; u = p[x], x = top[u]) {
		if (dep[x] < dep[y]) std::swap(u, v), std::swap(x, y);
		Flow::addedge(po, pre(u));
	}
	if (dep[u] > dep[v]) std::swap(u, v);
	ST::locate(1, 2, n, id[u] + 1, id[v], po);
}

int main() {
	int i, u, v;
	scanf("%d%d", &n, &m);
	for (i = 1; i < n; ++i) scanf("%d%d", &u, &v), addedge(u, v);
	dfs(1), dfs_hld(1, 1);
	for (i = 2; i <= n; ++i) Flow::addedge(eg(i), 2, 1);
	for (i = 2; i <= n; ++i) {
		Flow::addedge(pre(i), eg(i));
		if (i != top[i] && i != prf[1]) Flow::addedge(pre(i), pre(p[i]));
	}
	ST::build(2, n), assert(ST::cnt == 2 * n - 3);
	for (i = 1; i <= m; ++i) scanf("%d%d", &u, &v), solve(u, v, ci(i));
	printf("%d\n", Flow::Dinic());
	for (i = 1; i <= m; ++i) if (!~Flow::dep[ci(i)]) ans1[++*ans1] = i;
	for (i = 1; i < n; ++i) {
		u = to[i * 2], v = to[i * 2 - 1];
		if (p[u] == v) std::swap(u, v);
		if (~Flow::dep[eg(v)]) ans2[++*ans2] = i;
	}
	printf("%d", *ans1); for (i = 1; i <= *ans1; ++i) printf(" %d", ans1[i]); putchar(10);
	printf("%d", *ans2); for (i = 1; i <= *ans2; ++i) printf(" %d", ans2[i]); putchar(10);
	return 0;
}