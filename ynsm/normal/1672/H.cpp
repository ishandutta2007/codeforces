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

const int K = 4;
struct kek
{
    int ans;
    int k;
    pii a[K];
    kek()
    {
        ans = 0;
        k = 0;
    }
    kek(int x)
    {
        ans = 0;
        k = 1;
        a[0] = {x, 1};
    }
    void flex()
    {
        if (k >= 2)
        {
            int x = min(a[k - 1].s, a[k - 2].s) - 1;
            a[k - 1].s -= x;
            a[k - 2].s -= x;
            ans += x;
        }

        if (k >= 3 && a[k - 2].s == 1)
        {
            ans += 2;
            a[k - 3].s += a[k - 1].s - 1;
            k -= 2;
        }

        assert(k <= 3);
    }
    int get()
    {
        if (k <= 1)
            return ans;
        if (k == 2)
            return ans + 1;
        if (k == 3)
            return ans + 2;
    }

} t[N << 2];

kek merge(kek a, kek b)
{
    kek c;
    c.ans = a.ans + b.ans;

    for (int i = 0; i < a.k; i++)
    {
        if (c.k && c.a[c.k - 1].f == a.a[i].f)
            c.a[c.k - 1].s += a.a[i].s;
        else
            c.a[c.k++] = a.a[i];
        c.flex();
    }
    for (int i = 0; i < b.k; i++)
    {
        if (c.k && c.a[c.k - 1].f == b.a[i].f)
            c.a[c.k - 1].s += b.a[i].s;
        else
            c.a[c.k++] = b.a[i];
        c.flex();
    }
    return c;
}
int n, q;
char s[N];

void build(int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v] = kek(s[tl] - '0');
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm);
    build(v << 1 | 1, tm + 1, tr);
    t[v] = merge(t[v << 1], t[v << 1 | 1]);
}
kek get(int v, int tl, int tr, int l, int r)
{
    if (r < tl || tr < l || l > r)
        return kek();
    if (l <= tl && tr <= r)
        return t[v];
    int tm = (tl + tr) >> 1;
    return merge(
        get(v << 1, tl, tm, l, r),
        get(v << 1 | 1, tm + 1, tr, l, r));
}
void solve()
{
    scanf("%d%d", &n, &q);
    scanf("%s", s);
    build(1, 0, n - 1);
    while (q--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        l--, r--;
        printf("%d\n", r - l + 1 - get(1, 0, n - 1, l, r).get());
    }
}
int main()
{
    int t = 1;
    // scanf ("%d", &t);
    while (t--)
        solve();
}