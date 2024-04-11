#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 200054, M = N * 2;

int n, E;
int a[N], b[N];
ll f[N], g[N];
int to[M], first[N], next[M];

inline ll max(const ll x, const ll y) {return x < y ? y : x;}

inline void addedge(int u, int v) {
	to[++E] = v, next[E] = first[u], first[u] = E;
	to[++E] = u, next[E] = first[v], first[v] = E;
}

void dfs(int x, int px = 0) {
	int i, y; f[x] = g[x] = 0;
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != px)
			dfs(y, x),
			f[x] += max(abs(a[x] - a[y]) + f[y], abs(a[x] - b[y]) + g[y]),
			g[x] += max(abs(b[x] - a[y]) + f[y], abs(b[x] - b[y]) + g[y]);
}

void work() {
	int i, u, v;
	cin >> n, E = 0;
	for (i = 1; i <= n; ++i) cin >> a[i] >> b[i];
	memset(first, 0, (n + 1) << 2);
	for (i = 1; i < n; ++i) cin >> u >> v, addedge(u, v);
	dfs(1);
	cout << max(f[1], g[1]) << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}