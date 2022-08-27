#include <bits/stdc++.h>
#define lg2 std::__lg

const int N = 2054, M = 5054;

int n, R;
int a[N], cost[N], profit[M];
int f[N][N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}

int main() {
	int i, j, x, y, r;
	scanf("%d%d", &n, &R);
	for (i = n - 1; i >= 0; --i) scanf("%d", a + i), --a[i];
	for (i = n - 1; i >= 0; --i) scanf("%d", cost + i);
	for (i = 0; i < n + R; ++i) scanf("%d", profit + i);
	R += lg2(n), memset(f, 192, sizeof f);
	for (i = 0; i <= R; ++i) f[i][0] = 0;
	for (i = 0; i < n; ++i) {
		x = a[i];
		for (j = n; j; --j) up(f[x][j], f[x][j - 1] - cost[i] + profit[x]);
		for (r = n, y = x; y < R; ++y, r >>= 1)
			for (j = 0; j <= r; ++j)
				up(f[y + 1][j / 2], f[y][j] + j / 2 * profit[y + 1]);
	}
	printf("%d\n", f[R][0]);
	return 0;
}