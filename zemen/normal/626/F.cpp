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
    assert(freopen("f.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 204;
const int maxk = 1004;
int a[maxn];

int d[maxn][maxn][maxk];

const int mod = int(1e9) + 7;

void add(int &a, int b)
{
    a += b;
    if (a >= mod)
        a -= mod;
}

int mul(ll a, ll b)
{
    return (a * b) % mod;
}

int solve()
{
    int n, k;
    cin >> n >> k;
    forn (i, n)
        cin >> a[i];
    sort(a, a + n);
    a[n] = a[n - 1];
    d[0][0][0] = 1;
    forn (i, n)
        forn (open, n + 1)
            forn (bad, k + 1)
            {
                //middle
                do
                {
                    int nbad = bad + (a[i + 1] - a[i]) * open;
                    if (nbad > k)
                        break;
                    add(d[i + 1][open][nbad], mul(d[i][open][bad], open + 1));
                } while (false);
                //open
                do
                {
                    int nbad = bad + (a[i + 1] - a[i]) * (open + 1);
                    if (nbad > k)
                        break;
                    add(d[i + 1][open + 1][nbad], d[i][open][bad]);
                } while (false);
                //close
                do
                {
                    if (open == 0)
                        break;
                    int nbad = bad + (a[i + 1] - a[i]) * (open - 1);
                    if (nbad > k)
                        break;
                    add(d[i + 1][open - 1][nbad], mul(d[i][open][bad], open));
                } while (false);
            }
    int res = 0;
    forn (i, k + 1)
        add(res, d[n][0][i]);
    cout << res << '\n';
    return 0;
}