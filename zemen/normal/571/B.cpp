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

const int maxn = 1e6;
const int maxk = 5005;

int a[maxn];
ll d[maxk][maxk];

int solve()
{
    int n, k;
    cin >> n >> k;
    forn (i, n)
        scanf("%d", a + i);
    sort(a, a + n);
    int s = n / k;
    int r = n % k;
    forn (i, k + 1)
        forn (j, k + 1)
            d[i][j] = INFL;
    d[0][0] = 0;
    forn (i, k)
        forn (j, k)
        {
            if (d[i][j] == INFL)
                continue;
            int q = i * s + j;
            if (q + s < n)
                d[i + 1][j + 1] = min(d[i + 1][j + 1], d[i][j] + a[q + s] - a[q]);
            if (q + s - 1 < n)
                d[i + 1][j] = min(d[i + 1][j], d[i][j] + a[q + s - 1] - a[q]);
        }
    cout << d[k][r] << '\n';
    return 0;
}