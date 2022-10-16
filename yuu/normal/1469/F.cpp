#include <bits/stdc++.h>
using namespace std;
int n, k;
int l[200001];
class SegmentTree {
public:
    SegmentTree *left, *right;
    int l, m, r;
    int64_t sum;
    int64_t lazy;

    SegmentTree(int l, int r) : l(l), r(r), m((l + r) / 2), sum(0), lazy(0) {
        if (l == r) {
            if (l == 0) sum = 1;
        } else {
            left = new SegmentTree(l, m);
            right = new SegmentTree(m + 1, r);
            sum = left->sum + right->sum;
        }
    }

    void Down() {
        if (lazy == 0) return;
        left->lazy += lazy;
        right->lazy += lazy;
        left->sum += lazy * (m - l + 1);
        right->sum += lazy * (r - m);
        lazy = 0;
    }

    void Up() { sum = left->sum + right->sum; }

    void Update(int u, int v, int diff) {
        if ((l > v) || (r < u)) return;
        if ((u <= l) && (v >= r)) {
            lazy += diff;
            sum += diff * (r - l + 1);
        } else {
            Down();
            left->Update(u, v, diff);
            right->Update(u, v, diff);
            Up();
        }
    }

    int Get(int64_t k) {
        if (sum < k) return 1e9;
        if (l == r) {
            return l;
        } else {
            Down();
            if (left->sum >= k) return left->Get(k);
            else return right->Get(k - left->sum);
        }
    }
};
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> l[i];
    sort(l + 1, l + n + 1);
    auto tree = new SegmentTree(0, 400000);  // should be enough
    int ans = 1e9;
    for (int i = n; i >= 1; i--) {
        int attach_to = tree->Get(1);
        tree->Update(attach_to, attach_to, -1);
        int length = (l[i] - 1) / 2;
        tree->Update(attach_to + 2, attach_to + 2 + length - 1, 2);
        if (l[i] % 2 == 0) tree->Update(attach_to + 2 + length, attach_to + 2 + length, 1);
        ans = min(ans, tree->Get(k));
    }
    if (ans == 1e9) ans = -1;
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}