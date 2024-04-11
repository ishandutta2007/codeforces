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
    cout.precision(15);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 1005;
const int maxw = 100005;

int a[maxn];

ld cnt[2][maxw];

int solve()
{
    int n, m;
    cin >> n >> m;
    if (m == 1)
    {
        cout << 1 << '\n';
        return 0;
    }
    int mysum = 0;
    forn (i, n)
    {
        scanf("%d", a + i);
        mysum += a[i];
    }
    int qw = 0;
    cnt[qw][0] = 1;
    forn (i, n)
    {
        forn (w, maxw)
            cnt[qw ^ 1][w] = 0;

        ld sumc = 0;
        forn (w, maxw)
        {
            ld goodsumc = sumc;
            if (w >= a[i])
                goodsumc -= cnt[qw][w - a[i]];
            cnt[qw ^ 1][w] = goodsumc;

            sumc += cnt[qw][w];
            if (w - m >= 0)
                sumc -= cnt[qw][w - m];
        }

        qw ^= 1;
    }
    ld DIV = 1;
    forn (i, n)
        DIV *= m - 1;
    ld res = 1;
    forn (w, mysum)
        res += (m - 1) * cnt[qw][w] / DIV;
    cout << res << '\n';
    return 0;
}