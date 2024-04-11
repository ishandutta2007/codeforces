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
constexpr bool MULTI_TEST = 1;
int n;
vector<pair<int, int>> p;
vector<vector<int>> ans;
vector<int> output;
set<int> divisors;
void generate(int u, int v, int d) {
    if (u == p.size()) {
        if (d > 1) divisors.insert(d);
    } else {
        generate(u + 1, 0, d);
        if (v < p[u].second) generate(u, v + 1, d * p[u].first);
    }
}
void solve() {
    cin >> n;
    int on = n;
    p.clear();
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            p.emplace_back(i, 0);
            while (n % i == 0) {
                n /= i;
                p.back().second++;
            }
        }
    }
    if (n > 1) p.emplace_back(n, 1);
    n = on;
    if (p.size() == 2) {
        if (p[0].first * p[1].first == n) {
            cout << p[0].first << ' ' << p[1].first << ' ' << n << '\n';
            cout << "1\n";
            return;
        }
    }
    ans.clear();
    divisors.clear();
    generate(0, 0, 1);
    for (int i = 0; i < p.size(); i++) {
        ans.emplace_back();
        if (i + 1 < p.size()) {
            ans[i].emplace_back(p[i].first * p[i + 1].first);
            divisors.erase(p[i].first * p[i + 1].first);
        } else {
            ans[i].emplace_back(n);
            divisors.erase(n);
        }
        ans[i].emplace_back(p[i].first);
        divisors.erase(p[i].first);
    }
    for (auto&& d : divisors) {
        for (int i = 0; i < p.size(); i++) {
            if (d % p[i].first == 0) {
                ans[i].emplace_back(d);
                break;
            }
        }
    }
    output.clear();
    for (auto&& x : ans) {
        x | REVERSE;
        for (auto&& y : x) output.emplace_back(y);
    }
    for (auto&& x : output) cout << x << ' ';
    cout << "\n0\n";
    cout.flush();
    // for (int i = 0; i < output.size(); i++) assert(gcd(output[i], output[i + 1 % output.size()]) > 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    if constexpr (MULTI_TEST) cin >> t;
    while (t--) solve();
}