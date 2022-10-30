#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int N = 2e5 + 10;

int n, p[N], id[N], q;

namespace Tree {
    vector <int> e[N];

    int fa[N], tim, dfn[N], id[N<<1], b[N<<1], f[N<<1][20], d[N];

    void dfs_(int u) {
        ++tim;
        f[tim][0] = tim;
        dfn[u] = tim;
        id[tim] = u;

        for (int v : e[u]) {
            dfs_(v);
            f[++tim][0] = dfn[u];
        }
    }

    int lca_(int u, int v) {
        int l = dfn[u], r = dfn[v];

        if (l > r) {
            swap(l, r);
        }
//
        int k = b[r - l + 1];
        return id[min(f[l][k], f[r - (1<<k) + 1][k])];
    }

    int dis_(int u, int v) {
        return d[u] + d[v] - 2*d[lca_(u, v)];
    }

    bool chk_(int u, int v, int w) {
        return dis_(u, w) + dis_(v, w) == dis_(u, v);
    }

    void build_() {
        for (int i = 2; i <= n; i++) {
            cin>>fa[i];
            d[i] = d[fa[i]] + 1;
            e[fa[i]].push_back(i);
        }

        dfs_(1);

        for (int i = 2; i <= tim; i++) {
            b[i] = b[i>>1] + 1;
        }

        for (int k = 1; k <= b[tim]; k++) {
            for (int i = 1; i + (1<<k) - 1 <= tim; i++) {
                f[i][k] = min(f[i][k - 1], f[i + (1<<k - 1)][k - 1]);
            }
        }
    }
}

namespace DS {
    pii t[N<<2];

    pii add_(pii a, int z) {
        int x = a.first, y = a.second;

        if (Tree :: chk_(x, y, z)) {
            return pii(x, y);
        }

        if (Tree :: chk_(x, z, y)) {
            return pii(x, z);
        }

        if (Tree :: chk_(y, z, x)) {
            return pii(y, z);
        }

        return pii(0, 0);
    }

    pii merge_(pii a, pii b) {
        if (!a.first || !b.first) {
            return pii(0, 0);
        }

        a = add_(a, b.first);
        
        if (!a.first) {
            return a;
        }

        return add_(a, b.second);
    }

    void up_(int o) {
        t[o] = merge_(t[o<<1], t[o<<1|1]);
    }

    void build_(int o, int l, int r) {
        if (l == r) {
            t[o] = pii(id[l], id[l]);
            return;
        }

        int mid = (l + r)>>1;
        build_(o<<1, l, mid);
        build_(o<<1|1, mid + 1, r);
        up_(o);
    }

    int ask_(int o, int l, int r, pii x) {
        if (l == r) {
            return l;
        }

        int mid = (l + r)>>1;
        pii y = merge_(x, t[o<<1]);

        if (y.first) {
            return ask_(o<<1|1, mid + 1, r, y);
        }

        return ask_(o<<1, l, mid, x);
    }

    void upd_(int o, int l, int r, int x, int y) {
        if (l == r) {
            t[o] = pii(y, y);
            return;
        }

        int mid = (l + r)>>1;

        if (x <= mid) {
            upd_(o<<1, l, mid, x, y);
        } else {
            upd_(o<<1|1, mid + 1, r, x, y);
        }

        up_(o);
    }
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n;

    for (int i = 1; i <= n; i++) {
        cin>>p[i];
        id[p[i]] = i;
    }

    Tree :: build_();
    DS :: build_(1, 0, n);
    cin>>q;

    for (int op, x, y, i = 1; i <= q; i++) {
        cin>>op;

        if (op == 1) {
            cin>>x>>y;
            swap(p[x], p[y]);
            id[p[x]] = x;
            id[p[y]] = y;
            DS :: upd_(1, 0, n, p[x], x);
            DS :: upd_(1, 0, n, p[y], y);
        } else {
            cout<<DS :: ask_(1, 0, n, pii(id[0], id[0]))<<'\n';
        }
    }
}