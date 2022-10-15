#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, q, m, a[maxn], b[maxn];

int sign(int x) {
    return x <= n ? -1 : x > n + 1 ? 1 : 0;
}

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
const int maxm = 1 << 19;
int sum[maxm];
array<int, 2> mn[maxm];

void maintain(int k) {
    sum[k] = sum[ls] + sum[rs];
    mn[k] = min(mn[ls], array<int, 2>{mn[rs][0] + sum[ls], mn[rs][1]});
}

void build(int k, int l, int r) {
    if (l == r) { mn[k] = {sum[k] = sign(a[l]), l}; return; }
    build(ls, l, mid), build(rs, mid + 1, r);
    maintain(k);
}

void upd(int k, int l, int r, int p) {
    if (l == r) { mn[k] = {sum[k] = sign(a[l]), l}; return; }
    mid >= p ? upd(ls, l, mid, p) : upd(rs, mid + 1, r, p);
    maintain(k);
}

int query(int k, int l, int r, int p) {
    if (l == r) return 0;
    if (mid >= p) return query(ls, l, mid, p);
    return sum[ls] + query(rs, mid + 1, r, p);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q, m = 2 * n + 1;
    for (int i = 1; i <= m; i++) {
        cin >> a[i], b[a[i]] = i;
    }
    build(1, 1, m);
    int s1 = 0, s2 = 0;
    for (int i = 1; i <= n; i++) {
        if (b[i] > b[i + 1]) s1++;
        if (b[i + n] > b[i + n + 1]) s2++;
    }
    if (b[n + 1] > b[1]) s1++;
    if (b[m] > b[n + 1]) s2++;
    auto modify = [&](int p, int coef) {
        if (p <= n + 1) {
            int pre = p == 1 ? n + 1 : p - 1, nxt = p > n ? 1 : p + 1;
            s1 += coef * ((b[pre] > b[p]) + (b[p] > b[nxt]));
        }
        if (p > n) {
            int pre = p == n + 1 ? m : p - 1, nxt = p == m ? n + 1 : p + 1;
            s2 += coef * ((b[pre] > b[p]) + (b[p] > b[nxt]));
        }
    };
    while (q--) {
        int x, y;
        cin >> x >> y;
        modify(a[x], -1), b[a[x]] = y, modify(a[x], 1);
        modify(a[y], -1), b[a[y]] = x, modify(a[y], 1);
        swap(a[x], a[y]), upd(1, 1, m, x), upd(1, 1, m, y);
        if (mn[1][0] < query(1, 1, m, b[n + 1])) cout << mn[1][1] % m << "\n";
        else if (s1 ^ 1) cout << b[n + 1] % m << "\n";
        else if (s2 ^ 1) cout << b[n + 1] - 1 << "\n";
        else cout << "-1\n";
    }
    return 0;
}