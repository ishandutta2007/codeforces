#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

struct pt {
    ll x, y;

    pt operator-(const pt &p) const {
        return pt{x - p.x, y - p.y};
    }

    ll operator%(const pt &p) const {
        return x * p.y - y * p.x;
    }

    ld abs() const {
        return hypotl(x, y);
    }
};

const int maxn = 1005;
pt p[maxn];

ld dist(pt p, pt a, pt b) {
    ld s = llabs((p - a) % (p - b));
    return s / (a - b).abs();
}

int main() {
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    int n;
    cin >> n;
    forn (i, n)
        cin >> p[i].x >> p[i].y;
    reverse(p + 1, p + n);
    p[n] = p[0];
    p[n + 1] = p[1];
    ld res = 1e18;
    forn (i, n) {
        pt a = p[(i+n-1)%n];
        pt b = p[i];
        pt c = p[(i+1)%n];
        res = min(res, dist(b, a, c) / 2);
        res = min(res, dist(a, b, c) / 2);
        res = min(res, dist(c, a, b) / 2);
    }
    cout << fixed;
    cout.precision(10);
    cout << res << '\n';
}