#include <cstdio>
#include <algorithm>
using namespace std;

typedef long double ldouble;

inline ldouble read() {
    double x;
    scanf("%lf", &x);
    return x;
}

const ldouble eps = 1e-11;

pair<ldouble, ldouble> solve(ldouble x, ldouble v, ldouble l, ldouble r) {
    if (fabsl(v) < eps) {
        if (l + eps < x && x + eps < r) {
            return make_pair(-1e100, 1e100);
        } else {
            return make_pair(1e100, -1e100);
        }
    } else {
        ldouble t1 = (l - x) / v;
        ldouble t2 = (r - x) / v;
        if (t1 > t2)
            swap(t1, t2);
        return make_pair(t1, t2);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    ldouble x1, y1, x2, y2;
    x1 = read();
    y1 = read();
    x2 = read();
    y2 = read();
    ldouble mn = 0, mx = 1e100;
    for (int i = 0; i < n; i++) {
        ldouble x, y, vx, vy;
        x = read();
        y = read();
        vx = read();
        vy = read();
        auto prx = solve(x, vx, x1, x2);
        auto pry = solve(y, vy, y1, y2);
        if (mn < prx.first)
            mn = prx.first;
        if (mn < pry.first)
            mn = pry.first;
        if (mx > prx.second)
            mx = prx.second;
        if (mx > pry.second)
            mx = pry.second;
    }
    if (mx - mn > eps) {
        double ans = mn;
        printf("%.20lf\n", ans);
    } else {
        printf("-1\n");
    }
}