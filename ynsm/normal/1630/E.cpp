#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e6 + 123, inf = 1e9, mod = 998244353;
const ll INF = 1e18;

int sum(int a, int b)
{
    int s = a + b;
    if (s >= mod)
        s -= mod;
    return s;
}
int sub(int a, int b)
{
    int s = a - b;
    if (s < 0)
        s += mod;
    return s;
}
int mult(int a, int b)
{
    return (1LL * a * b) % mod;
}

ll bp(ll x, ll p)
{
    ll res = 1;
    while (p)
    {
        if (p & 1)
            res = res * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return res;
}
int inv[N], fact[N], invfact[N];

/*
ans = cnt _ comp
cnt_comp = n - cnt_edges

dp[i] = ans with i block
dp[i] = C - dp[j] j | i
C = n!/ cnt[1]! / cnt[2]! .... * n  - n - 2! / cnt[1] - 2! / cnt[2]! ....  * n
*/

int n, cnt[N], b[N], k, dp[N], dp2[N];
void solve()
{
    scanf("%d", &n);
    k = 0;
    for (int i = 1; i <= n; i++)
        dp[i] = dp2[i] = cnt[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    for (int i = 1; i <= n; i++)
        if (cnt[i])
            b[k++] = cnt[i];

    int g = n;
    for (int i = 0; i < k; i++)
        g = __gcd(b[i], g);

    if (g == n)
    {
        printf("1\n");
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (g % i)
            continue;
        int x = fact[n / i];
        int res = 0;
        for (int j = 0; j < k; j++)
            x = mult(x, invfact[b[j] / i]);

        dp2[n / i] = x;
        res = mult(x, n / i);
        // cerr << i << " " << res << endl;
        x = mult(x, invfact[n / i]);

        if (n / i >= 2)
        {
            x = mult(x, fact[n / i - 2]);
            for (int j = 0; j < k; j++)
            {
                if (b[j] / i >= 2)
                    res = sub(res, mult(n / i, mult(x, mult(fact[b[j] / i], invfact[b[j] / i - 2]))));
                // cerr << n / i<< " " << mult(x, mult(fact[b[j] / i], invfact[b[j] / i - 2])) << endl;;
            }
        }
        else
        {
        }

        // cerr << i << " " << res << endl;
        dp[n / i] = res;
    }

    int A = 0, B = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i)
            continue;
        // cerr << i << " " << dp[i] << " " << dp2[i] << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        if (n % i)
            continue;
        for (int j = i + i; j <= n; j += i)
        {
            int x = dp[i];
            x = mult(x, j / i);
            dp[j] = sub(dp[j], x);
            dp2[j] = sub(dp2[j], dp2[i]);
        }

        dp[i] = mult(dp[i], inv[i]);
        dp2[i] = mult(dp2[i], inv[i]);
        // cerr << i << " " << dp[i] << " " << dp2[i] << endl;
        A = sum(A, mult(dp[i], n / i));
        B = sum(B, dp2[i]);
    }
    int ans = mult(A, bp(B, mod - 2));
    printf("%d\n", ans);
}
int main()
{
    fact[0] = invfact[0] = inv[1] = fact[1] = invfact[1] = 1;
    for (int i = 2; i < N; i++)
    {
        fact[i] = mult(fact[i - 1], i);
        inv[i] = mult(inv[mod % i], mod - mod / i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}