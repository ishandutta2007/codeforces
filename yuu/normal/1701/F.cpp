#include <bits/stdc++.h>
using namespace std;
class matrix_t {
public:
    int64_t f[3][3];

    int64_t* operator[](const int& idx) { return f[idx]; }
    const int64_t* operator[](const int& idx) const { return f[idx]; }

    matrix_t operator*(const matrix_t& other) const {
        matrix_t res;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                res[i][j] = 0;
                for (int k = 0; k < 3; k++) res[i][j] += f[i][k] * other[k][j];
            }
        }
        return res;
    }

    matrix_t operator+(const matrix_t& other) const {
        matrix_t res;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) res[i][j] = f[i][j] + other[i][j];
        return res;
    }

    static const matrix_t& zero() {
        static matrix_t res;
        static bool init = 0;
        if (!init) {
            init = 1;
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++) res[i][j] = 0;
        }
        return res;
    }
    static const matrix_t& id() {
        static matrix_t res;
        static bool init = 0;
        if (!init) {
            init = 1;
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++) res[i][j] = (i == j);
        }
        return res;
    }

    static matrix_t from_vector(const vector<vector<int>>& val) {
        matrix_t res;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) res[i][j] = val[i][j];
        return res;
    }
};

matrix_t op_insert = matrix_t::from_vector({{1, 0, 0}, {2, 1, 0}, {0, 1, 1}});
matrix_t op_erase = matrix_t::from_vector({{1, 0, 0}, {-2, 1, 0}, {2, -1, 1}});

class segment_tree_t {
public:
    segment_tree_t *left, *right;
    int l, r, m;

    matrix_t value;
    matrix_t lazy;
    bool empty;

    segment_tree_t(int l, int r) : l(l), r(r), m((l + r) / 2) {
        value = matrix_t::zero();
        lazy = matrix_t::id();
        value[0][2] = r - l + 1;
        empty = 1;
        if (l != r) {
            left = new segment_tree_t(l, m);
            right = new segment_tree_t(m + 1, r);
        } else {
        }
    }

    void down() {
        left->value = left->value * lazy;
        right->value = right->value * lazy;
        left->lazy = left->lazy * lazy;
        right->lazy = right->lazy * lazy;
        lazy = matrix_t::id();
    }

    void up() {
        empty = left->empty && right->empty;
        value = matrix_t::zero();
        if (empty) return;

        if (!left->empty) value = value + left->value;
        if (!right->empty) value = value + right->value;
    }

    bool insert_or_erase(int u) {
        if (l == r) {
            empty = !empty;
            return empty;
        } else {
            down();
            int res;
            if (m >= u) res = left->insert_or_erase(u);
            else res = right->insert_or_erase(u);
            up();
            return res;
        }
    }

    void update(int u, int v, const matrix_t& trans) {
        if (l > v || r < u) return;
        if (u <= l && v >= r) {
            value = value * trans;
            lazy = lazy * trans;
        } else {
            down();
            left->update(u, v, trans);
            right->update(u, v, trans);
            up();
        }
    }
};
int q, d;
void solve() {
    cin >> q >> d;
    auto tree = new segment_tree_t(1, 200000);
    for (int i = 1, a; i <= q; i++) {
        cin >> a;
        bool is_erase = tree->insert_or_erase(a);
        if (is_erase) tree->update(a + 1, a + d, op_erase);
        else tree->update(a + 1, a + d, op_insert);
        // cerr << i << ' ' << is_erase << ' ' << tree->empty << '\n';
        cout << tree->value[0][0] / 2 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}