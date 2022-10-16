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
}  // namespace
// clang-format on

constexpr bool MULTI_TEST = 1;
// #define SKIP_ASSERT
#ifdef SKIP_ASSERT
#define assert(x) (x)
#endif
int n, a, b;
int ans[100001];
bool done[100001];
void check() {
    for (int i = 1; i <= n; i++) done[i] = 0;
    for (int i = 1; i <= n; i++) done[ans[i]] = 1;
    for (int i = 1; i <= n; i++) assert(done[i]);
    for (int i = 2; i < n; i++) {
        if ((ans[i] > ans[i - 1]) && (ans[i] > ans[i + 1])) a--;
        if ((ans[i] < ans[i - 1]) && (ans[i] < ans[i + 1])) b--;
    }
    assert(a == 0);
    assert(b == 0);
}
void solve() {
    // static int in = 1, ia = 0, ib = 0;
    // n = in;
    // a = ia;
    // b = ib;
    // cerr << n << ' ' << a << ' ' << b << '\n';
    // ib++;
    // if (ib == 10) {
    //     ib = 0;
    //     ia++;
    //     if (ia == 10) {
    //         ia = 0;
    //         in++;
    //     }
    // }
    cin >> n >> a >> b;

    if (max(a, b) > (n - 1) / 2) {
        cout << "-1\n";
        return;
    }
    if (abs(a - b) > 1) {
        cout << "-1\n";
        return;
    }
    if ((a + b) > n - 2) {
        cout << "-1\n";
        return;
    }

    // ababababababa
    if (a >= b) {
        ans[1] = 1;
        int high = n;
        int low = 2;
        int i = 2;
        int k = a;
        while ((i < n) && (k > 0)) {
            ans[i] = high--;
            ans[i + 1] = low++;
            k--;
            i += 2;
        }
        assert(k == 0);
        if (a > b) {
            i--;
            while (i <= n) ans[i++] = high--;
        } else {
            while (i <= n) ans[i++] = low++;
        }
    } else {
        ans[1] = n;
        int low = 1, high = n - 1;
        int i = 2;
        int k = b;
        while ((i < n) && (k > 0)) {
            ans[i] = low++;
            ans[i + 1] = high--;
            k--;
            i += 2;
        }
        assert(k == 0);
        i--;
        while (i <= n) ans[i++] = low++;
    }
    check();
    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    if constexpr (MULTI_TEST) cin >> t;
    while (t--) solve();
}