#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n;
vector<int> g[N];
int a[N], sz[N];

void dfs(int v, int p, int dep = 0)
{
    int need;
    if (v == p)
        need = 0;
    else
        need = 1;

    if (dep)
        need = -need;

    sz[v] = 0;

    for (auto to : g[v])
    {
        if (to == p)
            continue;
        dfs(to, v, dep ^ 1);
        sz[v] += sz[to];
    }
    a[v] = need - sz[v];
    sz[v] += a[v];
}
void solve()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        g[v].pb(u);
        g[u].pb(v);
    }
    dfs(1, 1);
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    printf("\n");
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        a[i] = 0;
        sz[i] = 0;
    }
}
int main()
{
    int t = 1;
    scanf ("%d", &t);
    while (t--)
        solve();
}