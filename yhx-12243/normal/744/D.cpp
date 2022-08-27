#include <bits/stdc++.h>

typedef long double ld;
typedef std::pair <ld, int> pr;
const int N = 1054, INF = 2003731;
const ld eps = 2e-9l, pi2 = 6.283185307179586476925286766559005768l;

struct vec2 {
	ld x, y;
	vec2 (ld x0 = 0.0, ld y0 = 0.0) : x(x0), y(y0) {}
	vec2 * read() {scanf("%Lf%Lf", &x, &y); return this;}
	inline vec2 operator - (const vec2 &B) const {return vec2(x - B.x, y - B.y);} 
	inline ld norm2() const {return x * x + y * y;}
	inline ld norm() const {return sqrtl(x * x + y * y);}
	inline bool operator == (const vec2 &B) const {return x == B.x && y == B.y;}
};


int Re, Bl;
vec2 r[N], b[N];
pr D[N * 20];

inline bool intersection(const vec2 O1, const vec2 O2, ld r, ld &beg, ld &end) {
	vec2 O12 = O2 - O1; ld d = O12.norm(), Cos = .5 * d / r, sAng = acosl(Cos), iAng = atan2l(O12.y, O12.x);
	return !(O1 == O2) && -1. <= Cos && Cos <= 1. ? (iAng < 0. ? iAng += pi2 : 0., (beg = iAng - sAng) < 0. ? beg += pi2 : 0., (end = iAng + sAng) > pi2 ? end -= pi2 : 0., true) : false;
}

int check(const vec2 O, ld radius, bool cover_red = false) {
	int i, s = 0, cnt = 0; ld il, ir;
	if (cover_red) D[cnt++] = pr(0, 1);
	for (i = 0; i < Re; ++i)
		if (intersection(O, r[i], radius, il, ir)) {
			if (il <= ir) D[cnt++] = pr(il, 1), D[cnt++] = pr(ir, -1);
			else D[cnt++] = pr(0, 1), D[cnt++] = pr(ir, -1), D[cnt++] = pr(il, 1);
		}
	for (i = 0; i < Bl; ++i)
		if (intersection(O, b[i], radius, il, ir)) {
			if (il <= ir) D[cnt++] = pr(il, -INF), D[cnt++] = pr(ir, INF);
			else D[cnt++] = pr(0, -INF), D[cnt++] = pr(ir, INF), D[cnt++] = pr(il, -INF);
		}
	std::sort(D, D + cnt);
	for (i = 0; i < cnt; ++i) if ((s += D[i].second) > 0) return true;
	return false;
}

int main() {
	int i; ld L = 1., R, M;
	char *_ = new char; std::mt19937 gen(time(NULL) + (unsigned long)_); delete _;
	scanf("%d%d", &Re, &Bl);
	for (i = 0; i < Re; ++i) r[i].read();
	for (i = 0; i < Bl; ++i) b[i].read();
	std::shuffle(r, r + Re, gen), std::shuffle(b, b + Bl, gen);
	for (i = 0; i < Re; ++i)
		if (check(r[i], L, true)) {
			for (R = 1e9; L + eps < R; check(r[i], M = (L + R) * .5, true) ? (L = M) : (R = M));
			L = (L + R) * .5;
		}
	for (i = 0; i < Bl; ++i)
		if (check(b[i], L)) {
			for (R = 1e9; L + eps < R; check(b[i], M = (L + R) * .5) ? (L = M) : (R = M));
			L = (L + R) * .5;
		}
	printf("%.12Lg\n", L > 1e9 - .3 ? -1. : L);
	return 0;
}