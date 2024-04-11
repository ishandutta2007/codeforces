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
int cnt, len, sz;
string s;
template <size_t SIZE = 4>
class templated_hash_t {
public:
    // inline static constexpr size_t SIZE = 4;
    static_assert(SIZE <= 4);
    inline static constexpr int base[] = {31, 37, 41, 43};
    inline static constexpr int mod[] = {1'000'000'007, 1'000'000'009, 999'727'999, 999'999'937};
    inline static templated_hash_t* p;
    static void init(int n) {
        p = new templated_hash_t[n + 1];
        for (size_t i = 0; i < SIZE; i++) p[0].h[i] = 1;
        templated_hash_t base_h;
        for (size_t i = 0; i < SIZE; i++) base_h.h[i] = base[i];
        for (int i = 1; i <= n; i++) p[i] = p[i - 1] * base_h;
        // cerr << "init called\n";
    }
 
    int64_t h[SIZE];
 
    bool operator<(const templated_hash_t& other) const {
        for (size_t i = 0; i < SIZE; i++)
            if (h[i] != other.h[i]) return h[i] < other.h[i];
        return 0;
    }
 
    void append_char(const char c) {
        for (size_t i = 0; i < SIZE; i++) ((h[i] *= base[i]) += c) %= mod[i];
    }
 
    static templated_hash_t empty() {
        templated_hash_t res;
        for (size_t i = 0; i < SIZE; i++) res.h[i] = 0;
        return res;
    }
 
    templated_hash_t operator-(const templated_hash_t& other) const {
        templated_hash_t res;
        for (size_t i = 0; i < SIZE; i++) {
            (res.h[i] = h[i] - other.h[i]) %= mod[i];
            if (res.h[i] < 0) res.h[i] += mod[i];
        }
        return res;
    }
 
    templated_hash_t operator*(const templated_hash_t& other) const {
        templated_hash_t res;
        for (size_t i = 0; i < SIZE; i++) (res.h[i] = h[i] * other.h[i]) %= mod[i];
        return res;
    }
 
    static templated_hash_t get_hash(templated_hash_t* h, int l, int r) {
        if (l == 0) return h[r];
        return h[r] - (h[l - 1] * p[r - l + 1]);
    }
 
    friend ostream& operator<<(ostream& out, const templated_hash_t& val) {
        out << "(";
        for (size_t i = 0; i < SIZE; i++) {
            if (i) out << ", ";
            out << val.h[i];
        }
        return out << ")";
    }
};
using hash_t = templated_hash_t<2>;
map<hash_t, int> m;
hash_t h[1111111];
map<hash_t, int> game;
void solve() {
    cin >> cnt >> len;
    cin >> s;
    s = '0' + s;
    sz = cnt * len + len - 1;
    hash_t::init(sz);
    for (int i = 1; i < len; i++) s += s[i];
    h[0] = hash_t::empty();
    for (int i = 1; i <= sz; i++) {
        (h[i] = h[i - 1]).append_char(s[i]);
        // cerr << i << ' ' << h[i] << ' ' << hash_t::p[i] << '\n';
    }
    int g;
    cin >> g;
    string t;
    for (int i = 1; i <= g; i++) {
        cin >> t;
        hash_t h = hash_t::empty();
        for (auto&& c : t) h.append_char(c);
        game[h] = i;
        // cerr << i << ' ' << t << ' ' << h << '\n';
    }
    for (int start = 1; start <= len; start++) {
        // start the original string at md
        int end = start + cnt * len - 1;
        assert(end <= sz);
        // check that all string are different
        static set<hash_t> chk;
        chk.clear();
        for (int i = start; i <= end; i += len) {
            hash_t val = hash_t::get_hash(h, i, i + len - 1);
            // cerr << i << ' ' << val << '\n';
            if (chk.count(val)) break;
            chk.insert(val);
        }
        if (chk.size() == cnt) {  // all string are different
            // check that all string are names of games
            static vector<int> ans;
            ans.clear();
            for (int i = start; i <= end; i += len) {
                hash_t val = hash_t::get_hash(h, i, i + len - 1);
                if (game.count(val) == 0) break;
                ans.emplace_back(game[val]);
            }
            if (ans.size() == cnt) {
                cout << "YES\n";
                for (auto&& x : ans) cout << x << ' ';
                return;
            }
        }
    }
    cout << "NO\n";
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