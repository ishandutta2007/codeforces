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
    ll a, b;
    cin >> a >> b;
    if (a < b)
    {
        cout << -1 << '\n';
        return 0;
    }
    ll k = (a + b) / b;
    if (k % 2)
        --k;
    ld x1 = k < 2 ? 2e18 : ld(a + b) / k;
    k = (a - b) / b;
    if (k % 2)
        --k;
    ld x2 = k <= 0 ? 2e18 : ld(a - b) / k;
    ld x = min(x1, x2);
    if (x > 1.5e18)
        cout << -1 << '\n';
    else
        cout << x << '\n';
    return 0;
}