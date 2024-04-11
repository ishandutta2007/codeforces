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

pdd f(const vd & a, double x) {
    double mi = 0, ma = 0;
    double prevmi = 0, prevma = 0;
    double s = 0;
    for (int i = 0; i < a.size(); ++i) {
        s += a[i] - x;
        ma = max(ma, s - prevmi);
        mi = min(mi, s - prevma);
        prevmi = min(prevmi, s);
        prevma = max(prevma, s);
    }
    return pdd(abs(ma), abs(mi));
}

int main() {
    int n;
    scanf("%d", &n);
    vd a(n);
    for (int i = 0; i < n; ++i) scanf("%lf", &a[i]);
    double l = -10000, r = 10000;
    for (int i = 0; i < 100; ++i) {
        double x = (l + r) / 2;
        pdd res = f(a, x);
/*        if (abs(res.first - res.second) < 1e-7) {
            printf("%.8lf\n", res.first);
            return 0;
        }*/
        if (res.first > res.second) {
            l = x;
        } else {
            r = x;
        }
    }
    pdd res = f(a, (l + r) / 2);
    printf("%.8lf\n", max(abs(res.first), abs(res.second)));
    return 0;
}