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
vector<int> ans[N][2];
vector<pii> ANS;

int dp[N];

void dfs(int v, int p)
{
    vector<int> a[4];
    for (auto to : g[v])
    {
        if (to == p)
            continue;
        dfs(to, v);
        a[dp[to]].pb(to);
    }

    dp[v] = 0;

    if (v == p)
    {
        int ptr[] = {0, 0, 0, 0};
        int cur = ((g[v].size() & 1) ^ 1);
        while (true)
        {
            bool ok = 0;
            for (int i = 0; i < 4; i++)
                ok |= (ptr[i] < a[i].size());

            if (!ok)
            {
                dp[v] = 1;
                break;
            }
            int p = -1;
            for (int i = 0; i < 4; i++)
                if (ptr[i] < a[i].size() && ((i >> cur) & 1))
                    p = a[i][ptr[i]++];
            if (p == -1)
                break;
            ans[v][0].pb(p);
            cur ^= 1;
        }
    }
    else
    {
        for (int px = 0; px < 2; px++)
        {
            int ptr[] = {0, 0, 0, 0};
            int cur = ((g[v].size() & 1) ^ 1);
            a[1 << px].pb(v);
            while (true)
            {
                bool ok = 0;
                for (int i = 0; i < 4; i++)
                    ok |= (ptr[i] < a[i].size());

                if (!ok)
                {
                    dp[v] |= (1 << px);
                    break;
                }
                int p = -1;
                for (int i = 0; i < 4; i++)
                    if (ptr[i] < a[i].size() && ((i >> cur) & 1))
                        p = a[i][ptr[i]++];
                if (p == -1)
                    break;
                ans[v][px].pb(p);
                cur ^= 1;
            }
            a[1 << px].pop_back();
        }
    }
}
void dfs2(int v, int p, int x)
{
    int cur = ((g[v].size() & 1) ^ 1);
    for (auto u : ans[v][x])
    {
        if (u == v)
        {
            ANS.pb({v, p});
        }
        else
        {
            dfs2(u, v, cur);
        }
        cur ^= 1;
    }
}
void solve()
{
    scanf("%d", &n);

    ANS.clear();
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        ans[i][0].clear();
        ans[i][1].clear();
    }

    for (int i = 1; i < n; i++)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        g[v].pb(u);
        g[u].pb(v);
    }

    dfs(1, 1);
    if (dp[1] == 0)
    {
        printf("NO\n");
        return;
    }
    printf("YES\n");
    dfs2(1, 1, 0);
    for (auto it : ANS)
        printf("%d %d\n", it.f, it.s);
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}