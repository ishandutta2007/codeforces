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
using ll = long long;
using ull = unsigned long long;
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}

using R = double;
using P = complex<R>;
const int MN = 100100;
int main() {
    P a, b, t;
    R x, y;
    cin >> x >> y;
    a = P(x, y);
    cin >> x >> y;
    b = P(x, y);
    cin >> x >> y;
    t = P(x, y);
    int n;
    cin >> n;
    P p[MN];
    R sm = 0;
    for (int i = 0; i < n; i++) {
        R x, y;
        cin >> x >> y;
        p[i] = P(x, y);
        sm += abs(p[i]-t);
    }
    sm *= 2;

    R ans = 1e18;
    for (int i = 0; i < n; i++) {
        ans = min(ans, sm + (abs(p[i]-a) - abs(p[i]-t)));
        ans = min(ans, sm + (abs(p[i]-b) - abs(p[i]-t)));
    }
    R mi;
    mi = 1e18;
    for (int i = 0; i < n; i++) {
        ans = min(ans, sm + (abs(p[i]-a) - abs(p[i]-t)) + mi);
        mi = min(mi, abs(p[i]-b) - abs(p[i]-t));
    }
    mi = 1e18;
    for (int i = n-1; i >= 0; i--) {
        ans = min(ans, sm + (abs(p[i]-a) - abs(p[i]-t)) + mi);
        mi = min(mi, abs(p[i]-b) - abs(p[i]-t));
    }

    mi = 1e18;
    for (int i = 0; i < n; i++) {
        ans = min(ans, sm + (abs(p[i]-b) - abs(p[i]-t)) + mi);
        mi = min(mi, abs(p[i]-a) - abs(p[i]-t));
    }
    mi = 1e18;
    for (int i = n-1; i >= 0; i--) {
        ans = min(ans, sm + (abs(p[i]-b) - abs(p[i]-t)) + mi);
        mi = min(mi, abs(p[i]-a) - abs(p[i]-t));
    }


    printf("%.20lf\n", ans);
    return 0;
}