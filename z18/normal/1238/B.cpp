#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1e5;
int T, n, m, a[maxn + 3], b[maxn + 3];

int main() {
	scanf("%d", &T);
	while (T --> 0) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a + 1, a + n + 1);
		b[n + 1] = 0, b[n] = 1;
		for (int i = n - 1; i > 0; i--) {
			b[i] = b[i + 1] + (a[i] != a[i + 1]);
		}
		int ans = n;
		for (int i = 0; i <= n; i++) {
			ans = min(ans, max(b[i + 1], (a[i] + m - 1) / m));
		}
		printf("%d\n", ans);
	}
	return 0;
}