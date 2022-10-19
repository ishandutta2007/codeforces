#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, c[N];
vector<int> g[N];
bool f[N];
void dfs1(int u, int fa) {
	f[u] = true;
	for (auto v : g[u]) {
		if (v == fa) continue;
		dfs1(v, u);
		if (!f[v] || (c[u] != c[v]))
			f[u] = false;
	}
}
void dfs2(int u, int fa) {
	int cnt = 0;
	for (auto v : g[u])
		if (v != fa) cnt += !f[v];
	if (cnt == 0) cout << "YES" << "\n" << u << "\n", exit(0);
	if (u > 1 && c[u] != c[fa]) return;
	cnt = 0;
	for (auto v : g[u]) 
		if (v != fa) cnt += (!f[v] || (c[u] != c[v]));
	if (cnt > 1) return;
	for (auto v : g[u]) {
		if (v == fa) continue;
		if (!f[v] || (c[u] != c[v])) dfs2(v, u);
	}
}
int main() {
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}	
	for (int i = 1; i <= n; ++i)
		cin >> c[i];
	dfs1(1, 0);
	dfs2(1, 0);
	cout << "NO" << "\n";
	return 0;
}