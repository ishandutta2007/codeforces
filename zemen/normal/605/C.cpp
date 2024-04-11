#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef __float128 ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;
int solve();


int main()
{
    srand(2317);
    cout.precision(20);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

typedef pair<ll, ll> Point;
#define x first
#define y second

ll prod(const Point &a, const Point &b)
{
    return a.x * b.y - a.y * b.x;
}

ll abs2(const Point &a)
{
    return a.x * a.x + a.y * a.y;
}

bool cmp(const Point &a, const Point &b)
{
    ll p = prod(a, b);
    if (p)
        return p > 0;
    return abs2(a) < abs2(b);
}

Point diff(const Point &a, const Point &b)
{
    return Point(a.x - b.x, a.y - b.y);
}

const int maxn = 100100;
Point p[maxn];

ld prod2(ld x1, ld y1, ld x2, ld y2, ld x3, ld y3)
{
    return (x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3);
}

ld calc(ld x1, ld y1, ld x2, ld y2, ld x, ld y)
{
    ld L = 0, R = 1e19;
    forn (iter, 10000)
    {
        ld C = (L + R) / 2;
        ld X = prod2(x, y, x2 * C, y2 * C, x1 * C, y1 * C);
        if (X > 0)
            L = C;
        else
            R = C;
    }
//    ld X = prod2(x, y, x2 * L, y2 * L, x1 * L, y1 * L);
//    cerr << L << ' ' << X << '\n';
    return (L + R) / 2;
}

int solve()
{
    int n;
    Point dir;
    cin >> n >> dir.x >> dir.y;
    ld res = 1e19;
    forn (i, n)
    {
        cin >> p[i].x >> p[i].y;
        res = min(res, max((ld) dir.x / p[i].x, (ld) dir.y / p[i].y));
    }
    sort(p, p + n, cmp);
    n = unique(p, p + n) - p;
    vector<Point> hull;
    hull.emplace_back(0, 0);
    forn (i, n)
    {
        Point c = p[i];
        while (sz(hull) > 1 && prod(diff(c, hull.back()), diff(hull.back(), hull[sz(hull) - 2])) > 0)
            hull.pop_back();
        hull.push_back(c);
    }
    reverse(hull.begin(), hull.end());
    hull.pop_back();
    reverse(hull.begin(), hull.end());

    int pos = lower_bound(hull.begin(), hull.end(), dir, cmp) - hull.begin();
//    cerr << pos << '\n';
    if (pos != 0 && pos != sz(hull))
    {
        Point a = hull[pos - 1];
        Point b = hull[pos];
        res = min(res, calc(a.x, a.y, b.x, b.y, dir.x, dir.y));
    }
    cout << (long double) res << '\n';
    return 0;
}