#include <bits/stdc++.h>
using namespace std;

const int N = 2010, mod = 1e9 + 7;

int n, m, L, b[N], cnt, f[N], ans, cx, cy;

vector <int> px, py, idx[N], idy[N];

multiset <int> s[N];

struct Node {
    int x, y, c;
} a[N];

namespace Seg {
    int sum[N<<2], cn[N<<2], mn[N<<2], sn[N<<2];

    void up_(int o) {
        int lc = o<<1, rc = o<<1|1;
        sum[o] = (sum[lc] + sum[rc])%mod;

        if (mn[lc] < mn[rc]) {
            mn[o] = mn[lc], cn[o] = cn[lc];
            sn[o] = min(sn[lc], mn[rc]);
        } else if (mn[lc] == mn[rc]) {
            mn[o] = mn[lc], cn[o] = cn[lc] + cn[rc];
            sn[o] = min(sn[lc], sn[rc]);
        } else {
            mn[o] = mn[rc], cn[o] = cn[rc];
            sn[o] = min(mn[lc], sn[rc]);
        }
    }

    void max_(int o, int v) {
        if (mn[o] < v) {
            //assert(sn[o] > v);
            sum[o] = (sum[o] + 1ll*cn[o]*(v - mn[o]))%mod;
            mn[o] = v;
        } 
    }

    void down_(int o) {
        max_(o<<1, mn[o]);
        max_(o<<1|1, mn[o]);
    }

    void build_(int o, int l, int r) {
        if (l == r) {
            cn[o] = px[l] - px[l - 1];
            mn[o] = px[f[l]], sn[o] = 2e9;
            sum[o] = 1ll*mn[o]*cn[o]%mod;
            return; 
        }

        int mid = (l + r)>>1;
        build_(o<<1, l, mid);
        build_(o<<1|1, mid + 1, r);
        up_(o);
    }

    void updmx_(int o, int l, int r, int x, int y, int v) {
        if (mn[o] >= v) {
            return;
        }

        if (x <= l && r <= y && sn[o] > v) {
            max_(o, v);
            return;
        } 

        int mid = (l + r)>>1;
        down_(o);

        if (x <= mid) {
            updmx_(o<<1, l, mid, x, y, v);
        }

        if (mid < y) {
            updmx_(o<<1|1, mid + 1, r, x, y, v);
        }

        up_(o);
    }
}

void upd_(int c, int v) {
    if (b[c]) {
        cnt--;
    }

    b[c] += v;

    if (b[c]) {
        cnt++;
    }

    //assert(b[c] >= 0);
}

void calc_(int l, int r) {
    int y = 1ll*(py[r + 1] - py[r])*(py[l] - py[l - 1])%mod;
    ans = (ans + 1ll*(L + 1)*px[cx]%mod*y)%mod;
    ans = (ans - 1ll*y*Seg :: sum[1])%mod;
/*
    for (int i = 1; i <= cx; i++) {
        ans = (ans + 1ll*y*(px[i] - px[i - 1])%mod*(L + 1 - px[f[i]]));
    }
*/
}
/*
void max_(int l, int r, int v) {
    for (int i = l; i <= r; i++) {
        f[i] = max(f[i], v);
    }
}
*/
int main() {
    scanf("%d%d%d", &n, &m, &L);

    px.push_back(0), px.push_back(L + 1);
    py.push_back(0), py.push_back(L + 1);

    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].c);
        px.push_back(++a[i].x);
        py.push_back(++a[i].y);
    }

    sort(px.begin(), px.end());
    px.erase(unique(px.begin(), px.end()), px.end());
    sort(py.begin(), py.end());
    py.erase(unique(py.begin(), py.end()), py.end());
    cx = px.size() - 2, cy = py.size() - 2;

    for (int i = 1; i <= n; i++) {
        a[i].x = lower_bound(px.begin(), px.end(), a[i].x) - px.begin();
        a[i].y = lower_bound(py.begin(), py.end(), a[i].y) - py.begin();
        idx[a[i].x].push_back(i);
        idy[a[i].y].push_back(i);
        assert(a[i].y <= cy);
    }

    for (int i = 1; i <= cy; i++) {
        memset(b, 0, sizeof(b));
        memset(f, 0, sizeof(f));
        cnt = 0;

        for (int j = 1; j <= m; j++) {
            s[j].clear();
            s[j].insert(0);
            s[j].insert(cx + 1);
        }

        for (int j = 1; j <= cx; j++) {
            f[j] = f[j - 1];

            for (int k : idx[j - 1]) {
                if (a[k].y >= i) {
                    upd_(a[k].c, -1);
                }
            }

            while (cnt < m && f[j] <= cx) {
                f[j]++;

                for (int k : idx[f[j]]) {
                    if (a[k].y >= i) {
                        upd_(a[k].c, 1);
                        s[a[k].c].insert(a[k].x);
                    }
                }
            }
        }

        Seg :: build_(1, 1, cx);
        calc_(i, cy);

        for (int j = cy; j > i; j--) {
            for (int k : idy[j]) {
                int c = a[k].c, x = a[k].x;
                s[c].erase(s[c].find(x));
                int nx = *s[c].lower_bound(x), pr;

                if (nx == x) {
                    continue;
                }

                pr = *--s[c].lower_bound(x);
                Seg :: updmx_(1, 1, cx, pr + 1, x, px[nx]);
               // max_(pr + 1, x, nx);
            }

            calc_(i, j - 1);
        }
    }

    printf("%d\n", (ans%mod + mod)%mod);
}