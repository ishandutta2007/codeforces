#include <bits/stdc++.h>
using namespace std;
int n;
int a[200001];
int64_t f[200001];
class SegmentTree {
  public:
    SegmentTree *left, *right;
    int l, r, m;
    int64_t lazy;
    int64_t min_val;

    SegmentTree(int l, int r) : l(l), r(r), m((l + r) / 2) {
        lazy = 0;
        if (l == r) {
            min_val = f[l];
        } else {
            left = new SegmentTree(l, m);
            right = new SegmentTree(m + 1, r);
            min_val = min(left->min_val, right->min_val);
        }
    }

    void Down() {
        if (!lazy) return;
        left->lazy += lazy;
        right->lazy += lazy;
        left->min_val += lazy;
        right->min_val += lazy;
        lazy = 0;
    }

    void Update(int u, int v, int diff) {
        if (l > v || r < u) return;
        if (u <= l && v >= r) {
            lazy += diff;
            min_val += diff;
        } else {
            Down();
            left->Update(u, v, diff);
            right->Update(u, v, diff);
            min_val = min(left->min_val, right->min_val);
        }
    }

    int64_t GetMin(int u, int v) {
        if (l > v || r < u) return 1e18;
        if (u <= l && v >= r)
            return min_val;
        else {
            Down();
            return min(left->GetMin(u, v), right->GetMin(u, v));
        }
    }
};
set<pair<int, int>> s;
void solve() {
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = f[i - 1];
        if (a[i] < 0) {
            s.insert({-a[i], i});
        } else {
            f[i] += a[i];
            ans++;
        }
    }
    SegmentTree* tree;
    tree = new SegmentTree(1, n);
    for (auto&& [weight, i] : s) {
        if (tree->GetMin(i, n) >= weight) {
            ans++;
            tree->Update(i, n, -weight);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}