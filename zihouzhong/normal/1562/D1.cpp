#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int T, n, q, pre[maxn], cnt[maxn], nxt[maxn];
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

#define mid (l + r >> 1)
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

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %s", &n, &q, s + 1);
        build(1, 1, n);
        while (q--) {
            int l, r;
            scanf("%d %d", &l, &r);
            int x = query(1, 1, n, l, r).cnt, y = (x + 1) / 2;
            if (y % 2 == 1) y--;
            if (x <= 4) printf("%d\n", x - y);
            else printf("%d\n", x % 2 == 0 ? 2 : 1);
        }
    }
    return 0;
}