#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e3, mod = 1e9 + 7;
int n, m, a[maxn + 3][maxn + 3], c_r[maxn + 3][maxn + 3], c_d[maxn + 3][maxn + 3], f[maxn + 3][maxn + 3], g[maxn + 3][maxn + 3];
char s[maxn + 3];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		for (int j = 1; j <= m; j++) {
			a[i][j] = s[j] == 'R';
		}
	}
	if (n == 1 && m == 1) {
		puts("1");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			c_r[i][j] = c_d[i][j] = a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = m; j > 1; j--) {
			c_r[i][j - 1] += c_r[i][j];
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = n; j > 1; j--) {
			c_d[j - 1][i] += c_d[j][i];
		}
	}
	f[1][1] = g[1][1] = 1;
	f[2][1] = g[1][2] = mod - 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1, t; j <= m; j++) {
			f[i][j] = (f[i][j] + f[i - 1][j]) % mod;
			g[i][j] = (g[i][j] + g[i][j - 1]) % mod;
			t = m - c_r[i][j + 1];
			g[i][j + 1] = (g[i][j + 1] + f[i][j]) % mod;
			g[i][t + 1] = (g[i][t + 1] + mod - f[i][j]) % mod;
			t = n - c_d[i + 1][j];
			f[i + 1][j] = (f[i + 1][j] + g[i][j]) % mod;
			f[t + 1][j] = (f[t + 1][j] + mod - g[i][j]) % mod;
		}
	}
	printf("%d\n", (f[n][m] + g[n][m]) % mod);
	return 0;
}