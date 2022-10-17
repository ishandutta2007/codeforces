#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)5e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n;
ll a[N], b[N];

int dp[N], t[N << 5];

void build(int v, int tl, int tr)
{
    t[v] = -inf;
    if (tl == tr)
        return;
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm);
    build(v << 1 | 1, tm + 1, tr);
}
int get(int v, int tl, int tr, int l, int r)
{
    if (r < tl || tr < l || l > r)
        return -inf;
    if (l <= tl && tr <= r)
        return t[v];
    int tm = (tl + tr) >> 1;
    return max(
        get(v << 1, tl, tm, l, r),
        get(v << 1 | 1, tm + 1, tr, l, r));
}
void upd(int v, int tl, int tr, int pos, int val)
{
    if (tl == tr)
    {
        t[v] = max(t[v], val);
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm)
        upd(v << 1, tl, tm, pos, val);
    else
        upd(v << 1 | 1, tm + 1, tr, pos, val);
    t[v] = max(t[v << 1], t[v << 1 | 1]);
}

void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        a[i] += a[i - 1];
    }
    for (int i = 0; i <= n; i++)
        b[i] = a[i];
    sort(b, b + n + 1);
    
    for (int i = 0; i <= n; i++)
        a[i] = lower_bound(b, b + n + 1, a[i]) - b;

    build(4, 0, n);
    build(5, 0, n);
    build(6, 0, n);
    {
        int i = 0;
        upd(4, 0, n, a[i], dp[i] - i);
        upd(5, 0, n, a[i], dp[i] + i);
        upd(6, 0, n, a[i], dp[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        dp[i] = -inf;
        dp[i] = max(dp[i], get(4, 0, n, 0, a[i] - 1) + i);
        dp[i] = max(dp[i], get(5, 0, n, a[i] + 1, n) - i);
        dp[i] = max(dp[i], get(6, 0, n, a[i], a[i]) + 0);

        // cerr << i << " " << dp[i] << endl;

        upd(4, 0, n, a[i], dp[i] - i);
        upd(5, 0, n, a[i], dp[i] + i);
        upd(6, 0, n, a[i], dp[i]);
    }

    printf("%d\n", dp[n]);
}
int main()
{
    int t = 1;
    scanf ("%d", &t);
    while (t--)
        solve();
}