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

const int maxn = 1000005;

const int mod = 1000000007;

int mul(ll a, ll b)
{
    return (a * b) % mod;
}

int fact[maxn];

int rev(int x, int deg = mod - 2)
{
    int res = 1;
    while (deg)
    {
        if (deg & 1)
            res = mul(res, x);
        deg /= 2;
        x = mul(x, x);
    }
    return res;
}

ll C(int n, int k)
{
    return mul(fact[n], rev(mul(fact[k], fact[n - k])));
}

int solve()
{
    fact[0] = 1;
    forab (i, 1, maxn)
        fact[i] = mul(fact[i - 1], i);
    int k;
    cin >> k;
    int ans = 1;
    int cnt = 0;
    forn (i, k)
    {
        int c;
        cin >> c;
        ans = mul(ans, C(cnt + c - 1, cnt));
        cnt += c;
    }
    cout << ans << '\n';
    return 0;
}