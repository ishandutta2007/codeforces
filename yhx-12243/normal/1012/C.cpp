#include <bits/stdc++.h>
#define N 5005
#define H 2505

typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

int n;
int a[N];
ll f[H][N];

inline void down(ll &x, const ll y) {x > y ? x = y : 0;}

int main() {
	int i, j, h; ll W, ans;
	scanf("%d", &n); a[0] = 0x131a371;
	for (i = 1; i <= n; ++i) scanf("%d", a + i);
	memset(f, 63, sizeof f); h = (n + 1) >> 1;
	for (i = 0; i <= n; ++i) f[0][i] = 0;
	for (i = 1; i <= h; ++i) {
		f[i][1] = (i == 1 ? 0 : INF); ans = W = INF;
		down(ans, f[i][1] + (1 == n ? 0 : std::max(a[2] - a[1] + 1, 0)));
		for (j = 2; j <= n; ++j) {
			down(f[i][j], W + std::max(a[j - 1] - a[j] + 1, 0));
			down(f[i][j], f[i - 1][j - 2] + std::max(a[j - 1] - std::min(a[j], a[j - 2]) + 1, 0));
			down(W, f[i - 1][j - 2] + std::max(a[j - 1] - a[j - 2] + 1, 0));
			down(ans, f[i][j] + (j == n ? 0 : std::max(a[j + 1] - a[j] + 1, 0)));
		}
		printf("%lld%c", ans, i == h ? 10 : 32);
	}
	return 0;
}