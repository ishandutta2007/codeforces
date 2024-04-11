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

const int maxn = 105;
const int maxc = 305;

int a[maxn];
int d[maxn * maxc][maxc][2];
int cnt[maxc];

int solve()
{
    int n, t;
    cin >> n >> t;
    forn (i, n)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int extra = t > maxc ? t - maxc : 0;
    t = min(t, maxc);
    forn (i, maxn * maxc)
        forn (k, maxc)
            forn (q, 2)
                d[i][k][q] = -INF;
    d[0][0][0] = 0;
    forn (i, n * t)
        forn (minv, maxc)
            forn (q, 2)
            {
                d[i + 1][minv][q] = max(d[i + 1][minv][q], d[i][minv][q]);
                int val = a[i % n];
                if (minv > val)
                    continue;
                d[i + 1][val][q] = max(d[i + 1][val][q], d[i][minv][q] + 1);
                if (q)
                    continue;
                d[i + 1][val][1] = max(d[i + 1][val][1], d[i][minv][q] + 1 + cnt[val] * extra);
            }
    int res = 0;
    forn (minv, maxc)
        forn (q, 2)
            res = max(res, d[t * n][minv][q]);
    cout << res << '\n';
    return 0;
}