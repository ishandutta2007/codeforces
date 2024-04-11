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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int main() {
    int h,w,a;
    cin >> w >> h >> a;
    if (a % 180 == 0) {
        cout << w*(ll)h << endl;
        return 0;
    }
    if (a == 90) {
        ll mi = min(w,h);
        cout << mi*mi << endl;
        return 0;
    }
    double al = a / 180. * M_PI;
    double cs = cos(al), sn = sin(al);
    const int N = 70000000;
    double n = N;
    double wcs = w*cs, hcs = h*cs;
    double wsn = w*sn, hsn = h*sn;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < N; ++i) {
        double x = wcs - (2*i/n-1)*hsn;
        double y = wsn + (2*i/n-1)*hcs;
        if (abs(x) <= w && abs(y) <= h)
            ++cnt1;
        double x1 = (2*i/n-1)*wcs - hsn;
        double y1 = (2*i/n-1)*wsn + hcs;
        if (abs(x1) <= w && abs(y1) <= h)
            ++cnt2;
    }
//    cerr << cnt1 << ' ' << cnt2 << endl;
    printf("%.10lf\n", (cnt1+cnt2)/n*w*h);
    return 0;
}