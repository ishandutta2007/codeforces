#include <bits/stdc++.h>
using namespace std;
// clang-format off
namespace {  // forbidden c++
#define PREFERED_OPERATOR operator|
enum general_operation_t {REVERSE, }; enum comparable_operation_t {SORT, UNIQUE, PREFIX_MIN, PREFIX_MAX, }; enum integer_operation_t {PREFIX_AND, PREFIX_OR, PREFIX_XOR, }; enum number_operation_t {PREFIX_SUM, PREFIX_PROD, }; enum single_input_operation_t {NEXT_INPUT, }; enum array_input_operation_t {ARRAY_INPUT, INDEX_1, }; enum array_output_operation_t {OUTPUT_1LINE, OUTPUT_1PER_LINE, INDEX_0, }; template <typename container_t> container_t& PREFERED_OPERATOR(container_t& a, const general_operation_t& op) { switch (op) {case REVERSE: reverse(a.begin(), a.end()); break; default: assert(false);}; return a;} template <typename container_t> container_t& PREFERED_OPERATOR(container_t& a, const comparable_operation_t& op) { switch (op) { case SORT: {sort(a.begin(), a.end()); break;}; case UNIQUE: {sort(a.begin(), a.end()); a.erase(unique(a.begin(), a.end()), a.end()); break;} case PREFIX_MIN: { for (size_t i = 1; i < a.size(); i++) a[i] = min(a[i], a[i - 1]); break;} case PREFIX_MAX: { for (size_t i = 1; i < a.size(); i++) a[i] = max(a[i], a[i - 1]); break;} default: assert(false);} return a;} template <typename container_t> container_t& PREFERED_OPERATOR(container_t& a, const number_operation_t& op) { switch (op) { case PREFIX_SUM: { for (size_t i = 1; i < a.size(); i++) a[i] += a[i - 1]; break; } case PREFIX_PROD: { for (size_t i = 1; i < a.size(); i++) a[i] *= a[i - 1]; break; } default: assert(false);} return a;} template <typename container_t> container_t& PREFERED_OPERATOR(container_t& a, const integer_operation_t& op) { switch (op) { case PREFIX_AND: { for (size_t i = 1; i < a.size(); i++) a[i] &= a[i - 1]; break; } case PREFIX_OR: { for (size_t i = 1; i < a.size(); i++) a[i] |= a[i - 1]; break; } case PREFIX_XOR: { for (size_t i = 1; i < a.size(); i++) a[i] ^= a[i - 1]; break; } default: break;} return a;} template <typename inputable_t> inputable_t& PREFERED_OPERATOR(inputable_t& var, const single_input_operation_t& op) {cin >> var; return var;} template <typename container_t> container_t& PREFERED_OPERATOR(container_t& a, const array_input_operation_t& op) { switch (op) { case ARRAY_INPUT: { for (auto&& x : a) x | NEXT_INPUT; break; } case INDEX_1: { a | REVERSE; a.emplace_back(); a | REVERSE; break; } default: assert(0); } return a; } template <typename container_t> container_t& PREFERED_OPERATOR(container_t& a, const array_output_operation_t& op) {switch (op) { case INDEX_0: { a | REVERSE; a.pop_back(); a | REVERSE; break; } case OUTPUT_1LINE: { for (auto&& x : a) cout << x << ' '; cout << '\n'; break; } case OUTPUT_1PER_LINE: { for (auto&& x : a) cout << x << '\n'; cout << '\n'; break; } default: assert(0); } return a; } enum operand_type_enum : uint32_t { DATA = 0, COMPOSED = 1 << 1, EXECUTABLE = 1 << 2, REQUIRE_PARAM = 1 << 3, }; template <class T> concept has_operand_type = requires() { { T::operand_type } -> convertible_to<uint32_t>; }; template <class T> class operand_type { public: inline static constexpr uint32_t value() { if constexpr (has_operand_type<T>) return T::operand_type; else return operand_type_enum::DATA; } }; template <class T> constexpr uint32_t operand_type_v = operand_type<decay_t<T>>::value(); template <class T> concept is_data = ((operand_type_v<T> & DATA) == DATA); template <class T> concept is_composed = ((operand_type_v<T> & COMPOSED) == COMPOSED); template <class T> concept require_param = ((operand_type_v<T> & REQUIRE_PARAM) == REQUIRE_PARAM); template <class T> concept require_no_param = !require_param<T>; template <class left_t, class right_t> class composed_operation_t { public: inline static constexpr uint32_t operand_type = COMPOSED | operand_type_v<right_t> | operand_type_v<left_t>; left_t left; right_t right; }; namespace array_binding_details { template <typename T> class array_binding_t_full { public: inline static constexpr uint32_t operand_type = DATA; T* array; int l, r; T* begin() { return array + l; } T* end() { return array + r + 1; } }; class array_binding_t_l_r { public: inline static constexpr uint32_t operand_type = EXECUTABLE; template <typename T> friend array_binding_t_full<T> operator|(T* array, const array_binding_t_l_r& binding) { return array_binding_t_full<T>{array, binding.l, binding.r}; } int l, r; }; class array_binding_t_l { public: inline static constexpr uint32_t operand_type = REQUIRE_PARAM; array_binding_t_l_r operator|(const int r) const { return array_binding_t_l_r{l, r}; } int l; }; class array_binding_t_empty { public: inline static constexpr uint32_t operand_type = REQUIRE_PARAM; array_binding_t_l operator|(const int l) const { return array_binding_t_l{l}; } }; static_assert(has_operand_type<array_binding_t_empty>); static_assert(require_param<array_binding_t_empty>); } constexpr array_binding_details::array_binding_t_empty ARRAY; constexpr array_binding_details::array_binding_t_l ARRAY_0{0}, ARRAY_1{1}; template <class left_t, class right_t> requires(is_composed<left_t> && (!is_composed<right_t>)) auto operator|(left_t&& left, right_t&& right) { return left.left | (left.right | right); } template <class left_t, class right_t> requires(is_data<left_t>&& require_param<right_t>) auto operator|(left_t&& left, right_t&& right) { return composed_operation_t<left_t, right_t>(left, right); }
}
// clang-format on

