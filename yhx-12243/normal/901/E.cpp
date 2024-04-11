#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define EB emplace_back
#define lg2 std::__lg
using std::cin;
using std::cout;

typedef long long ll;
const int N = 265000;
typedef int vec[N], *pvec;
typedef std::vector <int> vector;

int mod, iv2;

ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

namespace NT {
	typedef std::pair <int, int> pr;
	int pn = 0, c[N], p[23333];
	int cnt = 0;
	pr fac[54];

	inline void push(ll prime, int alpha) {fac[cnt++] = pr(prime, alpha);}

	void sieve(int n) {
		int i, j, v;
		memset(c, -1, sizeof c);
		for (i = 2; i <= n; ++i) {
			if (!~c[i]) p[pn] = i, c[i] = pn++;
			for (j = 0; j <= c[i] && (v = i * p[j]) <= n; ++j) c[v] = j;
		}
	}

	bool is_prime(int n) {
		if (!(n & 1) || PowerMod(2, mod - 1) != 1) return false;
		for (int i = 1; p[i] * p[i] <= n; ++i) if (!(n % p[i])) return false;
		return true;
	}

	void factor(int n) {
		int i, j; cnt = 0;
		for (i = 0; n != 1; ) {
			if (n >= N) {
				for (; (ll)p[i] * p[i] <= n && n % p[i]; ++i);
				if (n % p[i]) return push(n, 1);
			} else i = c[n];
			for (j = 0; !(n % p[i]); n /= p[i], ++j);
			push(p[i], j);
		}
	}

	int get_primitive_root(int p) {
		int g, i = 0; factor(p - 1);
		for (g = 2; i < cnt; ++g)
			for (i = 0; i < cnt && PowerMod(g, (p - 1) / fac[i].first) != 1; ++i);
		return --g;
	}

	void init() {sieve(N - 1);}
}

namespace Poly {
	typedef std::complex <double> C;

	int l, n, rev[N];
	C x[N], y[N], B1[N], B2[N], B3[N], B4[N];

	void FFT_init(int len) {
		if (l == len) return;
		n = 1 << (l = len);
		int i; double angle = M_PI;
		for (i = l - 1; i >= 0; angle *= .5, --i) x[1 << i] = C(cos(angle), sin(angle));
		for (i = 3; i < n; ++i) if (i & (i - 1)) x[i] = x[i & -i] * x[i ^ (i & -i)];
		*x = C(1.), *rev = 0;
		for (i = 1; i < n; ++i) rev[i] = rev[i >> 1] >> 1 | (i & 1) << (l - 1);
	}

	void DFT(C *d, C *t) {
		int i, len = 1, delta = n; C *j, *k, R;
		for (i = 0; i < n; ++i) t[rev[i]] = d[i];
		for (i = 0; i < l; ++i) {
			delta >>= 1;
			for (k = x, j = y; j < y + len; k += delta, ++j) *j = *k;
			for (j = t; j < t + n; j += len << 1)
				for (k = j; k < j + len; ++k)
					R = y[k - j] * k[len], k[len] = *k - R, *k += R;
			len <<= 1;
		}
	}

	void conv(int deg, int *a, int *b, int *c) {
		if (!deg) {*c = (ll)*a * *b % mod; return;}
		FFT_init(lg2(deg) + 1);
		int i, j; double iv = 1. / n;
		for (i = 0; i <= deg; ++i) B1[i] = C(a[i] & 32767, a[i] >> 15), B2[i] = C(b[i] & 32767, b[i] >> 15);
		std::fill(B1 + i, B1 + n, C()), std::fill(B2 + i, B2 + n, C());
		DFT(B1, B3), DFT(B2, B4), B3[n] = *B3, B4[n] = *B4;
		for (i = 0, j = n; i < n; ++i, --j)
			B1[j] = (B3[i] + std::conj(B3[j])) * B4[i] * C(.5, 0.),
			B2[j] = (B3[i] - std::conj(B3[j])) * B4[i] * C(0., -.5);
		*B1 = B1[n], *B2 = B2[n], DFT(B1, B3), DFT(B2, B4);
		for (i = 0; i <= deg; ++i)
			c[i] = (ll(B3[i].real() * iv + .5) + (ll((B3[i].imag() + B4[i].real()) * iv + .5) % mod << 15) + (ll(B4[i].imag() * iv + .5) % mod << 30) + mod) % mod;
	}
}

