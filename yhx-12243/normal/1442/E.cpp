#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 200054, M = N * 2;

int n, E = 0;
int to[M], first[N], next[M];
int a[N], b[N], p[N], dep[N];
int D1, D2, ret, diam;

inline void addedge(int u, int v) {
	to[++E] = v, next[E] = first[u], first[u] = E;
	to[++E] = u, next[E] = first[v], first[v] = E;
}

void __builtin_dfs(int x) {
	int i, y;
	if (dep[x] > dep[ret]) ret = x;
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != p[x])
			p[y] = x, b[y] = (a[y] ? a[y] : b[x]),
			dep[y] = dep[x] + (b[x] != b[y]), __builtin_dfs(y);
}

inline int dfs(int x) {return dep[x] = p[x] = 0, b[x] = a[x], __builtin_dfs(ret = x), ret;}

void work() {
	int i, u, v; E = 0;
	cin >> n, memset(first, 0, (n + 1) << 2);
	for (i = 1; i <= n; ++i) cin >> a[i];
	for (i = 1; i < n; ++i) cin >> u >> v, addedge(u, v);
	D1 = dfs(1), D2 = dfs(D1), diam = dep[D2];
	cout << (diam + 3) / 2 << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}