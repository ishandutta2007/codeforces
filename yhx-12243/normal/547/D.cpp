#include <bits/stdc++.h>
#define ad(x) ((x - 1 ^ 1) + 1)

typedef std::pair <int, int> pr;
const int N = 400054, M = N * 2;

int V1, V2, E, Es = 0;
int to[M], first[N], next[M], deg[N];
int g_[M];
bool used[M];
char ans[N];

inline void addedge(int u, int v) {
	to[++Es] = v, next[Es] = first[u], first[u] = Es, ++deg[u];
	to[++Es] = u, next[Es] = first[v], first[v] = Es, ++deg[v];
}

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

void dfs(int x) {
	for (int &i = first[x]; i; i = next[i])
		if (!used[i])
			used[ad(i)] = used[i] = true, ans[(i - 1) / 2] = i & 1 ? 98 : 114, dfs(to[i]);
}

int main() {
	int i, j = -1, u, v;
	scanf("%d", &E);
	for (i = 0; i < E; ++i) scanf("%d%d", g_ + i, g_ + (E + i)), DC::D[i] = pr(g_[i], i);
	V1 = DC::Discretize(E);
	for (i = 0; i < E; ++i) g_[i] = DC::F[i], DC::D[i] = pr(g_[E + i], i);
	V2 = DC::Discretize(E);
	for (i = 0; i < E; ++i) u = g_[i], v = DC::F[i], addedge(u, v + V1);
	for (i = 0; i < V1 + V2; ++i) if (deg[i] & 1) ~j ? addedge(j, i), j = -1 : j = i;
	for (i = 0; i < V1 + V2; ++i) dfs(i);
	ans[E] = 0, puts(ans);
	return 0;
}