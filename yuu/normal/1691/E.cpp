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
struct {
    int c, l, r;
} s[100001];
vector<int> x;
int find_pos(int a) { return lower_bound(x.begin(), x.end(), a) - x.begin(); }
vector<pair<int, int>> updates;
vector<int> special;
int find_first_special(int a) {
    if (special.empty() || (special.back() < a)) return special.size();
    return lower_bound(special.begin(), special.end(), a) - special.begin();
}
int find_last_special(int a) {
    if (special.empty() || (special[0] > a)) return -1;
    if (special.back() <= a) return special.size() - 1;
    return upper_bound(special.begin(), special.end(), a) - special.begin() - 1;
}
int cnt[2];
int r[300001];
int f[200000];
int root(int u) {
    if (r[u] < 0) return u;
    return r[u] = root(r[u]);
}

void unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return;
    if (r[u] > r[v]) swap(u, v);
    r[u] += r[v];
    r[v] = u;
}

void solve() {
    x.clear();
    updates.clear();
    special.clear();
    cnt[0] = cnt[1] = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i].c >> s[i].l >> s[i].r;
        x.emplace_back(s[i].l);
        x.emplace_back(s[i].r);
    }
    x | UNIQUE;
    for (int i = 1; i <= n; i++) {
        s[i].l = find_pos(s[i].l);
        s[i].r = find_pos(s[i].r);
        updates.emplace_back(s[i].l, s[i].c);
        updates.emplace_back(s[i].r + 1, s[i].c + 2);
    }
    updates | SORT;
    int old_pos = 0;
    for (auto&& [pos, update] : updates) {
        if (pos > old_pos) {
            if (cnt[0] && cnt[1]) special.emplace_back(old_pos);
        }
        if (update < 2) cnt[update]++;
        else cnt[update - 2]--;
        old_pos = pos;
    }
    if (cnt[0] && cnt[1]) special.emplace_back(old_pos);
    for (int i = 1; i <= n + special.size(); i++) r[i] = -1;
    for (int i = 0; i < special.size(); i++) f[i] = 0;
    for (int i = 1; i <= n; i++) {
        int fi = find_first_special(s[i].l);
        int la = find_last_special(s[i].r);
        if (fi > la) continue;
        unite(i, n + 1 + fi);
        f[fi]++;
        f[la]--;
    }
    int sum = 0;
    for (int i = 0; i < special.size(); i++) {
        sum += f[i];
        if (sum) unite(i + n + 1, i + n + 2);
    }
    set<int> all;
    for (int i = 1; i <= n; i++) all.insert(root(i));
    cout << all.size() << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    if constexpr (MULTI_TEST) cin >> t;
    while (t--) solve();
}