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
class set_with_sum {
public:
    set<pair<int, int>> s;
    int64_t sum_a;
    int sum_b;

    set_with_sum() : sum_a(0), sum_b(0), s() {}

    size_t size() { return s.size(); }

    void emplace(int a, int b) {
        if (s.count({a, b})) return;
        sum_a += a;
        sum_b += b;
        s.emplace(a, b);
    }

    void erase(int a, int b) {
        if (!s.count({a, b})) return;
        sum_a -= a;
        sum_b -= b;
        s.erase({a, b});
    }
} s, highest;

int64_t balance() {
    int target_size = s.sum_b;
    assert(abs(target_size - int(highest.size())) <= 1);
    if (highest.size()) {
        highest.erase(highest.s.begin()->first, highest.s.begin()->second);
    }
    while (highest.size() > target_size) highest.erase(highest.s.begin()->first, highest.s.begin()->second);
    while (highest.size() < target_size) {
        if (highest.size() == 0) {
            highest.emplace(s.s.rbegin()->first, s.s.rbegin()->second);
            continue;
        }
        auto it = s.s.find(*highest.s.begin());
        assert(it != s.s.end());
        assert(it != s.s.begin());
        it = prev(it);
        highest.emplace(it->first, it->second);
    }
    if (highest.size() == 0) return s.sum_a;
    if (highest.sum_b == s.sum_b) {
        assert(s.sum_b == highest.size());
        auto it = s.s.find(*highest.s.begin());
        assert(it != s.s.end());
        if (it == s.s.begin()) {
            assert(highest.size() == s.size());
            return highest.sum_a + s.sum_a - it->first;
        } else {
            assert(highest.size() < s.size());
            return highest.sum_a + s.sum_a - it->first + prev(it)->first;
        }
    } else {
        assert(highest.size() > highest.sum_b);
        return highest.sum_a + s.sum_a;
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1, type, d; i <= n; i++) {
        cin >> type >> d;
        if (d > 0) {
            s.emplace(d, type);
            highest.emplace(d, type);
        } else {
            s.erase(-d, type);
            highest.erase(-d, type);
        }
        cout << balance() << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    if constexpr (MULTI_TEST) cin >> t;
    while (t--) solve();
}