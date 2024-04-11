#include <bits/stdc++.h>

const int N = 200054, M = N * 2;

struct edge {
	int u, v, w;
	edge (int u0 = 0, int v0 = 0, int w0 = 0) : u(u0), v(v0), w(w0) {}
} e[M];

int n, E = 0;
int first[N], next[M];
int w[N], size[N];
double diff[N];
int ansC;
double cur, ansW = INFINITY;
bool fy[N];

inline bool up(int &x, const int y) {return x < y ? x = y, 1 : 0;}
inline bool up(double &x, const double y) {return x < y ? x = y, 1 : 0;}

inline void addedge(int u, int v, int w) {
	e[++E] = edge(u, v, w), next[E] = first[u], first[u] = E;
	e[++E] = edge(v, u, w), next[E] = first[v], first[v] = E;
}

namespace Centroid {
	int V, Gm, G, size[N];

	void init(int _V) {V = _V, Gm = INT_MAX;}

	int get(int x, int px = 0) {
		int i, y, Max = 0; size[x] = 1;
		for (i = first[x]; i; i = next[i])
			if ((y = e[i].v) != px && !fy[y])
				get(y, x), up(Max, size[y]), size[x] += size[y];
		up(Max, V - size[x]);
		return Max <= Gm ? (Gm = Max, G = x) : G;
	}
}

#define get_centroid(x, y) (Centroid::init(y), Centroid::get(x))

void dfs(int x, int px = 0) {
	int i, y; size[x] = 1;
	for (i = first[x]; i; i = next[i])
		if ((y = e[i].v) != px && !fy[y]) dfs(y, x), size[x] += size[y];
}

void compute(int x, int px, int dep) {
	int i, y; cur += double((long long)w[x] * dep) * sqrt(dep);
	for (i = first[x]; i; i = next[i])
		if ((y = e[i].v) != px) compute(y, x, dep + e[i].w);
}

void compute_diff(int x, int px, int dep) {
	int i, y; diff[x] = w[x] * sqrt(dep);
	for (i = first[x]; i; i = next[i])
		if ((y = e[i].v) != px) compute_diff(y, x, dep + e[i].w), diff[x] += diff[y];
}

void solve(int x) {
	int i, y, z = 0, G; double max = -INFINITY;
	cur = 0., fy[x] = true, dfs(x);
	if (compute(x, 0, 0), cur < ansW) ansC = x, ansW = cur;
	for (i = first[x]; i; i = next[i])
		if (!fy[y = e[i].v])
			if (compute_diff(y, x, e[i].w), up(max, diff[y])) z = y;
	if (z) G = get_centroid(z, size[z]), solve(G);
}

int main() {
	int i, G, $1, $2, $3;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) scanf("%d", w + i);
	for (i = 1; i < n; ++i) scanf("%d%d%d", &$1, &$2, &$3), addedge($1, $2, $3);
	G = get_centroid(1, n), solve(G);
	printf("%d %.12lg\n", ansC, ansW);
	return 0;
}