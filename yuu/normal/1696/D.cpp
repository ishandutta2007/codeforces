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

constexpr bool MULTI_TEST = 1;
// #define SKIP_ASSERT
#ifdef SKIP_ASSERT
#define assert(x) (x)
#endif
int n;
int a[250001];
int f[250001];
vector<int> min_q, max_q;
class segment_tree_t {
public:
    segment_tree_t *left, *right;
    int l, r, m;
    int mi;
    segment_tree_t(int l, int r) : l(l), r(r), m((l + r) / 2), mi(1e9) {
        if (l != r) {
            left = new segment_tree_t(l, m);
            right = new segment_tree_t(m + 1, r);
        }
    }

    void update(int u, int val) {
        if (l == r) mi = val;
        else {
            if (m >= u) left->update(u, val);
            else right->update(u, val);
            mi = min(left->mi, right->mi);
        }
    }

    int get(int u, int v) {
        if (l > v || r < u) return 1e9;
        if (u <= l && v >= r) return mi;
        return min(left->get(u, v), right->get(u, v));
    }
};

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    min_q.clear();
    max_q.clear();
    segment_tree_t *min_tree, *max_tree;
    min_tree = new segment_tree_t(1, n);
    max_tree = new segment_tree_t(1, n);
    f[1] = 0;
    min_tree->update(1, f[1]);
    max_tree->update(1, f[1]);
    min_q.emplace_back(1);
    max_q.emplace_back(1);
    for (int i = 2; i <= n; i++) {
        while ((!min_q.empty()) && (a[min_q.back()] > a[i])) {
            min_tree->update(min_q.back(), 1e9);
            min_q.pop_back();
        }
        while ((!max_q.empty()) && (a[max_q.back()] < a[i])) {
            max_tree->update(max_q.back(), 1e9);
            max_q.pop_back();
        }
        int allowed_min = max_q.empty() ? 1 : (max_q.back() + 1);
        int allowed_max = min_q.empty() ? 1 : (min_q.back() + 1);
        f[i] = min(min_tree->get(allowed_min, i - 1), max_tree->get(allowed_max, i - 1)) + 1;
        min_tree->update(i, f[i]);
        max_tree->update(i, f[i]);
        min_q.emplace_back(i);
        max_q.emplace_back(i);
    }
    cout << f[n] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    if constexpr (MULTI_TEST) cin >> t;
    while (t--) solve();
}