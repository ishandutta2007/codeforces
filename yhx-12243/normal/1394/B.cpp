#include <bits/stdc++.h>
#define EB emplace_back
using std::cin;
using std::cout;
using std::vector;

typedef std::pair <int, int> pr;
typedef unsigned long long u64;
typedef std::pair <u64, u64> PR;
const int N = 200054, M = N * 2;

int V, E, K, ans = 0;
u64 W[N], GL;
vector <pr> G[N];
u64 adj[10][10];

void dfs(int x, u64 S) {
	int i;
	if (x > K) {ans += S == GL; return;}
	for (i = 0; i < x; ++i) dfs(x + 1, S ^ adj[x][i]);
}

int main() {
	int i, j, d, u, v, w;
	std::mt19937_64 gen((std::random_device())());
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> V >> E >> K;
	for (i = 1; i <= E; ++i) cin >> u >> v >> w, G[u].EB(w, v);
	for (i = 1; i <= V; ++i) GL ^= W[i] = gen(), std::sort(G[i].begin(), G[i].end());
	for (i = 1; i <= V; ++i)
		for (d = G[i].size(), j = 0; j < d; ++j)
			adj[d][j] ^= W[ G[i][j].second ];
	dfs(1, 0);
	cout << ans << '\n';
	return 0;
}