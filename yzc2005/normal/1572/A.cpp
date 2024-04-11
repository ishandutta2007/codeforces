#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, dp[N], in[N], que[N];
vector<int> g[N];
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		g[i].clear();
	for (int i = 1; i <= n; ++i) {
		int k; 
		scanf("%d", &k);
		in[i] = k;
		while (k--) {
			int x; scanf("%d", &x);
			g[x].emplace_back(i);
		}
	}
	int l = 1, r = 0;
	fill(dp + 1, dp + n + 1, 0);
	for (int i = 1; i <= n; ++i)
		if (!in[i]) que[++r] = i;
	while (l <= r) {
		int u = que[l++];
		for (auto v : g[u]) {
			int val = dp[u] + (u > v);
			dp[v] = max(dp[v], val);
			if (!--in[v]) que[++r] = v;
		}
	}
	if (r < n) puts("-1");
	else printf("%d\n", *max_element(dp + 1, dp + n + 1) + 1);
}
int main() {
	int t; scanf("%d", &t);
	while (t--) solve();
	return 0;
}