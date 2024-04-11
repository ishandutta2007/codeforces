#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 1000100, mod = 1e9 + 7;

int n, m, k;
ll f[N], rf[N], pw[N];

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
void solve()
{
    scanf("%d%d%d", &n, &m, &k);
    m = n - m;
    if (m == 0)
    {
        printf("%lld\n", 1ll * n * k % mod);
        return;
    }
    ll ans = 0;
    for (int i = 1; i < n; i++)
    {
        ll cur = C(m - 1, n - i - 1) * pw[n - i] % mod;
        ans += cur * i % mod;
    }
    ans %= mod;
    ans = ans * k % mod;
    printf("%lld\n", ans);
}
int main()
{

    f[0] = 1, rf[0] = 1;
    for (int i = 1; i < N; i++)
        f[i] = f[i - 1] * i % mod, rf[i] = inv(f[i]);
    pw[0] = 1;
    ll x = inv(2);
    for (int i = 1; i < N; i++)
        pw[i] = pw[i - 1] * x % mod;

    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}