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
int x[1001], y[1001];
vector<pair<int, int>> g[1001];
map<int, vector<pair<int, int>>> with_x;
map<int, vector<pair<int, int>>> with_y;
int r[1001];
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
vector<int> rep;
set<int> testing;
class unique_counting_t {
public:
    int cnt[1001];
    int total;

    void reset(const vector<int>& target) {
        for (auto&& x : target) cnt[x] = 0;
        total = 0;
    }

    void add(int x) {
        cnt[x]++;
        if (cnt[x] == 1) total++;
    }

    void remove(int x) {
        cnt[x]--;
        if (cnt[x] == 0) total--;
    }
} uc;
bool check(int limit) {
    for (int i = 1; i <= n; i++) r[i] = -1;
    for (int i = 1; i <= n; i++) {
        for (auto&& [w, j] : g[i]) {
            if (w > limit) break;
            unite(i, j);
        }
    }
    if (-r[root(1)] == n) return true;  // no need for extra vertex
    // require an extra vertex
    rep.clear();
    for (int i = 1; i <= n; i++)
        if (root(i) == i) rep.emplace_back(i);
    assert(rep.size() > 1);
    for (int i = 1; i < rep.size(); i++)
        if (r[rep[i]] < r[rep[0]]) swap(rep[i], rep[0]);
    // The extra vertex need to share x or y coordinate

    // x cord only
    testing.clear();
    for (int i = 1; i <= n; i++)
        if (root(i) == rep[0]) testing.insert(x[i]);
    for (auto&& x_cord : testing) {
        uc.reset(rep);
        auto&& y_cords = with_x[x_cord];
        int last = 0;
        for (auto&& [y, id] : y_cords) {  // this is last
            while ((last < y_cords.size()) && (y_cords[last].first - y <= static_cast<int64_t>(limit) * 2)) {
                uc.add(root(y_cords[last].second));
                last++;
            }
            if (uc.total == rep.size()) return true;
            uc.remove(root(id));
        }
    }

    // y cord only
    testing.clear();
    for (int i = 1; i <= n; i++)
        if (root(i) == rep[0]) testing.insert(y[i]);

    for (auto&& y_cord : testing) {
        uc.reset(rep);
        auto&& x_cords = with_y[y_cord];
        int last = 0;
        for (auto&& [x, id] : x_cords) {  // this is last
            while ((last < x_cords.size()) && (x_cords[last].first - x <= static_cast<int64_t>(limit) * 2)) {
                uc.add(root(x_cords[last].second));
                last++;
            }
            if (uc.total == rep.size()) return true;
            uc.remove(root(id));
        }
    }

    // some intersection
    vector<int> last_index;
    last_index.resize(with_x.size(), 0);
    for (auto&& [y_cord, x_cords] : with_y) {
        uc.reset(rep);

        int first = 0, last = 0;
        int x_id = 0;
        for (auto&& [x_cord, y_cords] : with_x) {
            while ((last < x_cords.size()) && (x_cords[last].first - x_cord <= limit)) {
                uc.add(root(x_cords[last].second));
                last++;
            }
            while ((first < x_cords.size()) && (x_cord - x_cords[first].first > limit)) {
                uc.remove(root(x_cords[first].second));
                first++;
            }

            // only need to add the one directly up and down with this x_cord
            while ((last_index[x_id] + 1 < y_cords.size()) && (y_cords[last_index[x_id] + 1].first <= y_cord))
                last_index[x_id]++;

            if (last_index[x_id] < y_cords.size())
                if (abs(y_cord - y_cords[last_index[x_id]].first) <= limit) uc.add(root(y_cords[last_index[x_id]].second));

            if (last_index[x_id] + 1 < y_cords.size())
                if (abs(y_cords[last_index[x_id] + 1].first - y_cord) <= limit)
                    uc.add(root(y_cords[last_index[x_id] + 1].second));

            if (uc.total == rep.size()) return true;
            if (last_index[x_id] < y_cords.size())
                if (abs(y_cord - y_cords[last_index[x_id]].first) <= limit) uc.remove(root(y_cords[last_index[x_id]].second));

            if (last_index[x_id] + 1 < y_cords.size())
                if (abs(y_cords[last_index[x_id] + 1].first - y_cord) <= limit)
                    uc.remove(root(y_cords[last_index[x_id] + 1].second));

            x_id++;
        }
    }
    return false;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    for (int i = 1; i <= n; i++) with_x[x[i]].emplace_back(y[i], i);
    for (auto&& [key, value] : with_x) value | SORT;
    for (int i = 1; i <= n; i++) with_y[y[i]].emplace_back(x[i], i);
    for (auto&& [key, value] : with_y) value | SORT;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if ((x[i] == x[j]) || (y[i] == y[j])) {
                g[i].emplace_back(abs(x[i] - x[j]) + abs(y[i] - y[j]), j);
            }
        }
        g[i] | SORT;
    }
    int64_t low = 1, high = 2e9, mid, res = -1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (check(mid)) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    if constexpr (MULTI_TEST) cin >> t;
    while (t--) solve();
}