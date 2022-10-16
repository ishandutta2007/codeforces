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
int n, m;
int s_x, s_y, f_x, f_y;
vector<int> x, y;
vector<int> id_x, id_y;
vector<pair<int, int>> g[200002];

int find_pos(vector<int>& pos, int item) { return lower_bound(pos.begin(), pos.end(), item) - pos.begin(); }

void add_edge(int u, int v, int w) {
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
}
int64_t f[200002];
priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> q;

void solve() {
    cin >> n >> m;
    cin >> s_x >> s_y >> f_x >> f_y;
    x.resize(m);
    y.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
    }
    id_x = x;
    id_x.push_back(s_x);
    id_x | UNIQUE;
    id_y = y;
    id_y.push_back(s_y);
    id_y | UNIQUE;
    for (int i = 0; i + 1 < id_x.size(); i++) add_edge(i, i + 1, id_x[i + 1] - id_x[i]);
    for (int i = 0; i + 1 < id_y.size(); i++) add_edge(id_x.size() + i, id_x.size() + i + 1, id_y[i + 1] - id_y[i]);
    for (int i = 0; i < m; i++) add_edge(find_pos(id_x, x[i]), id_x.size() + find_pos(id_y, y[i]), 0);
    for (int i = 0; i < id_x.size() + id_y.size(); i++) f[i] = 1e18;
    f[find_pos(id_x, s_x)] = 0;
    f[id_x.size() + find_pos(id_y, s_y)] = 0;
    q.push({0, find_pos(id_x, s_x)});
    q.push({0, id_x.size() + find_pos(id_y, s_y)});
    while (!q.empty()) {
        auto [weight, u] = q.top();
        q.pop();
        if (f[u] != weight) continue;
        for (auto&& [v, w] : g[u]) {
            if (f[v] > weight + w) {
                f[v] = weight + w;
                q.push({f[v], v});
            }
        }
    }
    int64_t ans = abs(s_x - f_x) + abs(s_y - f_y);
    for (int i = 0; i < m; i++) ans = min(ans, f[find_pos(id_x, x[i])] + abs(f_x - x[i]) + abs(f_y - y[i]));
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    if constexpr (MULTI_TEST) cin >> t;
    while (t--) solve();
}