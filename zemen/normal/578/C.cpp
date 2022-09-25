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

const int maxn = 200050;

int a[maxn];
ll s[maxn];
int n;

ld get(ld x)
{
    ld vmin = 1e18, vmax = -1e18;
    forn (i, n + 1)
    {
        ld c = s[i] - i * x;
        vmin = min(vmin, c);
        vmax = max(vmax, c);
    }
    return vmax - vmin;
}

int solve()
{
    cin >> n;
    forn (i, n)
        cin >> a[i];
    forn (i, n)
        s[i + 1] = s[i] + a[i];
    ld minx = -maxn, maxx = maxn;
    forn (iter, 100)
    {
        ld cl = (minx * 21 + maxx * 20) / 41;
        ld cr = (minx * 20 + maxx * 21) / 41;
        ld vl = get(cl);
        ld vr = get(cr);
        if (vl < vr)
            maxx = cr;
        else
            minx = cl;
    }
    cout << get((minx + maxx) / 2) << '\n';
    return 0;
}