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

typedef __float128 R;
typedef complex<R> P;

/*
 -1 -> neg
  0 -> near 0
  1 -> pos
  */
int sgn(R a) {
    if (a < 0) return -1;
    return 1;
}


R cross(P a, P b) { return a.real()*b.imag() - a.imag()*b.real(); }
R dot(P a, P b) { return a.real()*b.real() + a.imag()*b.imag(); }


struct L {
    P x, y;
    L() {};
    L(P x, P y) :x(x), y(y) {};
};


typedef vector<P> Pol;

P cu(const Pol &p, int i) { 
    int s = p.size();
    return p[(i%s+s)%s];
};


bool insLS(const L &l, const L &s) {
    int sg1 = sgn(cross(l.y-l.x, s.x-l.x));
    int sg2 = sgn(cross(l.y-l.x, s.y-l.x));
    return (sg1 != sg2);
}

bool insPL(const Pol &pol, const L &s) {
    for (int i = 0; i < (int)pol.size(); i++) {
        P a=cu(pol,i), b=cu(pol,i+1);
        if (insLS(s, L(a, b))) return true;
    }
    return false;
}

P x, y;

bool solve(R md) {
    Pol v, w;
    v.push_back(x + P(md, md));
    v.push_back(x + P(-md, md));
    v.push_back(x + P(-md, -md));
    v.push_back(x + P(md, -md));
    w.push_back(y + P(md, md));
    w.push_back(y + P(-md, md));
    w.push_back(y + P(-md, -md));
    w.push_back(y + P(md, -md));
    for (P p: v) {
        if (insPL(w, L(P(0, 0), p))) return true;
    }
    for (P p: w) {
        if (insPL(v, L(P(0, 0), p))) return true;
    }
    return false;
}

int main() {
    ll aa, bb, cc, dd;
    cin >> aa >> bb >> cc >> dd;
    ll ma = max(max(abs(aa), abs(bb)), max(abs(cc), abs(dd)));
    R a = aa;
    R b = bb;
    R c = cc;
    R d = dd;
    x = P(a, b);
    y = P(c, d);
    R l = 0, r = ma;
    for (int i = 0; i < 200; i++) {
        R md = (l+r)/2;
        if (solve(md)) {
            r = md;
        } else {
            l = md;
        }
    }

    printf("%.20lf\n", (double)l);
    return 0;
}