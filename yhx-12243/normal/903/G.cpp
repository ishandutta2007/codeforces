#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 200054;

struct edge {
	int u, v, w;
	edge (int u0 = 0, int v0 = 0, int w0 = 0) : u(u0), v(v0), w(w0) {}
} e[N];

int V, E, q;
ll l[N], r[N], m[N];
int first[N], next[N];

inline ll min(const ll x, const ll y) {return x < y ? x : y;}

inline void addedge(int u, int v, int w, int id) {e[id] = edge(u, v, w), next[id] = first[u], first[u] = id;}

namespace ST {
	#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1

	struct node {ll v, tag;} x[530000];

	void build(int id, int L, int R) {
		x[id].tag = 0;
		if (L == R) {x[id].v = r[L]; return;}
		segc; build(lc, L, M), build(rc, M + 1, R);
		x[id].v = min(x[lc].v, x[rc].v);
	}

	void adj(int id, int L, int R, int h, ll v) {
		if (L == R) {x[id].v = v; return;}
		segc; h <= M ? adj(lc, L, M, h, v) : adj(rc, M + 1, R, h, v);
		x[id].v = min(x[lc].v, x[rc].v);
	}

	void add(int id, int L, int R, int ql, int qr, ll v) {
		if (ql <= L && R <= qr) {x[id].v += v, x[id].tag += v; return;}
		segc;
		if (ql <= M) add(lc, L, M, ql, qr, v);
		if (qr > M) add(rc, M + 1, R, ql, qr, v);
		x[id].v = min(x[lc].v, x[rc].v) + x[id].tag;
	}
}

int main() {
	int i, j, u, v, w;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> V >> E >> q;
	for (i = 1; i < V; ++i) cin >> l[i] >> r[i + 1];
	for (i = 1; i <= E; ++i) cin >> u >> v >> w, addedge(u, v, w, i);
	ST::build(1, 1, V);
	for (i = 1; i <= V; ++i) {
		for (j = first[i]; j; j = next[j]) ST::add(1, 1, V, 1, e[j].v, e[j].w);
		r[i] = l[i] + (m[i] = ST::x[1].v);
	}
	ST::build(1, 1, V), cout << ST::x[1].v << '\n';
	for (; q; --q)
		cin >> u >> v, ST::adj(1, 1, V, u, v + m[u]), cout << ST::x[1].v << '\n';
	return 0;
}