#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int N = 1005;
int n, a[N], match[N];
vector<int> e[N * N];
bool vis[N * N];

bool dfs(int u) {
	if (vis[u]) return 0;
	vis[u] = 1;
	for (auto v : e[u]) {
		if (match[v] == -1 || dfs(match[v])) {
			match[v] = u;
			return 1;
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> n;
	vector<i64> all;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		for (int j = 1; j <= n; ++j) all.emplace_back(1ll * a[i] * j);
	}
	sort(all.begin(), all.end()), all.erase(unique(all.begin(), all.end()), all.end());
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			e[lower_bound(all.begin(), all.end(), 1ll * a[i] * j) - all.begin()].emplace_back(i);
		}
	}

	memset(match, -1, sizeof match);
	i64 ans = 0;
	for (int i = 0; i < (int) all.size(); ++i) {
		if (dfs(i)) {
			ans += all[i];
			memset(vis, false, sizeof vis);
		}
	}

	cout << ans << "\n";

	return 0;
}