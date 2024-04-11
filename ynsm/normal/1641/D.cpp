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

int n, m, a[N][5], w[N];
int k, b[N * 5], c[N * 5];

int f = 18;
ll dp[1 << 20];

ll ans = INF;

void solve()
{
    scanf("%d%d", &n, &m);
    // n = 10000, m = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            // a[i][j] = i * m + j;
            scanf("%d", &a[i][j]);
        scanf("%d", &w[i]);
        // w[i] = rand();
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            b[k++] = a[i][j];
    sort(b, b + k);
    k = unique(b, b + k) - b;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = lower_bound(b, b + k, a[i][j]) - b;

    for (int it = 0; it < 50; it++)
    {
        for (int i = 0; i < k; i++)
            c[i] = rand() % f;
        for (int i = 0; i < (1 << f); i++)
            dp[i] = INF;
        for (int i = 0; i < n; i++)
        {
            int x = 0;
            for (int j = 0; j < m; j++)
                x |= (1 << c[a[i][j]]);
            dp[x] = min(dp[x], (ll)w[i]);
        }
        for (int i = 0; i < f; i++)
            for (int j = 0; j < (1 << f); j++)
                if ((j >> i) & 1)
                    dp[j] = min(dp[j], dp[j ^ (1 << i)]);
        for (int j = 0; j < (1 << f); j++)
            ans = min(ans, dp[j] + dp[((1 << f) - 1) ^ j]);
    }
    if (ans == INF)
        ans = -1;
    printf("%lld\n", ans);
}
int main()
{
    int t = 1;
    // scanf ("%d", &t);
    while (t--)
        solve();
}