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

const int maxn = 100100;
int a[maxn], pos[maxn];

int solve()
{
    int n;
    cin >> n;
    forn (i, n)
    {
        cin >> a[i];
        --a[i];
        pos[a[i]] = i;
    }
    pos[n] = -1;
    int l = 0;

    int res = INF;
    forn (r, n + 1)
    {
        if (r > 0 && pos[r] < pos[r - 1])
        {
            res = min(res, n - (r - l));
            l = r;
        }
    }
    cout << res << '\n';
    return 0;
}