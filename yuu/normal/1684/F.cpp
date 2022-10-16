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
int reach[200001];
map<int, vector<int>> pos;
vector<pair<int, int>> temp;
vector<pair<int, int>> required;
vector<pair<int, int>> allow;
void solve() {
    cin >> n >> m;
    pos.clear();
    required.clear();
    allow.clear();
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        pos[a].emplace_back(i);
    }
    allow.resize(m);
    for (auto&& [x, y] : allow) cin >> x >> y;
    for (int i = 1; i <= n; i++) reach[i] = 0;
    for (auto&& [l, r] : allow) reach[l] = max(reach[l], r);
    for (int i = 1; i <= n; i++) reach[i] = max(reach[i], reach[i - 1]);
    for (auto&& [x, v] : pos) {
        if (v.size() == 1) continue;
        int j = -1;
        for (auto&& l : v) {
            while ((j + 1 < v.size()) && (v[j + 1] <= reach[l])) j++;
            if ((j >= 0) && (v[j] > l)) required.emplace_back(l, v[j]);
        }
        for (int i = 1; i < v.size(); i++)
            if (reach[v[i - 1]] >= v[i]) required.emplace_back(v[i - 1], v[i]);
    }
    if (required.empty()) {
        cout << "0\n";
        return;
    }
    // the usable segment must contain at least one end point of every required segment
    // which means no segment outside of it, and no segment that fully contain it
    for (int i = 1; i <= n; i++) reach[i] = 0;
    for (auto&& [l, r] : required) reach[l] = max(reach[l], r);
    for (int i = 1; i <= n; i++) reach[i] = max(reach[i], reach[i - 1]);
    int min_left = n, max_right = 0;
    for (auto&& [l, r] : required) {
        min_left = min(min_left, r);
        max_right = max(max_right, l);
    }
    auto check = [&max_right, &min_left](int l, int r) -> bool {
        if (r < max_right) return false;
        if (l > min_left) return false;
        if (reach[l - 1] > r) return false;
        return true;
    };
    int ans = n + 1;
    for (int l = 1; l <= n; l++) {
        int low = l, high = n, r;
        while (low <= high) {
            r = (low + high) / 2;
            if (check(l, r)) {
                ans = min(ans, r - l + 1);
                high = r - 1;
            } else {
                low = r + 1;
            }
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