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

const int maxn = 200050;

int a[maxn];
int p[maxn];
int s[maxn];

int solve()
{
    int n, k, x;
    cin >> n >> k >> x;
    ll m = 1;
    forn (i, k)
        m *= x;
    forn (i, n)
    {
        scanf("%d", a + i);
        p[i + 1] = p[i] | a[i];
    }
    reverse(a, a + n);
    forn (i, n)
        s[i + 1] = s[i] | a[i];
    reverse(a, a + n);
    ll res = 0;
    forn (i, n)
        res = max(res, (m * a[i]) | p[i] | s[n - i - 1]);
    cout << res << '\n';
    return 0;
}