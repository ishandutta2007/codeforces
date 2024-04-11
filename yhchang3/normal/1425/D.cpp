#include <bits/stdc++.h>

using namespace std;

const int mod = (int )1e9 + 7;

int c[2005][2005];
int x[2005], y[2006], b[2006];
int ans = 0;
int n, m, R;
int cnt[2005];
bitset<2005> bit[2005];
int C(int x, int y) {
	if (x < y) return 0;
	return c[x][y];
}
int main( ) {
	scanf("%d %d %d", &n, &m, &R);
	for (int i = 0; i <= n; i ++) c[i][0] = 1;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
	for (int i = 1; i <= n; i ++) {
		scanf("%d %d %d", &x[i], &y[i], &b[i]);
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++)
			if (max(abs(x[i] - x[j]), abs(y[i] - y[j])) <= R) {
				++ cnt[j];
				bit[j - 1][i - 1] = true;
			}
	}
	for (int i = 1; i <= n; i ++) {
		ans += 1LL * b[i] * b[i] % mod * (0LL + 
				C(n, m) - C(n - cnt[i], m) + mod) % mod;
		ans %= mod;
	}
	for (int i = 1; i <= n; i ++) 
		for (int j = 1; j <= n; j ++) {
			if (i == j) continue;
			int same = (bit[i - 1] & bit[j - 1]).count();
			int diffx = cnt[i] + cnt[j] - same;
			int diff = 0;

			int tmp = C(n, m);
			tmp = (tmp - C(n - cnt[i], m) + mod) % mod;
			tmp = (tmp - C(n - cnt[j], m) + mod) % mod;
			tmp = (tmp + C(n - diffx, m)) % mod;

			//int allsame = (C(n, m) - C(n - same, m) + mod) % mod;
			
			//	diff = 1LL * (cnt[i] - same) * (cnt[j] - same) * 
			//	(C(n - same, m - 2)) % mod;
			ans += 1LL * b[i] * b[j] % mod * tmp % mod;
			ans %= mod;
		}
					
	printf("%d\n", ans);
	return 0;
}