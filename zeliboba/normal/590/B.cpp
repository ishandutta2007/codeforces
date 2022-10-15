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
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

double p2(double x) {
    return x*x;
}

int main() {
    vd y1(2), y(2);
    for (int i = 0; i < 2; ++i) scanf("%lf", &y1[i]);
    for (int i = 0; i < 2; ++i) {
        scanf("%lf", &y[i]);
        y[i] -= y1[i];
    }
    double v, t;
    scanf("%lf%lf", &v, &t);
    vd a(2), b(2);
    for (int i = 0; i < 2; ++i) scanf("%lf", &a[i]);
    for (int i = 0; i < 2; ++i) scanf("%lf", &b[i]);
    double l = 0, r = 1e18;
    while (r - l > 1e-8) {
        double x = (l + r) / 2;
        vd p(2);
        for (int i = 0; i < 2; ++i) {
            p[i] = min(x, t)*a[i] + max(0., x - t)*b[i];
        }
        if (p2(y[0] - p[0]) + p2(y[1] - p[1]) <= p2(x*v)) {
            r = x;
        } else {
            l = x;
        }
    }
    printf("%.8lf\n", (l+r)/2);
    return 0;
}