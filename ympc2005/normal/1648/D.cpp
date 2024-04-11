#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair <ll, int> pli;

const int N = 5e5 + 10;

int n, m;

ll s[3][N], ans = -1e18, f[N];

struct Seg1 {
    ll mx[N<<2];

    void init_() {
        memset(mx, -0x3f, sizeof(mx));
    }

    void upd_(int o, int l, int r, int x, int y, ll v) {
        if (x <= l && r <= y) {
            mx[o] = max(mx[o], v);
            return;
        }

        int mid = (l + r)>>1;

        if (x <= mid) {
            upd_(o<<1, l, mid, x, y, v);
        }

        if (mid < y) {
            upd_(o<<1|1, mid + 1, r, x, y, v);
        }
    }

    ll ask_(int o, int l, int r, int x) {
        ll res = mx[o];

        if (l < r) {
            int mid = (l + r)>>1;
            
            if (x <= mid) {
                res = max(res, ask_(o<<1, l, mid, x));
            } else {
                res = max(res, ask_(o<<1|1, mid + 1, r, x));
            }
        }

        return res;
    }
} T2;

struct Seg2 {
    pli mx[N<<2];

    void init_() {
        for (int i = 1; i < n*4; i++) {
            mx[i] = pli(-1e18, 0);
        }
    }

    void upd_(int o, int l, int r, int x, pli v) {
        if (l == r) {
            mx[o] = max(mx[o], v);
            return;
        }

        int mid = (l + r)>>1;

        if (x <= mid) {
            upd_(o<<1, l, mid, x, v);
        } else {
            upd_(o<<1|1, mid + 1, r, x, v);
        }

        mx[o] = max(mx[o<<1], mx[o<<1|1]);
    }

    pli ask_(int o, int l, int r, int x, int y) {
        if (x <= l && r <= y) {
            return mx[o];
        }

        int mid = (l + r)>>1;
        pli res = pli(-1e18, 0);

        if (x <= mid) {
            res = max(res, ask_(o<<1, l, mid, x, y));
        }
        
        if (mid < y) {
            res = max(res, ask_(o<<1|1, mid + 1, r, x, y));
        }

        return res;
    }
} T1, T3;

struct Node {
    int l, r, k;

    bool operator < (const Node &tmp) const {
        return r < tmp.r;
    }
} a[N];

namespace Seg3 {
    struct Node {
        ll mx, vl, vr;

        Node () {
            mx = vl = vr = -1e18;
        }
    } t[N<<2];

    Node operator + (Node a, Node b) {
        Node c;
        c.mx = max(max(a.mx, b.mx), a.vl + b.vr);
        c.vl = max(a.vl, b.vl);
        c.vr = max(a.vr, b.vr);
        return c;
    }

    void build_(int o, int l, int r) {
        if (l == r) {
            t[o].vl = s[0][l] - s[1][l - 1];
            t[o].vr = s[1][l] + s[2][n] - s[2][l - 1];
            t[o].mx = t[o].vl + t[o].vr;
            return;
        }

        int mid = (l + r)>>1;
        build_(o<<1, l, mid);
        build_(o<<1|1, mid + 1, r);
        t[o] = t[o<<1] + t[o<<1|1];
    }

    Node ask_(int o, int l, int r, int x, int y) {
        if (x <= l && r <= y) {
            return t[o];
        }

        int mid = (l + r)>>1; Node res;

        if (x <= mid) {
            res = ask_(o<<1, l, mid, x, y);
        }

        if (mid < y) {
            res = res + ask_(o<<1|1, mid + 1, r, x, y);
        }

        return res;
    }
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%lld", &s[i][j]);
            s[i][j] += s[i][j - 1];
        }
    }

    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].k);
    }

    T1.init_();
    T2.init_();
    T3.init_();

    for (int i = 1; i <= n; i++) {
        T1.upd_(1, 1, n, i, pli(s[0][i] - s[1][i - 1], i));
        T3.upd_(1, 1, n, i, pli(s[2][n] - s[2][i - 1] + s[1][i], i));
    }

    sort(a + 1, a + m + 1);

    Seg3 :: build_(1, 1, n);

    for (int i = 1; i <= m; i++) {
        f[i] = T2.ask_(1, 1, n, a[i].l) - a[i].k + s[1][a[i].r];
        ans = max(ans, f[i] + T3.ask_(1, 1, n, a[i].l, a[i].r).first - s[1][a[i].r]);
        T2.upd_(1, 1, n, a[i].l, min(a[i].r + 1, n), f[i] - s[1][a[i].r]);
        pli tmp = T1.ask_(1, 1, n, a[i].l, a[i].r);
        f[i] = -a[i].k + s[1][a[i].r] + tmp.first;
        T2.upd_(1, 1, n, tmp.second, min(a[i].r + 1, n), f[i] - s[1][a[i].r]);
        ans = max(ans, Seg3 :: ask_(1, 1, n, a[i].l, a[i].r).mx - a[i].k);
    }

    printf("%lld\n", ans);
}