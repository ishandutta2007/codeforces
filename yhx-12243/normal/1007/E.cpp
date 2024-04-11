#include <bits/stdc++.h>

typedef long long ll;
const int N = 254;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

int n, t, K;
int a[N], d[N];
ll A[N], D[N], lim[N];
ll f[N][N][2], g[N][N][2];
// f : last people, g : last train to empty (and not exceed)

inline void down(ll &x, const ll y) {x > y ? x = y : 0;}
inline ll max(const ll x, const ll y) {return x < y ? y : x;}

int main() {
	int i, j, k, r; ll times, time2, rem, need;
	scanf("%d%d%d", &n, &t, &K);
	for (i = 1; i <= n; ++i) scanf("%d%d%lld", a + i, d + i, lim + i);
	++n, a[n] = d[n] = INT_MAX, lim[n] = INF;
	for (i = 1; i <= n; ++i) A[i] = A[i - 1] + a[i], D[i] = D[i - 1] + d[i];
	memset(f, 63, sizeof f), memset(g, 63, sizeof g);
	memset(f, 0, sizeof*f), memset(g, 0, sizeof*g);
	for (i = 1; i <= n; ++i)
		for (j = 0; j <= t; ++j)
			for (k = 0; k < 2; ++k) {
				if ((ll)k * a[i] + (ll)j * d[i] <= lim[i] && f[i - 1][j][k] < INF) {
					down(f[i][j][k], f[i - 1][j][k]), times = (k * A[i - 1] + j * D[i - 1] + K - 1) / K;
					if (times * K <= k * A[i] + j * D[i]) down(g[i][j][k], times);
				}
				for (r = 0; r < j; ++r) if ((times = g[i][r][k]) < INF) {
					rem = k * A[i] + r * D[i] - K * times, assert(rem >= 0);
					need = (max(0, rem + (ll)(j - r) * d[i] - lim[i]) + K - 1) / K;
					if (need * K <= rem && f[i - 1][j - r][0] < INF) {
						down(f[i][j][k], times + need + f[i - 1][j - r][0]);
						time2 = ((j - r) * D[i - 1] + K - 1) / K;
						if (time2 * K <= (j - r) * D[i] + (rem - need * K)) down(g[i][j][k], times + need + time2);
					}
				}
			}
	printf("%lld\n", f[n][t][1]);
	return 0;
}