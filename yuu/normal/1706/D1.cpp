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
int n, k;
int have[100001];
int current[100001];
void solve() {
    cin >> n >> k;
    for (int i = 0; i <= 100000; i++) have[i] = 0;
    for (int i = 0; i <= 100000; i++) current[i] = 0;
    int low = 1e9, high = 0;
    int mx = 0;
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        mx = max(mx, a);
        have[a] = 1;
        high = max(high, a / k);
        low = min(low, a / k);
    }
    int ans = high - low;  // answer if we have a zero
    // otherwise everything must be at least 1
    int represented = 0;
    int limit_left = 0;
    for (int i = 1; i <= mx; i++)
        if (have[i]) current[i / k]++;
    for (int i = 1; i <= mx; i++) have[i] += have[i - 1];
    for (int limit_right = 1; limit_right <= mx; limit_right++) {
        for (int p = 1; p < k; p++) {
            if (p * limit_right > mx) break;
            // a / p == limit_right
            // p * limit_right <= a < p * (limit_right + 1)
            // previously, all of these would have used a / (p + 1)
            int q = p + 1;
            int low = p * limit_right;
            int high = low + p - 1;
            high = min(high, mx);
            // low / q, high / q
            for (int result_q = low / q; result_q <= high / q; result_q++) {
                int low_q = result_q * q;
                int high_q = low_q + q - 1;
                low_q = max(low_q, low);
                high_q = min(high_q, high);
                current[result_q] -= have[high_q] - have[low_q - 1];
            }
            current[limit_right] += have[high] - have[low - 1];
        }
        if (limit_right >= high) {
            while (!current[limit_left]) limit_left++;
            // cerr << limit_left << ' ' << limit_right << ' ' << high << '\n';
            ans = min(ans, limit_right - limit_left);
        }
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