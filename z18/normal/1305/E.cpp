#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000, inf = 1e9;
int n, m, a[maxn + 3], res[maxn + 3];

int main() {
	for (int i = 1; i <= maxn; i++) {
		a[i] = a[i - 1] + (i - 1) / 2;
	}
	scanf("%d %d", &n, &m);
	if (m > a[n]) {
		puts("-1");
		return 0;
	}
	int p = 0;
	for (int i = n; i; i--) {
		if (m >= a[i]) {
			p = i;
			break;
		}
	}
	m -= a[p];
	if (!m) {
		for (int i = 1; i <= p; i++) printf("%d ", i);
		for (int i = n - p; i; i--) printf("%d ", inf - i * 20000);
		return 0;
	}
	for (int i = p + 1; i <= p + p - 1; i++) {
		int c = 0;
		for (int j = 1; j <= p; j++) if (i - j > j && i - j <= p) c++;
		if (c == m) {
			for (int i = 1; i <= p; i++) printf("%d ", i);
			printf("%d ", i), p++;
			for (int i = n - p; i; i--) printf("%d ", inf - i * 20000);
			return 0;
		}
	}
	puts("-1");
	return 0;
}