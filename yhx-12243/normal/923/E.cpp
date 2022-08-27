#include <bits/stdc++.h>
#define N 530000
#define lg2(x) (31 - __builtin_clz(x))

typedef int vec[N], *pvec;
typedef long long ll;
const ll mod = 998244353, pmod = mod - 1, half_mod = (mod + 1) / 2, root = 31;

ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

namespace Poly {
	int l, n;
	vec rev, x, y;

	void in(int deg, pvec f) {for (int i = 0; i <= deg; ++i) scanf("%d", f + i);}

	void out(int deg, pvec f, const char *_name){
		printf("%s(x) =", _name);
		for (int i = 0; i <= deg; ++i) printf(" %+d x^%d", (int)(f[i] - (mod & -(f[i] >= half_mod))), i);
		putchar(10);
	}

	void series(int deg, pvec f) {for (int i = 0; i <= deg; ++i) printf("%d%c", f[i], i == deg ? 10 : 32);}

	#define fy_out(deg, f) Poly::out(deg, f, #f)

	void NTT_init(int len){
		if (l == len) return; n = 1 << (l = len);
		ll g = PowerMod(root, 1 << (23 - l));
		*x = 1; *rev = 0;
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
				for (k = j; k < j + len; ++k) {
					R = (ll)y[k - j] * k[len] % mod;
					k[len] = (*k - R < 0 ? *k - R + mod : *k - R);
					*k = (*k + R >= mod ? *k + R - mod : *k + R);
				}
			len <<= 1;
		}
	}

	vec B1;

	void Mul(int deg, pvec a, pvec b, pvec c) {
		if (!deg) {*c = (ll)*a * *b % mod; return;}
		NTT_init(lg2(deg) + 1);
		int i; ll iv = PowerMod(n, mod - 2);
		DNTT(a, c); DNTT(b, B1);
		for (i = 0; i < n; ++i) B1[i] = (ll)B1[i] * c[i] % mod;
		DNTT(B1, c); std::reverse(c + 1, c + n);
		for (i = 0; i < n; ++i) c[i] = c[i] * iv % mod;
	}
}

int n;
ll K;
vec fact, finv;
vec P, Q, a, b, gi;

int main() {
	int i;
	scanf("%d%lld", &n, &K); Poly::in(n, P); K = pmod - K % pmod;
	for (*fact = i = 1; i <= n; ++i) fact[i] = (ll)fact[i - 1] * i % mod;
	finv[n] = PowerMod(fact[n], mod - 2);
	for (i = n; i; --i) finv[i - 1] = (ll)finv[i] * i % mod;
	for (i = 0; i <= n; ++i) a[n - i] = (ll)P[i] * fact[i] % mod;
	Poly::Mul(n * 2, a, finv, b);
	memset(b + (n + 1), 0, n << 2);
	for (i = 0; i <= n; ++i) a[i] = PowerMod(n - i + 1, (int)K, b[i]);
	for (i = 0; i <= n; ++i) gi[i] = (i & 1 ? mod - finv[i] : finv[i]);
	Poly::Mul(n * 2, a, gi, b);
	for (i = 0; i <= n; ++i) Q[i] = (ll)b[n - i] * finv[i] % mod;
	Poly::series(n, Q);
	return 0;
}