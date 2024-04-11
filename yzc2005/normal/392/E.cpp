#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int rng(int l, int r) { return rnd() % (r - l + 1) + l; }
inline void up(int &x, int y) { x < y ? x = y : 0; }
const int N = 405, inf = 1e8;
int n, v[N], w[N], pot[N];
int dp[N][N][2], val[N][N], g[N], f[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &v[i]);
	for (int i = 1; i <= n; ++i) 
		scanf("%d", &w[i]);
	memset(val, 0xcf, sizeof val);
	for (int i = 1; i <= n + 1; ++i)
		val[i][i - 1] = 0;
	for (int l = n; l; --l) {
		memset(dp, 0xcf, sizeof dp);
		dp[1][l][0] = 0;
		for (int r = l; r <= n; ++r) {
			for (int mid = l; mid < r; ++mid)
				up(val[l][r], val[l][mid] + val[mid + 1][r]);
			int cnt = 0;
			for (int r1 = r + 1; r1 <= n; ++r1) {
				g[r1] = val[r + 1][r1 - 1];
				if (abs(w[r1] - w[r]) == 1 && g[r1] > -inf) pot[++cnt] = r1;
			}
			for (int len = 1; len <= r - l + 1; ++len) {
				for (int t = 0; t < 2; ++t)
					up(val[l][r], dp[len][r][t] + v[len]);
				int v0 = dp[len][r][0], v1 = max(v0, dp[len][r][1]);
				for (int o = 1; o <= cnt; ++o) {
					int r1 = pot[o];
					if (w[r1] == w[r] + 1) 
						up(dp[len + 1][r1][0], v0 + g[r1]);
					else 
						up(dp[len + 1][r1][1], v1 + g[r1]);
				} 
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j)
			up(f[i], f[j - 1] + val[j][i]);
		up(f[i], f[i - 1]);
	}
	printf("%d\n", f[n]);
	return 0;
}