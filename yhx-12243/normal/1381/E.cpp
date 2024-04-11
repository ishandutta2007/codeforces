#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef std::pair <double, int> pr;
const double eps = 1e-10;
const int N = 200054;

struct vec2 {
	double x, y;
	vec2 (double x0 = 0.0, double y0 = 0.0) : x(x0), y(y0) {}
	inline friend std::istream & operator >> (std::istream &in, vec2 &B) {return in >> B.x >> B.y;}
	inline double operator ^ (const vec2 &B) const {return x * B.y - y * B.x;}
} poly[N], l[N], m[N], r[N];

struct sweepLine {
	double x, a, b, c;
	sweepLine () {}
	sweepLine (double x_, double a_, double b_, double c_) : x(x_), a(a_), b(b_), c(c_) {}
	inline bool operator < (const sweepLine &B) const {return x < B.x;}
} sl[2003731];

int n, q, L, M, R;
double ansL[N], ansR[N];
pr qry[N];

inline double getX(const vec2 &P, const vec2 &Q, double y) {return ((Q.x - P.x) * y + (P ^ Q)) / (Q.y - P.y);}

void sweepTo(int L, vec2 *l, int R, vec2 *r, double *ans) {
	int i, j, cnt = 0; double dx, dy, k, A = 0., B = 0., C = 0.;
	for (i = 1; i < L; ++i) {
		dx = l[i].x - l[i - 1].x, dy = l[i].y - l[i - 1].y;
		if (fabs(dx) < eps)
			dx = (l[i - 1].x + l[i].x) * .5,
			sl[cnt++] = sweepLine(dx, 0., dy, -dy * dx);
		else if (dx > 0)
			k = .5 * dy / dx,
			sl[cnt++] = sweepLine(l[i - 1].x, k, -2. * k * l[i - 1].x, k * l[i - 1].x * l[i - 1].x),
			sl[cnt++] = sweepLine(l[i].x, -k, 2. * k * l[i].x, -k * l[i].x * l[i].x);
		else
			k = -.5 * dy / dx,
			sl[cnt++] = sweepLine(l[i].x, k, -2. * k * l[i].x, k * l[i].x * l[i].x),
			sl[cnt++] = sweepLine(l[i - 1].x, -k, 2. * k * l[i - 1].x, -k * l[i - 1].x * l[i - 1].x);
	}
	for (i = 1; i < R; ++i) {
		dx = r[i].x - r[i - 1].x, dy = r[i].y - r[i - 1].y;
		if (fabs(dx) < eps)
			dx = (r[i - 1].x + r[i].x) * .5,
			sl[cnt++] = sweepLine(dx, 0., -dy, dy * dx);
		else if (dx > 0)
			k = .5 * dy / dx,
			sl[cnt++] = sweepLine(r[i - 1].x, -k, 2. * k * r[i - 1].x, -k * r[i - 1].x * r[i - 1].x),
			sl[cnt++] = sweepLine(r[i].x, k, -2. * k * r[i].x, k * r[i].x * r[i].x);
		else
			k = -.5 * dy / dx,
			sl[cnt++] = sweepLine(r[i].x, -k, 2. * k * r[i].x, -k * r[i].x * r[i].x),
			sl[cnt++] = sweepLine(r[i - 1].x, k, -2. * k * r[i - 1].x, k * r[i - 1].x * r[i - 1].x);
	}
	std::sort(sl, sl + cnt);
	for (j = i = 0; i < cnt; ++i) {
		for (; j < q && qry[j].first <= sl[i].x; ++j) ans[qry[j].second] = (A * qry[j].first + B) * qry[j].first + C;
		A += sl[i].a, B += sl[i].b, C += sl[i].c;
	}
	for (; j < q; ++j) ans[qry[j].second] = C;
}

int main() {
	int i, j; double x, A = 0;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> q;
	for (i = 0; i < n; ++i) cin >> poly[i];
	for (j = 0, i = 1; i < n; ++i) if (poly[i].y < poly[j].y) j = i;
	std::rotate(poly, poly + j, poly + n), poly[n] = *poly;
	for (j = 0, i = 1; i < n; ++i) if (poly[i].y > poly[j].y) j = i;
	for (i = 0; i < n; ++i) A += poly[i] ^ poly[i + 1];
	if (A < 0) A = -A, std::reverse(poly + 1, poly + n), j = n - j;
	L = n - j + 1, std::reverse_copy(poly + j, poly + (n + 1), l),
	R = j + 1,     memcpy(r, poly, R * sizeof(vec2)), A *= .5;

	m[M++] = *poly;
	for (i = j = 1; i < L || j < R; )
		if (j != R && i != L && l[i].y == r[j].y)
			m[M++] = vec2((l[i].x + r[j].x) * .5, l[i].y), ++i, ++j;
		else if (j == R || (i != L && l[i].y < r[j].y))
			m[M++] = vec2((l[i].x + getX(r[j - 1], r[j], l[i].y)) * .5, l[i].y), ++i;
		else
			m[M++] = vec2((getX(l[i - 1], l[i], r[j].y) + r[j].x) * .5, r[j].y), ++j;

	for (i = 0; i < q; ++i) cin >> x, qry[i] = pr(x, i);
	std::sort(qry, qry + q), cout.precision(12),
	sweepTo(L, l, M, m, ansL), sweepTo(M, m, R, r, ansR);
	for (i = 0; i < q; ++i) cout << A - ansL[i] + ansR[i] << '\n';
	return 0;
}