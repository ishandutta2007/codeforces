#include <bits/stdc++.h>

const int N = 5054;

int n, m;
int a[N];

int main() {
	int i, j, s = 0, remain;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; ++i)
		if (s + i / 2 <= m) a[i] = i + 1, s += i / 2;
		else if (remain = m - s) {a[i] = a[i - 1] + a[i - 2 * remain], s = m; break;}
		else {--i; break;}
	if (s < m) return puts("-1"), 0;
	a[n] = 1000000000;
	for (j = n - 1; j > i; --j) a[j] = a[j + 1] - 12243;
	for (i = 0; i < n; ++i) printf("%d%c", a[i], i == n - 1 ? 10 : 32);
	return 0;
}