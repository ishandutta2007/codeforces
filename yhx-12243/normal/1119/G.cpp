#include <bits/stdc++.h>

const int N = 2000054;

int n, m;
int a[N], b[N], c[N];

int main() {
	int i, j, cnt = 0, sum = 0;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; ++i) scanf("%d", a + i), b[i] = (sum += a[i]) % n;
	printf("%d\n", (sum + n - 1) / n);
	b[m - 1] = n, std::sort(b, b + m), std::adjacent_difference(b, b + m, c);
	for (i = 0; i < m; ++i) printf("%d%c", c[i], i == m - 1 ? 10 : 32);
	for (j = i = 0; i < m; ++i) for (; a[i] > 0; a[i] -= c[j], ++j %= m) b[cnt++] = i;
	for (i = 0; i < cnt || i % m; ++i) printf("%d%c", ++b[i], (i + 1) % m ? 32 : 10);
	return 0;
}