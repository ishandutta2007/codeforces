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
int n;
vector<int> shield;
int f[81][81][81 * 80 / 2 + 1];
int ans[81 * 80 / 2 + 1];

class convex_hull_trick_t {
public:
    class line_t {
    public:
        int a, b;  // y = ab + x
        int operator()(const int& x) const { return a * x + b; }
    };

    deque<line_t> lines;
    void add(int a, int b) {
        line_t l{a, b};
        if (!lines.empty()) assert(a > lines.back().a);
        while ((!lines.empty()) && (lines.back()(a) <= l(a))) lines.pop_back();
        lines.push_back(l);
    }

    int get(int x) {
        if (lines.empty()) return -1e6;
        while ((lines.size() > 1) && (lines[1](x) >= lines[0](x))) lines.pop_front();
        return lines.front()(x);
    }
} cht[81][80 * 81 / 2 + 1];

int get_const(int j, int s, int weight) {
    weight += -j * j - j + s * j + s;
    return weight;
}

void solve() {
    cin >> n;
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        if (a) shield.emplace_back(i);
    }
    int max_cost = n * (n - 1) / 2;
    for (int i = 0; i <= n; i++)
        for (int s = 0; s <= shield.size(); s++)
            for (int cost = 0; cost <= max_cost; cost++) f[i][s][cost] = -1e6;
    f[0][0][0] = 0;
    for (int s = 0; s <= shield.size(); s++)
        for (int cost = 0; cost <= max_cost; cost++) {
            if (f[0][s][cost] >= 0) cht[s][cost].add(0, get_const(0, s, f[0][s][cost]));
        }
    for (int i = 1; i <= n; i++) {
        for (int s = int(shield.size()) - 1; s >= 0; s--) {
            for (int cost = 0; cost <= max_cost; cost++) {
                int prev_cost = cost - abs(shield[s] - i);
                if (prev_cost < 0) continue;
                f[i][s + 1][cost] = cht[s][prev_cost].get(i) - i * s;
                if (f[i][s + 1][cost] >= 0) cht[s + 1][cost].add(i, get_const(i, s + 1, f[i][s + 1][cost]));
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int cost = 0; cost <= max_cost; cost++) {
            ans[cost] = max(ans[cost], f[i][shield.size()][cost] + (i - int(shield.size())) * (n - i));
        }
    }
    for (int i = 0; i < max_cost; i++) ans[i + 1] = max(ans[i + 1], ans[i]);
    for (int i = 0; i <= max_cost; i++) cout << ans[i] << " \n"[i == max_cost];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    if constexpr (MULTI_TEST) cin >> t;
    while (t--) solve();
}