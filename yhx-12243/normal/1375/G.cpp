#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 200054, M = N * 2;

int n, E = 0;
int to[M], first[N], next[M];
int cc[2];

inline void addedge(int u, int v) {
	to[++E] = v, next[E] = first[u], first[u] = E;
	to[++E] = u, next[E] = first[v], first[v] = E;
}

void dfs(int x, int px = 0, int d = 0) {
	int i, y; ++cc[d];
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != px)
			dfs(y, x, d ^ 1);
}

int main() {
	int i, u, v;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	for (i = 1; i < n; ++i) cin >> u >> v, addedge(u, v);
	dfs(1);
	cout << std::min(cc[0], cc[1]) - 1 << '\n';
	return 0;
}