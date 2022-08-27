#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 300054, mod = 998244353;

int n;
int a[N];
int fact[N], finv[N];

ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

void init(int n) {
	int i;
	for (*fact = i = 1; i <= n; ++i) fact[i] = (ll)fact[i - 1] * i % mod;
	finv[n] = PowerMod(fact[n], mod - 2);
	for (i = n; i; --i) finv[i - 1] = (ll)finv[i] * i % mod;
}

int main() {
	int i; ll s = 0;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n, init(2 * n);
	for (i = 0; i < 2 * n; ++i) cin >> a[i];
	std::sort(a, a + 2 * n);
	for (i = 0; i < n; ++i) s += a[2 * n - 1 - i] - a[i];
	s %= mod, s += s >> 63 & mod;
	s = (ll)fact[2 * n] * finv[n] % mod * finv[n] % mod * s % mod;
	cout << s << '\n';
	return 0;
}