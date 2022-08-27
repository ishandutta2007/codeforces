#include <bits/stdc++.h>
#define EB emplace_back
#define lg2 std::__lg
#define ctz __builtin_ctz
using std::cin;
using std::cout;

typedef long long ll;
const int N = 1000054, mod = 1000000007, iv3 = (mod + 1) / 3;
typedef int vec[3 * N];

int n, q;
vec f, g, fact, finv;

ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

void init(int n) {
	int i;
	for (*fact = i = 1; i <= n; ++i) fact[i] = (ll)fact[i - 1] * i % mod;
	finv[n] = PowerMod(fact[n], mod - 2);
	for (i = n; i; --i) finv[i - 1] = (ll)finv[i] * i % mod;
}

inline ll C(int n, int r) {return (ll)fact[n] * finv[r] % mod * finv[n - r] % mod;}

void work() {
	int i, m = 3 * (n + 1);
	init(m);
	for (i = 0; i < m; ++i) f[i] = C(m, i + 1);
	*g = n + 1,
	g[1] = n * (n + 1ll) / 2 * 3 % mod;
	for (i = 2; i < m; ++i)
		g[i] = (ll(f[i] - g[i - 2] + mod) * iv3 + mod - g[i - 1]) % mod;
}

int main() {
	int i;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> q, work();
	for (; q; --q) cin >> i, cout << g[i] << '\n';
	return 0;
}