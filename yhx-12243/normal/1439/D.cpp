#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 540;

int mod;
int n, m;
int f[N], F[N];
int fact[N], finv[N];

ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

void init(int n) {
	int i;
	for (*fact = i = 1; i <= n; ++i) fact[i] = (ll)fact[i - 1] * i % mod;
	finv[n] = PowerMod(fact[n], mod - 2);
	for (i = n; i; --i) finv[i - 1] = (ll)finv[i] * i % mod;
}

inline int getF(int n) {
	int i, ret = 0;
	for (i = n - 2; i >= 0; --i) ret = (ret * (n + 1ll) + finv[i]) % mod;
	return PowerMod(2, n - 1, ret);
}

int main() {
	int i, D, ans = 0;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> m >> mod, init(m), D = n - m;
	for (*f = i = 1; i <= m; ++i) f[i] = PowerMod(2 * (i + D), i - 1, 2ll * D * finv[i] % mod);
	for (i = 2; i <= m; ++i) F[i] = getF(i);
	for (i = 0; i <= m; ++i) ans = (ans + (ll)f[i] * F[m - i]) % mod;
	cout << (D + 1ll) * fact[m] % mod * ans % mod << '\n';
	return 0;
}