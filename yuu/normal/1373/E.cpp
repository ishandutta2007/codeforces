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
int ans[151][10];
bool done[1'000'101];
int pre[1'000'101];
int f(int u) {
    if (done[u]) return pre[u];
    done[u] = 1;
    int x = u;
    while (x > 0) {
        pre[u] += x % 10;
        x /= 10;
    }
    return pre[u];
}
void prepare() {
    static bool done = false;
    if (done) return;
    done = true;
    for (int i = 1; i <= 150; i++)
        for (int k = 2; k <= 9; k++) ans[i][k] = -1;
    for (int i = 0; i <= 1'000'000; i++) {
        int sum = 0;
        sum += f(i);
        for (int k = 1; k <= 9; k++) {
            sum += f(i + k);
            if (sum > 150) break;
            if (ans[sum][k] == -1) ans[sum][k] = i;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= 150; i++)
        for (int k = 2; k <= 9; k++)
            if (ans[i][k] == -1) {
                cnt++;
                // cerr << i << ' ' << k << '\n';
            }
    // cerr << cnt << '\n';
}

int n, k;

int64_t last_digit(int n) {
    assert(k == 1);
    int64_t ans = 1e18;
    int64_t ending_9 = 0;
    int64_t ending_pw = 1;
    int64_t ending_sum = 0;
    while (ending_sum < n) {
        if (ending_9 > ans) break;
        for (int digit = 0; digit < 9; digit++) {
            int rem = n - ending_sum - digit - digit - 1;
            if (rem % 2) break;
            if (rem < 0) break;
            rem /= 2;
            int64_t res = rem % 9;
            while (rem >= 9) {
                (res *= 10) += 9;
                rem -= 9;
            }
            (res *= 10) += digit;
            (res *= ending_pw) += ending_9;
            ans = min(ans, res);
        }
        ending_sum += 9;
        (ending_9 *= 10) += 9;
        ending_pw *= 10;
    }
    if (ans == 1e18) ans = -1;
    return ans;
}

void solve() {
    prepare();
    cin >> n >> k;
    if (k >= 2) {
        cout << ans[n][k] << '\n';
        return;
    }
    if (k == 0) {
        if (n % 9) cout << n % 9;
        while (n >= 9) {
            cout << 9;
            n -= 9;
        }
        cout << '\n';
        return;
    }
    // last digit is 9
    cout << last_digit(n) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    if constexpr (MULTI_TEST) cin >> t;
    while (t--) solve();
}