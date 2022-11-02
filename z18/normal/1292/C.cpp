#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3000;
int n, deg[maxn + 3], sz[maxn + 3][maxn + 3], dist[maxn + 3][maxn + 3];
vector<int> G[maxn + 3];
ll dp[maxn + 3][maxn + 3];

void dfs(int sz[], int dist[], int u, int p = 0) {
	sz[u] = 1;
	if (p == 0) {
		dist[u] = 0;
	} else {
		dist[u] = dist[p] + 1;
	}
	for (int i = 0, v; i < G[u].size(); i++) {
		v = G[u][i];
		if (v == p) continue;
		dfs(sz, dist, v, u);
		sz[u] += sz[v];
	}
}

ll solve(int u, int v) {
	if (u > v) {
		swap(u, v);
	}
	if (dp[u][v]) {
		return dp[u][v];
	}
	for (int i = 0, t; i < G[u].size(); i++) {
		t = G[u][i];
		if (dist[u][t] + dist[v][t] == dist[u][v]) continue;
		dp[u][v] = max(dp[u][v], solve(t, v));
	}
	for (int i = 0, t; i < G[v].size(); i++) {
		t = G[v][i];
		if (dist[u][t] + dist[v][t] == dist[u][v]) continue;
		dp[u][v] = max(dp[u][v], solve(t, u));
	}
	dp[u][v] += sz[u][v] * sz[v][u];
	return dp[u][v];
}

int main() {
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d %d", &u, &v);
		G[u].push_back(v), G[v].push_back(u);
		deg[u]++, deg[v]++;
	}
	for (int i = 1; i <= n; i++) {
		dfs(sz[i], dist[i], i);
	}
	for (int i = 1; i <= n; i++) if (deg[i] == 1) {
		for (int j = i + 1; j <= n; j++) if (deg[j] == 1) {
			dp[i][j] = 1;
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0, v; j < G[i].size(); j++) {
			v = G[i][j];
			ans = max(ans, solve(i, v));
		}
	}
	printf("%lld\n", ans);
	return 0;
}