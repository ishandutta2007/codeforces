#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
typedef long long ll;

typedef double R;
typedef complex<R> P;

const R EPS = 1e-10;
const R PI = acos((R)(-1));

/*
 -1 -> neg
  0 -> near 0
  1 -> pos
  */
int sgn(R a) {
	if (a < -EPS) return -1;
	if (a > EPS) return 1;
	return 0;
}

/*
 -1 -> a > b
  0 -> a near b
  1 -> a < b
 */
int sgn(R a, R b) {
	return sgn(b-a);
}

bool near(const P &a, const P &b) {
	return !sgn(abs(a-b));
}


R cross(P a, P b) { return a.real()*b.imag() - a.imag()*b.real(); }
R dot(P a, P b) { return a.real()*b.real() + a.imag()*b.imag(); }

/* 1->cclock
  -1->clock
   0->on
   2->back
  -2->front
  */
int ccw(P a, P b, P c) {
	assert(!near(a, b));
	if (near(a, c) || near(b, c)) return 0;
	int s = sgn(cross(b-a, c-a));
	if (s) return s;
	if (dot(b-a, c-a) < 0) return 2;
	if (dot(a-b, c-b) < 0) return -2;
	return 0;
}

/*
 
 */
bool lessP(const P &l, const P &r) {
	if (sgn(l.real(), r.real())) return l.real() < r.real();
	if (sgn(l.imag(), r.imag())) return l.imag() < r.imag();
	return false;
}

struct L {
    P x, y;
    L() {}
    L(P x, P y) :x(x), y(y) {}
};

P vec(const L &l) {
    return l.y - l.x;
}

R abs(const L &l) {
    return abs(vec(l));
}

R arg(const L &l) {
    return arg(vec(l));
}

bool insLS(const L &l, const L &s) {
    int a = ccw(l.x, l.y, s.x);
    int b = ccw(l.x, l.y, s.y);
    if (a == 1 && b == 1) return false;
    if (a == -1 && b == -1) return false;
    return true;
}

int crossLL(const L &l, const L &m, P &r) {
    L mm = L(m.x - l.x, m.y - l.x);
    mm.x *= polar<R>(1.0, -arg(l));
    mm.y *= polar<R>(1.0, -arg(l));
    if (sgn(vec(mm).imag()) == 0) {
        r = l.x;
        if (sgn(mm.x.imag()) == 0) return -1;
        return 0;
    }
    r = mm.x - vec(mm) * (mm.x.imag() / vec(mm).imag());
    r *= polar<R>(1.0, arg(l));
    r += l.x;
    return 1;
}

typedef vector<P> Pol;

template<class C>
P cu(const C &p, int i) {
	int s = p.size();
	return p[(i%s+s)%s];
};

Pol convex(Pol p) {
	sort(p.begin(), p.end(), lessP);
	if (p.size() <= 2) return p;
	Pol up;
	for (P d: p) {
		while (up.size() > 1 && ccw(up[up.size()-2], up[up.size()-1], d) == 1) up.pop_back();
		up.push_back(d);
	}
	reverse(up.begin(), up.end());
	Pol down;
	for (P d: p) {
		while (down.size() > 1 && ccw(down[down.size()-2], down[down.size()-1], d) == -1) down.pop_back();
		down.push_back(d);
	}
	down.insert(down.begin(), up.begin()+1, up.end()-1);
	return down;
}

const int MN = 100100;
int n;
P p;
Pol a, po;

void solve() {
	po = convex(a);
	R re = 1e9;
	for (P q: po) {
		re = min(re,
			max(p.real() / q.real(), p.imag() / q.imag())
		);
	}
	int n = (int)po.size();
	for (int i = 0; i < n; i++) {
		P x = cu(po, i), y = cu(po, i+1);
		if (insLS(L(P(0, 0), p), L(x, y))) {
			P q;
			crossLL(L(P(0, 0), p), L(x, y), q);
			re = min(re,
				max(p.real() / q.real(), p.imag() / q.imag())
			);
		}
	}
	printf("%.20lf\n", re);
}


int main() {
	double x, y;
	scanf("%d %lf %lf", &n, &x, &y);
	p = P(x, y);
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int aa, bb;
		scanf("%d %d", &aa, &bb);
		v.push_back(make_pair(aa, bb));
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (auto p: v) {
		a.push_back(P(p.first, p.second));
	}
	solve();
	return 0;
}