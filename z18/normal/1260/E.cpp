#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 18, maxm = 1 << maxn;
const ll inf = 1e18;
int n, m, a[maxm + 3];
ll dp[maxn + 3][maxm + 3];

int main() {
	scanf("%d", &n);
	for (m = 0; 1 << m < n; m++);
	int p = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == -1) {
			p = i;
		}
	}
	for (int i = 1; i <= p; i++) {
		a[i] = 0;
	}
	for (int i = p; i < n; i++) {
		a[i] = a[i + 1];
	}
	n--;
	for (int i = 1; i <= n; i++) {
		dp[1][i] = a[i];
	}
	for (int i = 2; i <= m; i++) {
		int x = (1 << i) - 1;
		ll y = inf;
		for (int j = 1; j < x; j++) {
			y = min(y, dp[i - 1][j]);
			dp[i][j] = inf;
		}
		for (int j = x; j <= n; j++) {
			dp[i][j] = y + a[j];
			y = min(y, dp[i - 1][j]);
		}
	}
	printf("%lld\n", dp[m][n]);
	return 0;
}