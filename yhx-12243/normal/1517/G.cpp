#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;

namespace Flow {
	#define ad(x) (((x - 1) ^ 1) + 1)

	const int N = 2054, M = 10054;

	struct edge {
		int u, v; ll f;
		edge (int u0 = 0, int v0 = 0, ll f0 = 0) : u(u0), v(v0), f(f0) {}
	} e[M];

	int V = 2, E = 0, si = 1, ti = 2;
	ll flow;
	int first[N], next[M];
	int dep[N], cur[N], que[N];

	inline void addedge(int u, int v, ll f) {
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

	ll dfs(int x, int lim) {
		ll a, c, f = 0;
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

	ll Dinic() {
		for (flow = 0; bfs(); flow += dfs(si, INT_MAX))
			memcpy(cur, first, sizeof cur);
		return flow;
	}
}

typedef std::pair <int, int> pr;
typedef std::map <pr, int> map;
const int N = 1054;

int n;
map A;

inline void connect(int id, int x, int y) {
	map::iterator it = A.find(pr(x, y));
	if (it != A.end()) Flow::addedge(id + n, it->second, LLONG_MAX);
}

int main() {
	int i, x, y, w; pr t; ll sum = 0;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n;
	for (i = 0; i < n; ++i) {
		cin >> x >> y >> w, sum += w,
		A.emplace(pr(x, y), i + 3), Flow::addedge(i + 3, i + 3 + n, w);
		switch ((x & 1) | (y & 1) << 1) {
			case 1: Flow::addedge(1, i + 3, LLONG_MAX); break;
			case 3: Flow::addedge(i + 3 + n, 2, LLONG_MAX); break;
		}
	}
	for (const auto &e : A) {
		std::tie(t, i) = e, std::tie(x, y) = t;
		switch ((x & 1) | (y & 1) << 1) {
			case 0: connect(i, x, y - 1), connect(i, x, y + 1); break;
			case 1 ... 2: connect(i, x - 1, y), connect(i, x + 1, y); break;
		}
	}
	cout << sum - Flow::Dinic() << '\n';
	return 0;
}