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

const int maxn = 3001;
const int maxw = 400001;
const int mod = 1000000007;

int x[maxn], y[maxn];

int fact[maxw];

int mul(ll a, ll b)
{
    return (a * b) % mod;
}

int rev(ll a, int x = mod - 2)
{
    ll res = 1;
    while (x)
    {
        if (x % 2)
            res = mul(res, a);
        x /= 2;
        a = mul(a, a);
    }
    return res;
}

int C(int n, int k)
{
    return mul(fact[n], rev(mul(fact[k], fact[n - k])));
}

int ways(int dx, int dy)
{
    return C(dx + dy, dx);
}

void sub(int &a, int b)
{
    a += mod - b;
    a %= mod;
}

int n;
int d[maxn];

void calc(int id)
{
    if (d[id] != -1)
        return;
    d[id] = ways(x[id], y[id]);
    forn (i, n)
    {
        if (x[i] > x[id])
            continue;
        if (y[i] > y[id])
            continue;
        if (i == id)
            continue;
        calc(i);
        sub(d[id], mul(d[i], ways(x[id] - x[i], y[id] - y[i])));
    }
//    cerr << id << ' ' << d[id] << '\n';
}

int solve()
{
    fact[0] = 1;
    forab (i, 1, maxw)
        fact[i] = mul(fact[i - 1], i);
    int h, w;
    cin >> h >> w >> n;
    forn (i, n)
    {
        cin >> x[i] >> y[i];
        --x[i], --y[i];
    }
    x[n] = h - 1, y[n] = w - 1;
    ++n;

    forn (i, n)
        d[i] = -1;
    forn (i, n)
        calc(i);
    cout << d[n - 1] << '\n';
    return 0;
}