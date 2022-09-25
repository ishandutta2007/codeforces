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
    freopen("a.in", "r", stdin);
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 600;

int d[maxn][maxn];
int a[maxn];

int mod;

void add(int &a, int b)
{
    a += b;
    a %= mod;
}

int solve()
{
    int n, m, b;
    cin >> n >> m >> b >> mod;
    ++b;
    forn (i, n)
        cin >> a[i];
    d[0][0] = 1;
    forn (i, n)
    {
        forn (j, m)
            forn (k, b - a[i])
                add(d[j + 1][k + a[i]], d[j][k]);
    }
    int sum = 0;
    forn (i, b)
        add(sum, d[m][i]);
    cout << sum << '\n';
    return 0;
}