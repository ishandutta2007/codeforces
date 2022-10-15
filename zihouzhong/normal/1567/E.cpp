#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
int n, q, a[maxn], tag[maxn << 2];
ll sum[maxn << 2];
set<pair<int, int>> S;

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void pushdown(int k, int l, int r) {
    sum[ls] = 1LL * tag[k] * (mid - l + 1), tag[ls] = tag[k];
    sum[rs] = 1LL * tag[k] * (r - mid), tag[rs] = tag[k], tag[k] = 0;
}

void modify(int k, int l, int r, int ql, int qr, int v) {
    if (l >= ql && r <= qr) { tag[k] = v, sum[k] = 1LL * (r - l + 1) * v; return; }
    if (tag[k]) pushdown(k, l, r);
    if (mid >= ql) modify(ls, l, mid, ql, qr, v);
    if (mid < qr) modify(rs, mid + 1, r, ql, qr, v);
    sum[k] = sum[ls] + sum[rs];
}

ll query(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return sum[k];
    if (tag[k]) pushdown(k, l, r);
    ll s = 0;
    if (mid >= ql) s = query(ls, l, mid, ql, qr);
    if (mid < qr) s += query(rs, mid + 1, r, ql, qr);
    return s;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1, j; i <= n; i = j) {
        for (j = i + 1; j <= n && a[j - 1] <= a[j]; j++);
        S.emplace(i, j - 1);
        modify(1, 1, n, i, j - 1, j - 1);
    }
    while (q--) {
        int op, x, y;
        scanf("%d %d %d", &op, &x, &y);
        if (op == 1) {
            auto it = --S.lower_bound({x + 1, 0});
            int l = it->first, r = it->second;
            S.erase(it);
            if (l < x) modify(1, 1, n, l, x - 1, x - 1), S.emplace(l, x - 1);
            if (x < r) modify(1, 1, n, x + 1, r, r), S.emplace(x + 1, r);
            a[x] = y, l = r = x;
            if (x > 1 && a[x - 1] <= a[x]) l = prev(S.lower_bound({x, 0}))->first, S.erase({l, x - 1});
            if (x < n && a[x] <= a[x + 1]) r = S.lower_bound({x + 1, 0})->second, S.erase({x + 1, r});
            modify(1, 1, n, l, r, r), S.emplace(l, r);
        } else {
            int l = x, r = y, pos = x - 1;
            while (l <= r) {
                query(1, 1, n, mid, mid) <= y ? l = (pos = mid) + 1 : r = mid - 1;
            }
            ll ans = pos < x ? 0 : query(1, 1, n, x, pos);
            ans += 1LL * y * (y - pos);
            ans -= 1LL * (x + y - 2) * (y - x + 1) / 2;
            printf("%lld\n", ans);
        }
    }
    return 0;
}