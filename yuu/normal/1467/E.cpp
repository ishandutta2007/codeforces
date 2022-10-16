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
int n;
int a[200001];
map<int, vector<int>> group;
vector<int> g[200001];
int f[200001][21];
bool done[200001];
int first[200001];
int last[200001];
int h[200001];
int cnt;
void dfs(int u) {
    done[u] = 1;
    first[u] = ++cnt;
    for (int i = 0; f[f[u][i]][i]; i++) f[u][i + 1] = f[f[u][i]][i];
    for (auto&& v : g[u])
        if (done[v]) {
            swap(v, g[u].back());
            g[u].pop_back();
            break;
        }
    for (auto&& v : g[u]) {
        f[v][0] = u;
        h[v] = h[u] + 1;
        dfs(v);
    }
    last[u] = cnt;
}
int w[200002];
void ban(int u, int v) {
    w[u]++;
    w[v + 1]--;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        group[a[i]].emplace_back(i);
    }
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    h[1] = 1;
    dfs(1);
    for (auto&& [value, pos] : group) {
        if (pos.size() <= 1) continue;
        sort(pos.begin(), pos.end(), [](const int& a, const int& b) { return h[a] > h[b]; });
        int low = n + 1, high = 0;
        for (auto&& x : pos) {
            low = min(low, first[x]);
            high = max(high, first[x]);
        }
        set<pair<int, int>> current;
        for (auto&& x : pos) {
            if ((first[x] > low) || (last[x] < high)) ban(first[x], last[x]);
            else ban(first[x], first[x]);
            while (!current.empty()) {
                if (current.rbegin()->first < first[x]) break;
                auto [p, y] = *current.lower_bound({first[x], x});
                if (p > last[x]) break;
                current.erase({p, y});
                for (int i = __lg(h[y]); i >= 0; i--)
                    if (h[f[y][i]] > h[x]) y = f[y][i];
                ban(1, first[y] - 1);
                ban(last[y] + 1, n);
            }
            current.insert({first[x], x});
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        w[i] += w[i - 1];
        ans += (w[i] == 0);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    if constexpr (MULTI_TEST) cin >> t;
    while (t--) solve();
}