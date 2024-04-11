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
template <typename T> T& operator|(T& var, const single_input_operation_t& op) {cin >> var; return var;}
template <typename container_t> container_t& PREFERED_OPERATOR(container_t& a, const array_input_operation_t& op) { switch (op) { case ARRAY_INPUT: { for (auto&& x : a) x | NEXT_INPUT; break; } case INDEX_1: { a | REVERSE; a.emplace_back(); a | REVERSE; break; } default: assert(0); } return a; }
template <typename container_t> container_t& PREFERED_OPERATOR(container_t& a, const array_output_operation_t& op) {switch (op) { case INDEX_0: { a | REVERSE; a.pop_back(); a | REVERSE; break; } case OUTPUT_1LINE: { for (auto&& x : a) cout << x << ' '; cout << '\n'; break; } case OUTPUT_1PER_LINE: { for (auto&& x : a) cout << x << '\n'; cout << '\n'; break; } default: assert(0); } return a; }
}  // namespace
// clang-format on
constexpr bool MULTI_TEST = 0;
 
// DiD yOu KnOw ThAt f = e - v + 2
 
// TODO(template)
template <bool GET_DOWN>
class fenwick_t {
public:
    inline static constexpr int64_t MAX_INDEX = 1e6 + 1;
    int64_t ft[MAX_INDEX + 1];
 
    inline static void TRANSFORM_GET(int64_t& u) {
        if constexpr (GET_DOWN) u -= (u & -u);
        else u += (u & -u);
    }
    inline static void TRANSFORM_UPDATE(int64_t& u) {
        if constexpr (GET_DOWN) u += (u & -u);
        else u -= (u & -u);
    }
 
    void update(int64_t u, int64_t d) {
        for (u++; (u > 0) && (u <= MAX_INDEX); TRANSFORM_UPDATE(u)) ft[u] += d;
    }
 
    int64_t get(int64_t u) {
        int64_t res = 0;
        for (u++; (u > 0) && (u <= MAX_INDEX); TRANSFORM_GET(u)) res += ft[u];
        return res;
    }
};
int64_t n, m;
fenwick_t<true> tree;
vector<pair<int64_t, int64_t>> h_left, h_right;
vector<tuple<int64_t, int64_t, int64_t>> v;
set<pair<int64_t, int64_t>> vertices;
 
void solve() {
    cin >> n >> m;
    int64_t ans = 1;  // e - v + 1
    vertices.emplace(0, 0);
    vertices.emplace(0, 1e6);
    vertices.emplace(1e6, 0);
    vertices.emplace(1e6, 1e6);
    for (int64_t i = 1, y, l, r; i <= n; i++) {
        cin >> y >> l >> r;
        assert((l == 0) || (r == 1e6));
        if (l == 0) {
            h_left.emplace_back(r, y);
        } else {
            h_right.emplace_back(l, y);
        }
        assert(vertices.count({l, y}) == 0);
        vertices.emplace(l, y);
        assert(vertices.count({r, y}) == 0);
        vertices.emplace(r, y);
        ans--;              // 1 new edge and 2 new vertex
        ans += (l == 0);    // new edge
        ans += (r == 1e6);  // new edge
    }
    h_left | SORT | REVERSE;
    h_right | SORT | REVERSE;
    v.resize(m);
    for (auto&& [x, l, h] : v) {
        cin >> x >> l >> h;
        assert((l == 0) || (h == 1e6));
 
        // ans -= (1 - vertices.count({x, l})) * 2;  // possible new vertex
        if (vertices.count({x, l})) {
            // using an existing vertex, this will lead to double counting later
            ans--;
        } else {
            ans--;  // new edge
        }
        vertices.emplace(x, l);
        if (vertices.count({x, h})) {
            ans--;
        } else {
            ans--;  // new edge
        }
        vertices.emplace(x, h);
        ans++;              // new edge
        ans += (l == 0);    // new edge
        ans += (h == 1e6);  // new edge
    }
    v | SORT;
    for (auto&& [r, y] : h_left) tree.update(y, 1);
    for (auto&& [x, l, h] : v) {
        while (!h_left.empty()) {
            auto&& [r, y] = h_left.back();
            if (r < x) {
                tree.update(y, -1);
                h_left.pop_back();
            } else {
                break;
            }
        }
        while (!h_right.empty()) {
            auto&& [l, y] = h_right.back();
            if (l <= x) {
                tree.update(y, 1);
                h_right.pop_back();
            } else {
                break;
            }
        }
        ans += tree.get(h) - tree.get(l - 1);
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int64_t t = 1;
    if constexpr (MULTI_TEST) cin >> t;
    while (t--) solve();
}