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
int n, m;
char c[1000000];
char s[1000000];
bool done[1000000];
int nx[1000000];
int from[1000000];
int dist[1000000];
int entry[1000000];
bool has_0[1000000];
vector<vector<int>> cycles;
void prepare_cycle(int id) {
    auto&& c = cycles[id];
    for (auto&& u : c) from[u] = id;
    for (int i = 0; i < c.size(); i++) entry[c[i]] = i;
    for (auto&& u : c) dist[u] = 0;
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> c[i * m + j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> s[i * m + j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int ii = i;
            int jj = j;
            if (s[i * m + j] == 'U') ii--;
            else if (s[i * m + j] == 'R') jj++;
            else if (s[i * m + j] == 'D') ii++;
            else jj--;
            nx[i * m + j] = ii * m + jj;
        }
    }
    // every vertex ended up in a cycle
    // cannot place more than the size of the cycle because eventually there will be a hit
    // can place the size of the cycle by just choose the cycle at the start
    // to maximize number of black, we will want to let them join the cycle at a different time
    static vector<int> stk;
    stk.clear();
    for (int i = 0; i < n * m; i++) done[i] = 0;
    cycles.clear();
    for (int i = 0; i < n * m; i++) {
        if (done[i]) continue;
        stk.emplace_back(i);
        while (!done[stk.back()]) {
            done[stk.back()] = 1;
            stk.emplace_back(nx[stk.back()]);
        }
        int start = stk.back();
        stk.pop_back();
        for (auto&& x : stk) {
            if (x == start) {  // newly discovered cycle
                cycles.emplace_back();
                auto&& current = cycles.back();
                while (stk.back() != start) {
                    current.emplace_back(stk.back());
                    stk.pop_back();
                }
                current.emplace_back(stk.back());
                stk.pop_back();
                prepare_cycle(cycles.size() - 1);
                break;
            }
        }
        // stk is a chain that lead to a cycle
        while (!stk.empty()) {
            auto&& u = stk.back();
            dist[u] = dist[nx[u]] + 1;
            entry[u] = entry[nx[u]];
            from[u] = from[nx[u]];
            stk.pop_back();
        }
    }
    for (int i = 0; i < n * m; i++) has_0[i] = 0;
    for (int i = 0; i < n * m; i++) {
        if (c[i] == '1') continue;
        auto&& cyc = cycles[from[i]];
        int group = (entry[i] + dist[i]) % cyc.size();
        has_0[cyc[group]] = 1;
    }
    int ans_s = 0, ans_b = 0;
    for (auto&& c : cycles) ans_s += c.size();
    for (int i = 0; i < n * m; i++) ans_b += has_0[i];
    cout << ans_s << ' ' << ans_b << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    if constexpr (MULTI_TEST) cin >> t;
    while (t--) solve();
}