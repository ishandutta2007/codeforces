#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, B = 505, L = N / B + 5;
int n, a[N], pot[N * B], cnt[N], val[N];
pair<int, int> dp[N][L];
int solve() {
	int ans = 0;
	for (int x = 0; x < B; ++x) {
		for (int i = 1; i <= n; ++i)
			ans = max(ans, ++pot[a[i] + i * x]);
		for (int i = 1; i <= n; ++i)
			pot[a[i] + i * x] = 0;
	}
	memset(cnt, 0, sizeof cnt);
	for (int i = 1; i < N; ++i)
		val[i] = 1;
	for (int i = 1; i <= n; ++i) {
		int lim = min(n, i + L);
		for (int j = 0; j < cnt[i]; ++j)
			val[dp[i][j].first] = dp[i][j].second, ans = max(ans, dp[i][j].second);
		for (int j = i + 1; j <= lim; ++j) {
			if (a[i] < a[j] || (a[i] - a[j]) % (j - i)) continue;
			int x = (a[i] - a[j]) / (j - i);
			dp[j][cnt[j]++] = make_pair(x, val[x] + 1);
		}
		for (int j = 0; j < cnt[i]; ++j)
			val[dp[i][j].first] = 1;
	}
	return ans;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int ans = solve();
	reverse(a + 1, a + n + 1);
	ans = max(ans, solve());
	printf("%d\n", n - ans);
	return 0;
}