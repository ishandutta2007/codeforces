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

int n, q, ql[N], qr[N];
char a[N], b[N];
int t[N << 2], u[N << 2];

void push(int v, int tl, int tr)
{
    if (u[v] == -1)
        return;
    int tm = (tl + tr) >> 1;
    t[v << 1] = (tm - tl + 1) * u[v];
    t[v << 1 | 1] = (tr - tm) * u[v];
    u[v << 1] = u[v << 1 | 1] = u[v];
    u[v] = -1;
}
void build(int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v] = u[v] = b[tl - 1] - '0';
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm);
    build(v << 1 | 1, tm + 1, tr);
    t[v] = t[v << 1] + t[v << 1 | 1];
    u[v] = -1;
}
void upd(int v, int tl, int tr, int l, int r, int x)
{
    if (r < tl || tr < l)
        return;
    if (l <= tl && tr <= r)
    {
        u[v] = x;
        t[v] = (tr - tl + 1) * x;
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) >> 1;
    upd(v << 1, tl, tm, l, r, x);
    upd(v << 1 | 1, tm + 1, tr, l, r, x);
    t[v] = t[v << 1] + t[v << 1 | 1];
    u[v] = -1;
}
int get(int v, int tl, int tr, int l, int r)
{
    if (r < tl || tr < l)
        return 0;
    if (l <= tl && tr <= r)
        return t[v];
    push(v, tl, tr);
    int tm = (tl + tr) >> 1;
    return get(v << 1, tl, tm, l, r) + get(v << 1 | 1, tm + 1, tr, l, r);
}
void solve()
{
    scanf("%d %d\n", &n, &q);
    scanf("%s", &a);
    scanf("%s", &b);
    for (int i = 0; i < q; i++)
        scanf("%d%d", &ql[i], &qr[i]);
    build(1, 1, n);
    for (int i = q - 1; i >= 0; i--)
    {
        int l = ql[i], r = qr[i];
        int x = get(1, 1, n, l, r);
        int y = r - l + 1 - x;
         if (x == y)
        {
            puts("NO");
            return;
        }
        if (x < y)
            upd(1, 1, n, l, r, 0);
        else
            upd(1, 1, n, l, r, 1);
    }
    for (int i = 0; i < n; i++)
    {
        int x = a[i] - '0';
        int y = get(1, 1, n, i + 1, i + 1);
        if (x != y)
        {
            puts("NO");
            return;
        }
    }
    puts("YES");
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
}