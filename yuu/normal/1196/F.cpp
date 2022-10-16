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
int n, m, k;
map<int, int> min_dist[200001];
vector<pair<int, int>> g[200001];
class path_t {
public:
    int s, t;
    int64_t w;
    path_t(int s, int t, int64_t w) : s(s), t(t), w(w) {}
    bool operator<(const path_t& other) const {
        if (w != other.w) return w < other.w;
        if (s != other.s) return s < other.s;
        return t < other.t;
    }
};
set<path_t> best;
set<path_t> chosen;
map<pair<int, int>, int64_t> inside;

bool insert_path(const path_t& path) {
    auto&& [s, t, w] = path;
    auto it = inside.find({s, t});
    if (it != inside.end()) {
        if (it->second <= w) return false;
        best.erase({s, t, it->second});
        best.emplace(s, t, w);
        it->second = w;
        return true;
    } else {
        if (best.size() == k * 2) {
            if (best.rbegin()->w <= w) return false;
            inside.erase({best.rbegin()->s, best.rbegin()->t});
            best.erase(*best.rbegin());
        }
        best.emplace(s, t, w);
        inside[{s, t}] = w;
        return true;
    }
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 1, x, y, w; i <= m; i++) {
        cin >> x >> y >> w;
        g[x].emplace_back(w, y);
        g[y].emplace_back(w, x);
    }
    for (int i = 1; i <= n; i++) g[i] | SORT;
    for (int u = 1; u <= n; u++) {
        for (auto&& [w, v] : g[u]) {
            if (v > u) {
                insert_path({u, v, w});
            }
        }
    }
    while (chosen.size() < k) {
        auto path_it = best.begin();
        if (!chosen.empty()) path_it = best.upper_bound(*chosen.rbegin());
        assert(path_it != best.end());
        auto path = *path_it;
        auto&& [s, t, w] = path;
        chosen.insert(path);
        for (auto&& [e, v] : g[t]) {
            if (v == s) continue;
            insert_path({min(v, s), max(v, s), e + w});
        }
        for (auto&& [e, v] : g[s]) {
            if (v == t) continue;
            insert_path({min(v, t), max(v, t), e + w});
        }
        assert(best.size() == inside.size());
    }
    cout << chosen.rbegin()->w << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    if constexpr (MULTI_TEST) cin >> t;
    while (t--) solve();
}