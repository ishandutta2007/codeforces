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
int n;
string s[2];

int e[2][4][4];
bool done[2][4][4];

int get(int enter, int mask, int new_mask) {
    if (done[enter][mask][new_mask]) return e[enter][mask][new_mask];
    done[enter][mask][new_mask] = 1;
    auto& result = e[enter][mask][new_mask];
    bool bad[2][2];
    bad[0][0] = mask & 1;
    bad[1][0] = mask & 2;
    bad[0][1] = new_mask & 1;
    bad[1][1] = new_mask & 2;
    int c = 0, r = enter;
    while (true) {
        vector<tuple<int, int, int>> targets;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (!bad[i][j]) continue;
                int dist = abs(i - r) + abs(j - c);
                targets.emplace_back(dist, i, j);
            }
        }
        sort(targets.begin(), targets.end());
        while (targets.size() >= 2) {
            auto&& [d1, x1, y1] = targets.back();
            auto&& [d2, x2, y2] = targets[targets.size() - 2];
            if (d2 < d1) targets.pop_back();
            else break;
        }
        if (targets.size() == 2) return result = -1;
        if (targets.empty()) break;
        auto&& [d, x, y] = targets[0];
        bad[x][y] = 0;
        if (y == 0) {
            r = x;
            c = y;
            continue;
        } else {
            return result = r;
        }
    }
    return result = r;
}

// enter the previous column at what row, what is the state of the previous column
int f[2][4];
int g[2][4];
void solve() {
    cin >> n >> s[0] >> s[1];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 4; j++) f[i][j] = 1e9;
    f[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 4; j++) g[i][j] = 1e9;
        int full_new_mask = 1 * (s[0][i] == '1') + 2 * (s[1][i] == '1');
        for (int enter = 0; enter <= 1; enter++) {
            for (int old_mask = 0; old_mask < 4; old_mask++) {
                for (int new_mask = 0; new_mask < 4; new_mask++) {
                    if ((new_mask | full_new_mask) != full_new_mask) continue;
                    int new_enter = get(enter, old_mask, new_mask);
                    if (new_enter == -1) continue;
                    g[new_enter][new_mask] =
                            min(g[new_enter][new_mask], f[enter][old_mask] + __builtin_popcount(new_mask ^ full_new_mask));
                }
            }
        }
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 4; j++) f[i][j] = g[i][j];
    }

    int ans = 1e9;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 4; j++) ans = min(ans, f[i][j]);
    ans = -ans;
    for (auto&& c : s[0]) ans += (c == '1');
    for (auto&& c : s[1]) ans += (c == '1');
    cout << ans << '\n';
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