#include <bits/stdc++.h>
using namespace std;

template <class comp = less<>> struct rmq {
    vector<vector<int>> st;
    rmq(const vector<int> &arr) : st(__lg(arr.size()) + 1) {
        st[0] = arr;
        for (int k = 1; k < st.size(); k++) {
            st[k] = st[k - 1];
            for (int i = 0; i + (1 << k) <= st[k].size(); i++) {
                int x = st[k - 1][i + (1 << (k - 1))];
                st[k][i] = comp()(st[k][i], x) ? st[k][i] : x;
            }
        }
    }

    int query(int l, int r) {
        int k = __lg(r - l + 1);
        int x = st[k][l], y = st[k][r - (1 << k) + 1];
        return comp()(x, y) ? x : y;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x, x--;
    }
    int lim = __lg(n) + 2;
    vector<vector<int>> L(lim, vector<int>(n - 1)), R = L;
    vector<rmq<>> mn;
    vector<rmq<greater<>>> mx;
    auto trans = [&](int k, int l, int r) -> array<int, 2> {
        if (l == r--) return {l, l};
        return {mn[k].query(l, r), mx[k].query(l, r)};
    };
    for (int k = 0; k < lim; k++) {
        for (int i = 0; i < n - 1; i++) {
            if (!k) {
                L[k][i] = min(a[i], a[i + 1]);
                R[k][i] = max(a[i], a[i + 1]);
            } else {
                auto p = trans(k - 1, L[k - 1][i], R[k - 1][i]);
                L[k][i] = p[0], R[k][i] = p[1];
            }
        }
        mn.push_back(L[k]), mx.push_back(R[k]);
    }
    while (q--) {
        int l, r, ans = 1;
        cin >> l >> r, l--, r--;
        if (!l && r == n - 1) { cout << "0\n"; continue; }
        if (l == r) { cout << "-1\n"; continue; }
        for (int k = lim - 1; ~k; k--) {
            auto p = trans(k, l, r);
            if (p[0] || p[1] < n - 1) ans += 1LL << k, l = p[0], r = p[1];
        }
        if (trans(0, l, r) != array<int, 2>{0, n - 1}) ans = -1;
        cout << ans << "\n";
    }
    return 0;
}