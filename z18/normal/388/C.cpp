#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;
int n, m, a[maxn + 3], k, b[maxn + 3], sum, num;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &m);
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[j]);
			sum += a[j];
			if (j * 2 <= m) {
				num += a[j];
			}
		}
		if (m & 1) {
			b[++k] = a[(m + 1) >> 1];
		}
	}
	sort(b + 1, b + k + 1);
	reverse(b + 1, b + k + 1);
	for (int i = 1; i <= k; i += 2) {
		num += b[i];
	}
	printf("%d %d\n", num, sum - num);
	return 0;
}