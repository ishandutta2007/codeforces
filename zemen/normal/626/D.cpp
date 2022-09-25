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
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 5500;
int a[maxn];
ld pr[maxn];
ld sum[maxn];

int solve()
{
    int n;
    cin >> n;
    forn (i, n)
        cin >> a[i];
    sort(a, a + n);
    forn (i, n)
        forn (j, i)
            pr[a[i]- a[j]] += 2 / ld(n * (n - 1));
    for (int i = maxn - 2; i >= 0; --i)
        sum[i] = pr[i + 1] + sum[i + 1];
    ld res = 0;
    forn (i, maxn)
        forn (j, maxn)
        {
            if (i + j < maxn)
                res += pr[i] * pr[j] * sum[i + j];
        }
    cout << res << '\n';
    return 0;
}