#include <bits/stdc++.h>

typedef long long ll;
const int N = 200054;

int n, mod;
int a[N], c[N];
ll u[N];

ll PowerMod(ll a, ll n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

int main() {
	int i, j, ans = 1;
	scanf("%d%d", &n, &mod);
	for (i = 0; i < n; ++i) scanf("%d", a + i);
	std::sort(a, a + n);
	for (i = 0; i < n; ++i) a[i] %= mod;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < mod; ++j)
			u[(a[i] - j + mod) % mod] += c[j];
		++c[a[i]];
	}
	for (i = 0; i < mod; ++i) ans = PowerMod(i, u[i], ans);
	printf("%d\n", ans % mod);
	return 0;
}