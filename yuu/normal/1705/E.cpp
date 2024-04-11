#include <bits/stdc++.h>
using namespace std;
class segment_tree_t {
public:
    segment_tree_t *left, *right;
    int l, r, m;
    int count_1;
    int lazy;

    segment_tree_t(int l, int r) : l(l), r(r), m((l + r) / 2), count_1(0), lazy(-1) {
        if (l != r) {
            left = new segment_tree_t(l, m);
            right = new segment_tree_t(m + 1, r);
        }
    }

    void down() {
        if (lazy == -1) return;
        left->lazy = lazy;
        left->count_1 = lazy * (m - l + 1);
        right->lazy = lazy;
        right->count_1 = lazy * (r - m);
        lazy = -1;
    }

    int count(int val) {
        if (val == 1) return count_1;
        else return r - l + 1 - count_1;
    }

    void update(int u, int v, int val) {
        if (l > v || r < u) return;
        if (u <= l && v >= r) {
            lazy = val;
            count_1 = val * (r - l + 1);
        } else {
            down();
            left->update(u, v, val);
            right->update(u, v, val);
            count_1 = left->count_1 + right->count_1;
        }
    }

    // find the first 1 at >= u
    int find_first(int u, int val) {
        if (count(val) == 0) return 0;
        if (r < u) return 0;
        if (l == r) return r;
        down();
        if (u > m) {
            return right->find_first(u, val);
        } else {
            int res = left->find_first(u, val);
            if (res) return res;
            else return right->find_first(u, val);
        }
    }

    int find_last(int val) {
        if (count(val) == 0) return 0;
        if (l == r) return r;
        down();
        if (right->count(val)) return right->find_last(val);
        else return left->find_last(val);
    }
};
segment_tree_t* tree;

void add(int u) {
    int next_zero = tree->find_first(u, 0);
    tree->update(next_zero, next_zero, 1);
    if (u < next_zero) tree->update(u, next_zero - 1, 0);
}

void substract(int u) {
    int next_one = tree->find_first(u, 1);
    tree->update(next_one, next_one, 0);
    if (u < next_one) tree->update(u, next_one - 1, 1);
}
int n, q;
int a[200001];
void solve() {
    cin >> n >> q;
    tree = new segment_tree_t(1, 2e5 + 100);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        add(a[i]);
    }
    for (int i = 1, k, l; i <= q; i++) {
        cin >> k >> l;
        add(l);
        substract(a[k]);
        a[k] = l;
        cout << tree->find_last(1) << '\n';
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}