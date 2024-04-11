#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 1505, K = 11;

struct kek
{
    int sz = 0;
    pii val[K];
    void add(int c, int k)
    {
        for (int i = 0; i < sz; i++)
            if (val[i].f == c)
            {
                for (int j = i; j + 1 < sz; j++)
                    val[j] = val[j + 1];
                sz--;
            }
        if (sz == K)
        {
            for (int j = 0; j + 1 < sz; j++)
                val[j] = val[j + 1];
            sz--;
        }
        val[sz++] = {c, k};
    }
    void add(pii x)
    {
        add(x.f, x.s);
    }
};
int n, q, a[N][N];
kek b[N][N], c[N][N];

int was[N * N], timer;

int ans[N];

kek f(kek a, kek b)
{
    kek res;
    int i = 0, j = 0;
    while (i < a.sz || j < b.sz)
    {
        if (i == a.sz)
            res.add(b.val[j++]);
        else if (j == b.sz)
            res.add(a.val[i++]);
        else if (a.val[i].s > b.val[j].s)
            res.add(a.val[i++]);
        else
            res.add(b.val[j++]);
    }
    return res;
}
kek g(kek a, int x)
{
    for (int i = 0; i < a.sz; i++)
        a.val[i].s += x;
    return a;
}
void F(kek a, int mx)
{
    timer++;
    int cnt = 0;
    int res = 1e9;
    for (int i = 0; i < a.sz; i++)
    {
        int k = a.val[a.sz - 1 - i].s;
        int c = a.val[a.sz - 1 - i].f;
        if (was[c] == timer)
            continue;
        was[c] = timer;
        cnt++;
        if (cnt > q)
        {
            res = k;
            break;
        }
    }
    res = min(res, mx);
    ans[res]++;
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = n - 1; j >= 0; j--)
        {
            b[i][j] = b[i][j + 1];
            c[j][i] = c[j + 1][i];
            b[i][j].add(a[i][j], j);
            c[j][i].add(a[j][i], j);
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            b[i][j] = f(g(b[i][j], -j), g(c[i][j], -i));
    for (int i = n - 1; i >= 0; i--)
        for (int j = n - 1; j >= 0; j--)
            b[i][j] = f(b[i][j], g(b[i + 1][j + 1], 1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            F(b[i][j], n - max(i, j));
    for (int i = n; i >= 1; i--)
        ans[i] += ans[i + 1];
    for (int i = 1; i <= n; i++)
        printf("%d\n", ans[i]);
}