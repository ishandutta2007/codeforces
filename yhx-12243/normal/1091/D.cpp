#include <bits/stdc++.h>
#define N 1000054

typedef long long ll;
const ll mod = 998244353;

int n;

int main() {
	int i; ll ans, ft = 1, fy = 1;
	scanf("%d", &n);
	for (i = 2; i <= n; ++i) ft = ft * i % mod; ans = ft * n % mod;
	for (i = n; i > 1; --i) ans -= (fy = fy * i % mod);
	ans %= mod;
	printf("%lld\n", ans + (ans >> 63 & mod));
	return 0;
}