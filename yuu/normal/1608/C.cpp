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

class player_t {
public:
    int a, b, id;
} p[100001];

int done[100001];
vector<int> g[100001];
int cnt;
int low[100001];
int num[100001];
stack<int> s;
int cc[100001];
void dfs(int u) {
    done[u] = 1;
    low[u] = num[u] = ++cnt;
    s.push(u);
    for (auto&& v : g[u]) {
        if (!done[v]) dfs(v);
        if (done[v] == 1) low[u] = min(low[u], low[v]);
    }
    if (low[u] == num[u]) {
        while (true) {
            int x = s.top();
            s.pop();
            done[x] = 2;
            cc[x] = u;
            if (x == u) break;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i].a;
    for (int i = 1; i <= n; i++) cin >> p[i].b;
    for (int i = 1; i <= n; i++) p[i].id = i;
    for (int i = 1; i <= n; i++) g[i].clear();
    sort(p + 1, p + n + 1, [](const auto& a, const auto& b) { return a.a < b.a; });
    for (int i = 1; i < n; i++) g[p[i + 1].id].emplace_back(p[i].id);
    sort(p + 1, p + n + 1, [](const auto& a, const auto& b) { return a.b < b.b; });
    for (int i = 1; i < n; i++) g[p[i + 1].id].emplace_back(p[i].id);
    for (int i = 1; i <= n; i++) done[i] = 0;
    cnt = 0;
    for (int i = 1; i <= n; i++)
        if (!done[i]) dfs(i);
    for (int u = 1; u <= n; u++)
        for (auto&& v : g[u]) {
            if (cc[u] == cc[v]) continue;
            done[cc[v]] = 0;
        }
    for (int i = 1; i <= n; i++) cout << bool(done[cc[i]]);
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    if constexpr (MULTI_TEST) cin >> t;
    while (t--) solve();
}