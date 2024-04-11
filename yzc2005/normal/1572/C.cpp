#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
int n, a[N], dp[N][N];
vector<int> toR[N], toL[N];
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) {
		toR[i].clear(), toL[i].clear();
		for (int j = i + 1; j <= n; ++j)
			if (a[j] == a[i]) toR[i].emplace_back(j);
		for (int j = i - 1; j; --j)
			if (a[j] == a[i]) toL[i].emplace_back(j);
	}
	for (int len = 2; len <= n; ++len) {
		for (int i = 1, j = len; j <= n; ++i, ++j) {
			dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]) + (a[i] == a[j]);
			for (auto k : toR[i])
				if (k > j) break;
				else dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]);
			for (auto k : toL[j])
				if (k < i) break;
				else dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]);	
		}
	}
	printf("%d\n", n - 1 - dp[1][n]);
}
int main() {
	int t; 
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}