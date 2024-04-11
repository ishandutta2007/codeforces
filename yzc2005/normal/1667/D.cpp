#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, fa[N];
vector<int> e[N];
vector<int> ans;
bool mark[N];
int dfs(int u) {
	if (e[u].empty()) return 0;
	vector<int> vec[2];
	for (auto v : e[u]) {
		e[v].erase(find(e[v].begin(), e[v].end(), u));
		fa[v] = u;
		int res = dfs(v);
		if (res == -1) return -1;
		vec[res].emplace_back(v);
	}
	if (u == 1) swap(vec[0], vec[1]);
	e[u].clear();
	int val = vec[0].size() - vec[1].size();
	if (val == 0) {
		for (int i = 0; i < (int) vec[0].size(); ++i) {
			e[u].emplace_back(vec[0][i]);
			e[u].emplace_back(vec[1][i]);
		}
		return 0;
	} else if (val == 1) {
		for (int i = 0; i < (int) vec[1].size(); ++i) {
			e[u].emplace_back(vec[1][i]);
			e[u].emplace_back(vec[0][i]);
		}
		e[u].emplace_back(vec[0].back());
		mark[u] = true;
		return 1;
	} else if (val == -1) {
		for (int i = 0; i < (int) vec[0].size(); ++i) {
			e[u].emplace_back(vec[1][i]);
			e[u].emplace_back(vec[0][i]);
		}
		e[u].emplace_back(vec[1].back());
		return 0;
	} else if (val == 2) {
		for (int i = 0; i < (int) vec[1].size(); ++i) {
			e[u].emplace_back(vec[0][i]);
			e[u].emplace_back(vec[1][i]);
		}
		e[u].emplace_back(vec[0][vec[0].size() - 2]);
		e[u].emplace_back(vec[0].back());
		mark[u] = true;
		return 1;
	} else {
		return -1;
	}
}
void dfs1(int u) {
	if (e[u].empty()) {
		ans.emplace_back(u);
		return;
	}
	int son = e[u].back();
	e[u].pop_back();
	for (auto v : e[u]) 
		dfs1(v);
	if (mark[u]) {
		ans.emplace_back(u);
		dfs1(son);
	} else {
		dfs1(son);
		ans.emplace_back(u);
	}
}
void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		e[i].clear(), mark[i] = false;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	int res = dfs(1);
	if (res) {
		cout << "NO\n";
	} else {
		ans.clear();
		dfs1(1);
		cout << "YES\n";
		for (auto x : ans)
			if (x != 1) cout << x << " " << fa[x] << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}