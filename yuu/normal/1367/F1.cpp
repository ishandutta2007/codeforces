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
int a[200001];
int cnt[200002];
int low[200002];
int high[200002];
int last[200002];
int before[200002];
int after[200002];
int prefix[200002];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n + 1; i++) low[i] = n + 1;
    for (int i = 1; i <= n + 1; i++) high[i] = 0;
    vector<int> u;
    for (int i = 1; i <= n; i++) u.emplace_back(a[i]);
    u | UNIQUE;
    for (int i = 1; i <= n; i++) a[i] = lower_bound(u.begin(), u.end(), a[i]) - u.begin() + 1;
    int m = u.size();
    for (int i = 1; i <= n; i++) {
        low[a[i]] = min(low[a[i]], i);
        high[a[i]] = max(high[a[i]], i);
    }
    last[m] = m;
    for (int i = m - 1; i >= 1; i--) {
        if (high[i] < low[i + 1]) last[i] = last[i + 1];
        else last[i] = i;
    }
    for (int i = 1; i <= n + 1; i++) cnt[i] = 0;
    for (int i = 1; i <= n; i++) {
        if (i == low[a[i]]) before[a[i]] = cnt[a[i] - 1];
        cnt[a[i]]++;
    }
    for (int i = 1; i <= n + 1; i++) cnt[i] = 0;
    for (int i = n; i >= 1; i--) {
        if (i == high[a[i]]) after[a[i]] = cnt[a[i] + 1];
        cnt[a[i]]++;
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) prefix[i] = prefix[i - 1] + cnt[i];
    for (int i = 1; i <= m; i++) {
        int j = last[i];
        int keep = 0;
        keep += prefix[j] - prefix[i - 1];
        keep += after[last[i]];
        keep += before[i];
        ans = max(ans, keep);
    }
    ans = n - ans;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    if constexpr (MULTI_TEST) cin >> t;
    while (t--) solve();
}