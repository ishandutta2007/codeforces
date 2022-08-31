#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 200054, M = N * 2;

struct edge {
	int u, v, w;
	edge (int u0 = 0, int v0 = 0, int w0 = 0) : u(u0), v(v0), w(w0) {}
	inline bool operator < (const edge &B) const {return w < B.w;}
} e[M];

int V, E, Es = 0, Ek = 0, X = 0;
int first[N], next[M];
int p[N], pb[N], que[N];
int stamp = 0, used[N];
int nV[N], nE[N];
bool usedE[M];

int ancestor(int x) {return p[x] == x ? x : (p[x] = ancestor(p[x]));}

inline void addedge(int u, int v, int w) {
	e[++Es] = edge(u, v, w), next[Es] = first[u], first[u] = Es,
	e[++Es] = edge(v, u, w), next[Es] = first[v], first[v] = Es;
}

void bfs(int si) {
	int h, t = 1, i, x; *que = pb[si] = si;
	for (h = 0; h < t; ++h) {
		x = que[h], ++stamp, p[x] = ancestor(x + 1);
		for (i = first[x]; i; i = next[i]) used[e[i].v] = stamp;
		for (i = ancestor(1); i <= V; i = ancestor(i + 1))
			if (used[i] != stamp) pb[i] = si, p[i] = ancestor(i + 1), que[t++] = i;
	}
}

int main() {
	int i, u, v, w; ll mst = 0;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> V >> E;
	for (i = 0; i < E; ++i) cin >> u >> v >> w, addedge(u, v, w), X ^= w;
	std::iota(p, p + (V + 2), 0);
	for (i = 1; i <= V; i = ancestor(i + 1)) bfs(i);
	for (i = 1; i <= V; ++i) ++nV[pb[i]];
	for (i = 1; i <= Es; i += 2) {
		u = e[i].u, v = e[i].v, w = e[i].w;
		if (pb[u] == pb[v]) ++nE[pb[u]];
	}
	std::sort(e + 1, e + (Es + 1));
	memcpy(p, pb, (V + 2) << 2);
	for (i = 1; i <= Es; ++i) {
		u = e[i].u, v = e[i].v, w = e[i].w;
		if (u < v && ancestor(u) != ancestor(v)) p[ancestor(u)] = ancestor(v), mst += w, usedE[i] = true;
	}
	for (i = 1; i <= V; ++i) if (pb[i] == i && nV[i] * (nV[i] - 1ll) / 2 - nE[i] >= nV[i]) break;
	if (i <= V) return cout << mst << '\n', 0;
	std::iota(p, p + (V + 2), 0);
	for (i = 1; i <= Es; ++i) {
		u = e[i].u, v = e[i].v, w = e[i].w;
		if (w >= X) break;
		if (u > v) continue;
		if (usedE[i]) {p[ancestor(u)] = ancestor(v); continue;}
		if (ancestor(u) != ancestor(v)) {X = w; break;}
	}
	cout << mst + X << '\n';
	return 0;
}