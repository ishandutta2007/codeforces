#include <bits/stdc++.h>

const int N = 1054;

int n;
bool ok[N];
double p[N][N], f[N], acc[N], rem[N];

inline int find() {
	int i, v = n;
	for (i = 0; i < n; ++i) if (!ok[i] && f[i] < f[v]) v = i;
	return v;
}

int main() {
	int i, j, x;
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			scanf("%d", &x), p[i][j] = .01 * x;
	memset(f, 127, sizeof f), f[n - 1] = 0.;
	std::fill(acc, acc + n, 1.), std::fill(rem, rem + n, 1.);
	for (; (x = find()) != n; ) {
		ok[x] = true;
		for (i = 0; i < n; ++i) if (!ok[i])
			acc[i] += rem[i] * p[i][x] * f[x],
			rem[i] *= 1. - p[i][x],
			f[i] = acc[i] / (1. - rem[i]);
	}
	printf("%.12lg\n", *f);
	return 0;
}