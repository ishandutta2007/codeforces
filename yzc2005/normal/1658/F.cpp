#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, sum[N];
char s[N];
void solve() {
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; ++i)
		sum[i] = sum[i - 1] + (s[i] == '1');
	if (1ll * sum[n] * m % n) {
		puts("-1");
		return;
	}
	int k = 1ll * sum[n] * m / n;
	for (int i = m; i <= n; ++i) {
		if (sum[i] - sum[i - m] == k) {
			printf("1\n%d %d\n", i - m + 1, i);
			return;
		}
	}
	puts("2");
	int l1 = n - n % m - m + 1, r2 = n;
	for (int t = 1; t <= m; ++t) {
		int l2 = r2 - t + 1;
		int r1 = l1 + (m - t) - 1;
		if (sum[r1] - sum[l1 - 1] + sum[r2] - sum[l2 - 1] == k) {
			printf("%d %d\n", l1, r1);
			printf("%d %d\n", l2, r2);
			return;
		}
	}
	assert(false);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}