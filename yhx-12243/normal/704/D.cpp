#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair <int, int> pr;
const int N = 100054;

struct DC {
	int F[N]; pr D[N];

	int Discretize(int n) {
		int i, cnt = 0; std::sort(D, D + n);
		for (i = 0; i < n; ++i)
			F[D[i].second] = (i && D[i].first == D[i - 1].first ? cnt - 1 : (D[cnt] = D[i], cnt++));
		return cnt;
	}
} X, Y;

int n, q, cX, cY;
int x[N], y[N], cx[N], cy[N], lx[N], ly[N];

inline void down(int &x, const int y) {x > y ? x = y : 0;}

namespace F {
	#define ad(x) ((x - 1 ^ 1) + 1)

	const int N = 200054, M = 2003731;

	struct edge {
		int u, v, f;
		edge (int u0 = 0, int v0 = 0, int f0 = 0) : u(u0), v(v0), f(f0) {}
	} e[M];

	int V = 2, E = 0, si = 1, ti = 2, flow;
	int first[N], next[M], deg[N];
	int dep[N], cur[N], que[N];

	inline void addedge(int u, int v, int f) {
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

	inline void link(int u, int v, int l, int r) {addedge(u + 2, v + 2, r - l), deg[u] -= l, deg[v] += l;}

	inline void reduce(int x) {for (int &i = first[x]; i && e[i].v <= 2; i = next[i]);}

	int main() {
		int i;
		for (i = 1; i <= V; ++i)
			if (deg[i] > 0) addedge(1, i + 2, deg[i]);
			else if (deg[i] < 0) addedge(i + 2, 2, -deg[i]);
		addedge(4, 3, INT_MAX), Dinic();
		for (i = first[1]; i; i = next[i])
			if (~dep[e[i].v]) return -1;
		first[1] = first[2] = 0;
		for (i = 1; i <= V; ++i) reduce(i + 2);
		return si = 3, ti = 4, Dinic();
	}
}

int main() {
	int i, op, r, v, x0, y0; bool flip; ll A, B;
	scanf("%d%d%lld%lld", &n, &q, &A, &B);
	if (flip = A > B) std::swap(A, B);
	A -= B, B *= n;
	for (i = 0; i < n; ++i)
		scanf("%d%d", &x0, &y0), X.D[i] = pr(x0, i), Y.D[i] = pr(y0, i);
	cX = X.Discretize(n), cY = Y.Discretize(n);
	for (i = 0; i < n; ++i)
		++cx[ x[i] = X.F[i] ], ++cy[ y[i] = Y.F[i] ], F::link(x[i] + 3, y[i] + 3 + cX, 0, 1);
	memcpy(lx, cx, cX << 2), memcpy(ly, cy, cY << 2);
	for (; q; --q)
		if (scanf("%d%d%d", &op, &r, &v), op == 1) {
			x0 = std::lower_bound(X.D, X.D + cX, pr(r, 0)) - X.D;
			if (X.D[x0].first == r) down(lx[x0], (cx[x0] + v) / 2);
		} else {
			y0 = std::lower_bound(Y.D, Y.D + cY, pr(r, 0)) - Y.D;
			if (Y.D[y0].first == r) down(ly[y0], (cy[y0] + v) / 2);
		}
	for (i = 0; i < cX; ++i) {
		if (lx[i] * 2 < cx[i]) return puts("-1"), 0;
		F::link(1, i + 3, cx[i] - lx[i], lx[i]);
	}
	for (i = 0; i < cY; ++i) {
		if (ly[i] * 2 < cy[i]) return puts("-1"), 0;
		F::link(i + 3 + cX, 2, cy[i] - ly[i], ly[i]);
	}
	F::V = cX + cY + 2;
	if (!~(r = F::main())) return puts("-1"), 0;
	printf("%lld\n", A * r + B);
	flip ? (x0 = 114, y0 = 98) : (x0 = 98, y0 = 114);
	for (i = 0; i < n; ++i) putchar(F::e[i * 2 + 1].f ? x0 : y0);
	putchar(10);
	return 0;
}