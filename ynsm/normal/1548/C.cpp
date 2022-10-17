#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)3e6 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

ll f[N], rf[N];
int n, q;
ll dp[3][N];
ll bp(ll x, ll p)
{
    ll res = 1;
    while (p)
    {
        if (p & 1)
            res = res * x % mod;
        x = x * x % mod;
        p >>= 1;
    }
    return res;
}

ll inv(ll x)
{
    return bp(x, mod - 2);
}
ll C(int k, int n)
{
    if (k < 0 || k > n)
        return 0;
    return f[n] * rf[k] % mod * rf[n - k] % mod;
}

ll tup(ll n, ll k)
{
    ll res = 0;
    for (int i = 1; i <= n; i++)
        res += C(k, 3 * i);
    return res % mod;
}

int main()
{
    f[0] = 1;
    for (int i = 1; i < N; i++)
        f[i] = f[i - 1] * i % mod;
    rf[N - 1] = inv(f[N - 1]);
    for (int i = N - 2; i >= 0; i--)
        rf[i] = rf[i + 1] * (i + 1) % mod;

    scanf("%d%d", &n, &q);
    
    ll inv_3 = inv(3);
    for (int j = 0; j < 3; j++)
        dp[j][0] = (3 * n + j) / 3 + 1;
    for (int i = 1; i <= 3 * n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dp[j][i] = C(i + 1, 3 * n + j);
            if (j != 2)
                dp[j][i] -= dp[j + 1][i - 1] - C(i - 1, 3 * n + j + 1);
            else
                dp[j][i] -= dp[j - 2][i - 1];
            dp[j][i] -= 2 * (dp[j][i - 1] - C(i - 1, 3 * n + j));
            dp[j][i] %= mod;
            if (dp[j][i] < 0)
                dp[j][i] += mod;
            dp[j][i] = dp[j][i] * inv_3 + C(i, 3 * n + j);
            dp[j][i] %= mod;
        }
    }
    while (q--)
    {
        int x;
        scanf("%d", &x);
        printf("%lld\n", dp[0][x]);
    }
}