#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 216, forbidden = 0x3f3f3f3f;

namespace Flow {
	#define ad(x) (((x - 1) ^ 1) + 1)

	const int N = 80054, M = N * 4;

	struct edge {
		int u, v, f;
		edge (int u0 = 0, int v0 = 0, int f0 = 0) : u(u0), v(v0), f(f0) {}
	} e[M];

	int V = 2, E = 0, si = 1, ti = 2, flow;
	int first[N], next[M];
	int dep[N], cur[N], que[N];

	inline void addedge(int u, int v, int f) {
		e[++E] = edge(u, v, f), next[E] = first[u], first[u] = E;
		e[++E] = edge(v, u), next[E] = first[v], first[v] = E;
	}

	bool bfs() {
		int h, t = 1, i, x, y;
		memset(dep, -1, sizeof dep);
		que[0] = si, dep[si] = 0;
		for (h = 0; h < t; ++h) {
			if ((x = que[h]) == ti) return true;
			for (i = first[x]; i; i = next[i])
				if (dep[y = e[i].v] == -1 && e[i].f)
					que[t++] = y, dep[y] = dep[x] + 1;
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
				e[i].f -= c, e[ad(i)].f += c;
				if ((f += c) == lim) return f;
			}
		return f;
	}

	int Dinic() {
		for (flow = 0; bfs(); flow += dfs(si, forbidden))
			memcpy(cur, first, sizeof cur);
		return flow;
	}
}

int R, C, RC;
char s[N];

inline void True(int v, int c) {Flow::addedge(v, 2, c);}
inline void False(int v, int c) {Flow::addedge(1, v, c);}
inline void TrueFalse(int u, int v, int c) {Flow::addedge(u, v, c);}
inline void FalseTrue(int u, int v, int c) {Flow::addedge(v, u, c);}

#define h(r, c) ((r) * C + (c) + 3) // normal
#define v(r, c) ((r) * C + (c) + RC + 3) // negate
int main() {
	int i, j;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> R >> C, RC = R * C;
	for (i = 0; i < R; ++i)
		for (cin >> s, j = 0; j < C; ++j) {
			if (s[j] & 1)
				FalseTrue(h(i, j), v(i, j), forbidden),
				TrueFalse(h(i, j), v(i, j), forbidden);
			else
				True(h(i, j), forbidden),
				False(v(i, j), forbidden);
			if (j)
				TrueFalse(h(i, j), h(i, j - 1), 1);
			else
				True(h(i, j), 1);
			if (i)
				FalseTrue(v(i, j), v(i - 1, j), 1);
			else
				False(v(i, j), 1);
		}
	cout << Flow::Dinic() << '\n';
	return 0;
}