#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int T, n, q;
char s[maxn];
struct node { int cnt, lst; } t[maxn << 2];

node merge(node A, node B) {
    if (A.lst == (B.lst ^ (B.cnt % 2) ^ 1)) {
        if (A.cnt <= B.cnt) return (node){B.cnt - A.cnt, B.lst};
        else return (node){A.cnt - B.cnt, A.lst ^ (B.cnt % 2)};
    } else {
        return (node){A.cnt + B.cnt, B.lst};
    }
}

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void build(int k, int l, int r) {
    if (l == r) { t[k].cnt = 1, t[k].lst = s[l] == '+'; return; }
    build(ls, l, mid), build(rs, mid + 1, r);
    t[k] = merge(t[ls], t[rs]);
}

node query(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return t[k];
    if (mid >= qr) return query(ls, l, mid, ql, qr);
    if (mid < ql) return query(rs, mid + 1, r, ql, qr);
    return merge(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
}

int find(int k, int l, int r, int ql, int qr, int p) {
    if (l >= ql && r <= qr) {
        if (l == r) return l;
        auto A = t[ls], B = t[rs];
        if (A.lst == (B.lst ^ (B.cnt % 2) ^ 1)) {
            if (A.cnt <= B.cnt) return find(rs, mid + 1, r, ql, qr, p + A.cnt);
            return find(ls, l, mid, ql, qr, p);
        } else {
            if (p <= A.cnt) return find(ls, l, mid, ql, qr, p);
            return find(rs, mid + 1, r, ql, qr, p - A.cnt);
        }
    }
    if (mid >= qr) return find(ls, l, mid, ql, qr, p);
    if (mid < ql) return find(rs, mid + 1, r, ql, qr, p);
    auto A = query(ls, l, mid, ql, qr);
    auto B = query(rs, mid + 1, r, ql, qr);
    if (A.lst == (B.lst ^ (B.cnt % 2) ^ 1)) {
        if (A.cnt <= B.cnt) return find(rs, mid + 1, r, ql, qr, p + A.cnt);
        return find(ls, l, mid, ql, qr, p);
    } else {
        if (p <= A.cnt) return find(ls, l, mid, ql, qr, p);
        return find(rs, mid + 1, r, ql, qr, p - A.cnt);
    }
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %s", &n, &q, s + 1);
        build(1, 1, n);
        while (q--) {
            int l, r;
            scanf("%d %d", &l, &r);
            auto p = query(1, 1, n, l, r);
            int x = p.cnt;
            if (!x) {
                printf("%d\n", x);
            } else if (!(x & 1)) {
                printf("2\n%d %d\n", find(1, 1, n, l, r, x / 2), find(1, 1, n, l, r, x));
            } else {
                printf("1\n%d\n", find(1, 1, n, l, r, (x + 1) / 2));
            }
        }
    }
    return 0;
}