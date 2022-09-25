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
    int a[6];
    forn (i, 6)
        cin >> a[i];
    int w = a[0];
    ll res = 0;
    forn (i, min(a[1], a[5]))
    {
        res += 2 * w + 1;
        ++w;
    }
    forab (i, min(a[1], a[5]), max(a[1], a[5]))
        res += 2 * w;
    forab (i, max(a[1], a[5]), a[1] + a[2])
    {
        res += 2 * w - 1;
        --w;
    }
    assert(w == a[3]);
    cout << res << '\n';
    return 0;
}