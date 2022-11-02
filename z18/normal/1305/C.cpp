#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 2e5;
int n, m, a[maxn + 3], cnt[maxn + 3];
 
int qpow(int a, int b) {
	int c = 1;
	for (; b; b >>= 1, a = a * a % m) {
		if (b & 1) c = a * c % m;
	}
	return c;
}
 
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		if (cnt[a[i] % m]) {
			puts("0"); return 0;
		}
		for (int j = 0; j < m; j++) {
			ans = ans * qpow((a[i] - j + m) % m, cnt[j]) % m;
		}
		cnt[a[i] % m]++;
	}
	printf("%d\n", ans);
	return 0;
}