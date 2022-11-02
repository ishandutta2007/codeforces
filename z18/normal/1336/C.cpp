#include <bits/stdc++.h>
using namespace std;

const int maxn = 3000, mod = 998244353;
int n, m, f[maxn + 3][maxn + 3];
char s[maxn + 3], t[maxn + 3];

bool ok(int i, int j) {
	if (j > m) return true;
	return s[i] == t[j];
}

void mod_add(int &x, int y) {
	x += y, x < mod ? 0 : x -= mod;
}

int main() {
	scanf("%s %s", s + 1, t + 1);
	n = strlen(s + 1), m = strlen(t + 1);
	for (int i = 0; i <= n; i++) {
		f[i][i + 1] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int l = 0, r = k; r <= n + 1; l++, r++) {
			if (r <= n && ok(k, r)) {
				mod_add(f[l][r + 1], f[l][r]);
			}
			if (l && ok(k, l)) {
				mod_add(f[l - 1][r], f[l][r]);
			}
		}
	}
	int ans = 0;
	for (int k = m + 1; k <= n + 1; k++) {
		mod_add(ans, f[0][k]);
	}
	printf("%d\n", ans);
	return 0;
}