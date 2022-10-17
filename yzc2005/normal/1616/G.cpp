#include <bits/stdc++.h>
using namespace std;
int n, m, r[150005], d1[150005], d2[150005];
vector<int> g1[150005], g2[150005];
bool dp[150005][2], mark1[150005], mark2[150005];
void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		g1[i].clear();
		g2[i].clear();
		r[i] = d1[i] = d2[i] = 0;
	}
	vector<pair<int, int>> edges;
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x + 1 == y) {
			r[x] = 1;
		} else {
			edges.emplace_back(x + 1, y);
		}
	}
	r[n] = n;
	for (int i = n - 1; i; --i) {
		r[i] = r[i] ? r[i + 1] : i;
	}
	for (auto p : edges) {
		int x = p.first, y = p.second;
		if (y > r[x] + 1) {
			continue;
		}
		g1[x].emplace_back(y);
		++d1[y];
		g2[y].emplace_back(x);
		++d2[x];
	}
	if (r[1] == n) {
		printf("%lld\n", 1ll * n * (n - 1) / 2);
		return;
	}
	vector<int> st;
	for (int i = 1; i < n; ++i) {
		if (r[i] == i) {
			st.emplace_back(i + 1);
		}
	}
	int s = st[0], t = st.back();
	memset(dp, false, sizeof dp);
	dp[s][0] = true;
	queue<int> que;
	que.emplace(s);
	for (int i = s + 1; i <= n; ++i) {
		if (!d1[i]) {
			que.emplace(i);
		}
	}
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		for (auto v : g1[u]) {
			for (int i = 0; i < 2; ++i) {
				dp[v][i ^ 1] |= dp[u][i];
			}
			if (!--d1[v]) {
				que.emplace(v);
			}
		}
	}
	que.emplace(s);
	for (int i = 1; i < s; ++i) {
		if (!d2[i]) {
			que.emplace(i);
		}
	}
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		for (auto v : g2[u]) {
			for (int i = 0; i < 2; ++i) {
				dp[v][i ^ 1] |= dp[u][i];
			}
			if (!--d2[v]) {
				que.emplace(v);
			}
		}
	}
	long long ans = 0;
	int flag = 0;
	vector<int> v1[4], v2[4];
	for (int i = 1; i <= s; ++i) {
		v1[dp[i][0] + dp[i][1] * 2].emplace_back(i);
	}
	for (int i = t; i <= n; ++i) {
		v2[dp[i][0] + dp[i][1] * 2].emplace_back(i);
	}
	memset(mark1, false, sizeof mark1);
	memset(mark2, false, sizeof mark2);
	for (int i = 1; i < 4; ++i) {
		if (v1[i].empty()) {
			continue;
		}
		for (int j = 1; j < 4; ++j) {
			if (v2[j].empty()) {
				continue;
			}
			bool f[2] = {false, false};
			for (int x = 0; x < 2; ++x) {
				for (int y = 0; y < 2; ++y) {
					f[x ^ y] |= ((i >> x & 1) && (j >> y & 1));
				}
			}
			if (f[0]) {
				flag = 1;
				ans += 1ll * v1[i].size() * v2[j].size();
			}
			if (f[1]) {
				for (auto x : v1[i]) {
					mark1[x] = true;
				}
				for (auto x : v2[j]) {
					mark2[x - 1] = true;
				}
			}
		}
	}
	ans += flag;
	for (int i = 1; i <= n; ++i) {
		ans += mark1[i];
		ans += mark2[i];
	}
	ans -= (s == t);
	printf("%lld\n", ans);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}