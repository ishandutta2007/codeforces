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

int n, m;
string s[200001];
string t[200001];

constexpr int dx[] = {1, -1, 0, 0};
constexpr int dy[] = {0, 0, 1, -1};
bool good[400002];
int f[400002];
int trace[400002];
pair<int, int> pos[400002];
int get_id(int i, int j) {
    if (i < 1 || i > n) return -1;
    if (j < 1) return 0;
    if (j > m) return n * m + 1;
    return (i - 1) * m + j;
}
void bfs() {
    deque<pair<int, int>> q;
    q.emplace_back(0, 0);
    fill(f, f + n * m + 2, 1e9);
    f[0] = 0;
    while (!q.empty()) {
        auto [u, dist] = q.front();
        q.pop_front();
        auto&& [x, y] = pos[u];
        if (f[u] > dist) continue;
        if (u > n * m) break;  // done
        if (!good[u]) continue;
        if (u == 0) {
            for (int i = 1; i <= n; i++) {
                if (s[i][1] == '#') {
                    f[get_id(i, 1)] = 0;
                    trace[get_id(i, 1)] = 0;
                    q.emplace_front(get_id(i, 1), 0);
                } else {
                    f[get_id(i, 1)] = 1;
                    trace[get_id(i, 1)] = 0;
                    q.emplace_back(get_id(i, 1), 1);
                }
            }
        } else {
            for (int i = -1; i <= 1; i += 2)
                for (int j = -1; j <= 1; j += 2) {
                    int xx = x + i;
                    int yy = y + j;
                    int n_id = get_id(xx, yy);
                    if (n_id == -1) continue;
                    if (good[n_id]) {
                        int add = (s[xx][yy] != '#');
                        if (f[n_id] > dist + add) {
                            f[n_id] = dist + add;
                            trace[n_id] = u;
                            if (add == 0) q.emplace_front(n_id, f[n_id]);
                            else q.emplace_back(n_id, f[n_id]);
                        }
                    }
                }
        }
    }
    int v = n * m + 1;
    if (f[v] == 1e9) {
        cout << "NO\n";
        return;
    } else {
        v = trace[v];
        while (v > 0) {
            auto&& [x, y] = pos[v];
            s[x][y] = '#';
            v = trace[v];
        }
        cout << "YES\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) cout << s[i][j];
            cout << '\n';
        }
    }
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = '0' + s[i];
    }
    good[n * m + 1] = good[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pos[get_id(i, j)] = {i, j};
            if (s[i][j] == '#') {
                good[get_id(i, j)] = 1;
            } else {
                bool can_do = true;
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x < 1 || x > n) continue;
                    if (y < 1 || y > m) continue;
                    if (s[x][y] == '#') {
                        can_do = false;
                        break;
                    }
                }
                good[get_id(i, j)] = can_do;
            }
        }
    }

    bfs();
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