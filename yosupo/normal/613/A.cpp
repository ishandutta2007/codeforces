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
#include <iomanip>

using namespace std;
using ll = long long;

using R = double;
using P = complex<R>;

const R EPS = 1e-9;
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

/*
 
 */
bool lessP(const P &l, const P &r) {
    if (sgn(l.real(), r.real())) return l.real() < r.real();
    if (sgn(l.imag(), r.imag())) return l.imag() < r.imag();
    return false;
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


R distLP(const L &l, const P &p) {
    return abs(cross(vec(l), p-l.x)/abs(vec(l)));
}

R distSP(const L &s, const P &p) {
    P s2 = vec(s)*P(0, 1);
    if (ccw(s.x, s.x+s2, p) == 1) return abs(s.x-p);
    if (ccw(s.y, s.y+s2, p) == -1) return abs(s.y-p);
    return min(min(abs(s.x-p), abs(s.y-p)), distLP(s, p));
}

using Pol = vector<P>;

template<class C>
P cu(const C &p, int i) {
    int s = p.size();
    return p[(i%s+s)%s];
};

//0:P is out 1:P is on line 2:P is in
template<class C>
int contains(const C &pol, P p) {
    int in = -1;
    for (int i = 0; i < (int)pol.size(); i++) {
        P a=cu(pol,i)-p, b=cu(pol,i+1)-p;
        if (ccw(a, b, P(0, 0)) == 0) return 1;
        if (imag(a) > imag(b)) swap(a, b);
        if (imag(a) <= 0 && 0 < imag(b)) {
            if (cross(a, b) < 0) in *= -1;
        }
    }
    return in+1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int n;
    cin >> n;
    R x, y;
    cin >> x >> y;
    P st = P(x, y);
    Pol p;
    for (int i = 0; i < n; i++) {
        R u, v;
        cin >> u >> v;
        p.push_back(P(u, v));
    }
    R mi = 1e10, ma = -1;
    for (int i = 0; i < n; i++) {
        L l = L(cu(p, i), cu(p, i+1));
        mi = min(mi, distSP(l, st));
        ma = max(ma, abs(p[i]-st));
    }
    if (contains(p, st)) mi = 0;
    cout << (ma*ma - mi*mi) * PI << endl;
    return 0;
}