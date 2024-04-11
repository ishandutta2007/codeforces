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

const int maxn = 153;
int d[2][maxn * maxn / 2][maxn];

inline void upd(int &a, int b)
{
    a = min(a, b);
}

int a[maxn];

int solve()
{
    int n, k, s;
    cin >> n >> k >> s;
    forn (i, n)
        cin >> a[i];
    s = min(s, n * n / 2);
    int BOUND = n * n / 2 + 1;
    forn (sum, BOUND)
        forn (i, n + 1)
            d[0][sum][i] = INF;
    d[0][s][0] = 0;

    int q = 0;
    forn (id, k)
    {
        forn (i, BOUND)
            fill(d[q ^ 1][i], d[q ^ 1][i] + n + 1, INF);
        forn (sum, BOUND)
            forn (last, n)
            {
                upd(d[q][sum][last + 1], d[q][sum][last]);
                if (sum >= last - id)
                    upd(d[q ^ 1][sum - last + id][last + 1], d[q][sum][last] + a[last]);
            }
        q ^= 1;
    }
    int res = INF;
    forn (sum, BOUND)
        forn (last, n + 1)
            upd(res, d[q][sum][last]);
    cout << res << '\n';
    return 0;
}