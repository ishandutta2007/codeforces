#include <bits/stdc++.h>
#define EB emplace_back

typedef std::pair <int, int> pr;
const int N = 1054, M = N * 2;

int n, E = 0, G, Gm = INT_MAX;
int to[M], first[N], next[M];
int p[N], size[N];
int cnt = 0, nb[N];
int du[N];
std::priority_queue <pr, std::vector <pr>, std::greater <pr>> pq;

inline void up(int &x, const int y) {x < y ? x = y : 0;}

inline void addedge(int u, int v) {
	to[++E] = v, next[E] = first[u], first[u] = E;
	to[++E] = u, next[E] = first[v], first[v] = E;
}

void centr(int x, int px = 0) {
	int i, y, max = 0; size[x] = 1;
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != px)
			centr(y, x), up(max, size[y]), size[x] += size[y];
	if (up(max, n - size[x]), max <= Gm) Gm = max, G = x;
}

void dfs(int x) {
	int i, y; size[x] = 1;
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != p[x])
			p[y] = x, dfs(y), size[x] += size[y];
}

namespace dsu {
	int p[N];

	int ancestor(int x) {return p[x] == x ? x : (p[x] = ancestor(p[x]));}

	inline bool test(int x, int y, bool un = false) {
		if ((x = ancestor(x)) == (y = ancestor(y))) return true;
		return un && (p[x] = y, false);
	}
}

namespace assigner {
	int current, step;

	inline void reset(int step_) {current = 0, step = step_;}
	inline int next() {return current += step;}

	void work(int x) {
		int i, y; du[x] = next();
		for (i = first[x]; i; i = ::next[i])
			if (p[y = to[i]] == x) work(y);
		du[x] -= du[p[x]];
	}
}

int main() {
	int i, u, v, Su, Sv;
	scanf("%d", &n);
	for (i = 1; i < n; ++i) scanf("%d%d", &u, &v), addedge(u, v);
	centr(1), dfs(G);
	for (i = first[G]; i; i = next[i]) nb[cnt++] = v = to[i], pq.emplace(size[v], dsu::p[v] = v);
	for (; pq.size() > 2; )
		std::tie(Su, u) = pq.top(), pq.pop(),
		std::tie(Sv, v) = pq.top(), pq.pop(),
		dsu::test(u, v, true), pq.emplace(Su + Sv, v);
	assigner::reset(1);
	for (i = 0; i < cnt; ++i) if (dsu::test(*nb, nb[i])) assigner::work(nb[i]);
	assigner::reset(assigner::next());
	for (i = 0; i < cnt; ++i) if (!dsu::test(*nb, nb[i])) assigner::work(nb[i]);
	for (i = 1; i <= n; ++i) if (i != G) printf("%d %d %d\n", i, p[i], du[i]);
	return 0;
}