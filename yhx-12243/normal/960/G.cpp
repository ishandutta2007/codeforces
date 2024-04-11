#include <bits/stdc++.h>
#define EB emplace_back
#define lg2 std::__lg

typedef long long ll;
const int N = 530000, mod = 998244353, iv2 = (mod + 1) / 2, root = 31;
typedef int vec[N], *pvec;
typedef std::vector <int> vector;

vec fact, finv;

ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

void init() {
	int i;
	for (*fact = i = 1; i < N; ++i) fact[i] = (ll)fact[i - 1] * i % mod;
	--i, finv[i] = PowerMod(fact[i], mod - 2);
	for (; i; --i) finv[i - 1] = (ll)finv[i] * i % mod;
}

namespace Poly {
	int l, n;
	vec rev, x, y;

	void NTT_init(int len) {
		if (l == len) return; n = 1 << (l = len);
		ll g = PowerMod(root, 1 << (23 - l));
		*x = 1, *rev = 0;
		for (int i = 1; i < n; ++i)
			x[i] = x[i - 1] * g % mod, rev[i] = rev[i >> 1] >> 1 | (i & 1) << (l - 1);
	}

	void DNTT(int *d, int *t) {
		int i, *j, *k, len = 1, delta = n, R;
		for (i = 0; i < n; ++i) t[rev[i]] = d[i];
		for (i = 0; i < l; ++i) {
			delta >>= 1;
			for (k = x, j = y; j < y + len; k += delta, ++j) *j = *k;
			for (j = t; j < t + n; j += len << 1)
				for (k = j; k < j + len; ++k)
					R = (ll)y[k - j] * k[len] % mod,
					k[len] = (*k - R < 0 ? *k - R + mod : *k - R),
					*k = (*k + R >= mod ? *k + R - mod : *k + R);
			len <<= 1;
		}
	}

	vec B1, B2, B3, B4, B5;

	void Mul(int deg, pvec a, pvec b, pvec c) {
		if (!deg) {*c = (ll)*a * *b % mod; return;}
		NTT_init(lg2(deg) + 1);
		int i; ll iv = mod - (mod - 1) / n;
		DNTT(a, c), DNTT(b, B1);
		for (i = 0; i < n; ++i) B1[i] = (ll)B1[i] * c[i] % mod;
		DNTT(B1, c), std::reverse(c + 1, c + n);
		for (i = 0; i < n; ++i) c[i] = c[i] * iv % mod;
	}

	void translate(int deg, pvec a, int c, pvec b) {
		int i; ll pc = 1;
		for (i = 0; i <= deg; ++i) a[i] = (ll)a[i] * fact[i] % mod;
		for (i = deg; i >= 0; --i, pc = pc * c % mod) b[i] = finv[deg - i] * pc % mod;
		Mul(deg * 2, a, b, B2);
		for (i = 0; i <= deg; ++i) b[i] = (ll)B2[deg + i] * finv[i] % mod;
	}
}

vec f, g, h;

inline ll Cm(int a, int b) {return (ll)fact[a + b] * finv[a] % mod * finv[b] % mod;}

void Stirling(int n) {
	if (n <= 1) {f[n] = 1; return;}
	int m = (n + 1) / 2;
	Stirling(m),
	n & 1 ? (memcpy(g, f + 1, m << 2), Poly::translate(m - 1, g, m - 1, h))
		  : (memcpy(g, f, (m + 1) << 2), Poly::translate(m, g, m, h)),
	Poly::Mul(n, f, h, g), memcpy(f, g, (n + 1) << 2), memset(g, 0, (n + 1) << 2);
}

int main() {
	int n, a, b; init();
	scanf("%d%d%d", &n, &a, &b);
	if (--a + --b < 0) return putchar(48), putchar(10), 0;
	Stirling(n - 1), printf("%d\n", int(f[a + b] * Cm(a, b) % mod));
	return 0;
}