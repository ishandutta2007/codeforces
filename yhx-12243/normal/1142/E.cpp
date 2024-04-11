#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;

typedef std::vector <int> vector;
const int N = 100054;

struct edge {
	int u, v;
	edge (int u0 = 0, int v0 = 0) : u(u0), v(v0) {}
} e[N];

int V, E, Es = 0;
int first[N], next[N];
int cnt = 0, id[N], low[N];
int stc = 0, stack[N], top[N];
int deg[N];
bool instack[N], outstd[N];
vector scc[N], cur[N];

inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline void addedge(int u, int v) {e[++Es] = edge(u, v), next[Es] = first[u], first[u] = Es;}

void dfs(int x) {
	int i, y; id[x] = low[x] = ++cnt, instack[x] = true, stack[stc++] = x;
	for (i = first[x]; i; i = next[i])
		if (!id[y = e[i].v])
			dfs(y), down(low[x], low[y]);
		else if (instack[y])
			down(low[x], id[y]);
	if (id[x] == low[x])
		for (y = 0; y != x; y = stack[--stc], instack[y] = false, top[y] = x, scc[x].emplace_back(y));
}

int main() {
	int i, u, v;
	cin >> V >> E;
	for (i = 1; i <= E; ++i) cin >> u >> v, addedge(u, v);
	for (i = 1; i <= V; ++i) if (!id[i]) dfs(i);
	for (i = 1; i <= E; ++i)
		if ((u = top[e[i].u]) != (v = top[e[i].v])) ++deg[v];
	for (i = 1; i <= V; ++i)
		if (top[i] == i && !deg[i]) stack[stc++] = i, cur[i] = scc[i];
	for (; stc > 1; ) {
		int &_u = stack[stc - 1], &_v = stack[stc - 2];
		u = cur[_u].back(), v = cur[_v].back();
		cout << '?' << ' ' << u << ' ' << v << endl;
		if (cin >> i, i) std::swap(u, v), std::swap(_u, _v);
		if (cur[_u].pop_back(), cur[_u].empty()) --stc;
		for (i = first[u]; i; i = next[i])
			if (!--deg[v = top[e[i].v]]) stack[stc++] = v, cur[v] = scc[v];
	}
	cout << '!' << ' ' << cur[*stack].back() << endl;
	return 0;
}