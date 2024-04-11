#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

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
    freopen("c.in", "r", stdin);
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

int ex[800001];
vector <int> g[800001];
bool used[800001];

bool order = false;

void dfs(int u)
{
    while (sz(g[u]) > 0 && used[g[u].back()])
        g[u].pop_back();
    if (sz(g[u]) == 0)
        return;
    used[g[u].back()] = true;
    int v = ex[g[u].back()] ^ u;
    dfs(v);
    if (order)
        cout << u + 1 << ' ' << v + 1 << '\n';
    else
        cout << v + 1 << ' ' << u + 1 << '\n';
    order ^= 1;
    dfs(u);
}

int solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(i);
        g[v].push_back(i);
        ex[i] = u ^ v;
    }
    int bad = -1;
    for (int i = 0; i < n; ++i)
    {
        if (sz(g[i]) % 2 == 0)
            continue;
        if (bad == -1)
            bad = i;
        else
        {
            int u = i, v = bad;
            bad = -1;
            ex[m] = u ^ v;
            g[u].push_back(m);
            g[v].push_back(m);
            ++m;
        }
    }
    if (m % 2)
    {
        ex[m] = 0;
        g[0].push_back(m);
        g[0].push_back(m);
        ++m;
    }
    cout << m << '\n';
    dfs(0);
    return 0;
}