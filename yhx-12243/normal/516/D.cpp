#include <bits/stdc++.h>

typedef long long ll;
const int N = 100054, M = N * 2;

struct edge {
	int u, v, w;
	edge (int u0 = 0, int v0 = 0, int w0 = 0) : u(u0), v(v0), w(w0) {}
} e[M];

int n, q, V, E = 0, root;
int first[N], next[M];
int cnt = 0, p[N], o[N];
int D1, D2, ret;
ll diam, dep[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline ll min(const ll x, const ll y) {return x < y ? x : y;}

inline void addedge(int u, int v, int w) {
	e[++E] = edge(u, v, w), next[E] = first[u], first[u] = E;
	e[++E] = edge(v, u, w), next[E] = first[v], first[v] = E;
}

inline void deledge(int u, int v) {
	if (e[ first[u] ].v == v) {first[u] = next[ first[u] ]; return;}
	for (int i = first[u]; next[i]; i = next[i])
		if (e[ next[i] ].v == v) {next[i] = next[ next[i] ]; return;}
}

void dfs(int x) {
	int i, y; o[++cnt] = x;
	if (dep[x] > dep[ret]) ret = x;
	for (i = first[x]; i; i = next[i])
		if ((i - 1) ^ (p[x] - 1) ^ 1)
			p[y = e[i].v] = i, dep[y] = dep[x] + e[i].w, dfs(y);
}

namespace DSU {
	int p[N], size[N];

	inline void init(int n) {std::iota(p + 1, p + (n + 1), 1), std::fill(size + 1, size + (n + 1), 1);}

	int ancestor(int x) {return p[x] == x ? x : (p[x] = ancestor(p[x]));}

	inline bool test(int x, int y, bool un = false) {
		if ((x = ancestor(x)) == (y = ancestor(y))) return true;
		return un && (size[x] > size[y] && (std::swap(x, y), 0), p[x] = y, size[y] += size[x], false);
	}

	inline int & Size(int x) {return size[ancestor(x)];}
}

int main() {
	int i, u, v, w, *x, *del, ans = 0; ll $1, $2;
	scanf("%d", &n);
	for (i = 1; i < n; ++i) scanf("%d%d%d", &u, &v, &w), addedge(u, v, w);
	ret = 1,  dep[ret] = p[ret] = cnt = 0, dfs(ret), D1 = ret;
	ret = D1, dep[ret] = p[ret] = cnt = 0, dfs(ret), D2 = ret;
	diam = dep[D2];
	for (u = D2; u && dep[u] * 2 > diam; u = e[i].u) i = p[u];
	if (dep[u] * 2 == diam) root = v = u, V = n;
	else {
		v = e[i].v, root = V = n + 1;
		$1 = (diam + 1) / 2 - dep[u], $2 = dep[v] - diam / 2;
		deledge(u, v), deledge(v, u);
		addedge(root, u, $1), addedge(root, v, $2);
	}
	dep[root] = p[root] = cnt = 0, dfs(root);
	std::iota(o, o + V, 1);
	std::sort(o, o + V, [] (const int x, const int y) {return dep[x] > dep[y];});
	dep[root] = min(dep[u], dep[v]);
	for (scanf("%d", &q); q; --q) {
		scanf("%lld", &$1), DSU::init(V), ans = 1;
		if (root == n + 1) DSU::size[n + 1] = 0;
		for (del = x = o; x != o + V; ++x) {
			for (; dep[*del] > dep[*x] + $1; ++del) --DSU::Size(*del);
			up(ans, DSU::Size(*x)), DSU::test(*x, e[p[*x]].u, true);
		}
		printf("%d\n", ans);
	}
	return 0;
}