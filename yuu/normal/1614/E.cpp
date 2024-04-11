#include <bits/stdc++.h>
using namespace std;

class Seg {  // Seggggggggs
  public:
    Seg *left, *right;
    const int l, r, m;
    int offset, high;

    Seg(const int &l, const int &r) : left(nullptr), right(nullptr), l(l), m((l + r) / 2), r(r), offset(0), high(r) {}

    void Update(const int &u, const int &v, const int &diff) {
        if (l > v || r < u) return;
        if (u <= l && v >= r) {
            offset += diff;
            high += diff;
        } else {
            if (left == nullptr) {
                left = new Seg(l, m);
                right = new Seg(m + 1, r);
            }
            if (offset) {
                left->offset += offset;
                left->high += offset;
                right->offset += offset;
                right->high += offset;
                offset = 0;
            }
            left->Update(u, v, diff);
            right->Update(u, v, diff);
            high = right->high;
        }
    }

    int Get(const int &u) {
        if (l == r) {
            return high;
        } else {
            if (left == nullptr) {
                return u + offset;
            } else {
                if (offset) {
                    left->offset += offset;
                    left->high += offset;
                    right->offset += offset;
                    right->high += offset;
                    offset = 0;
                }
                if (m >= u)
                    return left->Get(u);
                else
                    return right->Get(u);
            }
        }
    }

    int FindLast(const int &val) {  // find the last position that is leq val
        if (high <= val) return r;
        if (l == r) {
            return -1;
        } else {
            if (left == nullptr) {
                // pos + offset = val
                return val - offset;
            } else {
                if (offset) {
                    left->offset += offset;
                    left->high += offset;
                    right->offset += offset;
                    right->high += offset;
                    offset = 0;
                }
                if (left->high > val)
                    return left->FindLast(val);
                else
                    return max(m, right->FindLast(val));
            }
        }
    }
};

void solve() {
    Seg *tree;
    tree = new Seg(0, 1'000'000'000);
    int n;
    cin >> n;
    int t, k, x;
    int last_ans = 0;
    while (n--) {
        cin >> t;
        int last_less = tree->FindLast(t - 1);
        int last_eq = tree->FindLast(t);
        if (0 <= last_less) tree->Update(0, last_less, 1);
        if (last_eq < 1e9) tree->Update(last_eq + 1, 1'000'000'000, -1);
        cin >> k;
        while (k--) {
            cin >> x;
            x = (x + last_ans) % (1'000'000'001);
            last_ans = tree->Get(x);
            cout << last_ans << '\n';
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