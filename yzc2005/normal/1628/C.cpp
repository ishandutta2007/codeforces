#include <bits/stdc++.h>
using namespace std;
int n, a[1005][1005], b[1005][1005];
void solve() {
	scanf("%d", &n);
	memset(b, 0, sizeof b);
	for (int j = 1; j < n; ++j)
		b[1][j] = 1;
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int sum = b[i - 1][j] ^ b[i][j - 1] ^ b[i][j + 1];
			b[i + 1][j] = !sum;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &a[i][j]);
			if (b[i][j]) ans ^= a[i][j];
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