#include <bits/stdc++.h>

const int N = 5054;

int n;
int a[N], f[N][N];
int g7[7], g[100054];

inline void up(int &x, const int y) {x < y ? x = y : 0;}

int main() {
	int i, j, ans = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) scanf("%d", a + i);
	for (i = 0; i <= n; ++i) {
		for (j = 0; j <= n; ++j)
			up(ans, f[i][j] = (i < j ? std::max({g7[a[j] % 7], g[a[j] - 1], g[a[j] + 1], f[0][i]}) + 1 : f[j][i])),
			up(g7[a[j] % 7], f[i][j]),
			up(g[a[j]], f[i][j]);
		for (memset(g7, 0, 28), j = 0; j <= n; ++j) g[a[j]] = 0;
	}
	printf("%d\n", ans);
	return 0;
}