#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 100054, M = N * 2;

int V, E, Es = 0;
int to[M], first[N], next[M];
int p[N], dep[N];
ll W[N];

inline void addedge(int u, int v) {
	to[++Es] = v, next[Es] = first[u], first[u] = Es;
	to[++Es] = u, next[Es] = first[v], first[v] = Es;
}

void dfs(int x) {
	int i, y;
	for (i = first[x]; i; i = next[i])
		if (!~p[y = to[i]]) p[y] = x, dep[y] = dep[x] + 1, dfs(y), W[x] -= W[y];
}

int main() {
	int i, u, v, key = 0; ll c;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> V >> E;
	for (i = 1; i <= V; ++i) cin >> W[i], p[i] = -1;
	for (i = 0; i < E; ++i) cin >> u >> v, addedge(u, v);
	p[1] = 0, dfs(1);
	for (i = 1; i <= Es; i += 2)
		if (u = to[i + 1], v = to[i], !((dep[u] ^ dep[v]) & 1)) {
			assert(!(*W & 1)), c = W[1] / 2;
			if (dep[u] > dep[v]) std::swap(u, v);
			for (; v != u; v = p[v]) dep[v] & 1 ? W[v] += c : W[v] -= c;
			for (; v; v = p[v]) dep[v] & 1 ? W[v] += c * 2 : W[v] -= c * 2;
			if (dep[u] & 1) c = -c;
			key = i; break;
		}
	if (W[1]) return cout << "NO\n", 0;
	cout << "YES\n";
	for (i = 1; i <= Es; i += 2) {
		if (i == key) cout << c;
		else {
			u = to[i + 1], v = to[i];
			if (dep[u] > dep[v]) std::swap(u, v);
			cout << (p[v] == u ? W[v] : 0);
		}
		cout.put('\n');
	}
	return 0;
}