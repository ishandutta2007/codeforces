#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<long double, long double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

bool g(long double a1, long double a2, long double b1, long double b2, long double c1, long double c2, long double d1, long double d2) {
//    cerr << a1 << ' ' << a2 << ' ' << b1 << ' ' << b2 << ' ' << c1 << ' ' << c2 << ' ' << d1 << ' ' << d2 << endl;
    if (a1 >= a2 || b1 >= b2 || c1 >= c2 || d1 >= d2) return false;
    int za = (a1 < 0) ? -1 : 1;
    int zb = (b1 < 0) ? -1 : 1;
    int zc = (c1 < 0) ? -1 : 1;
    int zd = (d1 < 0) ? -1 : 1;
    if (za*zd-zb*zc) return false;
    if (za == -1) {
        a1 = -a1; a2 = -a2;
        swap(a1,a2);
    }
    if (zb == -1) {
        b1 = -b1; b2 = -b2;
        swap(b1,b2);
    }
    if (zc == -1) {
        c1 = -c1; c1 = -c2;
        swap(c1,c2);
    }
    if (zd == -1) {
        d1 = -d1; d2 = -d2;
        swap(d1,d2);
    }
//    cerr << a1 << ' ' << a2 << ' ' << b1 << ' ' << b2 << ' ' << c1 << ' ' << c2 << ' ' << d1 << ' ' << d2 << endl;
/*    double mi1 = a1/b2;
    double ma1 = a2/b1;
    double mi2 = c1/d2;
    double ma2 = c2/d1;
    cerr << mi1 << ' ' << ma1 << ' ' << mi2 << ' ' << ma2 << endl;
    if (mi1 > ma2) return false;
    if (ma1 < mi2) return false;*/
    if (a1*d1 > b2*c2) return false;
    if (b1*c1 > a2*d2) return false;
    return true;    
}

pdd mm(long double a1, long double a2, long double b1, long double b2) {
    pdd res(a1*b1, a1*b1);
    long double a[2] = {a1,a2};
    long double b[2] = {b1,b2};
    for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) {
        res.first = min(res.first, a[i]*b[j]);
        res.second = max(res.second, a[i]*b[j]);
    }
    return res;
}

bool f(long double a1, long double a2, long double b1, long double b2, long double c1, long double c2, long double d1, long double d2) {
    pdd t1 = mm(a1,a2,d1,d2);
    pdd t2 = mm(b1,b2,c1,c2);
    return t1.first <= t2.second && t1.second >= t2.first;
/*    bool za = (a1*a2 < 0);
    bool zb = (b1*b2 < 0);
    bool zc = (c1*c2 < 0);
    bool zd = (d1*d2 < 0);
    if (za && zb) return true;
    if (za && zc) return true;
    if (zd && zb) return true;
    if (zd && zc) return true;
    if (za) return f(a1,0,b1,b2,c1,c2,d1,d2) || f(0,a2,b1,b2,c1,c2,d1,d2);
    if (zb) return f(a1,a2,b1,0,c1,c2,d1,d2) || f(a1,a2,0,b2,c1,c2,d1,d2);
    if (zc) return f(a1,a2,b1,b2,c1,0,d1,d2) || f(a1,a2,b1,b2,0,c2,d1,d2);
    if (zd) return f(a1,a2,b1,b2,c1,c2,d1,0) || f(a1,a2,b1,b2,c1,c2,0,d2);
    return g(a1,a2,b1,b2,c1,c2,d1,d2);*/
}

int main() {
//    cerr << f(-1,1,2,4,2,4,-1,1) << endl;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
//    long double mi = min(abs(a), min(abs(b), min(abs(c),abs(d))));
//    int mi = -1e9, ma = 1e9, step = 5e8;
//    for (int a = mi; a <= ma; a += step) for (int b = mi; b <= ma; b += step) for (int c = mi; c <= ma; c += step) for (int d = mi; d <= ma; d += step) 
    {
//        cerr << a << ' ' << b << ' ' << c << ' ' << d << endl;
        long double l = 0, r = 1.1e9;
        for (int t = 0; t < 200; ++t) {
            long double x = (l+r) / 2;
//            fprintf(stderr, "%.10lf %.10lf %.10lf\n",(double)l,(double)r,(double)x);
            if (f(a-x, a+x, b-x, b+x, c-x, c+x, d-x, d+x)) {
                r = x;
            } else {
                l = x;
            }
        }
        printf("%.10lf\n", (double)((l+r)/2));
    }
    return 0;
}