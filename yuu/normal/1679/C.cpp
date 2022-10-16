#include <bits/stdc++.h>
using namespace std;
class SegmentTree {
public:
    SegmentTree *left, *right;
    int coverage;
    int l, r, m;

    SegmentTree(int l, int r) : l(l), r(r), m((l + r) / 2), coverage(0) {
        if (l == r) return;
        left = new SegmentTree(l, m);
        right = new SegmentTree(m + 1, r);
    }

    void Update(int u, int d) {
        if (l == r) {
            coverage += d;
        } else {
            if (m >= u) left->Update(u, d);
            else right->Update(u, d);
            coverage = left->coverage && right->coverage;
        }
    }

    bool Check(int u, int v) {
        if (l > v || r < u) return true;
        if ((u <= l) && (v >= r)) return coverage;
        return left->Check(u, v) && right->Check(u, v);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    SegmentTree *x_tree, *y_tree;
    x_tree = new SegmentTree(1, n);
    y_tree = new SegmentTree(1, n);
    for (int i = 1, t, x, y, u, v; i <= q; i++) {
        cin >> t >> x >> y;
        if (t == 1) {
            x_tree->Update(x, 1);
            y_tree->Update(y, 1);
        } else if (t == 2) {
            x_tree->Update(x, -1);
            y_tree->Update(y, -1);
        } else {
            cin >> u >> v;
            if (x_tree->Check(x, u) || y_tree->Check(y, v)) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}