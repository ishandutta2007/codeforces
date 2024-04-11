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
constexpr int base = 998'244'353;
bool done[1 << 20];
int64_t f[1 << 20];
int64_t inv[1 << 20];

int64_t power(int64_t a, int64_t x) {
    int64_t res = 1;
    while (x) {
        if (x % 2) (res *= a) %= base;
        (a *= a) %= base;
        x /= 2;
    }
    return res;
}

int64_t inverse(int64_t x) {
    x %= base;
    return power(x, base - 2);
}
int n;

int64_t F(int val) {
    if (done[val]) return f[val];
    done[val] = 1;
    if (val == 0) return f[val] = 0;
    if (val % 2) return f[val] = F(val / 2);
    int lg = __lg(val);
    int cnt = 0;
    int choice = n * (n - 1) / 2;

    for (int i = 0; i <= lg; i++) {
        if (((val >> i) & 1) == 0) continue;
        for (int j = 0; j < i; j++) {
            if ((val >> j) & 1) continue;
            (f[val] += F(val ^ (1 << i) ^ (1 << j))) %= base;
            cnt++;
        }
    }
    inv[val] = cnt;
    return ((f[val] += choice) *= inverse(cnt)) %= base;
}

deque<int> pos[2];
int a[200001];
void solve() {
    cin >> n;
    // fill(done, done + (1 << n), 0);
    // int val = 0;
    // for (int i = 0, x; i < n; i++) {
    //     cin >> x;
    //     (val *= 2) += x;
    // }
    // vector<tuple<int, int, int, int>> v;
    // for (int i = 0; i < (1 << n); i++) {
    //     if (i % 2) continue;
    //     v.emplace_back(inv[i], __lg(i), i, F(i));
    // }
    // sort(v.begin(), v.end());
    // int old_inv = -1;
    // int old_lg = -1;
    // int64_t old_f_i;
    // for (auto&& [inv, lg, i, f_i] : v) {
    //     cerr << inv << ' ' << lg << ' ' << bitset<6>(i) << ' ' << f_i << '\n';
    // }
    // // cout << F(0) << '\n';
    // cout << F(val) << '\n';
    a | ARRAY | 1 | n | ARRAY_INPUT;
    pos[0].clear();
    pos[1].clear();
    for (int i = 1; i <= n; i++) pos[a[i]].push_back(i);
    int min_flip = 0;
    while ((!pos[1].empty()) && (!pos[0].empty()) && (pos[1].front() < pos[0].back())) {
        pos[1].pop_front();
        pos[0].pop_back();
        min_flip++;
    }
    int64_t choice = n;
    ((choice *= (n - 1)) /= 2) %= base;
    int64_t i_choice = inverse(choice);
    int64_t ans = 0;
    for (int64_t i = 1; i <= min_flip; i++) {
        (ans += inverse((i * i) % base)) %= base;
    }
    (ans *= choice) %= base;
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