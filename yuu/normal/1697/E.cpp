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
int x[101];
int y[101];
int min_dist[101];
int d(int a, int b) { return abs(x[a] - x[b]) + abs(y[a] - y[b]); }
bool done[101];
vector<int> sets;
constexpr int base = 998244353;
int64_t f[101];
bool used[101];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    for (int a = 1; a <= n; a++) {
        min_dist[a] = 1e9;
        for (int b = 1; b <= n; b++) {
            if (b == a) continue;
            min_dist[a] = min(min_dist[a], d(a, b));
        }
    }
    for (int a = 1; a <= n; a++) {
        if (done[a]) continue;
        for (int b = a + 1; b <= n; b++) {
            int dist = d(a, b);
            if (dist != min_dist[a]) continue;
            if (dist != min_dist[b]) continue;
            bool bad = 0;
            for (int i = 1; i <= n; i++) used[i] = 0;
            vector<int> req;
            req.push_back(a);
            req.push_back(b);

            queue<int> q;
            q.push(a);
            q.push(b);
            for (auto&& x : req) used[x] = 1;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int c = 1; c <= n; c++) {
                    if (used[c]) continue;
                    int ndist = d(u, c);
                    if (ndist < dist) {
                        bad = 1;
                        break;
                    }
                    if (ndist == dist) {
                        if (min_dist[c] != dist) {
                            bad = 1;
                            break;
                        }
                        used[c] = 1;
                        q.push(c);
                        req.push_back(c);
                    }
                }
            }

            if (bad) continue;
            for (auto&& x : req) {
                for (auto&& y : req) {
                    if (x == y) continue;
                    if (d(x, y) != dist) {
                        bad = 1;
                        break;
                    }
                }
            }
            if (bad) continue;
            for (auto&& x : req) done[x] = 1;
            sets.push_back(req.size());
            break;
        }
    }
    for (int a = 1; a <= n; a++)
        if (!done[a]) sets.push_back(1);
    f[0] = 1;
    for (auto&& x : sets) {
        if (x > 1) {
            for (int i = n; i >= x; i--) (f[i] = f[i - x] + f[i - 1]) %= base;
            for (int i = x - 1; i > 0; i--) f[i] = f[i - 1];
        } else {
            for (int i = n; i >= 1; i--) f[i] = f[i - 1];
        }
        f[0] = 0;
    }
    int64_t p = 1;
    int64_t ans = 0;
    for (int i = 1; i <= n; i++) {
        (p *= (n - i + 1)) %= base;
        (ans += p * f[i]) %= base;
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