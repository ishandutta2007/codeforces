#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int N = 2e5 + 10, M = 3e5 + 10, Q = 5e5 + 10;

int n, m, q, a[M], b[M], p[N], fa[N<<1], op[Q], id[Q], tot, g[N<<1];

int t[M], f[N<<1][20], st[N<<1], ed[N<<1], tim, c[N], ch[N<<1][2];

pii mx[N<<2], res;

int find_(int x) {
    return fa[x] == x ? x : fa[x] = find_(fa[x]);
}

void merge_(int k) {
    int u = find_(a[k]), v = find_(b[k]);

    if (u != v) {
        g[++tot] = t[k];
        fa[u] = fa[v] = fa[tot] = tot;
        f[u][0] = f[v][0] = tot;
        ch[tot][0] = u;
        ch[tot][1] = v;
    }
}

void dfs_(int u) {
    st[u] = tim + 1;

    if (u <= n) {
        c[++tim] = p[u];
    } else {
        dfs_(ch[u][0]);
        dfs_(ch[u][1]);
    }

    ed[u] = tim;
}

void up_(int o) {
    mx[o] = max(mx[o<<1], mx[o<<1|1]);
}

void build_(int o, int l, int r) {
    if (l == r) {
        mx[o] = pii(c[l], l);
        return;
    }

    int mid = (l + r)>>1;
    build_(o<<1, l, mid);
    build_(o<<1|1, mid + 1, r);
    up_(o);
}

void upd_(int o, int l, int r, int x) {
    if (l == r) {
        mx[o].first = 0;
        return;
    }

    int mid = (l + r)>>1;

    if (x <= mid) {
        upd_(o<<1, l, mid, x);
    } else {
        upd_(o<<1|1, mid + 1, r, x);
    }

    up_(o);
}

void ask_(int o, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        res = max(res, mx[o]);
        return;
    }

    int mid = (l + r)>>1;

    if (x <= mid) {
        ask_(o<<1, l, mid, x, y);
    }

    if (mid < y) {
        ask_(o<<1|1, mid + 1, r, x, y);
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &q);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        fa[i] = i, g[i] = q + 1;
    }

    tot = n;

    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &a[i], &b[i]);
        t[i] = q + 1;
    }

    for (int i = 1; i <= q; i++) {
        scanf("%d%d", &op[i], &id[i]);
        
        if (op[i] == 2) {
            t[id[i]] = i;
        }
    }

    for (int i = 1; i <= m; i++) {
        if (t[i] > q) {
            merge_(i);
        }
    }

    for (int i = q; i; i--) {
        if (op[i] == 2) {
            merge_(id[i]);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (find_(i) != find_(1)) {
            a[0] = i, b[0] = 1, t[0] = 0;
            merge_(0);
        }
    }

    dfs_(tot);

    build_(1, 1, n);

    f[tot][0] = tot;

    for (int k = 1; k < 20; k++) {
        for (int i = 1; i <= tot; i++) {
            f[i][k] = f[f[i][k - 1]][k - 1];
        }
    }

    for (int i = 1; i <= q; i++) {
        if (op[i] == 1) {
            int x = id[i];

            for (int k = 19; k >= 0; k--) {
                if (g[f[x][k]] > i) {
                    x = f[x][k];
                }
            }

            res = pii(0, st[x]);
            assert(st[x] <= ed[x] && ed[x] <= n && 1 <= st[x]);
            ask_(1, 1, n, st[x], ed[x]);
            printf("%d\n", res.first);
            //assert(1 <= res.second && res.second <= n);
            upd_(1, 1, n, res.second);
        }
    }
}