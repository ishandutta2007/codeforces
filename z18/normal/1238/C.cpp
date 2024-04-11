#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5;
int T, h, n, a[maxn + 3], m, b[maxn + 3];

int main() {
	scanf("%d", &T);
	while (T --> 0) {
		scanf("%d %d", &h, &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		a[++n] = 0, m = 0;
		for (int l = 1, r = 1; l <= n; l = r + 1, r = l) {
			while (r < n && a[r] == a[r + 1] + 1) r++;
			b[++m] = (r - l + 1) & 1;
		}
		if (m == 1) {
			puts("0");
			continue;
		}
		int ans = b[1] ^ 1;
		for (int i = 2; i < m; i++) {
			ans += b[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}