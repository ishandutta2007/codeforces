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

const int maxn = 200100;
vector<int> g[maxn];
int d[maxn], f[maxn];

void dfs(int u, int prev = -1)
{
    int sum = 0, max1 = -INF, max2 = -INF;
    for (int v: g[u])
    {
        if (v == prev)
            continue;
        dfs(v, u);
        sum += d[v];
        int delta = f[v] - d[v];
        if (delta > max1)
        {
            max2 = max1;
            max1 = delta;
        }
        else if (delta > max2)
            max2 = delta;
    }
    d[u] = sum;
    d[u] = max(d[u], sum + max1 + 1);
    f[u] = max(0, sum + max1 + 1);
    d[u] = max(d[u], sum + max1 + max2 + 2);
}

int solve()
{
    int n;
    ll x, y;
    cin >> n >> x >> y;
    forn (i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (x > y)
    {
        ll res = ll(y) * (n - 1);
        forn (i, n)
            if (sz(g[i]) == n - 1)
                res += x - y, i = n;
        cout << res << '\n';
        return 0;
    }
    int ROOT = 0;
    dfs(ROOT);
    ll res = (n - 1) * ll(y) + d[ROOT] * ll(x - y);
    cout << res << '\n';
    return 0;
}