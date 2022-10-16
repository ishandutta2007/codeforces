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
constexpr int search_until = 659;
int p[search_until + 1];
vector<pair<int64_t, vector<int>>> tests;
void prepare() {
    vector<int> primes;
    for (int i = 2; i <= search_until; i++) {
        if (p[i] == 0) {
            for (int j = i; j <= search_until; j += i)
                if (p[j] == 0) p[j] = i;
        }
    }
    for (int i = 2; i <= search_until; i++)
        if (p[i] == i) primes.emplace_back(i);
    tests.emplace_back(1LL, vector<int>{});
    for (auto&& x : primes) {
        if (static_cast<long double>(1) * tests.back().first * x > 1e18) {
            tests.emplace_back(1LL, vector<int>{});
        }
        tests.back().first *= x;
        tests.back().second.push_back(x);
    }
    cerr << tests.size() << '\n';
    int cnt = 0;
    for (auto&& [x, y] : tests) {
        cerr << x << '\n';
        assert(x <= 1e18);
        for (auto&& p : y) cerr << p << ' ';
        cerr << " end: " << ++cnt << '\n';
    }
    tests.pop_back();
}
int64_t hidden = 2 * 3 * 3 * 5 * 5 * 5 * 7 * 7 * 7 * 7;
int64_t ask(int64_t q) {
    assert(q <= 1e18);
    assert(q >= 1);
    cout << "? " << q << '\n';
    cout.flush();
    cin >> q;
    // return gcd(hidden, q);
    return q;
}

void answer(int x) {
    cout << "! " << x << '\n';
    cout.flush();
    return;
}

vector<int> find_prime_factor() {
    vector<int> res;
    for (auto&& [x, y] : tests) {
        int64_t g = ask(x);
        for (auto&& p : y)
            if (g % p == 0) res.emplace_back(p);
    }
    return res;
}

void solve() {
    auto primes = find_prime_factor();
    if (primes.empty()) {
        // X has at most 4 different prime factor, leading to the number of divisor in the range of [1, 16], so 8 is always
        // correct.
        answer(8);
        return;
    }
    map<int, int> factor;
    for (auto&& x : primes) factor[x] = 1;
    while (!primes.empty()) {
        int64_t query = 1;
        for (auto&& [x, y] : factor)
            for (int i = 0; i < y; i++) query *= x;
        int64_t original = query;
        map<int, int> add;
        for (auto&& x : primes) {
            query *= x;
            add[x] = 1;
        }
        while (true) {
            bool found = 0;
            for (auto&& x : primes) {
                while (true) {
                    if (static_cast<long double>(query) * x > 1e18) break;
                    found = 1;
                    query *= x;
                    add[x]++;
                }
            }
            if (!found) break;
        }
        assert(query <= 1e18);

        int64_t res = ask(query);
        res /= original;
        for (auto&& [x, y] : add) {
            while (res % x == 0) {
                res /= x;
                y--;
                factor[x]++;
            }
        }
        primes.clear();
        for (auto&& [x, y] : add)
            if (y == 0) primes.push_back(x);
    }
    int ans = 1;
    int64_t X = 1;
    for (auto&& [x, y] : factor) {
        ans *= (y + 1);
        for (int j = 0; j < y; j++) X *= x;
    }
    if (X >= 4) {
        // there might be at most 2 more prime factor that we don't know about
        // so the actual answer might be ans * [1, 2, 3, 4], choosing ans*2 is always correct
        answer(ans * 2);
    } else {
        // there might be up to 3 more different prime factor, which make the actual answer
        // ans * [1 .. 8]
        answer(8);
    }
}

int main() {
    prepare();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
#ifdef MULTI_TEST
    cin >> t;
#endif
    while (t--) solve();
}