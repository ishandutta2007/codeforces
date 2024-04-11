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

const int maxn = 2e5;
vector<int> g[maxn];
bool del[maxn];
int bamboo[maxn];
bool type2[maxn];

queue<int> o;

int solve()
{
    int n;
    cin >> n;
    forn (i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    forn (i, n)
        if (sz(g[i]) == 1)
            o.push(i);
    while (!o.empty())
    {
        int u = o.front();
        del[u] = true;
        o.pop();
        for (int v: g[u])
        {
            if (del[v])
                continue;
            if (sz(g[v]) == 2)
                o.push(v);
            else
                ++bamboo[v];
        }
    }
    bool fail = false;
    forn (i, n)
    {
        if (del[i])
            continue;
        if (sz(g[i]) <= 3 && sz(g[i]) <= bamboo[i] + 1)
            type2[i] = true;
    }
    forn (i, n)
    {
        if (type2[i] || del[i])
            continue;
        int deg = 0;
        for (int v: g[i])
            if (!type2[v] && !del[v])
                ++deg;
        if (deg > 2)
            fail = true;
    }
//    forn (i, n)
//        cout << (del[i] ? 1 : (type2[i] ? 2 : 3)) << ' ';
    if (fail)
        cout << "No\n";
    else
        cout << "Yes\n";
    return 0;
}