#include <bits/stdc++.h>
#define EB emplace_back

typedef long long ll;
typedef std::vector <int> vector;
const int N = 300054, M = N * 2;

struct chain {
	int d, u, w;
	chain * read() {return scanf("%d%d%d", &d, &u, &w), this;}
	inline bool operator < (const chain &B) const {return w > B.w;}
} c[N];

typedef std::priority_queue <chain> heap;

int n, C, E = 0;
int to[M], first[N], next[M];
int dep[N], offset[N];
ll ans = 0;
vector cs[N];
heap pq[N];

inline void addedge(int u, int v) {
	to[++E] = v, next[E] = first[u], first[u] = E;
	to[++E] = u, next[E] = first[v], first[v] = E; 
}

inline void merge(int x, int y) {
	for (chain t; !pq[y].empty(); pq[y].pop())
		t = pq[y].top(), t.w += offset[y] - offset[x], pq[x].push(t);
}

inline bool dfs(int x, int px = 0) {
	int i, y, w; chain t;
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != px) {
			if (dep[y] = dep[x] + 1, !dfs(y, x)) return false;
			if (pq[x].size() < pq[y].size()) pq[x].swap(pq[y]), std::swap(offset[x], offset[y]);
			merge(x, y);
		}
	for (int id : cs[x]) t = c[id], t.w -= offset[x], pq[x].push(t);
	for (; !pq[x].empty() && dep[pq[x].top().u] >= dep[x]; pq[x].pop());
	if (pq[x].empty()) return false;
	return ans += w = pq[x].top().w + offset[x], offset[x] -= w, true;
}

int main() {
	int i, u, v;
	scanf("%d%d", &n, &C);
	for (i = 1; i < n; ++i) scanf("%d%d", &u, &v), addedge(u, v);
	for (i = 0; i < C; ++i) cs[c[i].read()->d].EB(i);
	for (i = first[1]; i; i = next[i])
		if (v = to[i], dep[v] = 1, !dfs(v, 1)) return puts("-1"), 0;
	printf("%lld\n", ans);
	return 0;
}