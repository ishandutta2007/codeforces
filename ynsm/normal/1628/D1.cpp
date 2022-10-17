#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 2500, mod = 1e9 + 7;

int n, m, k;
ll dp[N][N];

ll f(ll a)
{
    if (a >= mod)
        a -= mod;
    if (a & 1)
        return (a + mod) / 2;
    return a / 2;
}
void solve()
{
    scanf("%d%d%d", &n, &m, &k);
    m = n - m;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m && j <= i; j++)
        {
            if (j == 0)
                dp[i][j] = dp[i - 1][j] + 1;
            else if (j == i)
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = f(dp[i - 1][j] + dp[i - 1][j - 1]);
        }
    }
    ll ans = dp[n][m] * k % mod;
    printf("%lld\n", ans);
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}