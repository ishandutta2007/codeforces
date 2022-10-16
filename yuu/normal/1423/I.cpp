#include <bits/stdc++.h>
using namespace std;
int k, n;
int flow[(1 << 16) + 1];
int fhigh[(1 << 16) + 1];
int low[1 << 16];
int high[1 << 16];
int full;
class segment_tree_t {
public:
    int l, r, m;
    int value;
    segment_tree_t *left, *right;
    segment_tree_t(int l, int r, int *f) : l(l), r(r), m((l + r) / 2) {
        if (l == r) {
            value = f[l];
            left = right = nullptr;
        } else {
            left = new segment_tree_t(l, m, f);
            right = new segment_tree_t(m + 1, r, f);
            value = left->value | right->value;
        }
    }
    int get(int u, int v) {
        if (l > v || r < u) return 0;
        if (u <= l && v >= r) return value;
        return left->get(u, v) | right->get(u, v);
    }
};
segment_tree_t *tree_low, *tree_high;
class pair_range_t {
public:
    int lx, ly;
    int hx, hy;

    pair_range_t(int lx, int ly, int hx, int hy) : lx(lx), ly(ly), hx(hx), hy(hy) {}
    
    bool test(int v) {
        // check if a&b == b for lx <= a <= ly and hx <= b <= hy
        // all the 1 is correct
        // only need to test the 0
        int can_be_one = tree_low->get(lx, ly) & tree_high->get(hx, hy);
        return can_be_one == v;
    }
};
void force_one_low(int l, int r) {
    flow[l]++;
    flow[r + 1]--;
}
void force_one_high(int l, int r) {
    fhigh[l]++;
    fhigh[r + 1]--;
}
class range_t {
public:
    int64_t l, r;
    int v;
    vector<pair_range_t> x;
    void input() { cin >> l >> r >> v; }
    void make_range(int64_t a, int64_t b) { x.emplace_back(a & full, b & full, a >> k, b >> k); }
    void deconstruct() {
        make_range(l, min(r, l + ((1 << k) - (l & (full)) - 1)));
        l += (1 << k) - (l & full);
        if (l > r) return;
        make_range(max(l, r - (r & full)), r);
        r -= (r & full) + 1;
        if (l > r) return;
        make_range(l, r);
    }
    void force_one_bit(int bit) {
        if ((v >> bit) & 1) {
            for (auto p : x) {
                force_one_low(p.lx, p.ly);
                force_one_high(p.hx, p.hy);
            }
        }
    }
    bool test() {
        for (auto p : x)
            if (!p.test(v)) return 0;
        return 1;
    }
} q[200001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> k >> n;
    full = 1 << k;
    full--;
    for (int i = 1; i <= n; i++) q[i].input();
    for (int i = 1; i <= n; i++) q[i].deconstruct();
    for (int bit = 0; bit < 16; bit++) {
        for (int i = 0; i <= full; i++) flow[i] = 0;
        for (int i = 0; i <= full; i++) fhigh[i] = 0;
        for (int i = 1; i <= n; i++) q[i].force_one_bit(bit);
        for (int i = 0; i <= full; i++) {
            if (i) flow[i] += flow[i - 1];
            if (flow[i]) low[i] ^= 1 << bit;
        }
        for (int i = 0; i <= full; i++) {
            if (i) fhigh[i] += fhigh[i - 1];
            if (fhigh[i]) high[i] ^= 1 << bit;
        }
    }
    tree_low = new segment_tree_t(0, full, low);
    tree_high = new segment_tree_t(0, full, high);
    for (int i = 1; i <= n; i++)
        if (!q[i].test()) {
            cout << "impossible\n";
            return 0;
        }
    cout << "possible\n";
    for (int i = 0; i <= full; i++) cout << low[i] << '\n';
    for (int i = 0; i <= full; i++) cout << high[i] << '\n';
}