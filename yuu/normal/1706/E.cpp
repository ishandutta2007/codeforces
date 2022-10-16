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

class dsu_t {
public:
    int r[100001];
    vector<tuple<int, int, int>> edge_used;
    void reset(int n) {
        edge_used.clear();
        for (int i = 1; i <= n; i++) r[i] = -1;
    }

    int root(int u) {
        if (r[u] < 0) return u;
        return u = root(r[u]);
    }

    pair<int, int> unite(int u, int v, int id = 0) {
        // cerr << u << ' ' << v << ' ' << id << '\n';
        u = root(u);
        v = root(v);
        if (u == v) return {0, 0};
        if (id) edge_used.emplace_back(u, v, id);
        if (r[u] > r[v]) swap(u, v);
        r[u] += r[v];
        r[v] = u;
        return {u, v};
    }
} dsu, array_dsu;
vector<int> vertices[200001];
int n, m, q;
vector<int> todo[200001];
class binary_search_t {
public:
    int l, r, id;
    int low, high, mid, ans;

    void init() {
        if (l == r) {
            ans = 0;
            low = 1;
            high = 0;
            return;
        }

        low = 1;
        high = m;
        ans = m + 1;
    }

    bool register_mid() {
        if (low > high) return false;
        mid = (low + high) / 2;
        todo[mid].emplace_back(id);
        return true;
    }

    void update() {
        if (dsu.root(l) == dsu.root(r)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
} query[200001];
void solve() {
    cin >> n >> m >> q;
    dsu.reset(n);
    array_dsu.reset(n);
    for (int i = 1; i <= n; i++) {
        vertices[i].clear();
        vertices[i].emplace_back(i);
    }
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        auto&& [a, b] = dsu.unite(u, v);
        if (a == 0) continue;
        assert(vertices[a].size() >= vertices[b].size());
        for (auto&& x : vertices[b]) {
            if ((x > 1) && (dsu.root(x - 1) == dsu.root(x))) array_dsu.unite(x - 1, x, i);
            if ((x < n) && (dsu.root(x + 1) == dsu.root(x))) array_dsu.unite(x, x + 1, i);
            vertices[a].emplace_back(x);
        }
    }
    assert(array_dsu.edge_used.size() == n - 1);
    for (int i = 1; i <= q; i++) {
        cin >> query[i].l >> query[i].r;
        query[i].id = i;
        query[i].init();
    }

    while (true) {
        for (int i = 1; i <= m; i++) todo[i].clear();
        bool good = false;
        for (int i = 1; i <= q; i++) {
            if (!good) good = query[i].register_mid();
            else query[i].register_mid();
        }
        if (!good) break;
        dsu.reset(n);
        auto&& edges = array_dsu.edge_used;
        int x = 0;
        for (int i = 1; i <= m; i++) {
            while (x < edges.size()) {
                auto&& [a, b, id] = edges[x];
                if (id > i) break;
                dsu.unite(a, b);
                x++;
            }
            for (auto&& id : todo[i]) query[id].update();
        }
    }
    for (int i = 1; i <= q; i++) cout << query[i].ans << " \n"[i == q];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    if constexpr (MULTI_TEST) cin >> t;
    while (t--) solve();
}