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

const int maxn = 5001;

const int mod = 1000000007;

int d[maxn][2];

int c[maxn][maxn];

void add(int &a, int b)
{
    a += b;
    a %= mod;
}

int mul(ll a, ll b)
{
    return (a * b) % mod;
}

int solve()
{
    int n;
    cin >> n;
    forn (i, n + 1)
        c[i][0] = c[i][i] = 1;
    forn (i, n + 1)
        forab (j, 1, i)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    d[0][0] = 1;
    forn (i, n)
        forn (j, 2)
            forab (k, i + 1, n + 1)
                forn (j2, 2)
                {
                    if (j2 && k > i + 1)
                        continue;
                    add(d[k][j || j2], mul(d[i][j], c[n - i - 1][k - i - 1]));
                }
    cout << d[n][1] << '\n';
    return 0;
}