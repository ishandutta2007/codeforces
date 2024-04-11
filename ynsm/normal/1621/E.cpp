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

int n, m, k, a[N], b[N];
int bl[N], br[N];

int t[N << 2], u[N << 2];
void build(int v, int tl, int tr)
{
    t[v] = u[v] = 0;
    if (tl == tr)
        return;
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm);
    build(v << 1 | 1, tm + 1, tr);
}
void upd(int v, int tl, int tr, int pos, int val)
{
    if (pos < tl)
        return;
    if (tr <= pos)
    {
        t[v] += val;
        u[v] += val;
        return;
    }
    int tm = (tl + tr) >> 1;
    upd(v << 1, tl, tm, pos, val);
    upd(v << 1 | 1, tm + 1, tr, pos, val);
    t[v] = min(t[v << 1], t[v << 1 | 1]) + u[v];
}
int check()
{
    return t[1] >= 0;
}

int get(ll p, ll q)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int m = (l + r) >> 1;
        if (a[m] * q < p)
            l = m + 1;
        else
            r = m - 1;
    }
    // cerr << p << " " << q << " " << l << endl;
    // for(int i = 0; i < n; i++)
    //     cerr << a[i] << " ";
    // cerr << endl;
    return l;
}
void solve()
{
    k = 0;

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
    {
        int sz;
        scanf("%d", &sz);
        bl[i] = k;
        for (int j = 0; j < sz; j++)
            scanf("%d", &b[k++]);
        br[i] = k;
    }

    sort(a, a + n);
    build(1, 0, n);
    for (int i = 0; i < n; i++)
        upd(1, 0, n, get(a[i], 1), 1);
    for (int i = 0; i < m; i++)
    {
        ll s = 0;
        for (int j = bl[i]; j < br[i]; j++)
            s += b[j];
        upd(1, 0, n, get(s, br[i] - bl[i]), -1);
    }
    for (int i = 0; i < m; i++)
    {
        ll s = 0;
        for (int j = bl[i]; j < br[i]; j++)
            s += b[j];
        upd(1, 0, n, get(s, br[i] - bl[i]), 1);
        for (int j = bl[i]; j < br[i]; j++)
        {
            upd(1, 0, n, get(s - b[j], br[i] - bl[i] - 1), -1);
            printf("%d", check());
            upd(1, 0, n, get(s - b[j], br[i] - bl[i] - 1), 1); 
        }
        upd(1, 0, n, get(s, br[i] - bl[i]), -1);
    }
    printf("\n");
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}