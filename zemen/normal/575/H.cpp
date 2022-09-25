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

const int mod = 1000000007;
int mpow(int x, int k) {
    int a = 1;
    while (k) {
        if (k&1) a = (ll)a*x%mod;
        x = (ll)x*x%mod;
        k /= 2;
    }
    return a;
}
int rev(int x) { return mpow(x, mod-2); }

const int maxn = 2000500;
int f[maxn];
int rf[maxn];

int c(int n, int k) {
    return (ll)f[n] * rf[k] % mod * rf[n-k] % mod;
}

int solve()
{
    int n;
    cin >> n;
    f[0] = rf[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        f[i] = (ll)f[i - 1] * i % mod;
        rf[i] = (ll)rf[i - 1] * rev(i) % mod;
    }
    int res = 1;
    forn (i, n)
    {
        res = (res + c(2 * i + 2, i)) % mod;
        res = (res + c(2 * i + 2, i)) % mod;
        res = (res + c(2 * i + 2, i + 1)) % mod;
    }
    cout << res << '\n';
    return 0;
}

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