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
struct {
    int l, r;
} merc[300002];
int done[300002];
struct {
    int a, b;
} hate_pair[20];
int avail[300002];
int weight[300002][41];

constexpr int base = 998244353;
int64_t fact[300002];
int64_t inv[300002];
int64_t C(int n, int k) {
    if (n < k) return 0;
    return ((fact[n] * inv[k]) % base * inv[n - k]) % base;
}

int64_t power(int64_t x, int64_t a) {
    int64_t res = 1;
    while (a) {
        if (a % 2) (res *= x) %= base;
        (x *= x) %= base;
        a /= 2;
    }
    return res;
}

void solve() {
    cin >> n >> m;
    fact[0] = 1;
    for (int i = 1; i <= n; i++) (fact[i] = fact[i - 1] * i) %= base;
    inv[n] = power(fact[n], base - 2);
    for (int i = n; i >= 1; i--) (inv[i - 1] = inv[i] * i) %= base;

    for (int i = 1; i <= n; i++) cin >> merc[i].l >> merc[i].r;
    for (int i = 0; i < m; i++) cin >> hate_pair[i].a >> hate_pair[i].b;
    for (int i = 0; i < (1 << m); i++) {
        int l = 1, r = n, cnt = 0;
        for (int j = 0; j < m; j++)
            if ((i >> j) & 1) {
                auto&& [a, b] = hate_pair[j];
                if (done[a] != i + 1) {
                    cnt++;
                    done[a] = i + 1;
                    l = max(l, merc[a].l);
                    r = min(r, merc[a].r);
                }
                if (done[b] != i + 1) {
                    cnt++;
                    done[b] = i + 1;
                    l = max(l, merc[b].l);
                    r = min(r, merc[b].r);
                }
            }
        if (l > r) continue;
        if (__builtin_popcount(i) % 2 == 0) {
            weight[l][cnt]++;
            weight[r + 1][cnt]--;
        } else {
            weight[l][cnt]--;
            weight[r + 1][cnt]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        auto&& [l, r] = merc[i];
        avail[l]++;
        avail[r + 1]--;
    }
    int64_t ans = 0;
    for (int i = 1; i <= n; i++) {
        avail[i] += avail[i - 1];
        for (int j = 0; j <= m * 2; j++) {
            weight[i][j] += weight[i - 1][j];
            if (j > i) continue;
            (ans += C(avail[i] - j, i - j) * weight[i][j]) %= base;
        }
    }
    (ans += base) %= base;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    if constexpr (MULTI_TEST) cin >> t;
    while (t--) solve();
}