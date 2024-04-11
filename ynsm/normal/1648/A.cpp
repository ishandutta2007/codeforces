#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 100500, K = 400;

int n, m, a[K][N];
ll cnt[K], ans;
pll dp[K];
vector<pii> g[N];

void solve()
{
    scanf("%d%d", &n, &m);
    if (n < m)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d", &a[i][j]);
    }
    else
    {
        swap(n, m);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &a[j][i]);
    }
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++)
            g[a[i][j]].pb({i, j});
    for (int i = 0; i < N; i++)
    {
        for (auto it : g[i])
        {
            int x = it.f;
            int y = it.s;
            for (int j = 0; j < K; j++)
                if (j < x)
                    ans += cnt[j] * (x + y) + dp[j].f;
                else
                    ans += cnt[j] * (-x + y) + dp[j].s;
            cnt[x]++;
            dp[x].f += -x - y;
            dp[x].s += x - y;
            // cerr << i << " " << x << " " << y << " " << ans << endl;
        }
        for (int j = 0; j < K; j++)
            cnt[j] = dp[j].f = dp[j].s = 0;
    }
    printf("%lld\n", ans);
}
int main()
{
    int t = 1;
    // scanf ("%d", &t);
    while (t--)
        solve();
}