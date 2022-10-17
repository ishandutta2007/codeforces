#include <bits/stdc++.h>
using namespace std;
int n, par[300005], sg[300005];
vector<int> g[300005];
bool mark[300005];
void dfs(int u) {
	for (auto v : g[u]) {
		if (v == par[u]) continue;
		par[v] = u;
		dfs(v);
		sg[u] ^= sg[v] + 1;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	dfs(1);
	int ans = sg[1];
	putchar(ans ? '1' : '2');
	mark[1] = true;
	for (int u = 2; u <= n; ++u) {
		if (!mark[u]) {
			vector<int> f = {u};
			while (!mark[f.back()])
				f.emplace_back(par[f.back()]);
			ans ^= sg[f.back()];
			for (int i = (int) f.size() - 1; i; --i) {
				int x = f[i], y = f[i - 1];
				mark[y] = true;
				sg[x] ^= sg[y] + 1;
			}
			for (int i = 1; i < (int) f.size(); ++i) {
				int x = f[i], y = f[i - 1];
				sg[x] ^= sg[y] ^ 1;
			}
			ans ^= sg[f.back()];
		}
		putchar(ans ? '1' : '2');
	}
	return 0;
}