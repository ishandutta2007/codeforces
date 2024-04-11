#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int n, m, x[maxn + 3], y[maxn + 3];

int main() {
	scanf("%d", &n);
	if (n & 1) {
		puts("No");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}
	m = n / 2;
	for (int i = 1; i <= m; i++) {
		int p = i, q = i + m;
		if (x[p] - x[p % n + 1] != x[q % n + 1] - x[q] || y[p] - y[p % n + 1] != y[q % n + 1] - y[q]) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}