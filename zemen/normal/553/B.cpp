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

const int maxn = 55;

int p[maxn];
ll f[maxn];

int solve()
{
    int n;
    ll k;
    cin >> n >> k;
    forn (i, n)
        cin >> p[i];
    f[0] = f[1] = 1;
    forab (i, 2, maxn)
        f[i] = f[i - 1] + f[i - 2];
    forn (i, n)
    {
        if (k - f[n - i - 1] >= 1)
        {
            k -= f[n - i - 1];
            cout << i + 2 << ' ' << i + 1 << ' ';
            ++i;
            continue;
        }
        else
        {
            cout << i + 1 << ' ';
            continue;
        }
    }
    cout << '\n';
    return 0;
}