#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= int(b); i++)
#define per(i, a, b) for (int i = (a); i >= int(b); i--)
#define fir first
#define sec second
#define tct template<class type>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int maxn = 1e6;
int n, r1, r2, r3, d, a[maxn + 5];
ll p[maxn + 5], q[maxn + 5], f[maxn + 5][3], g[maxn + 5];

tct inline void cmax(type &x, type y) { x < y ? x = y : 0; }
tct inline void cmin(type &x, type y) { x > y ? x = y : 0; }

int main() {
	scanf("%d %d %d %d %d", &n, &r1, &r2, &r3, &d);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		p[i] = 1ll * r1 * a[i] + r3;
		q[i] = min(1ll * r1 * (a[i] + 1), 1ll * r2) + r1;
	}
	f[0][1] = f[0][2] = 1e18;
	rep(i, 1, n) {
		rep(j, 0, 2) f[i][j] = 1e18;
		rep(j, 0, 2) cmin(f[i][0], f[i - 1][j] + p[i]);
		cmin(f[i][1], min(f[i - 1][0], f[i - 1][2]) + q[i] + 2 * d);
		cmin(f[i][2], f[i - 1][1] + q[i]);
	}
	ll ans = 1e18;
	rep(i, 0, 2) cmin(ans, f[n][i]);
	per(i, n - 1, 1) g[i - 1] = g[i] + min(p[i], q[i]);
	rep(i, 0, n - 1) {
		ll mn = 1e18;
		rep(j, 0, 2) cmin(mn, f[i][j]);
		cmin(ans, mn + g[i] + p[n] + 1ll * (n - 1 - i) * d);
		cmin(ans, mn + g[i] + q[n] + 1ll * (i == n - 2 ? 2 : n + 1 - i) * d);
	}
	printf("%lld\n", ans + 1ll * (n - 1) * d);
	return 0;
}