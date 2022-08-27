#include <bits/stdc++.h>

const int N = 300054;

int n;
int a[N], f[N];
bool z[N];

int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%d", a + i);
	*f = -1, f[1] = j = 0;
	for (i = 1; i < n; f[++i] = ++j)
		for (; ~j && a[j] != a[i]; j = f[j]);
	for (j = n; j; j = f[j]) z[j] = true;
	for (j = 1; j <= n && z[j]; ++j);
	printf("%d\n", n - j);
	return 0;
}