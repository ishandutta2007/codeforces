#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <random>
#include <complex>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <cassert>
 
using namespace std;
typedef long long ll;
typedef long double R;
typedef complex<R> P;
const R EPS = 1e-7;
const R PI = acos(-1);
R cross(P a, P b) { return imag(conj(a)*b); }
R dot(P a, P b) { return real(conj(a)*b); }
struct L {
    P x, y;
    L() {};
    L(P x, P y) :x(x), y(y) {};
};
bool insLS(const L &l, const L &s) {
    double a = cross(l.y-l.x, s.x-l.x);
    double b = cross(l.y-l.x, s.y-l.x);
    if ((a<EPS&&-EPS<b)||(b<EPS&&-EPS<a)) return true;
    return false;
}


int main() {
    P px, py;
    R a, b, c;
    cin >> a >> b;
    px = P(a, b);
    cin >> a >> b;
    py = P(a, b);
    L l = L(px, py);
    int m;
    cin >> m;
    int res = 0;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (a != 0) {
            px = P(-c/a, 0);
        } else {
            px = P(0, -c/b);
        }
        py = px + P(b, -a);
        if (insLS(L(px, py), l)) {
            res++;
            //cout << i << endl;
        }
    }
    cout << res << endl;
    return 0;
}