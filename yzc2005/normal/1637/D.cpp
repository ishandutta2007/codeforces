#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, a[N], b[N];
bool g[N * N], f[N * N];
void solve() {
	scanf("%d", &n);
	long long val = 0, sum = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		val += 1ll * a[i] * a[i] * (n - 2);
		sum += a[i];
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
		val += 1ll * b[i] * b[i] * (n - 2);
		sum += b[i];
	}
	memset(f, false, sizeof f);
	f[0] = true;
	for (int i = 1; i <= n; ++i) {
		memset(g, false, sizeof g);
		for (int x = N * N - 1; ~x; --x) {
			if (x >= a[i]) g[x] |= f[x - a[i]];
			if (x >= b[i]) g[x] |= f[x - b[i]];
		}
		memcpy(f, g, sizeof f);
	}
	long long ans = 1e18;
	for (int i = 0; i < N * N; ++i)
		if (f[i]) ans = min(ans, 1ll * i * i + 1ll * (sum - i) * (sum - i));
	printf("%lld\n", ans + val);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}