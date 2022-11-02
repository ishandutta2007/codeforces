#include <bits/stdc++.h>
using namespace std;

const int maxn = 100, mod = 1e9 + 7;
int R, a[4], p[4], b[maxn + 3][maxn + 3][maxn + 3], c[maxn + 3][maxn + 3], res[maxn + 3];

int qpow(int a, int b) {
	int c = 1;
	for (; b; b >>= 1, a = 1ll * a * a % mod) {
		if (b & 1) c = 1ll * a * c % mod;
	}
	return c;
}

bool valid(int x, int y) {
	return (x - R) * (x - R) + (y - R) * (y - R) <= R * R;
}

inline int func(int x) {
	return x < 0 ? -x : x;
}

void add(int a[], int b[], int c) {
	for (int i = 0; i <= R * 2 + 1; i++) {
		a[i] = (a[i] + 1ll * b[i] * c) % mod;
	}
}

void gauss(int a[][maxn + 3], int n) {
	for (int i = 0; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (a[j][i]) {
				swap(a[i], a[j]);
				break;
			}
		}
		int x = qpow(a[i][i], mod - 2);
		for (int j = i + 1; j <= n; j++) {
			int y = 1ll * x * a[j][i] % mod;
			for (int k = i; k <= n + 1; k++) {
				a[j][k] = (a[j][k] + 1ll * a[i][k] * (mod - y)) % mod; 
			}
		}
	}
	for (int i = n; i >= 0; i--) {
		res[i] = 1ll * (mod - a[i][n + 1]) * qpow(a[i][i], mod - 2) % mod;
		for (int j = 0; j < i; j++) {
			a[j][n + 1] = (a[j][n + 1] + 1ll * res[i] * a[j][i]) % mod;
		}
	}
}

int main() {
	scanf("%d %d %d %d %d", &R, &a[0], &a[1], &a[2], &a[3]);
	if (R == 0) return puts("1"), 0;
	int sum = a[0] + a[1] + a[2] + a[3], inv = qpow(sum, mod - 2);
	for (int i = 0; i < 4; i++) {
		p[i] = 1ll * a[i] * inv % mod;
	}
	int ip2 = qpow(p[2], mod - 2);
	for (int i = 0; i <= R * 2 + 1; i++) {
		for (int j = 0; j <= R * 2; j++) {
			bool fl_1 = valid(i - 1, j), fl_2 = valid(i, j);
			if (!fl_1 && fl_2) {
				b[i][j][j] = 1;
			} else if (fl_1) {
				add(b[i][j], b[i - 1][j], 1);
				if (i - 2 >= 0) add(b[i][j], b[i - 2][j], mod - p[0]);
				add(b[i][j], b[i - 1][j - 1], mod - p[1]);
				add(b[i][j], b[i - 1][j + 1], mod - p[3]);
				b[i][j][R * 2 + 1] = func(b[i][j][R * 2 + 1] + mod - 1);
				for (int t = 0; t <= R * 2 + 1; t++) {
					b[i][j][t] = 1ll * b[i][j][t] * ip2 % mod;
				}
				if (!fl_2) {
					add(c[j], b[i][j], 1);
				}
			}
		}
	}
	gauss(c, R * 2);
	res[R * 2 + 1] = 1;
	int ans = 0;
	for (int i = 0; i <= R * 2 + 1; i++) {
		ans = (ans + 1ll * res[i] * b[R][R][i]) % mod;
	}
	printf("%d\n", ans);
	return 0;
}