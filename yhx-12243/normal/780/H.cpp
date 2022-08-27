#include <bits/stdc++.h>
#define lt(x, y) ((x) < (y) - eps)
#define gt(x, y) ((x) > (y) + eps)
#define le(x, y) ((x) <= (y) + eps)
#define ge(x, y) ((x) >= (y) - eps)
#define eq(x, y) (le(x, y) && ge(x, y))
#define dot(x, y, z) (((y) - (x)) * ((z) - (x)))
#define cross(x, y, z) (((y) - (x)) ^ ((z) - (x)))

typedef std::pair <double, double> pr;
const int N = 500054;
const double eps = 3e-10;

inline void up(double &x, const double y) {x < y ? x = y : 0.;}
inline void down(double &x, const double y) {x > y ? x = y : 0.;}
inline double max(const double x, const double y) {return x < y ? y : x;}

struct quadratic {
	double A, B, C;
	quadratic (double A_ = 0., double B_ = 0., double C_ = 0.) : A(A_), B(B_), C(C_) {}
	inline double operator () (double x) const {return (A * x + B) * x + C;}
	inline pr root(double y) const {
		if (eq(A, 0)) return pr((y - C) / B, NAN);
		double b = -.5 * B / A, d = b * b + (y - C) / A;
		return lt(d, 0) ? pr(NAN, NAN) : (d = sqrt(max(d, 0.)), pr(b - d, b + d));
	}
	inline pr range(double x_min, double x_max) const {
		assert(x_min <= x_max);
		pr ret = std::minmax((*this)(x_min), (*this)(x_max));
		double mid = -.5 * B / A;
		if (eq(A, 0) || mid < x_min || x_max < mid) ;
		else mid = (*this)(mid), down(ret.first, mid), up(ret.second, mid);
		return ret;
	}
};

struct vec2 {
	double x, y;
	vec2 (double x0 = 0., double y0 = 0.) : x(x0), y(y0) {}
	vec2 * read() {scanf("%lf%lf", &x, &y); return this;}
	inline vec2 operator - () const {return vec2(-x, -y);}
	inline vec2 operator + (const vec2 &B) const {return vec2(x + B.x, y + B.y);}
	inline vec2 operator - (const vec2 &B) const {return vec2(x - B.x, y - B.y);}
	inline vec2 operator * (double k) const {return vec2(x * k, y * k);}
	inline vec2 operator / (double k) const {return *this * (1.0 / k);}
	inline double operator * (const vec2 &B) const {return x * B.x + y * B.y;}
	inline double operator ^ (const vec2 &B) const {return x * B.y - y * B.x;}
	inline double norm2() const {return x * x + y * y;}
	inline double norm() const {return sqrt(x * x + y * y);}
	inline bool operator < (const vec2 &B) const {return lt(x, B.x) || le(x, B.x) && lt(y, B.y);}
	inline bool operator == (const vec2 &B) const {return eq(x, B.x) && eq(y, B.y);}
};

int n, m, sr = 0;
vec2 p[N], unit[N];
double C[N], co[N], u;

double st[N];
quadratic f[N];
pr rg[N];

inline int pred(int x) {return (x ? x : n) - 1;}
inline int succ(int x) {return ++x == n ? 0 : x;}

void append(double len, int i1, double s1, int i2, double s2) {
	if (s1 < 0) s1 += C[n];
	if (s2 < 0) s2 += C[n];
	st[sr + 1] = st[sr] + len;
	vec2 O = (p[i1] + unit[i1] * s1) - (p[i2] + unit[i2] * s2), v = unit[i1] - unit[i2];
	f[sr++] = quadratic(v.norm2(), v * O * 2., O.norm2());
}

namespace seg {
	int n;
	bool danger;
	pr a[N];

	inline void reset() {n = 0, danger = false;}

	inline void insert(double L, double R) {
		assert(L <= R);
		int Li = L / u, Ri = R / u; L -= Li * u, R -= Ri * u;
		if (Li == Ri) a[n++] = pr(L, R);
		else if (Li + 1 == Ri && L > R) a[n++] = pr(L, u), a[n++] = pr(0, R);
		else danger = true;
	}

	bool exist() {
		if (danger) return false;
		int i; double k = 0;
		std::sort(a, a + n);
		for (i = 0; i < n; ++i) {
			if (k < a[i].first) return true;
			up(k, a[i].second);
		}
		return lt(k, u);
	}
}

inline bool check(double lim) {
	int i; double L, R, x1, x2;
	seg::reset();
	for (i = 0; i < sr; ++i) {
		if (L = st[i], R = st[i + 1], eq(L, R)) continue;
		if (lim <= rg[i].first) seg::insert(L, R);
		else if (lim < rg[i].second) {
			std::tie(x1, x2) = f[i].root(lim), x1 += L, x2 += L;
			if (!(L <= x1 && x1 <= R)) std::swap(x1, x2);
			if (L <= x2 && x2 <= R)
				f[i].C >= lim ? seg::insert(L, x1), seg::insert(x2, R) : seg::insert(x1, x2);
			else
				f[i].C >= lim ? seg::insert(L, x1) : seg::insert(x1, R);
		}
	}
	return seg::exist();
}

int main() {
	int i, j; double L, R, M;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; ++i) p[i].read(); p[n] = *p;
	for (i = 0; i < n; ++i) L = (p[i] - p[i + 1]).norm(), C[i + 1] = C[i] + L, unit[i] = (p[i + 1] - p[i]) / L;
	u = C[n] / m;
	for (i = 0; i < n; ++i) co[i] = fmod(C[i] + C[n] - u, C[n]);
	j = pred(std::min_element(co, co + n) - co);
	for (i = 0; i < n; ++i) {
		for (L = C[i]; C[i] <= co[succ(j)] && co[succ(j)] < C[i + 1]; j = succ(j), L = co[j])
			append(co[succ(j)] - L, i, L - C[i], j, L - co[j]);
		append(C[i + 1] - L, i, L - C[i], j, L - co[j]);
	}
	for (i = 0; i < sr; ++i) rg[i] = f[i].range(0, st[i + 1] - st[i]);
	{vec2 *_1, *_2; std::tie(_1, _2) = std::minmax_element(p, p + n), R = (*_1 - *_2).norm();}
	for (L = 0.; L + eps < R; ) M = (L + R) * .5, check(M * M) ? R = M : L = M;
	printf("%.10lg\n", (L + R) * .5);
	return 0;
}