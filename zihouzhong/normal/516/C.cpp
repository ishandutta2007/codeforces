#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
int n, m;
ll sum[maxn], h[maxn], a[maxn];

struct node {
    ll mx, mn, ans;
    node() { mx = mn = ans = -1e18; }
} t[maxn << 2];

node operator + (node a, node b) {
    node c;
    c.mx = max(a.mx, b.mx), c.mn = max(a.mn, b.mn);
    c.ans = max(a.mn + b.mx, max(a.ans, b.ans));
    return c;
}

#define ls (k << 1)
#define rs (k << 1 | 1)
#define mid ((l + r) >> 1)
void build(int k, int l, int r) {
    if (l == r) {
        t[k].mx = sum[l - 1] + 2 * h[l], t[k].mn = -sum[l - 1] + 2 * h[l];
        return;
    }
    build(ls, l, mid), build(rs, mid + 1, r), t[k] = t[ls] + t[rs];
}


node query(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return t[k];
    node s;
    if (mid >= ql) s = query(ls, l, mid, ql, qr);
    if (mid < qr) s = s + query(rs, mid + 1, r, ql, qr);
    return s;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]), a[i + n] = a[i];
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &h[i]), h[i + n] = h[i];
    }
    for (int i = 1; i <= 2 * n; i++) {
        sum[i] = a[i] + sum[i - 1];
    }
    build(1, 1, 2 * n);
    while (m--) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a <= b) printf("%lld\n", query(1, 1, 2 * n, b + 1, a + n - 1).ans);
        else printf("%lld\n", query(1, 1, 2 * n, b + 1, a - 1).ans);
    }
    return 0;
}