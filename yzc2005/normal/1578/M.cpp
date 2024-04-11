#include <bits/stdc++.h>
using namespace std;
const int N = 4005;
int n, m, a[N];
long long dp[N][N];
int solve(int l, int r) {
	if (l > r) return 0;
	int mid = min_element(a + l, a + r + 1) - a;
	int ls = solve(l, mid - 1);
	int rs = solve(mid + 1, r);
	int s1 = min(m, mid - l), v1 = a[ls] - a[mid];
	int s2 = min(m, r - mid), v2 = a[rs] - a[mid];
	for (int i = 1; i <= s1; ++i)
		dp[ls][i] += 1ll * v1 * i * (m - i);
	for (int i = 1; i <= s2; ++i)
		dp[rs][i] += 1ll * v2 * i * (m - i);
	for (int i = 0; i <= s1; ++i) {
		for (int j = 0; j <= s2 && i + j <= m; ++j) {
			long long val = dp[ls][i] + dp[rs][j];
			dp[mid][i + j] = max(dp[mid][i + j], val);
			dp[mid][i + j + 1] = max(dp[mid][i + j + 1], val);
		}
	} 
	return mid;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int u = solve(1, n);
	printf("%lld\n", dp[u][m]);
	return 0;
}