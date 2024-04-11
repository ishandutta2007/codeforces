#include <bits/stdc++.h>
using namespace std;

const int maxn = 250010;
int T, n, a[maxn], d[maxn], mn1[maxn << 2], mn2[maxn << 2];
int lb1[maxn], lb2[maxn], rb1[maxn], rb2[maxn];
vector<array<int, 2>> M1[maxn], M2[maxn];

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void upd(int *mn, int k, int l, int r, int p, int v) {
    if (l == r) { mn[k] = v; return; }
    mid >= p ? upd(mn, ls, l, mid, p, v) : upd(mn, rs, mid + 1, r, p, v);
    mn[k] = min(mn[ls], mn[rs]);
}

int query(int *mn, int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return mn[k];
    int s = 1e9;
    if (mid >= ql) s = query(mn, ls, l, mid, ql, qr);
    if (mid < qr) s = min(s, query(mn, rs, mid + 1, r, ql, qr));
    return s;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            M1[i].clear(), M2[i].clear();
        }
        vector<int> st;
        for (int i = 1; i <= n; i++) {
            while (!st.empty() && a[st.back()] < a[i]) st.pop_back();
            lb1[i] = !st.empty() ? st.back() + 1 : 1, st.push_back(i);
        }
        st.clear();
        for (int i = 1; i <= n; i++) {
            while (!st.empty() && a[st.back()] > a[i]) st.pop_back();
            lb2[i] = !st.empty() ? st.back() + 1 : 1, st.push_back(i);
        }
        st.clear();
        for (int i = n; i; i--) {
            while (!st.empty() && a[st.back()] < a[i]) st.pop_back();
            rb1[i] = !st.empty() ? st.back() - 1 : n, st.push_back(i);
        }
        st.clear();
        for (int i = n; i; i--) {
            while (!st.empty() && a[st.back()] > a[i]) st.pop_back();
            rb2[i] = !st.empty() ? st.back() - 1 : n, st.push_back(i);
        }
        fill(mn1, mn1 + (n << 2), 1e9);
        fill(mn2, mn2 + (n << 2), 1e9);
        for (int i = 1; i <= n; i++) {
            for (auto &p : M1[i]) {
                if (p[1]) upd(mn1, 1, 1, n, p[0], d[p[0]]);
                else upd(mn1, 1, 1, n, p[0], 1e9);
            }
            for (auto &p : M2[i]) {
                if (p[1]) upd(mn2, 1, 1, n, p[0], d[p[0]]);
                else upd(mn2, 1, 1, n, p[0], 1e9);
            }
            if (i > 1) {
                d[i] = query(mn1, 1, 1, n, lb1[i], i) + 1;
                d[i] = min(d[i], query(mn2, 1, 1, n, lb2[i], i) + 1);
            }
            if (i < n) {
                M1[i + 1].push_back({i, 1});
                M1[rb2[i] + 1].push_back({i, 0});
                M2[i + 1].push_back({i, 1});
                M2[rb1[i] + 1].push_back({i, 0});
            }
        }
        cout << d[n] << "\n";
    }
    return 0;
}