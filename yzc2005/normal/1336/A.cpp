#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n, k, dep[N], sz[N], id[N];
long long ans;
vector<int> g[N];

void dfs(int u, int fa) {
	sz[u] = 1;
	for(int v : g[u]) {
		if(v == fa) continue;
		dep[v] = dep[u] + 1;
		dfs(v, u);
		sz[u] += sz[v];
	}
}

inline bool cmp(int &u, int &v) {
	return dep[u] - sz[u] > dep[v] - sz[v];
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
	for(int i = 1; i <= n; ++i) id[i] = i;
	sort(id + 1, id + n + 1, cmp);
	for(int i = 1; i <= k; ++i) ans += dep[id[i]] + 1 - sz[id[i]];
	cout << ans;
}