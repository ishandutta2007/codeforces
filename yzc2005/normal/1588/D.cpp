#include <bits/stdc++.h>
using namespace std;
int get(char x) {
	if (x >= 'a' && x <= 'z') return x - 'a';
	return 26 + x - 'A';
}
char rev(int x) {
	if (x < 26) {
		return 'a' + x;
	} 
	return 'A' + x - 26;
}
const int M = 10, N = 66666;
int n, dp[N], in[N];
vector<pair<int, int>> g[N];
pair<int, int> prv[N];
int ID(int x, int y) {
	return x * (1 << n) + y + 1;
}
void solve() {
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	vector<vector<vector<int>>> nxt(52, vector<vector<int>>(n)), pos(52, vector<vector<int>>(n));
	for (int c = 0; c < 52; ++c) {
		for (int i = 0; i < n; ++i) {
			int m = (int) s[i].length();
			nxt[c][i].resize(m);
			int cur = m;
			for (int j = m - 1; j >= 0; --j) {
				nxt[c][i][j] = cur;
				if (get(s[i][j]) == c) {
					cur = j;
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < s[i].length(); ++j) {
			pos[get(s[i][j])][i].emplace_back(j);
		}
	}
	auto find = [&](int i, int j) {
		int c = get(s[i][j]);
		return (pos[c][i][0] == j) ? 0 : 1;
	};
	memset(dp, 0, sizeof dp);
	memset(in, 0, sizeof in);
	for (int i = 0; i < N; ++i) {
		g[i].clear();
	}
	auto add = [&](int x, int y, int z) {
		g[x].emplace_back(y, z);
		++in[y];
	};
	for (int c = 0; c < 52; ++c) {
		for (int s1 = 0; s1 < 1 << n; ++s1) {
			bool f = true;
			for (int i = 0; i < n; ++i) {
				int r = 1 + (s1 >> i & 1);
				if (r > (int) pos[c][i].size()) {
					f = false;
					break;
				}
			}
			if (!f) {
				continue;
			}
			int u = ID(c, s1);
			add(0, u, c);
			for (int t = 0; t < 52; ++t) {
				int s2 = 0;
				bool f = true;
				for (int i = 0; i < n; ++i) {
					int p = pos[c][i][s1 >> i & 1];
					p = nxt[t][i][p];
					if (p == s[i].length()) {
						f = false;
						break;
					}
					if (find(i, p)) {
						s2 |= 1 << i;
					}
				}
				if (!f) {
					continue;
				}
				int v = ID(t, s2);
				add(u, v, t);
			}
		}
	} 
	queue<int> que;
	que.emplace(0);
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		for (auto p : g[u]) {
			int v = p.first, c = p.second;
			if (dp[v] < dp[u] + 1) {
				dp[v] = dp[u] + 1;
				prv[v] = make_pair(u, c);
			}
			if (!--in[v]) {
				que.emplace(v);
			}
		}
	}
	int u = max_element(dp, dp + N) - dp;
	string ans;
	while (u) {
		ans += rev(prv[u].second);
		u = prv[u].first;
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	cout << ans << "\n";
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}