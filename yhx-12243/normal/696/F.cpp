#include <bits/stdc++.h>

typedef long double ld;
const int N = 654;
const ld eps = 1e-10;

#define lt(x, y) ((x) < (y) - eps)
#define gt(x, y) ((x) > (y) + eps)
#define le(x, y) ((x) <= (y) + eps)
#define ge(x, y) ((x) >= (y) - eps)
#define eq(x, y) (le(x, y) && ge(x, y))
#define dot(x, y, z) (((y) - (x)) * ((z) - (x)))
#define cross(x, y, z) (((y) - (x)) ^ ((z) - (x)))

struct vec2 {
	ld x, y;
	vec2 (ld x0 = 0.0, ld y0 = 0.0) : x(x0), y(y0) {}
	vec2 * read() {scanf("%Lf%Lf", &x, &y); return this;}
	inline vec2 operator * (ld k) const {return vec2(x * k, y * k);}
	inline ld operator ^ (const vec2 &B) const {return x * B.y - y * B.x;}
};

struct line {
	ld A, B, C;
	line (ld A0 = 0.0, ld B0 = 0.0, ld C0 = 0.0) : A(A0), B(B0), C(C0) {}
	line (const vec2 &u, const vec2 &v) : A(u.y - v.y), B(v.x - u.x), C(u ^ v) {}
	inline line operator - () const {return line(-A, -B, -C);}
	inline vec2 normVec() const {return vec2(A, B);}
	inline ld norm2() const {return A * A + B * B;}
	inline ld operator () (const vec2 &P) const {return A * P.x + B * P.y + C;}
};

inline vec2 intersection(const line u, const line v) {
	ld Det = 1.0 / (u.A * v.B - u.B * v.A);
	return vec2(u.B * v.C - u.C * v.B, u.C * v.A - u.A * v.C) * Det;
}

inline line angle_bisector(const line u, const line v) {
	ld U = sqrtl(u.norm2()), V = sqrtl(v.norm2());
	return line(u.A * V + v.A * U, u.B * V + v.B * U, u.C * V + v.C * U);
}

inline ld dis2(const vec2 P, const line l) {return l(P) * l(P) / l.norm2();}

int n;
vec2 p[N], center[N][N];
line v[N];
ld weight[N][N];

int main() {
	int i, j, k; vec2 mp, bp, lp; ld ans = INFINITY, cur;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) p[i].read();
	std::copy(p, p + n, p + n), p[2 * n] = *p;
	for (i = 0; i < 2 * n; ++i) v[i] = line(p[i], p[i + 1]);
	for (i = 0; i < n; ++i) std::fill(weight[i], weight[i] + n, INFINITY);
	for (i = 0; i < n; ++i) {
		center[i][i] = p[i], weight[i][i] = 0.;
		k = i + 1;
		for (j = i + 1; ge(v[i].normVec() ^ v[j].normVec(), 0); ++j) {
			for (; k < j && le(dis2(p[k + 1], v[i]), dis2(p[k + 1], v[j])); ++k);
			mp = intersection(v[k], angle_bisector(v[i], -v[j]));
			center[i][j % n] = mp;
			weight[i][j % n] = 0.5 * (dis2(mp, v[i]) + dis2(mp, v[j]));
		}
	}
	for (i = 0; i < n; ++i)
		for (k = (i + n - 1) % n, j = i; j < i + n - 1; ++j) {
			cur = std::max(weight[i][j % n], weight[(j + 1) % n][k]);
			if (cur < ans) ans = cur, bp = center[i][j % n], lp = center[(j + 1) % n][k];
		}
	assert(std::isfinite(ans));
	if (ans < eps) ans = 0.;
	printf("%.16Lg\n%.16Lg %.16Lg\n%.16Lg %.16Lg\n", sqrtl(ans), bp.x, bp.y, lp.x, lp.y);
	return 0;
}