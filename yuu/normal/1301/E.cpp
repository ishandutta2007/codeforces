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

// #define MULTI_TEST
// #define SKIP_ASSERT
#ifdef SKIP_ASSERT
#define assert(x) (x)
#endif
int n, m, q;
string s[501];
int f[500][500];
int g[501][501];

int r[501][501][10][10];

int get_max(int x, int y, int u, int v) {
    if ((x > u) || (y > v)) return 0;
    const int lg_x = __lg(u - x + 1);
    const int lg_y = __lg(v - y + 1);
    return max({r[x][y][lg_x][lg_y], r[u - (1 << lg_x) + 1][y][lg_x][lg_y], r[x][v - (1 << lg_y) + 1][lg_x][lg_y],
                r[u - (1 << lg_x) + 1][v - (1 << lg_y) + 1][lg_x][lg_y]});
}

void solve() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = '0' + s[i];
    }

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++) f[i][j] = 1e9;

    char colour = 'R';
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (s[i][j] != colour) {
                g[i][j] = 0;
            } else {
                g[i][j] = min({g[i - 1][j], g[i - 1][j - 1], g[i][j - 1]}) + 1;
            }
            f[i][j] = min(f[i][j], g[i][j]);
        }
    }

    colour = 'G';
    for (int i = 1; i < n; i++) {
        for (int j = m - 1; j >= 1; j--) {
            if (s[i][j + 1] != colour) {
                g[i][j] = 0;
            } else {
                g[i][j] = min({g[i - 1][j], g[i - 1][j + 1], g[i][j + 1]}) + 1;
            }
            f[i][j] = min(f[i][j], g[i][j]);
        }
    }

    colour = 'B';
    for (int i = n - 1; i >= 1; i--) {
        for (int j = m - 1; j >= 1; j--) {
            if (s[i + 1][j + 1] != colour) {
                g[i][j] = 0;
            } else {
                g[i][j] = min({g[i + 1][j], g[i + 1][j + 1], g[i][j + 1]}) + 1;
            }
            f[i][j] = min(f[i][j], g[i][j]);
        }
    }

    colour = 'Y';
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j < m; j++) {
            if (s[i + 1][j] != colour) {
                g[i][j] = 0;
            } else {
                g[i][j] = min({g[i + 1][j], g[i + 1][j - 1], g[i][j - 1]}) + 1;
            }
            f[i][j] = min(f[i][j], g[i][j]);
        }
    }
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++) r[i][j][0][0] = f[i][j];

    for (int x = 0; x < 9; x++) {
        for (int i = 1; i < n; i++)
            for (int y = 0; y < 9; y++)
                for (int j = 1; j + (1 << y) < m; j++) r[i][j][x][y + 1] = max(r[i][j][x][y], r[i][j + (1 << y)][x][y]);

        for (int i = 1; i + (1 << x) < n; i++)
            for (int j = 1; j < m; j++)
                for (int y = 0; y < 9; y++) r[i][j][x + 1][y] = max(r[i][j][x][y], r[i + (1 << x)][j][x][y]);
    }

    // for (int i = 1; i < n; i++)
    //     for (int j = 1; j < m; j++) cerr << f[i][j] << " \n"[j + 1 == m];
    for (int i = 1, x, y, u, v; i <= q; i++) {
        cin >> x >> y >> u >> v;
        if ((u <= x) || (v <= y)) {
            cout << 0 << '\n';
            continue;
        }
        int low = 1, high = min(u - x + 1, v - y + 1), mid, res = 0;
        while (low <= high) {
            mid = (low + high) / 2;
            if (get_max(x + mid - 1, y + mid - 1, u - mid, v - mid) >= mid) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << res * 2 * res * 2 << '\n';
    }
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