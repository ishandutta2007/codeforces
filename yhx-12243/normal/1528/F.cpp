#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef unsigned long long u64;
const int N = 100054, mod = 998244353;

int n, L;
int fact[N], finv[N];
int pn = 0, c[N], p[9600], pwn[N];

inline void reduce(int &x) {x += x >> 31 & mod;}
u64 PowerMod(u64 a, int n, u64 c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

void init(int n) {
	int i;
	for (*fact = i = 1; i <= n; ++i) fact[i] = (u64)fact[i - 1] * i % mod;
	finv[n] = PowerMod(fact[n], mod - 2);
	for (i = n; i; --i) finv[i - 1] = (u64)finv[i] * i % mod;
}

void sieve(int n) {
	int i, j, v; pwn[1] = 1;
	memset(c, -1, sizeof c);
	for (i = 2; i <= n; ++i) {
		if (!~c[i]) p[pn] = i, c[i] = pn++, pwn[i] = PowerMod(i, n);
		for (j = 0; (v = i * p[j]) <= n && j <= c[i]; ++j) c[v] = j, pwn[v] = (u64)pwn[i] * pwn[p[j]] % mod;
	}
}

int main() {
	int i, s = 1, t = 0, ans = 0;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> L >> n, init(n), sieve(n);
	if (L <= n) {
		for (i = L; i >= 0; --i, s = (u64)s * L % mod) ans = (ans + (u64)finv[i] * finv[L - i] % mod * pwn[i] % mod * s) % mod;
		ans = (u64)fact[L] % mod * ans % mod;
	} else {
		for (i = n; i >= 0; --i)
			t = (L * u64(i + 1) % mod * t + (u64)s * finv[i] % mod * finv[n - i]) % mod,
			s = s * u64(mod - L % mod + i) % mod, ans = (ans * u64(L - i) + (u64)t * pwn[i]) % mod;
		ans = PowerMod(L + 1, L - n, ans);
	}
	cout << ans << '\n';
	return 0;
}