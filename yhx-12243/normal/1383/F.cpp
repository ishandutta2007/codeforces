#include <bits/stdc++.h>
#define popc __builtin_popcount
#define ctz __builtin_ctz
using std::cin;
using std::cout;

const int N = 10054, M = 20054, INF = 0x6666666;

inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline int min(const int x, const int y) {return x < y ? x : y;}

namespace Flow {
	#define ad(x) (((x - 1) ^ 1) + 1)

	struct edge {
		int u, v, f, nxt;
		edge (int u0 = 0, int v0 = 0, int f0 = 0, int next = 0)
			: u(u0), v(v0), f(f0), nxt(next) {}
	} e[M];

	int V = 2, E = 0, si = 1, ti = 2, flow;
	int first[N];
	int dep[N], cur[N], que[N];

	inline void addedge(int u, int v, int f) {
		e[++E] = edge(u, v, f, first[u]), first[u] = E;
		e[++E] = edge(v, u, 0, first[v]), first[v] = E;
	}

	bool bfs() {
		int h, t = 1, i, x, y;
		memset(dep, -1, (V + 1) << 2);
		que[0] = si, dep[si] = 0;
		for (h = 0; h < t; ++h) {
			if ((x = que[h]) == ti) return true;
			for (i = first[x]; i; i = e[i].nxt)
				if (dep[y = e[i].v] == -1 && e[i].f)
					que[t++] = y, dep[y] = dep[x] + 1;
		}
		return false;
	}

	int dfs(int x, int lim) {
		int a, c, f = 0;
		if (x == ti || !lim) return lim;
		for (int &i = cur[x]; i; i = e[i].nxt)
			if (dep[e[i].v] == dep[x] + 1 && e[i].f) {
				a = min(lim - f, e[i].f);
				c = dfs(e[i].v, a);
				e[i].f -= c, e[ad(i)].f += c;
				if ((f += c) == lim) return f;
			}
		return f;
	}

	int Dinic() {
		for (; bfs(); flow += dfs(si, INF))
			memcpy(cur, first, (V + 1) << 2);
		return flow;
	}

	int pre[N], tag[N], stamp = 0;
	int stack[N];

	bool small_flow_bfs() {
		int h, t = 1, x, y, i, j, c, top;
		*que = si, tag[si] = ++stamp;
		for (h = 0; h < t; ++h)
			for (i = first[x = que[h]]; i; i = e[i].nxt) {
				if (tag[y = e[i].v] != stamp && e[i].f) {
					pre[y] = i;
					if (y == ti) {
						c = INT_MAX, top = 0;
						for (j = pre[ti]; ; j = pre[ e[j].u ]) {
							down(c, e[j].f), stack[++top] = j;
							if (e[j].u == si) break;
						}
						for (flow += c; top; --top)
							e[stack[top]].f -= c, e[ad(stack[top])].f += c;
						return true;
					}
					tag[y] = stamp, que[t++] = y;
				}
			}
		return false;
	}

	int small_flow() {
		for (; small_flow_bfs(); );
		return flow;
	}
}

int V, E, K, ALL, q;
int ex[1025], flow[1025], cut[1025];
int f[1025][M];

int main() {
	int i, j, u, v, w, ans, _[10];
	char *_c = new char;
	std::mt19937 gen(time(NULL) + (size_t)_c); delete _c;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> V >> E >> K >> q, ALL = ~(-1 << K);
	Flow::V = V, Flow::si = 1, Flow::ti = V;
	for (i = 0; i < E; ++i) cin >> u >> v >> w, Flow::addedge(u, v, w);
	*flow = Flow::Dinic();
	for (u = 1; u <= 2 * E; ++u) f[0][u] = Flow::e[u].f;
	for (i = 1; i <= ALL; ++i) {
		w = -1;
		for (j = i; j; j &= j - 1)
			if (flow[i & ~(j & -j)] > w) w = flow[i & ~(j & -j)], v = j;
			else if (flow[i & ~(j & -j)] == w && gen() & 1) v = j;
		Flow::flow = w, w = i & ~(v & -v);
		for (u = 1; u <= 2 * E; ++u) Flow::e[u].f = f[w][u];
		Flow::e[2 * ctz(v) + 1].f = 25, flow[i] = Flow::small_flow();
		for (u = 1; u <= 2 * E; ++u) f[i][u] = Flow::e[u].f;
	}
	for (i = 0; i <= ALL; ++i) cut[i ^ ALL] = flow[i];
	for (; q; --q) {
		for (i = 0; i < K; ++i) cin >> _[i];
		for (i = 1; i <= ALL; ++i) ex[i] = ex[i & (i - 1)] + _[ctz(i)];
		for (ans = *cut, i = 1; i <= ALL; ++i) down(ans, ex[i] + cut[i]);
		cout << ans << '\n';
	}
	return 0;
}