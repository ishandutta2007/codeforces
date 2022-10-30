#include <bits/stdc++.h>
using namespace std;

const int maxn = 700, mod = 1e9 + 7;
int n, f[maxn + 3][maxn + 3][2];
char s[maxn + 3];

void mod_add(int &x, int y) {
	x += y, x < mod ? 0 : x -= mod;
}

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	reverse(s + 1, s + n + 1);
	int res = 0;
	for (int i = 1; i <= 9; i++) {
		memset(f, 0, sizeof(f));
		f[0][0][1] = 1;
		for (int j = 1; j <= n; j++) {
			int x = s[j] - '0';
			for (int k = 0; k < j; k++) {
				for (int t = 0; t < 2; t++) {
					for (int y = 0; y < 10; y++) {
						mod_add(f[j][k + (y >= i)][(y < x || (y == x && t))], f[j - 1][k][t]);
					}
				}
			}
		}
		int cur = 1, sum = 0;
		for (int j = 1; j <= n; j++) {
			mod_add(sum, cur);
			res = (res + 1ll * sum * f[n][j][1]) % mod;
			cur = 10ll * cur % mod;
		}
	}
	printf("%d\n", res);
	return 0;
}