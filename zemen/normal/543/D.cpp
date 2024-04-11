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
    freopen("d.in", "r", stdin);
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 200050;
const int mod = 1000000007;

int mul(ll a, ll b)
{
    return (a * b) % mod;
}

void add(int &a, int b)
{
    a += b;
    a %= mod;
}

vector<int> g[maxn];
int d[maxn];

void dfs(int u, int prev = -1)
{
    d[u] = 1;
    for (int v: g[u])
    {
        if (v == prev)
            continue;
        dfs(v, u);
        d[u] = mul(d[u], d[v]);
    }
    add(d[u], 1);
}

int ans[maxn];

int binpow(ll a, ll x)
{
    ll res = 1;
    while (x)
    {
        if (x & 1)
            res = mul(res, a);
        x >>= 1;
        a = mul(a, a);
    }
    return res;
}

int rev(int a)
{
    return binpow(a, mod - 2);
}

void calc(int u, int prev = -1)
{
    ans[u] = d[u];
    add(ans[u], mod - 1);
    int zeros = 0;
    ll prod = 1;
    for (int v: g[u])
    {
        zeros += (d[v] == 0);
        if (d[v])
            prod = mul(prod, d[v]);
    }
    for (int v: g[u])
    {
        if (v == prev)
            continue;
        ll cprod = prod;
        if (d[v])
            cprod = mul(cprod, rev(d[v]));
        if (zeros > 1 || (zeros == 1 && d[v]))
            cprod = 0;
        int old_d = d[u];
        int old_dv = d[v];
//        cerr << u << ' ' << v << ' ' << cprod << '\n';
        d[u] = cprod;
        add(d[u], 1);
        add(d[v], mod - 1);
        d[v] = mul(d[v], d[u]);
        add(d[v], 1);
        calc(v, u);
        d[u] = old_d;
        d[v] = old_dv;
    }
}

int solve()
{
    int n;
    cin >> n;
    forn (i, n - 1)
    {
        int u;
        scanf("%d", &u);
        g[u - 1].push_back(i + 1);
        g[i + 1].push_back(u - 1);
    }
    dfs(0);
    calc(0);
    forn (i, n)
        cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}