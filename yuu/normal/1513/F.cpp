#include <bits/stdc++.h>
using namespace std;
class Pair {
  public:
    int a, b, j;
    bool operator<(const Pair& other) const { return a < other.a; }
} p[200001];
int64_t get_cost(int i, int j) { return abs(p[i].a - p[j].b); }
class SegmentTree {
  public:
    SegmentTree *left, *right;
    int l, r, m;
    int const_reduction;
    bool has_variable_reduction;

    SegmentTree(int l, int r) : l(l), r(r), m((l + r) / 2), const_reduction(0), has_variable_reduction(0) {
        if (l != r) {
            left = new SegmentTree(l, m);
            right = new SegmentTree(m + 1, r);
        }
    }

    void UpdateConst(int u, int value) {
        if (l == r) {
            has_variable_reduction = false;
            const_reduction = value;
        } else {
            if (m >= u)
                left->UpdateConst(u, value);
            else
                right->UpdateConst(u, value);
            has_variable_reduction = left->has_variable_reduction || right->has_variable_reduction;
            const_reduction = max(left->const_reduction, right->const_reduction);
        }
    }

    void UpdateVariable(int u) {
        if (l == r) {
            has_variable_reduction = true;
        } else {
            if (m >= u)
                left->UpdateVariable(u);
            else
                right->UpdateVariable(u);
            has_variable_reduction = left->has_variable_reduction || right->has_variable_reduction;
            const_reduction = max(left->const_reduction, right->const_reduction);
        }
    }

    int GetConst(int u, int v) {
        if ((l > v) || (r < u)) return 0;
        if ((u <= l) && (v >= r)) return const_reduction;
        return max(left->GetConst(u, v), right->GetConst(u, v));
    }

    int GetLastVariable(int u, int v) {
        if ((r < u) || (l > v)) return 0;
        if (!has_variable_reduction) return 0;
        if (l == r) return l;
        int res = right->GetLastVariable(u, v);
        if (res) return res;
        return left->GetLastVariable(u, v);
    }
};

SegmentTree* tree;
priority_queue<pair<int, int>> q;
int n;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i].a;
    for (int i = 1; i <= n; i++) cin >> p[i].b;
    sort(p + 1, p + n + 1);
    int64_t base_ans = 0;
    for (int i = 1; i <= n; i++) base_ans += abs(p[i].a - p[i].b);
    int64_t ans = 0;

    p[n].j = n;
    for (int i = n - 1; i >= 1; i--) {
        if (p[i].b < p[p[i + 1].j].b) {
            p[i].j = i;
        } else {
            p[i].j = p[i + 1].j;
        }
    }

    tree = new SegmentTree(1, n);
    auto find_last = [](const int lim) {
        int low = 1, high = n, res = 0, mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (p[mid].a <= lim) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    };
    for (int i = n; i >= 1; i--) {
        while ((!q.empty()) && (q.top().first >= p[i].a)) {
            auto [b, j] = q.top();
            q.pop();
            tree->UpdateConst(j, (p[j].a - p[j].b) * 2);
        }

        if (p[i].a <= p[i].b) {
            int max_j = find_last(p[i].b);
            if (max_j > i) {
                ans = max(ans, static_cast<int64_t>(tree->GetConst(i + 1, max_j)));
                int j = tree->GetLastVariable(i + 1, max_j);
                if (j) ans = max(ans, static_cast<int64_t>(p[j].a - p[i].a) * 2);
            }
            if (max_j < n) {
                int j = p[max_j + 1].j;
                ans = max(ans, get_cost(i, i) + get_cost(j, j) - get_cost(i, j) - get_cost(j, i));
            }
        }
        if (p[i].a >= p[i].b) {
            tree->UpdateVariable(i);
            q.emplace(p[i].b, i);
        }
    }

    cout << base_ans - ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}