#include <bits/stdc++.h>

typedef long long ll;

const int kN = 45;

ll f[kN][kN];

int main() {
	int n, h; scanf("%d%d", &n, &h);
	for(int i = 1; i <= n; ++i) f[1][i] = f[0][i] = 1;
	for(int i = 2; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			for(int k = 0; k < i; ++k) {
				f[i][j] += f[k][j - 1] * f[i - k - 1][j - 1];
			}
	printf("%lld", f[n][n] - f[n][h - 1]);
	return 0;
}