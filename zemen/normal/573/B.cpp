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

const int maxn = 2e5;
int a[maxn];

int l[maxn];
int r[maxn];

int solve()
{
    int n;
    cin >> n;
    forn (i, n)
        cin >> a[i + 1];
    n += 2;
    int bad = INF;
    forn (i, n)
    {
        bad = min(bad, a[i] - i);
        l[i] = bad + i;
//        cerr << l[i] << ' ';
    }
//    cerr << '\n';
    bad = INF;
    for (int i = n - 1; i >= 0; --i)
    {
        bad = min(bad, a[i] + i);
        r[i] = bad - i;
    }
    int res = 0;
    forn (i, n)
        res = max(res, min(l[i], r[i]));
    cout << res << '\n';
    return 0;
}