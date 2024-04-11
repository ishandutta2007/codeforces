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

int n, m, cnt[N];
ll f[N], rf[N];

ll ans;

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

pll t[N << 2];
pll merge(pll a, pll b)
{
    return {
        a.f * b.f % mod,
        (a.f * b.s + a.s * b.f) % mod};
}
void upd(int v, int tl, int tr, int p, pll x)
{
    if (tl == tr)
    {
        t[v] = x;
        return;
    }
    int tm = (tl + tr) >> 1;
    if (p <= tm)
        upd(v << 1, tl, tm, p, x);
    else
        upd(v << 1 | 1, tm + 1, tr, p, x);
    t[v] = merge(t[v << 1], t[v << 1 | 1]);
}
pll get(int v, int tl, int tr, int l, int r)
{
    if (r < tl || tr < l || l > r)
        return {1, 0};
    if (l <= tl && tr <= r)
        return t[v];
    int tm = (tl + tr) >> 1;
    return merge(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
}
int cur;
ll get(int k)
{
    // ll sum = 0;
    // for (int i = 0; i < N; i++)
    //     sum += cnt[i];
    ll x = 1;
    for (int i = 0; i < N; i++)
        x = x * rf[cnt[i]] % mod;
    // ll res = 0;
    // for (int i = 0; i < k; i++)
    //     if (cnt[i] > 0)
    //         res = (res + cur * f[cnt[i]] * rf[cnt[i] - 1] % mod * f[sum - 1]) % mod;
    // cerr << k << " " << get(1, 0, N - 1, 0, k - 1).f << " " << x << endl;
    if (cur > 0)
        return get(1, 0, N - 1, 0, k - 1).s * get(1, 0, N - 1, k, N - 1).f % mod * f[cur - 1] % mod;
    return 0;
}

void solve()
{
    f[0] = rf[0] = 1;
    for (int i = 1; i < N; i++)
        f[i] = f[i - 1] * i % mod, rf[i] = inv(f[i]);

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }

    for (int i = 0; i < N; i++)
        if (cnt[i] > 0)
            upd(1, 0, N - 1, i, {rf[cnt[i]], rf[cnt[i] - 1]});
        else
            upd(1, 0, N - 1, i, {1, 0});
    cur = n;
    for (int i = 0; i < m; i++)
    {
        int x;
        scanf("%d", &x);
        ans += get(x);
        // cerr << i << " " << ans << endl;
        if (cnt[x] > 0)
        {
            cnt[x]--, cur--;
            if (cnt[x] > 0)
                upd(1, 0, N - 1, x, {rf[cnt[x]], rf[cnt[x] - 1]});
            else
                upd(1, 0, N - 1, x, {1, 0});
        }
        else
            break;
        if (i == n - 1 && i != m - 1)
            ans++;
    }
    ans %= mod;

    printf("%lld\n", ans);
}
int main()
{
    int t = 1;
    // scanf ("%d", &t);
    while (t--)
        solve();
}