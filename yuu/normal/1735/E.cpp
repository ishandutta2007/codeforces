#include <bits/stdc++.h>
using namespace std;
// clang-format off
namespace { enum operand_type_enum : uint32_t { RAW = 0, COMPOSED = 1 << 1, REQUIRE_PARAM = 1 << 2, }; template <class T> concept has_operand_type = requires() { { T::operand_type } -> convertible_to<uint32_t>; }; template <class T> class operand_type { public: inline static constexpr uint32_t value() { if constexpr (has_operand_type<T>) return T::operand_type; else return operand_type_enum::RAW; } }; template <class T> constexpr uint32_t operand_type_v = operand_type<decay_t<T>>::value();
template <class T> concept is_raw = ((operand_type_v<T> & RAW) == RAW); template <class T> concept is_composed = ((operand_type_v<T> & COMPOSED) == COMPOSED); template <class T> concept require_param = ((operand_type_v<T> & REQUIRE_PARAM) == REQUIRE_PARAM); template <class T> concept require_no_param = !require_param<T>; template <class left_t, class right_t> class composed_operation_t { public: inline static constexpr uint32_t operand_type = COMPOSED | operand_type_v<right_t> | operand_type_v<left_t>;
left_t left; right_t right; }; template <class left_t, class right_t> requires(is_composed<left_t> && (!is_composed<right_t>)) auto operator|(left_t&& left, right_t&& right) { return left.left | (left.right | right); } template <class left_t, class right_t> requires(is_raw<left_t>&& require_param<right_t>) auto operator|(left_t&& left, right_t&& right) { return composed_operation_t<left_t, right_t>(left, right); } namespace array_binding_details { template <typename T> class array_binding_t_full { public:
inline static constexpr uint32_t operand_type = RAW; T* array; int l, r; T* begin() { return array + l; } T* end() { return array + r + 1; } void resize(const size_t sz) { r = l + sz - 1; } }; class array_binding_t_l_r { public: inline static constexpr uint32_t operand_type = RAW; template <typename T> friend array_binding_t_full<T> operator|(T* array, const array_binding_t_l_r& binding) { return array_binding_t_full<T>{array, binding.l, binding.r}; } int l, r; }; class array_binding_t_l { public:
inline static constexpr uint32_t operand_type = REQUIRE_PARAM; array_binding_t_l_r operator|(const int r) const { return array_binding_t_l_r{l, r}; } int l; }; class array_binding_t_empty { public: inline static constexpr uint32_t operand_type = REQUIRE_PARAM; array_binding_t_l operator|(const int l) const { return array_binding_t_l{l}; } }; static_assert(has_operand_type<array_binding_t_empty>); static_assert(require_param<array_binding_t_empty>); } enum general_operation_t { REVERSE, };
enum comparable_operation_t { SORT, UNIQUE, PREFIX_MIN, PREFIX_MAX, }; enum integer_operation_t { PREFIX_AND, PREFIX_OR, PREFIX_XOR, }; enum number_operation_t { PREFIX_SUM, PREFIX_PROD, }; enum single_input_operation_t { NEXT_INPUT, }; enum array_input_operation_t { ARRAY_INPUT, INDEX_1, }; enum array_output_operation_t { OUTPUT_1LINE, OUTPUT_1_PER_LINE, }; template <typename container_t> auto operator|(container_t&& a, const general_operation_t& op) { switch (op) {
case REVERSE: reverse(a.begin(), a.end()); break; default: assert(false); }; return a; } template <typename container_t> auto operator|(container_t&& a, const comparable_operation_t& op) { switch (op) { case SORT: { sort(a.begin(), a.end()); break; }; case UNIQUE: { sort(a.begin(), a.end()); a.resize(unique(a.begin(), a.end()) - a.begin()); break; } case PREFIX_MIN: { auto begin = a.begin(); ++begin; while (begin < a.end()) { (*begin) = min(*begin, *(begin - 1)); begin++; } break; } case PREFIX_MAX: {
auto begin = a.begin(); ++begin; while (begin < a.end()) { (*begin) = max(*begin, *(begin - 1)); begin++; } break; } default: assert(false); } return a; } template <typename container_t> auto operator|(container_t&& a, const number_operation_t& op) { switch (op) { case PREFIX_SUM: { for (size_t i = 1; i < a.size(); i++) a[i] += a[i - 1]; break; } case PREFIX_PROD: { for (size_t i = 1; i < a.size(); i++) a[i] *= a[i - 1]; break; } default: assert(false); } return a; } template <typename container_t>
auto operator|(container_t&& a, const integer_operation_t& op) { switch (op) { case PREFIX_AND: { for (size_t i = 1; i < a.size(); i++) a[i] &= a[i - 1]; break; } case PREFIX_OR: { for (size_t i = 1; i < a.size(); i++) a[i] |= a[i - 1]; break; } case PREFIX_XOR: { for (size_t i = 1; i < a.size(); i++) a[i] ^= a[i - 1]; break; } default: break; } return a; } template <typename container_t> auto operator|(container_t&& a, const array_input_operation_t& op) { switch (op) { case ARRAY_INPUT: {
for (auto&& x : a) cin >> x; break; } default: assert(0); } return a; } template <typename container_t> auto operator|(container_t&& a, const array_output_operation_t& op) { switch (op) { case OUTPUT_1LINE: { for (auto&& x : a) cout << x << ' '; cout << '\n'; break; } case OUTPUT_1_PER_LINE: { for (auto&& x : a) cout << x << '\n'; cout << '\n'; break; } default: assert(0); } return a; } constexpr array_binding_details::array_binding_t_empty ARRAY; }
// clang-format on

