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

const int maxn = 3000001;
int a[maxn];

int solve()
{
    int n;
    cin >> n;
    forn (i, n)
    {
        int x;
        scanf("%d", &x);
        a[x]++;
    }
    ll res = 0;
    forn (i, maxn - 1)
    {
        res += a[i] % 2;
        a[i + 1] += a[i] / 2;
    }
    cout << res << '\n';
    return 0;
}