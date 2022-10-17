#include <bits/stdc++.h>
const int MaxN = 100010;
struct node
{
    int val, dfn, r, id;
};
struct query
{
    int l, r;
    int pos, id, k;
};
struct edge
{
    int next, to;
};
node a[MaxN];
query q[MaxN];
edge e[MaxN << 1];
int n, m, cnt, dfscnt, size;
int head[MaxN], ans[MaxN], sum[MaxN], val[MaxN];
inline int comp(node a, node b) { return a.dfn < b.dfn; }
inline int cmp(query a, query b)
{
    if (a.pos != b.pos)
        return a.pos < b.pos;
    return a.r < b.r;
}
inline void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}
inline void dfs(int u)
{
    a[u].dfn = ++dfscnt;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (!a[v].dfn)
            dfs(v);
    }
    a[u].r = dfscnt;
}
inline int read()
{
    int x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}
inline void add(int x) { ++val[a[x].val], ++sum[val[a[x].val]]; }
inline void del(int x) { --sum[val[a[x].val]], --val[a[x].val]; }
inline void solve()
{
    int l = 1, r = 0;
    for (int i = 1; i <= m; i++)
    {
        while (l > q[i].l)
            --l, add(l);
        while (r < q[i].r)
            ++r, add(r);
        while (l < q[i].l)
            del(l), ++l;
        while (r > q[i].r)
            del(r), --r;
        ans[q[i].id] = sum[q[i].k];
    }
}
int main()
{
    n = read(), m = read();
    size = pow(n, 0.55);
    for (int i = 1; i <= n; i++)
        a[i].val = read(), a[i].id = i;
    for (int i = 1; i <= n - 1; i++)
    {
        int u = read(), v = read();
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs(1);
    for (int i = 1; i <= m; i++)
    {
        int v, k;
        v = read(), k = read();
        q[i].l = a[v].dfn, q[i].r = a[v].r, q[i].k = k;
        q[i].id = i, q[i].pos = (q[i].l - 1) / size + 1;
    }
    std::sort(q, q + m + 1, cmp);
    std::sort(a + 1, a + n + 1, comp);
    solve();
    for (int i = 1; i <= m; i++)
        printf("%d\n", ans[i]);
    return 0;
}