#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e3, inf = 1e9;
int n, m, l[maxn + 3], s[maxn + 3], c[maxn + 3], dp[maxn + 3][maxn + 3];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &l[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
	for (int i = 1; i <= n + m; i++) scanf("%d", &c[i]);
	memset(dp, 0xc0, sizeof(dp));
	for (int i = 1; i <= n + m; i++) dp[i][0] = 0;
	for (int i = n; i; i--) {
		for (int j = n; j; j--) {
			dp[l[i]][j] = max(dp[l[i]][j], dp[l[i]][j - 1] - s[i] + c[l[i]]);
		}
		int cur = n;
		for (int j = l[i] + 1; j <= n + m; j++) {
			cur >>= 1;
			for (int k = 0; k <= cur; k++) {
				dp[j][k] = max(dp[j][k], max(dp[j - 1][k * 2], dp[j - 1][k * 2 + 1]) + k * c[j]);
			}
		}
	}
	printf("%d\n", dp[n + m][0]);
	return 0;
}