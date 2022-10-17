#include <bits/stdc++.h>
using namespace std;
int n, a[105], c[105][105], dp[105];
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) {
		set<int> s;
		int cur = 0;
		for (int j = i; j <= n; ++j) {
			s.insert(a[j]);
			while (s.count(cur))
				++cur;
			c[i][j] = cur + 1;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		memset(dp, 0, sizeof dp);
		dp[i - 1] = 0;
		for (int x = i; x <= n; ++x) {
			for (int y = i; y <= x; ++y)
				dp[x] = max(dp[x], dp[y - 1] + c[y][x]);
			ans += dp[x];
		}
	}
	printf("%d\n", ans);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}