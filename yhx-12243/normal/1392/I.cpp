#define	_USE_MATH_DEFINES
#include <bits/stdc++.h>
#define lg2 std::__lg
using std::cin;
using std::cout;

typedef long long ll;
const int N = 265000;
constexpr double pi = M_PI;

// typedef std::complex <double> C;
struct C {
	double r, i;
	C () {}
	C (double real, double imag = 0.0) : r(real), i(imag) {}
	inline C operator + (const C &B) const {return C(r + B.r, i + B.i);}
	inline C operator - (const C &B) const {return C(r - B.r, i - B.i);}
	inline C operator * (const C &B) const {return C(r * B.r - i * B.i, r * B.i + i * B.r);}
	inline C operator * (double k) const {return C(r * k, i * k);}
	inline C operator / (double k) const {return *this * (1.0 / k);}
	inline C conj() const {return C(r, -i);}
};

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline int min(const int x, const int y) {return x < y ? x : y;}
inline int max(const int x, const int y) {return x < y ? y : x;}

namespace rpoly_base {
	int l, n; double iv; C w2[N];

	void init(int n = N) {
		int i, t = min(n > 1 ? lg2(n - 1) : 0, 21); double angle = pi;
		for (*w2 = C(1), i = 0; i <= t; ++i) angle *= .5, w2[1 << i] = C(cos(angle), sin(angle));
		for (i = 3; i < n; ++i) if (i & (i - 1)) w2[i] = w2[i & (i - 1)] * w2[i & -i];
	}

	inline void FFT_init(int len) {n = 1 << (l = len), iv = 1. / n;}

	void DIF(C *a) {
		int i, len = n >> 1; C *j, *k, *o, R;
		for (i = 0; i < l; ++i, len >>= 1)
			for (j = a, o = w2; j != a + n; j += len << 1, ++o)
				for (k = j; k != j + len; ++k)
					R = *o * k[len], k[len] = *k - R, *k = *k + R;
	}

	void DIT(C *a) {
		int i, len = 1; C *j, *k, *o, R;
		for (i = 0; i < l; ++i, len <<= 1)
			for (j = a, o = w2; j != a + n; j += len << 1, ++o)
				for (k = j; k != j + len; ++k)
					R = *k + k[len], k[len] = (*k - k[len]) * *o, *k = R;
	}
}

int Row, Col, n, q;
int r[N], c[N], re[N], ce[N], ri[N], ci[N], rs[N], cs[N];
C R1[N], R2[N];
ll res[N];

int main() {
	int i, x, rmin = INT_MAX, rmax = INT_MIN, cmin = INT_MAX, cmax = INT_MIN;
	namespace rpb = rpoly_base;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> Row >> Col >> q;
	for (i = 0; i < Row; ++i) cin >> r[i], down(rmin, r[i]), up(rmax, r[i]);
	for (i = 0; i < Col; ++i) cin >> c[i], down(cmin, c[i]), up(cmax, c[i]);
	for (i = 0; i < Row; ++i) ++re[ r[i] -= rmin ];
	for (i = 0; i < Col; ++i) ++ce[ c[i] -= cmin ];
	for (i = 1; i < Row; ++i) ++ri[min(r[i - 1], r[i])], ++rs[max(r[i - 1], r[i])];
	for (i = 1; i < Col; ++i) ++ci[min(c[i - 1], c[i])], ++cs[max(c[i - 1], c[i])];
	n = (rmax - rmin) + (cmax - cmin), rpb::FFT_init(n ? lg2(n) + 1 : 0), rpb::init(rpb::n);

	for (i = 0; i <= n; ++i) R1[i] = C(re[i] - ri[i], re[i] - rs[i]), R2[i] = C(ci[i] - ce[i], ce[i] - cs[i]);
	rpb::DIF(R1), rpb::DIF(R2);
	for (i = 0; i < rpb::n; ++i) R1[i] = R1[i] * R2[i];
	rpb::DIT(R1), std::reverse(R1 + 1, R1 + rpb::n);
	for (i = 0; i <= n; ++i) res[i] = llroundl(R1[i].r * rpb::iv);

	for (i = 1; i <= n; ++i) res[i] += res[i - 1];
	for (; q; --q)
		cin >> x, x -= rmin + cmin + 1, cout << 1 + (x < 0 ? 0 : res[min(x, n)]) << '\n';
	return 0;
}