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

const int maxn = 505;
int a[maxn];
int d[maxn][maxn];

int solve()
{
    int n;
    cin >> n;
    forn (i, n)
        cin >> a[i];
    forab (len, 1, n + 1)
        forn (l, n - len + 1)
        {
            int r = l + len;
            d[l][r] = d[l + 1][r] + 1;
            forab (k, l + 1, r)
            {
                if (a[k] != a[l])
                    continue;
                d[l][r] = min(d[l][r], max(1, d[l + 1][k]) + d[k + 1][r]);
            }
        }
    cout << d[0][n] << '\n';
    return 0;
}