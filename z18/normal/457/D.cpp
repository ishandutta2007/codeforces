#include <bits/stdc++.h>
using namespace std;

typedef double db;
const int maxn = 1e5, maxm = 300;
int n, m, k;
db a[maxn + 3], b[maxm + 3][maxm + 3];

int main() {
	scanf("%d %d %d", &n, &m, &k);
	a[0] = 1;
	for (int i = 0; i < n * n; i++) {
		a[i + 1] = a[i] * (k - i) / (m - i);
	}
	for (int i = 0; i <= n; i++) {
		b[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			b[i][j] = b[i - 1][j - 1] + b[i - 1][j];
		}
	}
	db ans = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			int t = (i + j) * n - i * j;
			if (k >= t) {
				ans += b[n][i] * b[n][j] * a[t];
			}
		}
	}
	ans = min(ans, 1e99);
	printf("%.10lf\n", ans);
	return 0;
}