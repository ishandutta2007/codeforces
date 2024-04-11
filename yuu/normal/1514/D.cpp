#include <bits/stdc++.h>
using namespace std;
int n, q;
int a[300001];
vector<int> pos[300001];
int find_last(int r, int e) {
    if (pos[e][0] > r) return -1;
    if (pos[e].back() <= r) return pos[e].size() - 1;
    return int(upper_bound(pos[e].begin(), pos[e].end(), r) - pos[e].begin()) - 1;
}

int get_count(int l, int r, int e) { return find_last(r, e) - find_last(l - 1, e); }

class SegmentTree {
  public:
    SegmentTree *left, *right;
    int l, r, m;
    int common;
    int count;

    SegmentTree(int l, int r) : l(l), r(r), m((l + r) / 2) {
        if (l == r) {
            common = a[l];
            count = 1;
        } else {
            left = new SegmentTree(l, m);
            right = new SegmentTree(m + 1, r);
            if (left->common == right->common) {
                common = left->common;
                count = left->count + right->count;
            } else {
                int cnt_left = get_count(l, r, left->common);
                int cnt_right = get_count(l, r, right->common);
                if (cnt_left > cnt_right) {
                    common = left->common;
                    count = cnt_left;
                } else {
                    common = right->common;
                    count = cnt_right;
                }
            }
        }
    }

    void GetCommons(int u, int v, set<int>& res) {
        if ((u > r) || (v < l)) return;
        if ((u <= l) && (v >= r)) {
            res.insert(common);
        } else {
            left->GetCommons(u, v, res);
            right->GetCommons(u, v, res);
        }
    }
};
void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    SegmentTree* tree;
    tree = new SegmentTree(1, n);
    set<int> to_check;
    for (int i = 1, l, r; i <= q; i++) {
        cin >> l >> r;
        to_check.clear();
        tree->GetCommons(l, r, to_check);
        int max_cnt = 0;
        for (auto&& x : to_check) max_cnt = max(max_cnt, get_count(l, r, x));
        int remain = r - l + 1 - max_cnt;
        // x -> need (x-1)
        cout << max(1, max_cnt - remain) << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}