#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 10;

int n, m, T, a[N], b[N], id[N], add[N<<2], mn[N<<2], t[N];

ll ans;

void add_(int x) {
    for (; x <= n; x += x&-x) {
        t[x]++;
    }
}

int ask_(int x, int res = 0) {
    for (; x; x -= x&-x) {
        res += t[x];
    }

    return res;
}

bool cmp_(int u, int v) {
    return a[u] == a[v] ? u < v : a[u] < a[v];
}

void up_(int o) {
    mn[o] = min(mn[o<<1], mn[o<<1|1]);
}

void padd_(int o, int v) {
    mn[o] += v, add[o] += v;
}

void down_(int o) {
    if (add[o]) {
        padd_(o<<1, add[o]);
        padd_(o<<1|1, add[o]);
        add[o] = 0;
    }
}

void build_(int o, int l, int r) {
    add[o] = 0;

    if (l == r) {
        mn[o] = l;
        return;
    }

    int mid = (l + r)>>1;
    build_(o<<1, l, mid);
    build_(o<<1|1, mid + 1, r);
    up_(o);
}

void upd_(int o, int l, int r, int x, int y, int v) {
    if (x <= l && r <= y) {
        padd_(o, v);
        return;
    }

    down_(o);
    int mid = (l + r)>>1;

    if (x <= mid) {
        upd_(o<<1, l, mid, x, y, v);
    } 

    if (mid < y) {
        upd_(o<<1|1, mid + 1, r, x, y, v);
    }

    up_(o);
}

void init_() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        id[i] = i;
    }

    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
    }

    build_(1, 0, n);
    sort(id + 1, id + n + 1, cmp_);
    sort(b + 1, b + m + 1);
}

void work_() {
    ans = 0;

    for (int i = 1, j = 0, k = 0; i <= m; i++) {
        while (b[i] >= a[id[j + 1]] && j < n) {
            j++;
            upd_(1, 0, n, id[j], n, -1);
        }

        while (b[i] > a[id[k + 1]] && k < n) {
            k++;
            upd_(1, 0, n, 0, id[k] - 1, 1);
        }

        ans += mn[1];
    }

    for (int i = 1; i <= n; i++) {
        t[i] = 0;
    }

    for (int i = n; i; i--) {
        ans += ask_(id[i]);
        add_(id[i]);
    }

    printf("%lld\n", ans);
}

int main() {
    scanf("%d", &T);

    while (T--) {
        init_();
        work_();
    }
}