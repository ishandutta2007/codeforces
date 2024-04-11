#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, tot, p[maxn], pos[maxn], pre[maxn], suf[maxn];
int flag, lst;

struct node {
    int l, r, sz, lb = INT_MAX, rb = 0, ok = 1;
} t1[maxn * 20], t2[maxn * 20];

void maintain(node *t, int k) {
    int ls = t[k].l, rs = t[k].r;
    t[k].sz = t[ls].sz + t[rs].sz;
    t[k].lb = ls ? t[ls].lb : t[rs].lb;
    t[k].rb = rs ? t[rs].rb : t[ls].rb;
    t[k].ok = t[ls].ok & t[rs].ok & (t[ls].rb < t[rs].lb);
}

void ins(node *t, int &k1, int k2, int l, int r, int p, int v) {
    t[k1 = ++tot] = t[k2];
    if (l == r) { t[k1].sz++, t[k1].lb = t[k1].rb = v; return; }
    int mid = (l + r) / 2;
    if (mid >= p) ins(t, t[k1].l, t[k2].l, l, mid, p, v);
    else ins(t, t[k1].r, t[k2].r, mid + 1, r, p, v);
    maintain(t, k1);
}

int query(node *t, int k, int l, int r, int ql, int qr) {
    if (!k || l >= ql && r <= qr) return t[k].sz;
    int mid = (l + r) / 2, s = 0;
    if (mid >= ql) s = query(t, t[k].l, l, mid, ql, qr);
    if (mid < qr) s += query(t, t[k].r, mid + 1, r, ql, qr);
    return s;
}

void chk(node *t, int k, int l, int r, int ql, int qr) {
    if (!t[k].sz) return;
    if (l >= ql && r <= qr) { flag &= lst < t[k].lb && t[k].ok, lst = t[k].rb; return; }
    int mid = (l + r) / 2;
    if (mid >= ql) chk(t, t[k].l, l, mid, ql, qr);
    if (mid < qr) chk(t, t[k].r, mid + 1, r, ql, qr);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i], pos[p[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        ins(t1, pre[i], pre[i - 1], 1, n, pos[i], n - i + 1);
    }
    tot = 0;
    for (int i = n; i; i--) {
        ins(t2, suf[i], suf[i + 1], 1, n, pos[i], i);
    }
    vector<int> inc, dec;
    for (int i = 1; i <= n; i++) {
        if (p[i] < p[i + 1]) inc.push_back(i);
        else dec.push_back(i);
    }
    p[n + 1] = 0, p[n + 2] = n + 1;
    inc.push_back(n + 1), dec.push_back(n + 2);
    vector<int> nxt1(inc.size()), nxt2(dec.size());
    for (int i = inc.size() - 1; ~i; i--) {
        nxt1[i] = i;
        if (i + 1 < inc.size() && p[inc[i]] < p[inc[i + 1]]) nxt1[i] = nxt1[i + 1];
    }
    for (int i = dec.size() - 1; ~i; i--) {
        nxt2[i] = i;
        if (i + 1 < dec.size() && p[dec[i]] > p[dec[i + 1]]) nxt2[i] = nxt2[i + 1];   
    }
    auto test = [&](int i, int j) {
        int lb = i, rb = j, k, l, r;
        while (lb <= rb) {
            int mid = (lb + rb) / 2;
            bool flag = 1;
            int l1 = lower_bound(inc.begin(), inc.end(), i) - inc.begin();
            int r1 = upper_bound(inc.begin(), inc.end(), mid) - inc.begin();
            if (inc[l1] <= mid) flag &= nxt1[l1] + 1 >= r1;
            int l2 = lower_bound(dec.begin(), dec.end(), i) - dec.begin();
            int r2 = upper_bound(dec.begin(), dec.end(), mid) - dec.begin();
            if (dec[l2] <= mid) flag &= nxt2[l2] + 1 >= r2;
            int x = inc[l1] <= mid ? p[inc[r1 - 1]] : 0;
            int y = dec[l2] <= mid ? p[dec[r2 - 1]] : n + 1;
            if (flag && x <= y) lb = (k = mid) + 1, l = x, r = y;
            else rb = mid - 1;
        }
        if (k++ == j) return 1;
        if (p[k] > r) l = p[k];
        else r = p[k];
        if (k++ == j) return 1;
        if (query(t1, pre[r], 1, n, k, j) + query(t2, suf[l], 1, n, k, j) <= j - k) return 0;
        flag = 1, lst = 0, chk(t1, pre[r], 1, n, k, j);
        if (!flag) return 0;
        flag = 1, lst = 0, chk(t2, suf[l], 1, n, k, j);
        if (!flag) return 0;
        return 1;
    };
    long long ans = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        while (j < n && test(i, j + 1)) j++;
        ans += j - i + 1;
    }
    cout << ans << "\n";
    return 0;
}