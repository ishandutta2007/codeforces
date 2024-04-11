#include <bits/stdc++.h>

typedef long long ll;
const int N = 100054, mod = 1000000007;

int n, L = 0;
int deg[N];

ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

int main() {
	int i, u, v;
#ifndef ONLINE_JUDGE
	freopen("wan.in", "r", stdin);
	freopen("wan.out", "w", stdout);
#endif
	scanf("%d", &n);
	if (n == 1) return putchar(49), putchar(10), 0;
	for (i = 1; i < n; ++i) scanf("%d%d", &u, &v), ++deg[u], ++deg[v];
	L = std::count(deg + 1, deg + (n + 1), 1);
	printf("%lld\n", PowerMod(2, n - L, n + L));
	return 0;
}