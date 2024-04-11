#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 100054, M = 200054;

struct edge {
	int u, v;
	edge (int u0 = 0, int v0 = 0) : u(u0), v(v0) {}
} e[M];

int V, E, root;
int first[N], next[M];
int a[N], cand[N];
int p[N], cov[N], Cov[N];
int cnt = 0, o[N];
int ans[N];
bool instack[N], succ[N];
std::mt19937 gen;

inline int min(const int x, const int y) {return x < y ? x : y;}

inline void addedge(int u, int v, int id) {e[id] = edge(u, v), next[id] = first[u], first[u] = id;}

bool dfs(int x) {
	int i, y; instack[x] = true;
	o[++cnt] = x;
	for (i = first[x]; i; i = next[i])
		if (!p[y = e[i].v]) {
			if (p[y] = x, !dfs(y)) return false;
		} else if (!instack[y]) return false;
	return instack[x] = false, true;
}

bool check(int x) {
	int i; memset(p, 0, (V + 1) << 2), p[x] = -1, cnt = 0;
	if (!dfs(x)) return false;
	for (i = 1; i <= V && p[i]; ++i);
	return i > V;
}

void work() {
	int i, u, v, n;
	cin >> V >> E, memset(first, 0, (V + 1) << 2);
	for (i = 1; i <= E; ++i) cin >> u >> v, addedge(u, v, i);
	std::iota(a, a + V, 1), n = min(V, 54);
	std::sample(a, a + V, cand, n, gen);
	for (i = 0; i < n && !check(cand[i]); ++i);
	if (i == n) {cout << "-1\n"; return;}
	root = cand[i], memset(cov, 0, (V + 1) << 2), memset(Cov, 0, (V + 1) << 2);
	for (i = 1; i <= E; ++i)
		if (u = e[i].u, v = e[i].v, p[v] != u)
			++cov[u], --cov[v], Cov[u] ^= i, Cov[v] ^= i;
	for (i = V; i; --i) v = o[i], cov[p[v]] += cov[v], Cov[p[v]] ^= Cov[v];
	for (i = 1; i <= V; ++i) v = o[i], succ[v] = i == 1 || (cov[v] == 1 && succ[ e[ Cov[v] ].v ]);
	for (n = 0, i = 1; i <= V; ++i) if (succ[i]) ans[n++] = i;
	if (5 * n < V) {cout << "-1\n"; return;}
	for (i = 0; i < n; ++i) cout << ans[i] << (i == n - 1 ? '\n' : ' ');
}

int main() {
	int T; gen.seed((std::random_device())());	
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}