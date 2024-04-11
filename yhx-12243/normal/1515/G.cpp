#include <bits/stdc++.h>
#define gcd std::__gcd
using std::cin;
using std::cout;

typedef long long ll;
const int N = 200054, M = N * 2;

struct edge {
	int u, v, w;
	edge (int u0 = 0, int v0 = 0, int w0 = 0) : u(u0), v(v0), w(w0) {}
} e[M];

int V, E, Es, q;
int first[N], next[M];
int cnt = 0, id[N], low[N];
int stc = 0, sta[N], bel[N];
ll D[N], G[N];
bool instack[N];

inline void down(int &x, const int y) {x > y ? x = y : 0;}

inline void addedge(int u, int v, int w) {e[++Es] = edge(u, v, w), next[Es] = first[u], first[u] = Es;}

void dfs(int x) {
	int i, y;
	id[x] = low[x] = ++cnt, instack[x] = true, sta[stc++] = x;
	for(i = first[x]; i; i = next[i])
		if (!id[y = e[i].v])
			D[y] = D[x] + e[i].w, dfs(y), down(low[x], low[y]);
		else if (instack[y])
			down(low[x], id[y]);
	if (id[x] == low[x])
		for (y = 0; y != x; )
			y = sta[--stc], instack[y] = false, bel[y] = x;
}

int main() {
	int i, u, v, w, a, m;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> V >> E;
	for (i = 0; i < E; ++i) cin >> u >> v >> w, addedge(u, v, w);
	for (i = 1; i <= V; ++i) if (!id[i]) dfs(i);
	for (i = 1; i <= Es; ++i)
		if (bel[u = e[i].u] == bel[v = e[i].v])
			G[bel[u]] = gcd(G[bel[u]], llabs(D[u] + e[i].w - D[v]));
	for (cin >> q; q; --q)
		cin >> v >> a >> m,
		cout << ((G[bel[v]] ? a % gcd<ll>(G[bel[v]], m) : a) ? "NO\n" : "YES\n");
	return 0;
}