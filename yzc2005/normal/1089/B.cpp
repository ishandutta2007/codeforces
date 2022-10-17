#include <bits/stdc++.h>
using namespace std;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 305;
int n, m, match[N];
vector<int> e[N];
bool vis[N];
int dfs(int u) {
	vis[u] = true;
	shuffle(e[u].begin(), e[u].end(), rnd);
	for (auto v : e[u]) {
		int w = match[v];
		if (vis[w]) {
			continue;
		}
		match[u] = v;
		match[v] = u;
		match[w] = 0;
		if (!w || dfs(w)) return 1;
		match[u] = 0;
		match[v] = w;
		match[w] = v;
	}
	return 0;
}
int solve(int n) {
	vector<int> ord(n);
	iota(ord.begin(), ord.end(), 1);
	int ans = 0; 
	memset(match, 0, sizeof match);
	for (int i = 1; i <= 15; ++i) {
		shuffle(ord.begin(), ord.end(), rnd);
		for (auto x : ord) {
			if (!match[x]) {
				memset(vis, false, sizeof vis);
				ans += dfs(x);
			}
		}
	}
	return ans;
}
void add_edge(int u, int v) {
	e[u].emplace_back(v);
	e[v].emplace_back(u);
}
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= 2 * n + m; ++i) {
		e[i].clear();
	}
	for (int i = 1; i <= n; ++i) {
		int x = i * 2 - 1, y = i * 2;
		add_edge(x, y);
		string s;
		cin >> s;
		for (int j = 1; j <= m; ++j) {
			if (s[j - 1] == '0') continue;
			add_edge(x, 2 * n + j);
			add_edge(y, 2 * n + j);			
		}
	}
	cout << solve(2 * n + m) - n << "\n";
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}