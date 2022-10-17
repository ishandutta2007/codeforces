#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
int n, q;

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
namespace BIT {
ll c1[maxn], c2[maxn];

void add(ll *c, int p, ll v) {
    for (; p <= n; p += p & -p) c[p] += v;
}

ll sum(ll *c, int p) {
    ll s = 0;
    for (; p; p -= p & -p) s += c[p];
    return s;
}

void modify(int p, int v) {
    add(c1, p, v), add(c2, p, 1LL * p * v);
}

void add(int l, int r, int v) {
    if (l <= r) modify(l, v), modify(r + 1, -v);
}

ll sum(int l) {
    return 1LL * (l + 1) * sum(c1, l) - sum(c2, l) + l;
}
}  // namespace BIT

namespace SEG {
int mx[maxn << 2], sec[maxn << 2], cnt[maxn << 2], tag[maxn << 2];

void maintain(int k) {
    mx[k] = max(mx[ls], mx[rs]), sec[k] = 0;
    cnt[k] = (mx[k] == mx[ls] ? cnt[ls] : 0) + (mx[k] == mx[rs] ? cnt[rs] : 0);
    auto chk = [&](int x) { if (x ^ mx[k]) sec[k] = max(sec[k], x); };
    chk(mx[ls]), chk(mx[rs]), chk(sec[ls]), chk(sec[rs]);
}

void apply(int k, int v) {
    if (mx[k] > v) mx[k] = tag[k] = v;
}

void pushdown(int k) {
    apply(ls, tag[k]), apply(rs, tag[k]), tag[k] = INT_MAX;
}

void build(int k, int l, int r) {
    tag[k] = INT_MAX;
    if (l == r) { mx[k] = l, cnt[k] = 1; return; }
    build(ls, l, mid), build(rs, mid + 1, r), maintain(k);
}

void modify(int k, int l, int r, int ql, int qr, int v) {
    if (mx[k] <= v) return;
    if (l >= ql && r <= qr && sec[k] < v) {
        BIT::add(v + 1, mx[k], -cnt[k]), apply(k, v); return;
    }
    if (tag[k] ^ INT_MAX) pushdown(k);
    if (mid >= ql) modify(ls, l, mid, ql, qr, v);
    if (mid < qr) modify(rs, mid + 1, r, ql, qr, v);
    maintain(k);
}

void upd(int k, int l, int r, int p, int v) {
    if (l == r) {
        if (v > mx[k]) BIT::add(mx[k] + 1, v, 1);
        else BIT::add(v + 1, mx[k], -1);
        mx[k] = v, sec[k] = 0, cnt[k] = 1; return;
    }
    if (tag[k] ^ INT_MAX) pushdown(k);
    mid >= p ? upd(ls, l, mid, p, v) : upd(rs, mid + 1, r, p, v);
    maintain(k);
}
}  // namespace SEG

int main() {
    scanf("%d %d", &n, &q);
    SEG::build(1, 1, n);
    while (q--) {
        int op, x, y;
        scanf("%d %d %d", &op, &x, &y);
        if (op == 1) {
            if (x > 1) SEG::modify(1, 1, n, 1, x - 1, x - 1);
            SEG::upd(1, 1, n, x, y);
        } else {
            printf("%lld\n", BIT::sum(y) - BIT::sum(x - 1));
        }
    }
    return 0;
}