#include <bits/stdc++.h>
#define EB emplace_back
using std::cin;
using std::cout;

typedef long long ll;
typedef std::set <int> set;
typedef std::priority_queue <int, std::vector <int>, std::greater <int>> heap;
const int N = 100054, M = N * 2;

struct edge {
	int u, v, w;
	edge (int u0 = 0, int v0 = 0, int w0 = 0) : u(u0), v(v0), w(w0) {}
} e[M];

int n, C, E = 0;
int first[N], next[M], size[N];
int bel[N], deg[N];
int btop = 0, buf[N];
int spec, cG = 0, G[3];
ll ans = 0;
heap H[N];
set global;

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline int min(const int x, const int y) {return x < y ? x : y;}

inline void addedge(int u, int v, int w) {
	e[++E] = edge(u, v, w), next[E] = first[u], first[u] = E;
	e[++E] = edge(v, u, w), next[E] = first[v], first[v] = E;
}

void dfs(int x, int px = 0) {
	int i, y, max = 0; size[x] = 1;
	for (i = first[x]; i; i = next[i])
		if ((y = e[i].v) != px)
			dfs(y, x), size[x] += size[y], up(max, size[y]),
			ans += (ll)e[i].w * min(size[y], n - size[y]);
	if (up(max, n - size[x]), max <= n / 2) G[cG++] = x;
}

void make_subtree(int x, int px = 0) {
	int i, y; buf[btop++] = x, bel[x] = C;
	for (i = first[x]; i; i = next[i]) if ((y = e[i].v) != px) make_subtree(y, x);
}

namespace pb_ds {
	typedef std::list <int> list;
	typedef list::iterator lit;

	int maxdeg = 0;
	list li[N];
	lit at[N];

	inline void init(int x) {
		if (x == spec) return;
		li[ deg[x] ].EB(x), at[x] = --li[ deg[x] ].end();
		up(maxdeg, deg[x]);
	}

	inline void decrease(int x) {
		if (x == spec) return;
		li[ deg[x] ].erase(at[x]);
		if (~--deg[x]) li[ deg[x] ].EB(x), at[x] = --li[ deg[x] ].end();
		maxdeg -= li[maxdeg].empty();
	}

	inline int any() {return li[maxdeg].back();}
}

int main() {
	int i, j, u, v, w;
	set::iterator it;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	for (i = 1; i < n; ++i) cin >> u >> v >> w, addedge(u, v, w);
	dfs(1), cout << 2 * ans << '\n';
	if (cG == 1) {
		H->emplace(*G), ++C, spec = 0;
		for (i = first[*G]; i; i = next[i])
			btop = 0, make_subtree(e[i].v, *G), H[C++] = heap(buf, buf + btop);
	} else {
		assert(cG == 2), spec = -1;
		btop = 0, make_subtree(*G, G[1]), H[C++] = heap(buf, buf + btop);
		btop = 0, make_subtree(G[1], *G), H[C++] = heap(buf, buf + btop);
	}
	for (i = 0; i < C; ++i) deg[i] = H[i].size() * 2, pb_ds::init(i), global.emplace(H[i].top());
	if (~spec) deg[spec] = -1;
	for (i = 1, j = n; j; ++i, --j) {
		if (pb_ds::maxdeg == j && deg[bel[i]] != j)
			v = pb_ds::any(),
			u = H[v].top(), H[v].pop(), assert(global.erase(u));
		else {
			it = global.begin();
			if (bel[i] != spec && bel[i] == bel[*it]) ++it;
			u = *it, v = bel[u], H[v].pop();
			global.erase(it);
		}
		if (!H[v].empty()) global.emplace(H[v].top());
		pb_ds::decrease(bel[i]), pb_ds::decrease(v);
		cout << u << (i == n ? '\n' : ' ');
	}
	return 0;
}