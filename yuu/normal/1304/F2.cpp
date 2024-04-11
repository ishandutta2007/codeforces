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
// This is called venice trick in some blog because wather raising something something.
// I haven't came up with a name for it.
class sliding_venice_trick_t {
public:
    deque<pair<int, int>> max_item;
    int shift;

    sliding_venice_trick_t() : max_item{}, shift{0} {}

    void push_back(int value, int pos) {
        // value is actual value
        value -= shift;
        auto p = make_pair(value, pos);
        while ((!max_item.empty()) && (p >= max_item.back())) max_item.pop_back();
        max_item.push_back(p);
    }

    int get_max(int pos) {
        while ((!max_item.empty()) && (max_item.front().second < pos)) max_item.pop_front();
        if (max_item.empty()) return -1e9;
        return max_item.front().first + shift;
    }

    void change_shift(int delta) { shift += delta; }
};

int n, m, k;
int f[20002];
int r[20002];
int l[20002];
int a[52][20001];
int s[52][20001];
void solve() {
    cin >> n >> m >> k;
    for (int day = 1; day <= n; day++) {
        for (int i = 1; i <= m; i++) {
            cin >> a[day][i];
            s[day][i] = s[day][i - 1] + a[day][i];
        }
    }
    const int max_cam = m - k + 1;
    for (int i = 1; i <= max_cam; i++) f[i] = s[1][min(m, i + k - 1)] - s[1][i - 1] + s[2][min(m, i + k - 1)] - s[2][i - 1];
    for (int day = 2; day <= n; day++) {
        for (int i = 1; i <= max_cam; i++) l[i] = max(l[i - 1], f[i]);
        for (int i = max_cam; i >= 1; i--) r[i] = max(r[i + 1], f[i]);
        sliding_venice_trick_t l_venice;  // colisions from the left
        sliding_venice_trick_t r_venice;  // colisions from the right
        for (int i = 1; i <= min(max_cam, k - 1); i++) r_venice.push_back(f[i] - (s[day][k - 1] - s[day][i - 1]), i);

        for (int i = 1; i <= max_cam; i++) {
            // add to l_venice
            l_venice.push_back(f[i] - (s[day][i + k - 1] - s[day][i - 1]), i);
            // add to r_venice
            if (i + k - 1 <= max_cam) r_venice.push_back(f[i + k - 1], i + k - 1);
            r_venice.change_shift(-a[day][i + k - 1]);  // i + k - 1 will now be counted toward this instead

            f[i] = r_venice.get_max(i + 1);  // must have some colision
            f[i] = max(f[i], l_venice.get_max(i - k + 1));
            if (i >= k) f[i] = max(f[i], l[i - k]);  // no collision
            if (i + k <= max_cam) f[i] = max(f[i], r[i + k]);
            f[i] += s[day][i + k - 1] - s[day][i - 1] + s[day + 1][i + k - 1] - s[day + 1][i - 1];

            l_venice.change_shift(+a[day][i]);  // a[day][i] is no longer counted toward this
        }
        // for (int i = 1; i <= max_cam; i++) cerr << f[i] << " \n"[i == max_cam];
    }
    cout << *max_element(f + 1, f + max_cam + 1) << '\n';
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