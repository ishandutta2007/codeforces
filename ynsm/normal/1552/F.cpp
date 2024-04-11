#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 998244353;
const ll INF = 1e18;

struct node
{
    int l, r;
    ll dp;
    node operator+(node other)
    {
        node res;
        res.l = min(l, other.l);
        res.r = max(r, other.r);
        res.dp = (dp + other.dp);
        if (res.dp >= mod)
            res.dp -= mod;
        return res;
    }
} t[N << 2];

int n, a[N], b[N], c[N];
ll dp[N];

void build(int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v].l = t[v].r = a[tl];
        t[v].dp = 0;
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm);
    build(v << 1 | 1, tm + 1, tr);
    t[v] = t[v << 1] + t[v << 1 | 1];
}
ll get(int v, int tl, int tr, int l, int r)
{
    if (r < t[v].l || t[v].r < l || l > r)
        return 0;
    if (l <= t[v].l && t[v].r <= r)
        return t[v].dp;
    int tm = (tl + tr) >> 1;
    return get(v << 1, tl, tm, l, r) + get(v << 1 | 1, tm + 1, tr, l, r);
}
void upd(int v, int tl, int tr, int p, ll x)
{
    if (tl == tr)
    {
        t[v].dp = x;
        return;
    }
    int tm = (tl + tr) >> 1;
    if (p <= tm)
        upd(v << 1, tl, tm, p, x);
    else
        upd(v << 1 | 1, tm + 1, tr, p, x);
    t[v] = t[v << 1] + t[v << 1 | 1];
}
void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    build(1, 1, n);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = (a[i] - b[i] + get(1, 1, n, b[i], a[i] - 1)) % mod;
        if (dp[i] < 0)
            dp[i] += mod;
        upd(1, 1, n, i, dp[i]);
        if (c[i])
            ans += dp[i];
    }
    ans += a[n] + 1;
    ans %= mod;
    printf("%lld\n", ans);
}
int main()
{
    int t = 1;
    while (t--)
        solve();
}