int n, SOL = 0;
vec w, b, c, db, dc;
vec tp, b_fft, c_fft;
vec wU, wD, CZ1, CZ2;
vector sol[5];

void CZT(int n, int *f, int *g) {
	int i;
	for (i = 0; i < n; ++i) CZ1[n - 1 - i] = (ll)wD[i] * f[i] % mod;
	Poly::conv(2 * (n - 1), wU, CZ1, CZ2);
	for (i = 0; i < n; ++i) g[i] = (ll)wD[i] * CZ2[n - 1 + i] % mod; 
}

bool work() {
	int i, omega; ll iv = mod - (mod - 1) / n, iv2 = (mod + 1) / 2, base = 0, L = 0, Q = -*c, delta, sqdelta;
	omega = PowerMod(NT::get_primitive_root(mod), (mod - 1) / n);
	for (*w = i = 1; i <= n; ++i) w[i] = (ll)w[i - 1] * omega % mod;
	for (*wU = *wD = i = 1; i < 2 * n - 1; ++i) wU[i] = w[(i - 1) % n], wD[i] = w[(2 * n - i + 1) % n];
	for (i = 2; i < 2 * n - 1; ++i) wU[i] = (ll)wU[i] * wU[i - 1] % mod, wD[i] = (ll)wD[i] * wD[i - 1] % mod;
	for (i = 0; i < n; ++i) tp[i] = (db[i] + mod) % mod;
	CZT(n, tp, b_fft);
	for (i = 0; i < n; ++i) if (!b_fft[i]) return false;
	for (i = 0; i < n; ++i) tp[i] = (dc[i] + mod) % mod;
	CZT(n, tp, c_fft);
	for (i = 0; i < n; ++i) c_fft[i] = PowerMod(b_fft[i], mod - 2, c_fft[i]);
	CZT(n, c_fft, tp), std::reverse(tp + 1, tp + n);
	for (i = 0; i < n; ++i)	{
		tp[i] = tp[i] * iv % mod, tp[i] -= (iv2 - tp[i]) >> 31 & mod;
		if (tp[i] >= 65536 || tp[i] <= -65536) return true;
	}
	for (i = 0; i < n; base += tp[++i]) L += b[i] - base, Q += (b[i] - base) * (b[i] - base);
	delta = L * L - n * Q, sqdelta = llroundl(sqrtl(delta));
	if (delta < 0 || (ll)sqdelta * sqdelta != delta) return true;
	if (!((L + sqdelta) % n)) {
		vector &cur = sol[SOL++]; cur.reserve(n), cur.EB((L + sqdelta) / n);
		for (i = 1; i < n; ++i) cur.EB(cur.back() + tp[i]);
	}
	if (sqdelta && !((L - sqdelta) % n)) {
		vector &cur = sol[SOL++]; cur.reserve(n), cur.EB((L - sqdelta) / n);
		for (i = 1; i < n; ++i) cur.EB(cur.back() + tp[i]);
	}
	return true;
}

int main() {
	int i, j; NT::init();
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	for (mod = INT_MAX / (2 * n) * n + 1; !NT::is_prime(mod); mod -= n);
	for (i = 0; i < n; ++i) cin >> b[i];
	std::reverse_copy(b, b + n, db);
	for (i = 0; i < n; ++i) cin >> c[i];
	for (i = 1; i < n; ++i) if ((*c ^ c[i]) & 1) return cout << "0\n", 0;
	for (c[n] = *c, i = 0; i < n; ++i) dc[i] = (c[i] - c[i + 1]) / 2;
	for (; !work(); ) for (; !NT::is_prime(mod -= n); );
	std::sort(sol, sol + SOL), cout << SOL << '\n';
	for (j = 0; j < SOL; ++j)
		for (i = 0; i < n; ++i) cout << sol[j][i] << (i == n - 1 ? '\n' : ' ');
	return 0;
}