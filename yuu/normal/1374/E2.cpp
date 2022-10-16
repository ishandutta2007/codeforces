#include <bits/stdc++.h>
using namespace std;
// clang-format off
namespace {  // forbidden c++
// must be an operator that execute from left to right to make sense.
// need concept to use <<, >>, so we use | for now
#define PREFERED_OPERATOR operator|
enum general_operation_t {REVERSE, };
enum comparable_operation_t {SORT, UNIQUE, PREFIX_MIN, PREFIX_MAX, };
enum integer_operation_t {PREFIX_AND, PREFIX_OR, PREFIX_XOR, };
enum number_operation_t {PREFIX_SUM, PREFIX_PROD, };
enum single_input_operation_t {NEXT_INPUT, };
enum array_input_operation_t {ARRAY_INPUT, INDEX_1, };
// enum single_output_operation_t {OUTPUT, OUTPUT_SP, OUTPUT_LN, };
enum array_output_operation_t {OUTPUT_1LINE, OUTPUT_1PER_LINE, INDEX_0, };
template <typename container_t> container_t& PREFERED_OPERATOR(container_t& a, const general_operation_t& op) { switch (op) {case REVERSE: reverse(a.begin(), a.end()); break; default: assert(false);}; return a;}
template <typename container_t> container_t& PREFERED_OPERATOR(container_t& a, const comparable_operation_t& op) { switch (op) { case SORT: {sort(a.begin(), a.end()); break;}; case UNIQUE: {sort(a.begin(), a.end()); a.erase(unique(a.begin(), a.end()), a.end()); break;} case PREFIX_MIN: { for (size_t i = 1; i < a.size(); i++) a[i] = min(a[i], a[i - 1]); break;} case PREFIX_MAX: { for (size_t i = 1; i < a.size(); i++) a[i] = max(a[i], a[i - 1]); break;} default: assert(false);} return a;}
template <typename container_t> container_t& PREFERED_OPERATOR(container_t& a, const number_operation_t& op) { switch (op) { case PREFIX_SUM: { for (size_t i = 1; i < a.size(); i++) a[i] += a[i - 1]; break; } case PREFIX_PROD: { for (size_t i = 1; i < a.size(); i++) a[i] *= a[i - 1]; break; } default: assert(false);} return a;}
template <typename container_t> container_t& PREFERED_OPERATOR(container_t& a, const integer_operation_t& op) { switch (op) { case PREFIX_AND: { for (size_t i = 1; i < a.size(); i++) a[i] &= a[i - 1]; break; } case PREFIX_OR: { for (size_t i = 1; i < a.size(); i++) a[i] |= a[i - 1]; break; } case PREFIX_XOR: { for (size_t i = 1; i < a.size(); i++) a[i] ^= a[i - 1]; break; } default: break;} return a;}
template <typename inputable_t> inputable_t& PREFERED_OPERATOR(inputable_t& var, const single_input_operation_t& op) {cin >> var; return var;}
template <typename container_t> container_t& PREFERED_OPERATOR(container_t& a, const array_input_operation_t& op) { switch (op) { case ARRAY_INPUT: { for (auto&& x : a) x | NEXT_INPUT; break; } case INDEX_1: { a | REVERSE; a.emplace_back(); a | REVERSE; break; } default: assert(0); } return a; }
template <typename container_t> container_t& PREFERED_OPERATOR(container_t& a, const array_output_operation_t& op) {switch (op) { case INDEX_0: { a | REVERSE; a.pop_back(); a | REVERSE; break; } case OUTPUT_1LINE: { for (auto&& x : a) cout << x << ' '; cout << '\n'; break; } case OUTPUT_1PER_LINE: { for (auto&& x : a) cout << x << '\n'; cout << '\n'; break; } default: assert(0); } return a; }
}  // namespace
// clang-format on

constexpr bool MULTI_TEST = 0;
// #define SKIP_ASSERT
#ifdef SKIP_ASSERT
#define assert(x) (x)
#endif

class segment_tree_t {
public:
    segment_tree_t *left, *right;
    set<int> ids;
    int l, r, m;
    unsigned sum;
    int count;

