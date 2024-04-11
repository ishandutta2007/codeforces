#include <bits/stdc++.h>
#define EB emplace_back
using std::cin;
using std::cout;
using std::vector;

typedef long long ll;
typedef std::pair <ll, int> pr;
const int N = 300054, M = N * 2;

struct edge {
	int u, v, w;
	edge (int u0 = 0, int v0 = 0, int w0 = 0) : u(u0), v(v0), w(w0) {}
} e[M];

int V, E, Es, C;
int first[N], next[M];
int a[N];
int len = 0, ans[N];
vector <pr> S[N];

namespace dsu {
	int p[N];

	void init(int n) {std::iota(p, p + (n + 1), 0);}

	int ancestor(int x) {return p[x] == x ? x : (p[x] = ancestor(p[x]));}

	inline bool test(int x, int y, bool un = false) {
		if ((x = ancestor(x)) == (y = ancestor(y))) return true;
		return un && (p[x] = y, false);
	}
}

inline void addedge(int u, int v, int w) {
	e[++Es] = edge(u, v, w), next[Es] = first[u], first[u] = Es,
	e[++Es] = edge(v, u, w), next[Es] = first[v], first[v] = Es;
}

void merge(vector <pr> &A, vector <pr> &B) {
	if (A.size() < B.size()) A.swap(B);
	A.insert(A.end(), B.begin(), B.end()), B.clear(), B.shrink_to_fit();
}

void dfs(int x, int px, int id) {
	int i, y; ll cur = a[x];
	for (i = first[x]; i; i = next[i])
		if ((y = e[i].v) != px) {
			dfs(y, x, e[i].w);
			for (; !S[y].empty() && cur + S[y].back().first >= -C; )
				cur += S[y].back().first, ans[len++] = S[y].back().second, S[y].pop_back();
			merge(S[x], S[y]);
		}
	if (x != 1) S[x].EB(cur, id);
	fprintf(stderr, "%d => %lld\n", x, cur);
}

int main() {
	int i, u, v; ll s = 0;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> V >> E >> C;
	for (i = 1; i <= V; ++i) cin >> a[i], s += a[i] -= C;
	if (s < -C) return cout << "NO\n", 0;
	dsu::init(V);
	for (i = 0; i < E; ++i) {
		cin >> u >> v;
		if (!dsu::test(u, v, true)) addedge(u, v, i + 1);
	}
	dfs(1, 0, 0);
	for (; !S[1].empty(); ) ans[len++] = S[1].back().second, S[1].pop_back();
	assert(len == V - 1), assert(S[1].empty());
	cout << "YES\n";
	for (i = 0; i < len; ++i) cout << ans[i] << '\n';
	return 0;
}