#include <bits/stdc++.h>
#define N 2005

int n, m, R = 0, C = 0;
int r[N], c[N];
double f[N][N];

int main() {
	int i, j, x, y, z;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; ++i) scanf("%d%d", &x, &y), r[x] = c[y] = 1;
	for (i = 1; i <= n; ++i) R += !r[i], C += !c[i];
	f[1][1] = 0;
	for (i = 0; i <= R; ++i)
		for (j = 0; j <= C; ++j) {
			if (!(i || j)) continue; 
			x = i * j; y = i * (n - j); z = (n - i) * j;
			f[i + 1][j + 1] = (x * f[i][j] + y * f[i][j + 1] + z * f[i + 1][j] + (double)n * n) / (double)(x + y + z);
		}
	printf("%.8lg\n", f[R + 1][C + 1]);
	return 0;
}