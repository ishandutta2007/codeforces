#include <bits/stdc++.h>
#define popc __builtin_popcount
#define ctz __builtin_ctz
using std::cin;
using std::cout;

typedef long long ll;
typedef unsigned long long u64;
const int N = 21, N2 = 1050000;

int mod, M1, M2;
int n, ALL;
int tr[N], f[N2], g[N2];
u64 F[N2], G[N2];
ll D;

inline int & reduce(int &x) {return x += x >> 31 & M1;}

ll PowerMod(ll a, ll n, ll c = 1) {for (; n; n >>= 1, a = a * a % M1) if (n & 1) c = c * a % M1; return c;}
u64 pow64(u64 a, ll n, u64 c = 1) {for (; n; n >>= 1, a *= a) if (n & 1) c *= a; return c;}

int exgcd(int a, int b, int &x, int &y) {
	if (b) {int d = exgcd(b, a % b, y, x); return y -= a / b * x, d;}
	else return x = 1, y = 0, a;
}

void FWT(int *a, u64 *A) {
	int i, j, k, $, len = 1; u64 _;
	for (i = 0; i < n; ++i, len <<= 1)
		for (j = 0; j <= ALL; j += len << 1)
			for (k = j; k < j + len; ++k)
				$ = a[k + len], reduce(a[k + len] = a[k] - $), reduce(a[k] += $ - M1),
				_ = A[k + len], A[k + len] = A[k] - _, A[k] += _;
}

int main() {
	int i, x, U1, U2, mask;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> D >> mod, ALL = ~(-1 << n), M2 = ctz(mod), M1 = mod >> M2, mask = ~(-1 << M2);
	for (i = 0; i <= ALL; ++i) cin >> x, f[i] = x % M1, F[i] = x & mask;
	for (i = 0; i <= n; ++i) cin >> tr[i], tr[i] %= mod;
	for (i = 0; i <= ALL; ++i) g[i] = tr[popc(i)] % M1, G[i] = tr[popc(i)] & mask;
	FWT(f, F), FWT(g, G);
	for (i = 0; i <= ALL; ++i) f[i] = PowerMod(g[i], D, f[i]), F[i] = pow64(G[i], D, F[i]);
	FWT(f, F), x = PowerMod((M1 + 1) / 2, n),
	exgcd(1 << M2, M1, U2, U1), U1 = ((ll)U1 * M1 + mod) % mod, U2 = (ll(U2 + M1) << M2) % mod;
	for (i = 0; i <= ALL; ++i)
		f[i] = (ll)f[i] * x % M1, F[i] = F[i] >> n & mask,
		cout << ((ll)f[i] * U2 + (ll)F[i] * U1) % mod << '\n';
	return 0;
}