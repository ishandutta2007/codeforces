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

// f[i] = how many way to choose the op such that the current set contain i
// union with [l, r]: f[l <= i <= r] = (number of way to choose previous op), f[i < l or i > r] is the same
// intersection with [l, r]: f[l <= i <= r] is the same, f[i < l or i > r] = 0.
// symmetric difference with [l, r]: f[i < l or i > r] stay the same, f[l <= i <= r] is set to (number of way to choose previous
// op) - f[l <= i <= r]
// so next[l <= i <= r] =  (number of way to choose previous op) + f[i] + (number of way to choose previous op) - f[i] = (number
// of way to choose previous op) * 2.
// next [i < l or i > r] = f[i] + 0 + f[i] -> * 2
// need to support operations: set, multiply, sum
// In actuallyity only need to support set and sum, the multiply is always 2 so we can prepare for that

constexpr int base = 998244353;
constexpr int half = (base + 1) / 2;
class segment_tree_t {
public:
    segment_tree_t *left, *right;
    int l, r, m;
    int64_t sum;
    optional<int64_t> set_value;

    segment_tree_t(int l, int r) : l(l), r(r), m((l + r) / 2), sum(0), set_value() {
        if (l != r) {
            left = new segment_tree_t(l, m);
            right = new segment_tree_t(m + 1, r);
        }
    }

    void down() {
        if (set_value) {
            int64_t val = *set_value;
            left->set_value = val;
            (left->sum = val * (m - l + 1)) %= base;
            right->set_value = val;
            (right->sum = val * (r - m)) %= base;
            set_value = optional<int64_t>();
        }
    }

    void set(const int& u, const int& v, const int64_t& val) {
        if ((l > v) || (r < u)) return;
        if (u <= l && v >= r) {
            set_value = val;
            (sum = (val * (r - l + 1))) %= base;
        } else {
            down();
            left->set(u, v, val);
            right->set(u, v, val);
            (sum = left->sum + right->sum) %= base;
        }
    }
};
segment_tree_t* tree;
int n, l, r;
void solve() {
    cin >> n >> l >> r;
    tree = new segment_tree_t(0, 3e5);
    tree->set(l, r, 1);
    int64_t ans_multiplier = 1;
    int64_t multiplier = 1;
    for (int i = 1; i < n; i++) {
        cin >> l >> r;
        (ans_multiplier *= 2) %= base;
        tree->set(l, r, multiplier);
        (multiplier *= half) %= base;
        (multiplier *= 3) %= base;
    }
    cout << (tree->sum * ans_multiplier) % base << '\n';
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