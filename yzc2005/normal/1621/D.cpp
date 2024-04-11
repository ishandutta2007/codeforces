#include <bits/stdc++.h>
using namespace std;
int n, c[505][505];
void solve() {
	scanf("%d", &n);
	long long ans = 0;
	for (int i = 1; i <= 2 * n; ++i) {
		for (int j = 1; j <= 2 * n; ++j) {
			scanf("%d", &c[i][j]);
			if (i > n && j > n) {
				ans += c[i][j];
			}
		}
	}
	ans += min(min(min(c[n + 1][n], c[2 * n][n]), min(c[n][n + 1], c[n][2 * n])), min(min(c[n + 1][1], c[2 * n][1]), min(c[1][n + 1], c[1][2 * n])));
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