constexpr bool MULTI_TEST = 0;
// #define SKIP_ASSERT
#ifdef SKIP_ASSERT
#define assert(x) (x)
#endif
int n, m, k;

vector<pair<int, int>> g[100001];
int64_t f[100001];
priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> q;
void dijkstra() {
    for (int i = 1; i <= n; i++) q.emplace(f[i], i);
    while (!q.empty()) {
        auto [w, u] = q.top();
        q.pop();
        if (f[u] != w) continue;
        for (auto&& [v, c] : g[u]) {
            if (f[v] > w + c) {
                f[v] = w + c;
                q.emplace(w + c, v);
            }
        }
    }
}

class convex_hull_trick_t {
public:
    class line_t {
    public:
        int64_t a, b, dom;
        int64_t operator()(const int64_t& x) const { return a * x + b; }

        void find_dom(const line_t& other) {
            // min x such that a * x + b < other.a * x + other.b
            // (other.a - a) * x > b - other.b
            // x > (b - other.b) / (other.a - a)
            assert(other.a > a);
            dom = (b - other.b) / (other.a - a);
            while (operator()(dom) < other(dom)) dom--;
            while (operator()(dom) >= other(dom)) dom++;
            assert(operator()(dom) < other(dom));
            assert(operator()(dom - 1) >= other(dom - 1));
        }
    };
    deque<line_t> lines;

    // must insert in the decreasing order of a
    void insert(int64_t a, int64_t b) {
        line_t l{a, b, 1};
        while ((!lines.empty()) && (lines.back()(lines.back().dom) >= l(lines.back().dom))) lines.pop_back();
        if (lines.empty()) l.dom = 1;
        else l.find_dom(lines.back());
        lines.push_back(l);
    }

    // must get in the decreasing order of x
    int64_t get(int64_t x) {
        while (lines.back().dom > x) lines.pop_back();
        return lines.back()(x);
    }
};

void flight() {
    convex_hull_trick_t cht;
    for (int i = 1; i <= n; i++) cht.insert(-i * 2, f[i] + 1LL * i * i);
    for (int i = n; i >= 1; i--) f[i] = cht.get(i) + 1LL * i * i;
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    for (int i = 1; i <= n; i++) f[i] = 1LL * (n - 1) * (n - 1);
    f[1] = 0;
    dijkstra();
    for (int i = 1; i <= k; i++) {
        flight();
        dijkstra();
    }
    for (int i = 1; i <= n; i++) cout << f[i] << " \n"[i == n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    if constexpr (MULTI_TEST) cin >> t;
    while (t--) solve();
}