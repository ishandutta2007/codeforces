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

int n, k, m, a[N];

pii b[N];
int c[N];

pii t[N << 2];
void build(int v, int tl, int tr)
{
    t[v].f = 0;
    t[v].s = 0;
    if (tl == tr)
        return;
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm);
    build(v << 1 | 1, tm + 1, tr);
}
void upd(int v, int tl, int tr, int p, pii x)
{
    t[v].f += x.f;
    t[v].s += x.s;
    if (tl == tr)
        return;
    int tm = (tl + tr) >> 1;
    if (p <= tm)
        upd(v << 1, tl, tm, p, x);
    else
        upd(v << 1 | 1, tm + 1, tr, p, x);
}

int S, ANS;
void get(int v, int tl, int tr)
{
    if (S == 0)
        return;

    if (t[v].f <= S)
    {
        S -= t[v].f;
        ANS += t[v].s;
        return;
    }
    if (tl == tr)
    {
        S = 0;
        return;
    }

    int tm = (tl + tr) >> 1;
    get(v << 1, tl, tm);
    get(v << 1 | 1, tm + 1, tr);
}

void solve()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);

    m = 0;
    for (int i = 0, j = 0; i < n; i = j)
    {
        while (j < n && a[i] == a[j])
            j++;
        b[m++] = {j - i, a[i]};
    }
    sort(b, b + m);

    for (int i = 0; i < n; i++)
        c[i] = -1;
    for (int i = 0; i < m; i++)
        if (b[i].s < n)
            c[b[i].s] = i;

    build(1, 0, m - 1);
    for (int i = 0; i < m; i++)
        upd(1, 0, m - 1, i, {b[i].f, 1});

    int ans = m;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (c[i] != -1)
        {
            cnt++;
            upd(1, 0, m - 1, c[i], {-b[c[i]].f, -1});
        }
        S = k;
        ANS = 0;
        get(1, 0, m - 1);
        // cerr << i << " " << cnt << " " << m << " "
        if (i - cnt + 1 <= k)
            ans = min(ans, m - cnt - ANS);
    }

    printf("%d\n", ans);
}

int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}