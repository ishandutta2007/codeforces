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
int n, m;
vector<int> discs[200001];
int t[200001];
int r[200001];

int f[200001];
int find_tower(int i) {
    if (f[i] < 0) return i;
    return f[i] = find_tower(f[i]);
}

int root(int u) {
    if (r[u] < 0) return u;
    return r[u] = root(r[u]);
}

bool unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return 0;
    if (r[u] > r[v]) swap(u, v);
    r[u] += r[v];
    r[v] = u;
    return 1;
}

int ans;

void solve() {
    cin >> n >> m;
    ans = n - 1;
    for (int i = 1; i <= n; i++) f[i] = -1;
    for (int i = 1; i <= n; i++) r[i] = -1;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        if (!discs[t[i]].empty()) {
            if (discs[t[i]].back() == i - 1) ans -= unite(i - 1, i);
        }
        discs[t[i]].emplace_back(i);
    }
    cout << ans << '\n';
    for (int i = 1, a, b; i < m; i++) {
        cin >> a >> b;
        a = find_tower(a);
        b = find_tower(b);
        if (discs[a].size() > discs[b].size()) swap(a, b);
        for (auto&& x : discs[a]) {
            if ((x > 1) && (t[x - 1] == b)) ans -= unite(x - 1, x);
            if ((x < n) && (t[x + 1] == b)) ans -= unite(x + 1, x);
            t[x] = b;
            discs[b].emplace_back(x);
        }
        discs[a].clear();
        f[a] = b;
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    if constexpr (MULTI_TEST) cin >> t;
    while (t--) solve();
}