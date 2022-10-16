#include <bits/stdc++.h>
using namespace std;
class SegmentTree {
  public:
    SegmentTree *left, *right;
    const int l, r, m;
    uint32_t mi;
    uint32_t lazy;

    SegmentTree(int l, int r) : l(l), m((l + r) / 2), r(r) {
        if (l == r) return;
        left = new SegmentTree(l, m);
        right = new SegmentTree(m + 1, r);
    }

    void Clear(const uint32_t* a) {
        lazy = 0;
        if (l == r)
            mi = a[l];
        else {
            left->Clear(a);
            right->Clear(a);
            mi = min(left->mi, right->mi);
        }
    }

    void Down() {
        if (!lazy) return;
        left->lazy += lazy;
        right->lazy += lazy;
        left->mi += lazy;
        right->mi += lazy;
        lazy = 0;
    }

    void Update(const int& u, const int& v, const int& diff) {
        if (l > v || r < u) return;
        if (u <= l && v >= r) {
            mi += diff;
            lazy += diff;
        } else {
            Down();
            left->Update(u, v, diff);
            right->Update(u, v, diff);
            mi = min(left->mi, right->mi);
        }
    }

    uint32_t Get(const int& u, const int& v) {
        if (l > v || r < u) return 2e9;
        if (u <= l && v >= r)
            return mi;
        else {
            Down();
            return min(left->Get(u, v), right->Get(u, v));
        }
    }
};
SegmentTree* tree;
int n, k;
int a[35001];
int last[35001];
uint32_t ans[35001];
map<int, int> m;
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        last[i] = m[a[i]];
        m[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) ans[i] = 2e9;
    ans[0] = 0;
    tree = new SegmentTree(0, n);
    for (int i = 1; i <= k; i++) {
        tree->Clear(ans);
        for (int j = 1; j <= n; j++) {
            if (last[j]) {
                tree->Update(0, last[j] - 1, j - last[j]);
            }
            ans[j] = tree->Get(0, j - 1);
        }
    }
    cout << ans[n] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}