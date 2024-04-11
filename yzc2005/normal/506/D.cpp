#include <bits/stdc++.h>
using namespace std;
int n, m, q, u[100005], v[100005];
vector<int> g[100005];
int par[100005];
vector<pair<int, int>> e[100005];
int ans[100005];
unordered_map<long long, int> cnt;
int find(int x) {
	if (x == par[x]) return x;
	return par[x] = find(par[x]);
}
bool vis[100005];
vector<int> vec;
void dfs(int u) {
	vis[u] -= true;
	vec.emplace_back(u);
	for (auto v : g[u])
		if (!vis[v]) dfs(v);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		e[c].emplace_back(u, v);
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; ++i) {
		scanf("%d%d", &u[i], &v[i]);
		if (u[i] > v[i]) swap(u[i], v[i]);
	}
	for (int c = 1; c <= m; ++c) {
		if ((int) e[c].size() >= 400) {
			iota(par + 1, par + n + 1, 1);
			for (const auto &p : e[c])
				par[find(p.first)] = find(p.second);
			for (int i = 1; i <= q; ++i) 
				ans[i] += (find(u[i]) == find(v[i]));
		} else {
			set<int> s;
			for (const auto &p : e[c]) {
				s.insert(p.first);
				s.insert(p.second);
				g[p.first].emplace_back(p.second);
				g[p.second].emplace_back(p.first);
			}
			for (auto x : s) {
				if (vis[x]) continue;
				vec.clear(), dfs(x);
				sort(vec.begin(), vec.end());
				int m = vec.size();
				for (int i = 0; i < m; ++i)
					for (int j = i + 1; j < m; ++j)
						++cnt[1ll * vec[i] * n + vec[j]];
			}
			for (auto x : s) {
				g[x].clear();
				vis[x] = false;
			}
		}
	}
	for (int i = 1; i <= q; ++i)
		printf("%d\n", ans[i] + cnt[1ll * u[i] * n + v[i]]);
	return 0;
}