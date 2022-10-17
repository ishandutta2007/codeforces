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

int n, a[N], b[N];
vector<int> g[N];
ll ans;

void dfs(int v, int p)
{
    if (p == -1)
    {
        vector<int> c;
        for (auto to : g[v])
        {
            dfs(to, v);
            c.pb(max(a[v] - b[to], 0));
        }
        c.pb(a[v]);
        sort(c.begin(), c.end());
        ans += c[0] + c[1];
    }
    else
    {
        for (auto to : g[v])
        {
            if (to == p)
                continue;
            dfs(to, v);
            b[v] = max(b[v], b[to]);
        }
        ans += max(a[v] - b[v], 0);
        b[v] = max(b[v], a[v]);
    }
}
void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i < n; i++)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        g[v].pb(u);
        g[u].pb(v);
    }
    int root = 1;
    for (int i = 1; i <= n; i++)
        if (a[root] < a[i])
            root = i;
    dfs(root, -1);
    printf("%lld\n", ans);
}
int main()
{
    int t = 1;
    // scanf ("%d", &t);
    while (t--)
        solve();
}