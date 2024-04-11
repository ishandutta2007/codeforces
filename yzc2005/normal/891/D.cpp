#include <bits/stdc++.h>
using namespace std;
using pr = pair<int, int>;
const int N = 5e5 + 5;
int n, siz[N], cnt[N];
vector<int> e[N];
pr dp[N];
long long ans;
inline void operator+=(pr &a, const pr &b) {
	if (a.first > b.first) return;
	if (a.first < b.first) a = b;
	else a.second += b.second;
}
void dfs1(int u) {
	siz[u] = 1;
	for (auto v : e[u]) {
		e[v].erase(find(e[v].begin(), e[v].end(), u));
		dfs1(v);
		siz[u] += siz[v];
		cnt[u] += cnt[v];
		dp[u] += dp[v];
	}
	dp[u] += pr(0, 1);
	dp[u].first += (siz[u] & 1) ? 1 : -1;
	cnt[u] += (siz[u] % 2 == 0);
}
void dfs2(int u, int offset, pr cur, int val) {
	int sum = 0, m = e[u].size();
	for (auto v : e[u]) 
		sum += cnt[v];
	vector<pr> pre(m + 2), suf(m + 2);
	pre[0] = suf[m + 1] = pr(0, 0);
	for (int i = 1; i <= m; ++i)
		pre[i] = pre[i - 1], pre[i] += dp[e[u][i - 1]]; 
	for (int i = m; i; --i)
		suf[i] = suf[i + 1], suf[i] += dp[e[u][i - 1]];
	for (int i = 1; i <= m; ++i) {
		int v = e[u][i - 1];
		int new_offset = offset + sum - cnt[v];
		pr nxt = cur;
		pre[i - 1].first += val;
		suf[i + 1].first += val;
		nxt += pre[i - 1];
		nxt += suf[i + 1];
		if (siz[v] & 1) {
			int rest = n / 2 - cnt[v] - new_offset - nxt.first;
			assert(dp[v].first <= rest);
			if (dp[v].first == rest) ans += 1ll * nxt.second * dp[v].second;
		} else {
			if (cnt[1] == n / 2) ans += 1ll * siz[v] * (n - siz[v]);
		}
		new_offset += (siz[v] & 1);
		int new_val = val + ((siz[v] & 1) ? -1 : 1);
		nxt += {new_val, 1};
		dfs2(v, new_offset, nxt, new_val);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	if (n & 1) {
		puts("0");
		return 0;
	}
	dfs1(1);
	dfs2(1, 0, {0, 1}, 0);
	printf("%lld\n", ans);
	return 0;
}