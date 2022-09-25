#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;
int solve();


int main()
{
    srand(2317);
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

ld go(ld dx, ld dy, ld vx, ld vy, ld R)
{
    ld D = hypotl(dx, dy);
    if (D == 0)
        return 0;
    ld rsinb = fabsl(vx * dy - vy * dx) / D;
    ld rcosb = sqrtl(max(0.L, R * R - rsinb * rsinb));
    ld v = rcosb + (vx * dx + vy * dy) / D;
    return D / v;
}

int solve()
{
    ld x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ld vmax, t;
    cin >> vmax >> t;
    ld vx1, vy1;
    cin >> vx1 >> vy1;
    
    ld dx = x2 - x1;
    ld dy = y2 - y1;
    ld T = go(dx, dy, vx1, vy1, vmax);
    if (T <= t)
    {
        cout << T << '\n';
        return 0;
    }
    ld vx2, vy2;
    cin >> vx2 >> vy2;
    x2 -= (vx1 - vx2) * t;
    y2 -= (vy1 - vy2) * t;
    dx = x2 - x1;
    dy = y2 - y1;
    T = go(dx, dy, vx2, vy2, vmax);
    cout << T << '\n';
    return 0;
}