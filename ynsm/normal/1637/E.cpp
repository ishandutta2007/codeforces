#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)3e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, m, a[N], cnt[N];
vector<int> g[N], G[N], conds;
ll ans;
bool ban[N];

void solve()
{
    ans = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);

    for (int i = 0; i < n; i++)
        cnt[lower_bound(a, a + n, a[i]) - a]++;
    for (int i = 0; i < n; i++)
        G[cnt[i]].pb(i);

    for (int i = 1; i <= n; i++)
    {
        if (G[i].size())
            conds.pb(i);
        sort(G[i].begin(), G[i].end());
        reverse(G[i].begin(), G[i].end());
    }

    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x = lower_bound(a, a + n, x) - a;
        y = lower_bound(a, a + n, y) - a;
        g[x].pb(y);
        g[y].pb(x);
    }
    for (int i = 0; i < n; i++)
    {
        if (cnt[i] == 0)
            continue;
        ban[i] = 1;
        for (auto j : g[i])
            ban[j] = 1;

        for (auto x : conds)
            for (auto j : G[x])
                if (!ban[j])
                {
                    ans = max(ans, 1ll * (cnt[i] + cnt[j]) * (a[i] + a[j]));
                    break;
                }

        ban[i] = 0;
        for (auto j : g[i])
            ban[j] = 0;
    }
    printf("%lld\n", ans);

    conds.clear();
    for (int i = 0; i <= n; i++)
    {
        cnt[i] = 0;
        g[i].clear();
        G[i].clear();
    }
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}