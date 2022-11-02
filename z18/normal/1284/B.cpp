#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5;
int n, m, a[maxn + 3], k, l[maxn + 3], r[maxn + 3];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &m);
		for (int i = 1; i <= m; i++) {
			scanf("%d", &a[i]);
		}
		bool flag = true;
		for (int i = 1; i < m; i++) {
			flag &= a[i] >= a[i + 1];
		}
		if (flag) {
			l[++k] = a[1], r[k] = a[m];
		}
	}
	sort(l + 1, l + k + 1);
	sort(r + 1, r + k + 1);
	int p = k;
	ll ans = 1ll * n * n;
	for (int i = k; i; i--) {
		while (p && r[p] >= l[i]) {
			p--;
		}
		ans -= k - p;
	}
	printf("%I64d\n", ans);
	return 0;
}