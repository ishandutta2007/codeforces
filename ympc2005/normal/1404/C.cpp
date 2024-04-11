#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int n, q, a[N], f[N], t[N], ans[N], y[N], b[N], mn[N<<2], id[N<<2];

bool vis[N];

vector <int> p[N];

void upd_(int x, int v) {
    for (; x <= n; x += x&-x) {
        t[x] += v;
    }
}

int ask_(int x, int res = 0) {
    for (; x; x -= x&-x) {
        res += t[x];
    }

    return res;
}

namespace Seg {
    int mn[N<<2], id[N<<2], add[N<<2];
    
    void up_(int o) {
        if (mn[o<<1] <= mn[o<<1|1]) {
            mn[o] = mn[o<<1];
            id[o] = id[o<<1];
        } else {
            mn[o] = mn[o<<1|1];
            id[o] = id[o<<1|1];
        }
    }

    void add_(int o, int v) {
        mn[o] += v;
        add[o] += v;
    }

    void down_(int o) {
        if (add[o]) {
            add_(o<<1, add[o]);
            add_(o<<1|1, add[o]);
            add[o] = 0;
        }
    }

    void upd_(int o, int l, int r, int x, int y, int k) {
        if (x <= l && r <= y) {
            add_(o, k);
            return;
        }

        int mid = (l + r)>>1;
        down_(o);

        if (x <= mid) {
            upd_(o<<1, l, mid, x, y, k);
        }

        if (mid < y) {
            upd_(o<<1|1, mid + 1, r, x, y, k);
        }

        up_(o);
    }

    void build_(int o, int l, int r) {
        if (l == r) {
            mn[o] = b[l];
            id[o] = l;
            return;
        }

        int mid = (l + r)>>1;
        build_(o<<1, l, mid);
        build_(o<<1|1, mid + 1, r);
        up_(o);
    }
}

void work_(int i) {
    upd_(i, -1);
    vis[i] = 0;
    Seg :: upd_(1, 1, n, i, i, n + 1);
            
    if (i < n) {
        Seg :: upd_(1, 1, n, i + 1, n, -1);
    }
}

int main() {
    scanf("%d%d", &n, &q);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        f[i] = f[i - 1];

        if (i >= a[i] && a[i] + f[i - 1] - i >= 0) {
            f[i]++;
            vis[i] = 1;
            upd_(i, 1);
            b[i] = a[i] + f[i - 1] - i;
        } else {
            b[i] = n + 1;
        }
    }

    Seg :: build_(1, 1, n);

    for (int x, i = 1; i <= q; i++) {
        scanf("%d%d", &x, &y[i]);
        p[x].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        if (i && vis[i]) {
            work_(i);
        }

        while (Seg :: mn[1] < 0) {
            work_(Seg :: id[1]);
        }

        for (int k : p[i]) {
            ans[k] = ask_(n - y[k]);
        }
    }
    
    for (int i = 1; i <= q; i++) {
        printf("%d\n", ans[i]);
    }
}