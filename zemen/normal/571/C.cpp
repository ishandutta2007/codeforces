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

const int maxn = 3e5;

vector<int> where[maxn];
vector<bool> neg[maxn];
bool ans[maxn];
bool usedId[maxn];

bool good[maxn];

struct Edge
{
    int to, id;

    Edge(int to, int id): to(to), id(id) {}

};

vector<Edge> g[maxn];

bool used[maxn];
bool used2[maxn];

void dfsGood(int u)
{
    used[u] = true;
    for (auto e: g[u])
    {
        int v = e.to;
        int id = e.id;
        if (!usedId[id])
            ans[id] = (where[id][0] == v ? !neg[id][0] : !neg[id][1]);
        usedId[id] = true;
        if (used[v])
            continue;
        dfsGood(v);
    }
}

int dfs(int u, int prevId = -1)
{
    used2[u] = true;
    for (auto e: g[u])
    {
        if (e.id == prevId)
            continue;
        if (used2[e.to])
            return e.to;
        int v = dfs(e.to, e.id);
        if (v != -1)
            return v;
    }
    return -1;
}

int solve()
{
    int n, m;
    cin >> n >> m;
    forn (i, n)
    {
        int k;
        scanf("%d", &k);
        forn (j, k)
        {
            int x;
            scanf("%d", &x);
            where[abs(x) - 1].push_back(i);
            neg[abs(x) - 1].push_back(x < 0);
        }
    }
    forn (i, m)
    {
        if (sz(where[i]) == 0)
            continue;
        if (sz(where[i]) == 1)
        {
            good[where[i][0]] = true;
            ans[i] = !neg[i][0];
            continue;
        }
        assert(sz(where[i]) == 2);
        if (where[i][0] == where[i][1])
        {
            good[where[i][0]] = true;
            ans[i] = !neg[i][0];
            continue;
        }
        if (neg[i][0] == neg[i][1])
        {
            good[where[i][0]] = true;
            good[where[i][1]] = true;
            ans[i] = !neg[i][0];
            continue;
        }
        g[where[i][0]].emplace_back(where[i][1], i);
        g[where[i][1]].emplace_back(where[i][0], i);
    }
    forn (i, n)
        if (!used[i] && good[i])
            dfsGood(i);
    forn (i, n)
        if (!used[i])
        {
            int u = dfs(i);
            if (u == -1)
            {
                cout << "NO\n";
                return 0;
            }
            dfsGood(u);
        }
    cout << "YES\n";
    forn (i, m)
        cout << ans[i];
    cout << '\n';
    return 0;
}