    segment_tree_t(int l, int r) : l(l), r(r), m((l + r) / 2), sum(0), count(0) {
        if (l == r) return;
        left = new segment_tree_t(l, m);
        right = new segment_tree_t(m + 1, r);
    }

    void insert(int u, int id) {
        count++;
        sum += u;
        if (l != r) {
            if (m >= u) left->insert(u, id);
            else right->insert(u, id);
        } else {
            ids.insert(id);
        }
    }

    void erase(int u, int id) {
        count--;
        sum -= u;
        if (l != r) {
            if (m >= u) left->erase(u, id);
            else right->erase(u, id);
        } else {
            ids.erase(id);
        }
    }

    unsigned min_sum(int k) {
        if ((k < 0) || (k > count)) return 2e9;
        if (k == 0) return 0;
        if (l == r) {
            return l * k;
        } else {
            if (left->count >= k) return left->min_sum(k);
            else return left->sum + right->min_sum(k - left->count);
        }
    }

    void get_min_sum_index(int k, vector<int>& res) {
        if ((k < 0) || (k > count)) return;
        if (k == 0) return;
        if (l == r) {
            for (auto&& x : ids) {
                res.emplace_back(x);
                k--;
                if (k == 0) break;
            }
        } else {
            left->get_min_sum_index(min(k, left->count), res);
            if (left->count < k) right->get_min_sum_index(k - left->count, res);
        }
    }
};
int n, m, k;
vector<pair<int, int>> val[2][2];
set<int> current_inside;
unsigned ans = 2e9 + 7;
void calculate(bool get_answer) {
    auto tree = new segment_tree_t(1, 10000);
    current_inside.clear();
    if (val[1][1].size() + min(val[1][0].size(), val[0][1].size()) < k) {
        cout << "-1\n";
        exit(0);
    }
    for (int a = 0; a <= 1; a++)
        for (int b = 0; b <= 1; b++) val[a][b] | SORT;
    unsigned cost = 0;
    for (auto&& [x, y] : val[0][0]) tree->insert(x, y);
    for (auto&& [x, y] : val[1][1]) tree->insert(x, y);
    auto&& a = val[0][1];
    auto&& b = val[1][0];
    auto&& f = val[1][1];
    int x = 0;
    while (x < a.size()) {
        cost += a[x].first;
        current_inside.insert(a[x].second);
        x++;
    }
    int y = 0;
    while (y < b.size()) {
        cost += b[y].first;
        current_inside.insert(b[y].second);
        y++;
    }
    for (int i = 0; i <= f.size(); i++) {
        while ((x > 0) && (x + i > k)) {
            x--;
            current_inside.erase(a[x].second);
            cost -= a[x].first;
            tree->insert(a[x].first, a[x].second);
        }
        while ((y > 0) && (y + i > k)) {
            y--;
            current_inside.erase(b[y].second);
            cost -= b[y].first;
            tree->insert(b[y].first, b[y].second);
        }
        if (i + min(x, y) >= k) {
            if (m >= x + y + i) {
                ans = min(ans, cost + tree->min_sum(m - x - y - i));
                if (get_answer && (ans == cost + tree->min_sum(m - x - y - i))) {
                    cout << ans << '\n';
                    for (auto&& x : current_inside) cout << x << ' ';
                    vector<int> res;
                    tree->get_min_sum_index(m - x - y - i, res);
                    for (auto&& x : res) cout << x << ' ';
                    cout << '\n';
                    return;
                }
            }
        }
        if (i == f.size()) break;
        tree->erase(f[i].first, f[i].second);
        cost += f[i].first;
        current_inside.insert(f[i].second);
    }
    if (ans > 2e9) {
        cout << -1 << '\n';
        exit(0);
    }
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 1, t, a, b; i <= n; i++) {
        cin >> t >> a >> b;
        val[a][b].emplace_back(t, i);
    }
    for (int i = 0; i <= 1; i++) calculate(i);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    if constexpr (MULTI_TEST) cin >> t;
    while (t--) solve();
}