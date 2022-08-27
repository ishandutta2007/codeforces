#include <bits/stdc++.h>
#define sg(i) (2 + n + R + (i))

const int N = 5054;

int n, R;
int count[N], from[N];
int type[N];

namespace F {
	#define ad(x) (((x - 1) ^ 1) + 1)

	const int N = 20000, M = 6000000;

	struct edge {
		int u, v, f;
		edge (int u0 = 0, int v0 = 0, int f0 = 0) : u(u0), v(v0), f(f0) {}
	} e[M];

	int V = 2, E = 0, si = 1, ti = 2, F;
	int first[N], next[M];
	int dep[N], cur[N], que[N];

	inline void addedge(int u, int v, int f) {
		e[++E] = edge(u, v, f), next[E] = first[u], first[u] = E;
		e[++E] = edge(v, u), next[E] = first[v], first[v] = E;
	}

	bool bfs() {
		int h, t = 1, i, x, y;
		memset(dep, -1, sizeof dep);
		que[0] = si, dep[si] = 0;
		for (h = 0; h < t; h++) {
			if ((x = que[h]) == ti) return true;
			for (i = first[x]; i; i = next[i])
				if (dep[y = e[i].v] == -1 && e[i].f)
					que[t++] = y, dep[y] = dep[x] + 1;
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
				if ((f += c) == lim) return f;
			}
		return f;
	}

	int Dinic() {
		for (F = 0; bfs(); F += dfs(si, INT_MAX))
			memcpy(cur, first, sizeof cur);
		return F;
	}
}

namespace ST {
	struct node {int v, lc, rc;} x[N * 4];
	int cnt;

	int build(int L, int R) {
		if (L == R) return 2 + n + L;
		int id = ++cnt, M = (L + R - 1) >> 1;
		x[id].lc = build(L, M), x[id].rc = build(M + 1, R);
		F::addedge(id, x[id].lc, INT_MAX), F::addedge(id, x[id].rc, INT_MAX);
		return id;
	}

	void locate(int id, int L, int R, int ql, int qr, int v) {
		if (ql <= L && R <= qr) return F::addedge(v, id, 1);
		int M = (L + R - 1) >> 1;
		if (ql <= M) locate(x[id].lc, L, M, ql, qr, v);
		if (qr > M) locate(x[id].rc, M + 1, R, ql, qr, v);
	}
}

inline void link(int x, int y) {++count[x], from[y] = x;}

int dfsA(int x, int px = 0) {
	using namespace F;
	int i, y;
	for (i = first[x]; i; i = next[i])
		if ((y = e[i].v) != px && e[ad(i)].f) {
			if (2 + n < y && y <= 2 + n + R) return ++e[i].f, --e[ad(i)].f, y - n - 2;
			if (x < y) return ++e[i].f, --e[ad(i)].f, dfsA(y, x);
		}
	return 0;
}

int main() {
	int i, c, u, v, w, root;
	scanf("%d%d", &n, &R);
	for (i = 1; i <= R; ++i) F::addedge(2 + n + i, 2, 1);
	ST::cnt = 2 + n + R, F::V = ST::cnt + R - 1;
	root = ST::build(1, R), assert(ST::cnt == F::V);
	for (i = 1; i <= n; ++i) {
		scanf("%d", type + i), F::addedge(1, 2 + i, type[i] + !type[i]);
		switch (type[i]) {
			case 0:
				for (scanf("%d", &c); c; --c) scanf("%d", &v), F::addedge(2 + i, 2 + n + v, 1);
				break;
			case 1:
				scanf("%d%d", &u, &v), ST::locate(root, 1, R, u, v, 2 + i);
				break;
			case 2:
				scanf("%d%d%d", &u, &v, &w),
				F::addedge(2 + i, 2 + n + u, 1),
				F::addedge(2 + i, 2 + n + v, 1),
				F::addedge(2 + i, 2 + n + w, 1);
				break;
		}
	}
	printf("%d\n", F::Dinic());
	for (v = 1; v <= n; ++v)
		if (type[v] == 1) {
			if ((u = dfsA(2 + v))) link(v, u);
		} else for (i = F::first[2 + v]; i; i = F::next[i])
			if (!F::e[i].f)
				if (u = F::e[i].v - n - 2, 0 < u && u <= R)
					link(v, u);
	for (v = 1; v <= n; ++v) if (type[v] == 2 && count[v] == 1) {
		for (i = F::first[2 + v]; i; i = F::next[i]) if (F::e[i].f) {
			u = F::e[i].v - n - 2;
			if (0 < u && u <= R && from[u]) {
				assert(u != v);
				assert(type[from[u]] != 2);
				from[u] = v, ++count[v];
				break;
			}
		}
		assert(i);
	}
	for (v = 1; v <= n; ++v) if (type[v] == 2) {
		if (count[v] && count[v] != 2)
			printf("DANGER %d %d %d\n" ,v, type[v], count[v]);
	}
	for (i = 1; i <= R; ++i) if (from[i]) printf("%d %d\n", from[i], i);
	return 0;
}