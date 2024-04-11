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
    assert(freopen("a.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

int solve()
{
    ll a, b, c, l;
    cin >> a >> b >> c >> l;
    ll res = (l + 3) * (l + 2) * (l + 1) / 6;

    forn (i, l + 1)
    {
        ll rem = a + i - b - c;
        if (rem < 0)
            continue;
        rem = min(rem, l - i);
        res -= (rem + 2) * (rem + 1) / 2;
    }
    swap(a, b);
    forn (i, l + 1)
    {
        ll rem = a + i - b - c;
        if (rem < 0)
            continue;
        rem = min(rem, l - i);
        res -= (rem + 2) * (rem + 1) / 2;
    }
    swap(a, c);
    forn (i, l + 1)
    {
        ll rem = a + i - b - c;
        if (rem < 0)
            continue;
        rem = min(rem, l - i);
        res -= (rem + 2) * (rem + 1) / 2;
    }

    cout << res << '\n';
    return 0;
}