#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int T, n, p[N], ans;

bool vis[N];

struct Node {
    int mx, add, op;
} t[N<<2];

void build_(int o, int l, int r) {
    t[o] = {0, 0, 0};

    if (l == r) return;

    int mid = (l + r)>>1;
    build_(o<<1, l, mid), build_(o<<1|1, mid + 1, r);
}

void up_(int o) {
    t[o].mx = 0;

    if (t[o<<1].op)
        t[o].mx = max(t[o].mx, t[o<<1].mx), t[o].op = 1;
    
    if (t[o<<1|1].op)
        t[o].mx = max(t[o].mx, t[o<<1|1].mx), t[o].op = 1;
}

void add_(int o, int v) {
    t[o].add += v, t[o].mx += v;
}

void down_(int o) {
    if (t[o].add) {
        add_(o<<1, t[o].add);
        add_(o<<1|1, t[o].add);
        t[o].add = 0;
    }
}

void set_(int o, int l, int r, int x) {
    if (l == r) {
        t[o].op = 1;
        t[o].mx += x + (x&1);
        return;
    }

    int mid = (l + r)>>1;
    down_(o);

    if (x <= mid) set_(o<<1, l, mid, x);
    else set_(o<<1|1, mid + 1, r, x);

    up_(o);
}

void upd_(int o, int l, int r, int x, int y, int v) {
    if (x <= l && r <= y) {
        add_(o, v);
        return;
    }

    int mid = (l + r)>>1;
    down_(o);

    if (x <= mid) 
        upd_(o<<1, l, mid, x, y, v);
    
    if (mid < y)
        upd_(o<<1|1, mid + 1, r, x, y, v);

    up_(o);
}

int ask_(int o, int l, int r, int x, int y) {
    if (x <= l && r <= y)
        return t[o].op ? t[o].mx : 0;
    
    int mid = (l + r)>>1, res = 0;
    down_(o);

    if (x <= mid) res = max(res, ask_(o<<1, l, mid, x, y));

    if (mid < y) res = max(res, ask_(o<<1|1, mid + 1, r, x, y));

    return res;
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        for (int x, i = 1; i <= n; i++)
            scanf("%d", &x), p[x] = i, vis[i] = 0;
        
        build_(1, 1, n);

        for (int i = 1, j = 0; i <= n; i++) {
            if (p[i] > 1)
                upd_(1, 1, n, 1, p[i] - 1, 1);

            set_(1, 1, n, p[i]), upd_(1, 1, n, p[i], n, -1), vis[p[i]] = 1;

            while (j < n && vis[j + 1])
                j++;
            
            if (j < n) 
                ans = max(ans, ask_(1, 1, n, j + 1, n));
        }

        printf("%d\n", ans), ans = 0;
    }
}