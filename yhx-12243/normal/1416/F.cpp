#include <bits/stdc++.h>
#define EB emplace_back
using std::cin;
using std::cout;

typedef std::pair <int, int> pr;
typedef std::vector <int> vector;
const int N = 100054;

namespace Flow {
	#define ad(x) (((x - 1) ^ 1) + 1)

	const int N = ::N, M = N * 6;

	struct edge {
		int u, v, f;
		edge (int u0 = 0, int v0 = 0, int f0 = 0) : u(u0), v(v0), f(f0) {}
	} e[M];

	int V = 2, E = 0, si = 1, ti = 2, flow;
	int first[N], next[M];
	int dep[N], cur[N], que[N];

	inline void init(int n) {for (V = n; E; --E) first[e[E].u] = 0;}

	inline void addedge(int u, int v, int f) {
		e[++E] = edge(u, v, f), next[E] = first[u], first[u] = E;
		e[++E] = edge(v, u), next[E] = first[v], first[v] = E;
	}

	bool bfs() {
		int h, t = 1, i, x, y;
		memset(dep, -1, (V + 1) << 2);
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
		for (flow = 0; bfs(); flow += dfs(si, INT_MAX))
			memcpy(cur, first, (V + 1) << 2);
		return flow;
	}

	inline bool check() {
		for (int i = first[si]; i; i = next[i]) if (~dep[e[i].v]) return false;
		return true;
	}
}

int R, C, n, W;
int a[N], s[N], tag[N];
int U1[N], U2[N]; 
char dir[N];
vector pos[N];

namespace DC {
	int F[N]; pr D[N];

	int Discretize(int n) {
		int i, cnt = 0;
		std::sort(D, D + n);
		for (i = 0; i < n; ++i)
			F[D[i].second] = (i && D[i].first == D[i - 1].first ? cnt - 1 : (D[cnt] = D[i], cnt++));
		return cnt;
	}
}

namespace Graph {
	int V1, V2, E, M;
	bool SL[N], SR[N];
	pr e[N * 2], mat[N];

	inline void init() {V1 = V2 = E = M = 0;}
	inline void addedge(int u, int v) {e[E++] = pr(u, v);}

	bool main() {
		int i, Lx = 0, Rx = 0;
		Flow::init(V1 + V2 + 3);
		for (i = 0; i < E; ++i) Flow::addedge(3 + e[i].first, 3 + V1 + e[i].second, 1);
		for (i = 1; i <= V1; ++i) Lx += SL[i], Flow::addedge(SL[i] ? 1 : 3, 3 + i, 1);
		for (i = 1; i <= V2; ++i) Rx += SR[i], Flow::addedge(3 + V1 + i, SR[i] ? 2 : 3, 1);
		Flow::addedge(1, 3, Rx), Flow::addedge(3, 2, Lx), Flow::Dinic();
		if (!Flow::check()) return false;
		for (i = 0; i < E; ++i) if (!Flow::e[i * 2 + 1].f) mat[M++] = e[i];
		return true;
	}
}

inline void match(int x, int y) {
	if (x > y) std::swap(x, y);
	assert(s[x] == s[y]), a[x] = 1, a[y] = s[y] - 1;
	if (x + C == y) dir[x] = 68, dir[y] = 85;
	else if (x + 1 == y) dir[x] = 82, dir[y] = 76;
	else throw "error";
}

void work() {
	int i, j, r, c, m, u, v;
	cin >> R >> C, n = R * C;
	for (i = 0; i < n; ++i) cin >> s[i], DC::D[i] = pr(s[i], i);
	for (i = 0; i < n; ++i)
		if (i % C && s[i - 1] < s[i]) dir[i] = 76, a[i] = s[i] - s[i - 1];
		else if ((i + 1) % C && s[i + 1] < s[i]) dir[i] = 82, a[i] = s[i] - s[i + 1];
		else if (i >= C && s[i - C] < s[i]) dir[i] = 85, a[i] = s[i] - s[i - C];
		else if (i + C < n && s[i + C] < s[i]) dir[i] = 68, a[i] = s[i] - s[i + C];
		else dir[i] = a[i] = 0;
	W = DC::Discretize(n);
	for (i = 0; i < n; ++i) pos[ DC::F[i] ].EB(i);
	for (i = 0; i < W; ++i) {
		m = pos[i].size(), Graph::init();
		for (j = 0; j < m; ++j) {
			v = pos[i][j], r = v / C, c = v % C;
			if ((r ^ c) & 1)
				U2[ u = ++Graph::V2 ] = v;
			else
				U1[ u = ++Graph::V1 ] = v;
			tag[v] = u;
			if (c && s[v - 1] == s[v])
				(r ^ c) & 1 ? Graph::addedge(tag[v - 1], u) : Graph::addedge(u, tag[v - 1]);
			if (r && s[v - C] == s[v])
				(r ^ c) & 1 ? Graph::addedge(tag[v - C], u) : Graph::addedge(u, tag[v - C]);
			((r ^ c) & 1 ? Graph::SR[u] : Graph::SL[u]) = !dir[v];
		}
		if (!Graph::main()) break;
		for (j = 0; j < Graph::M; ++j)
			std::tie(u, v) = Graph::mat[j], match(U1[u], U2[v]);
		pos[i].clear();
	}
	if (i == W) {
		cout << "YES\n";
		for (i = 0; i < n; ++i)
			cout << a[i] << ((i + 1) % C ? ' ' : '\n');
		for (i = 0; i < n; ++i)
			cout << dir[i] << ((i + 1) % C ? ' ' : '\n');
	} else
		for (cout << "NO\n"; i < W; ++i) pos[i].clear();
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}