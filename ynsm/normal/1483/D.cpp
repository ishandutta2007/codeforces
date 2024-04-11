#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 1010;
const ll inf = 1e18;

int n, m;
ll d[N][N], q[N][N], dp[N], e[N][N];
bool was[N], ans[N][N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            d[i][j] = inf;
    for (int i = 0; i < n; i++)
        d[i][i] = 0;
    for (int i = 0; i < m; i++)
    {
        int v, u, w;
        scanf("%d%d%d", &v, &u, &w);
        --v, --u;
        d[v][u] = d[u][v] = w;
        e[v][u] = e[u][v] = w;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int v, u, w;
        scanf("%d%d%d", &v, &u, &w);
        --v, --u;
        q[v][u] = q[u][v] = w;
    }

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    for (int v = 0; v < n; v++)
    {
        for (int u = 0; u < n; u++)
            dp[u] = q[v][u], was[u] = 0;

        for (int i = 0; i < n; ++i)
        {
            int u = -1;
            for (int j = 0; j < n; ++j)
                if (!was[j] && (u == -1 || dp[j] > dp[u]))
                    u = j;
            was[u] = true;
            for (int to = 0; to < n; to++)
                dp[to] = max(dp[to], dp[u] - d[u][to]);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (e[i][j] == 0)
                    continue;
                if (d[v][i] + e[i][j] <= dp[j])
                    ans[i][j] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            cnt += (ans[i][j] || ans[j][i]);
    printf("%d\n", cnt);
}