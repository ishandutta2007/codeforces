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

struct node
{
    ll p1, p2, s;
    node()
    {
        p1 = p2 = s = 0;
    }

} t[N << 2];

int n, q, a[N], b[N], c[N];

node merge(node a, node b)
{
    node c;
    c.s = a.s + b.s;
    c.p1 = min(a.p1, a.s + b.p1);
    c.p2 = max(a.p2, a.s + b.p2);
    return c;
}

void build(int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v].p1 = min(t[v].p1, (ll)c[tl]);
        t[v].p2 = max(t[v].p2, (ll)c[tl]);
        t[v].s += c[tl];
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm);
    build(v << 1 | 1, tm + 1, tr);
    t[v] = merge(t[v << 1], t[v << 1 | 1]);
    // cerr << "B " << t[v].mx << endl;
}
node get(int v, int tl, int tr, int l, int r)
{
    if (r < tl || tr < l || l > r)
        return node();
    if (l <= tl && tr <= r)
        return t[v];
    int tm = (tl + tr) >> 1;
    return merge(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    for (int i = 0; i < n; i++)
        c[i] = b[i] - a[i];
    build(1, 0, n - 1);
    while (q--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        l--, r--;
        node x = get(1, 0, n - 1, l, r);
        ll ans;
        if (x.p1 < 0 || x.s != 0)
            ans = -1;
        else
            ans = x.p2;
        printf("%lld\n", ans);
    }
}