#define MULTI_TEST
// #define SKIP_ASSERT
#ifdef SKIP_ASSERT
#define assert(x) (x)
#endif

int n;
int a[1001];
int b[1001];
class edge_t {
public:
    int u, v;
    int64_t d;
};
vector<edge_t> e;
bool has_a[1001];
bool has_b[1001];

namespace hopcroft_karp {
// http://zobayer.blogspot.com/2010/05/maximum-matching.html
#define MAX 2001
#define NIL 0
#define INF (1 << 28)

vector<int> G[MAX];
int n, m, match[MAX], dist[MAX];
// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// G = NIL[0]  G1[G[1---n]]  G2[G[n+1---n+m]]

bool bfs() {
    int i, u, v, len;
    queue<int> Q;
    for (i = 1; i <= n; i++) {
        if (match[i] == NIL) {
            dist[i] = 0;
            Q.push(i);
        } else dist[i] = INF;
    }
    dist[NIL] = INF;
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        if (u != NIL) {
            len = G[u].size();
            for (i = 0; i < len; i++) {
                v = G[u][i];
                if (dist[match[v]] == INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL] != INF);
}

bool dfs(int u) {
    int i, v, len;
    if (u != NIL) {
        len = G[u].size();
        for (i = 0; i < len; i++) {
            v = G[u][i];
            if (dist[match[v]] == dist[u] + 1) {
                if (dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp() {
    int matching = 0, i;
    // match[] is assumed NIL for all vertex in G
    while (bfs())
        for (i = 1; i <= n; i++)
            if (match[i] == NIL && dfs(i)) matching++;
    return matching;
}
}  // namespace hopcroft_karp

int64_t p_a, p_b;
int64_t h[1001];
bool solved;
int64_t resolve_house(int i, int j) {
    // b[i], b[j] with p_a, p_b
    if (a[i] + b[j] == p_b - p_a) return p_a + a[i];
    if (a[i] - b[j] == p_b - p_a) return p_a + a[i];
    assert(b[j] - a[i] == p_b - p_a);
    return p_b - b[j];
}

void solve(const int& l, const int& r) {
    // solve using the edge from l to r
    if (r - l + 1 < n) return;  // must have enough edge
    // cerr << "Passed precheck: " << e[l].d << '\n';
    hopcroft_karp::n = hopcroft_karp::m = n;
    for (int i = 1; i <= n; i++) hopcroft_karp::G[i].clear();
    for (int i = l; i <= r; i++) hopcroft_karp::G[e[i].u].push_back(e[i].v + n);
    fill(hopcroft_karp::match + 1, hopcroft_karp::match + n + n + 1, NIL);
    int matching = hopcroft_karp::hopcroft_karp();
    // cerr << "matching: " << matching << '\n';
    if (matching != n) return;
    solved = 1;
    cout << "YES\n";
    p_a = 0;
    p_b = e[l].d;
    for (int i = 1; i <= n; i++) h[i] = resolve_house(i, hopcroft_karp::match[i] - n);
    int64_t mi = *min_element(h + 1, h + n + 1);
    mi = min(mi, p_a);
    mi = min(mi, p_b);
    p_a -= mi;
    p_b -= mi;
    for (int i = 1; i <= n; i++) h[i] -= mi;
    assert(p_a <= 2e9);
    assert(p_b <= 2e9);
    assert(*max_element(h + 1, h + n + 1) <= 2e9);
    for (int i = 1; i <= n; i++) cout << h[i] << " \n"[i == n];
    cout << p_a << ' ' << p_b << '\n';
}

void solve() {
    cin >> n;
    a | ARRAY | 1 | n | ARRAY_INPUT;
    b | ARRAY | 1 | n | ARRAY_INPUT;
    e.clear();
    solved = false;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            e.emplace_back(i, j, a[i] + b[j]);
            e.emplace_back(i, j, a[i] - b[j]);
            e.emplace_back(i, j, -a[i] + b[j]);
            // e.emplace_back(i, j, -a[i] - b[j]); WLOG p_a <= p_b
        }
    sort(e.begin(), e.end(), [](const auto& A, const auto& B) { return A.d < B.d; });
    for (int i = 0; i < e.size(); i++) {
        int j = i;
        while ((j + 1 < e.size()) && (e[j + 1].d == e[j].d)) j++;
        solve(i, j);
        if (solved) break;
        i = j;
    }
    if (!solved) cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
#ifdef MULTI_TEST
    cin >> t;
#endif
    while (t--) solve();
}