#include <bits/stdc++.h>
using namespace std;
// clang-format off
namespace {  // forbidden c++
// must be an operator that execute from left to right to make sense.
// need concept to use <<, >>, so we use | for now
#define PREFERED_OPERATOR operator|
enum general_operation_t {REVERSE,};
enum comparable_operation_t {SORT,UNIQUE,PREFIX_MIN,PREFIX_MAX,};
enum integer_operation_t {PREFIX_AND,PREFIX_OR,PREFIX_XOR,};
enum number_operation_t {PREFIX_SUM,PREFIX_PROD,};
template <typename container_t> container_t& PREFERED_OPERATOR(container_t& a, const general_operation_t& op) { switch (op) {case REVERSE: reverse(a.begin(), a.end()); break; default: assert(false);}; return a;}
template <typename container_t> container_t& PREFERED_OPERATOR(container_t& a, const comparable_operation_t& op) { switch (op) { case SORT: {sort(a.begin(), a.end()); break;}; case UNIQUE: {sort(a.begin(), a.end()); a.erase(unique(a.begin(), a.end()), a.end()); break;} case PREFIX_MIN: { for (size_t i = 1; i < a.size(); i++) a[i] = min(a[i], a[i - 1]); break;} case PREFIX_MAX: { for (size_t i = 1; i < a.size(); i++) a[i] = max(a[i], a[i - 1]); break;} default: assert(false);} return a;}
template <typename container_t> container_t& PREFERED_OPERATOR(container_t& a, const number_operation_t& op) { switch (op) { case PREFIX_SUM: { for (size_t i = 1; i < a.size(); i++) a[i] += a[i - 1]; break; } case PREFIX_PROD: { for (size_t i = 1; i < a.size(); i++) a[i] *= a[i - 1]; break; } default: assert(false);} return a;}
template <typename container_t> container_t& PREFERED_OPERATOR(container_t& a, const integer_operation_t& op) { switch (op) { case PREFIX_AND: { for (size_t i = 1; i < a.size(); i++) a[i] &= a[i - 1]; break; } case PREFIX_OR: { for (size_t i = 1; i < a.size(); i++) a[i] |= a[i - 1]; break; } case PREFIX_XOR: { for (size_t i = 1; i < a.size(); i++) a[i] ^= a[i - 1]; break; } default: break;} return a;}
}  // namespace
// clang-format on
int n;
string s, t;
vector<int> pos[256];
vector<pair<int, int>> req;

int ft[200001];
void update(int u) {
    for (; u > 0; u -= (u & -u)) ft[u]++;
}
int get(int u) {
    int res = 0;
    for (; u <= n; u += (u & -u)) res += ft[u];
    return res;
}
void solve() {
    cin >> n >> s;
    (t = s) | REVERSE;
    for (int i = 0; i < n; i++) pos[t[i]].push_back(i);
    req.clear();
    for (int i = n - 1; i >= 0; i--) {
        req.emplace_back(i, pos[s[i]].back());
        pos[s[i]].pop_back();
    }
    req | SORT;
    for (int i = 1; i <= n; i++) ft[i] = 0;
    int64_t ans = 0;
    for (auto&& [x, y] : req) {
        y++;
        ans += get(y);
        update(y);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}