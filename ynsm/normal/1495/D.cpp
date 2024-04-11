#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 1010, mod = 998244353;

vector<int> g[N];
int n, m;
bool was[N];
int d[N][N];
ll ans[N][N];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        g[v].pb(u);
        g[u].pb(v);
    }
    for (int i = 1; i <= n; i++)
    {
        queue<int> q;
        for (int j = 1; j <= n; j++)
            was[j] = 0;
        was[i] = 1;
        q.push(i);
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (auto to : g[v])
                if (!was[to])
                {
                    was[to] = 1;
                    d[i][to] = d[i][v] + 1;
                    q.push(to);
                }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            ll cur = 1;
            int x = 0;
            for (int v = 1; v <= n; v++)
            {
                if (d[i][v] + d[v][j] == d[i][j])
                    x++;
                else
                {
                    int y = 0;
                    for (auto to : g[v])
                        if (d[i][v] == d[i][to] + 1 && d[j][v] == d[j][to] + 1)
                            y++;
                    cur = cur * y % mod;
                }
            }
            if (x != d[i][j] + 1)
                cur = 0;
            ans[i][j] = ans[j][i] = cur;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%lld ", ans[i][j]);
        printf("\n");
    }
}