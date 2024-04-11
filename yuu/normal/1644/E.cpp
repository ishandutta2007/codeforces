#include <bits/stdc++.h>
using namespace std;
int64_t n;
string s;
vector<tuple<int, int, int, int>> rects;
vector<int> px;
vector<int> py;

class SegmentTree {
  public:
    SegmentTree *left, *right;
    int l, r;

    int covered;
    int count;
    int size;

    SegmentTree(int l, int r) : l(l), r(r), covered(0), count(0) {
        if (l < r) {
            left = new SegmentTree(l, (l + r) / 2);
            right = new SegmentTree((l + r) / 2 + 1, r);
            size = left->size + right->size;
        } else {
            if (l + 1 < px.size())
                size = px[l + 1] - px[l];
            else
                size = 0;
        }
    }

    void Mark(int u, int v, int x) {
        if (l > v || r < u) return;
        if (u <= l && v >= r) {
            covered += x;
        } else {
            left->Mark(u, v, x);
            right->Mark(u, v, x);
        }
        if (covered)
            count = size;
        else if (l == r)
            count = 0;
        else
            count = left->count + right->count;
    }
};

SegmentTree* root;
vector<tuple<int, int, int, int>> mark;
int64_t area_of_union() {
    px.clear();
    for (auto&& [lx, hx, ly, hy] : rects) {
        hx++;
        px.push_back(lx);
        px.push_back(hx);
        hy++;
    }
    sort(px.begin(), px.end());
    px.erase(unique(px.begin(), px.end()), px.end());
    mark.clear();
    auto get_index = [&px](int x) { return lower_bound(px.begin(), px.end(), x) - px.begin(); };
    for (auto&& [lx, hx, ly, hy] : rects) {
        mark.emplace_back(ly, get_index(lx), get_index(hx) - 1, 1);
        mark.emplace_back(hy, get_index(lx), get_index(hx) - 1, -1);
    }
    root = new SegmentTree(0, px.size() - 1);
    sort(mark.begin(), mark.end());
    int64_t ans = 0;
    int last_y = 0;
    for (auto&& [y, lx, hx, d] : mark) {
        if (y != last_y) {
            ans += (int64_t(y - last_y)) * root->count;
            last_y = y;
        }
        root->Mark(lx, hx, d);
    }
    return ans;
}

void solve() {
    cin >> n >> s;
    int dx = 0, dy = 0;
    for (auto&& c : s)
        if (c == 'D')
            dx++;
        else
            dy++;
    rects.clear();
    bool can_move_x = 0, can_move_y = 0;
    int cx = 1, cy = 1;
    for (auto&& c : s) {
        if (c == 'D') {
            can_move_x = 1;
            dx--;
            cx++;
        } else {
            can_move_y = 1;
            dy--;
            cy++;
        }
        int high_x = can_move_x ? (n - dx) : cx;
        int high_y = can_move_y ? (n - dy) : cy;
        rects.emplace_back(cx, high_x, cy, high_y);
    }
    rects.emplace_back(1, 1, 1, 1);
    cout << area_of_union() << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}