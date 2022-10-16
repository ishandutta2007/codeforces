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
class word_t {
public:
    int c;
    string s;
    void input() {
        cin >> c >> s;
        static set<int> g[12];
        for (auto&& x : s) x -= 'a';
        for (int i = 0; i < 12; i++) g[i].clear();
        for (int i = 1; i < s.size(); i++) {
            g[s[i]].insert(s[i - 1]);
            g[s[i - 1]].insert(s[i]);
        }
        for (int i = 0; i < 12; i++)
            if (g[s[i]].size() > 2) {
                c = 0;
                return;
            }
        int start = 0;
        while ((start < 12) && (g[start].size() != 1)) start++;
        if (start == 12) return;
        s.clear();
        s.push_back(start);
        start = *g[start].begin();
        while (true) {
            s.push_back(start);
            if (g[start].size() == 1) break;
            start = (*g[start].begin()) ^ (*g[start].rbegin()) ^ (s[s.size() - 2]);
        }
        // cerr << c << ' ';
        // for (auto&& x : s) cerr << char(x + 'a');
        // cerr << '\n';
    }
} w[1001];

class aho_corasick_t {
public:
    inline static int node_count;
    aho_corasick_t *parent, *fall_back;
    int64_t weight;
    char c;
    aho_corasick_t* g[12];
    aho_corasick_t* next[12];
    int64_t dp[1 << 12];
    pair<aho_corasick_t*, int> trace[1 << 12];

    aho_corasick_t(aho_corasick_t* parent = nullptr, char c = -1) : parent(parent), fall_back(nullptr), c(c), weight(0) {
        fill(g, g + 12, nullptr);
        fill(dp, dp + (1 << 12), -1e18);
    }

    static void add(aho_corasick_t* root, const string& s, const int64_t& w) {
        for (auto&& c : s) {
            if (root->g[c] == nullptr) root->g[c] = new aho_corasick_t(root, c);
            root = root->g[c];
        }
        root->weight += w;
    }

    static void build_fall_back(aho_corasick_t* root) {
        queue<aho_corasick_t*> q;
        q.push(root);
        while (!q.empty()) {
            aho_corasick_t* u = q.front();
            q.pop();
            for (int c = 0; c < 12; c++)
                if (u->g[c]) q.push(u->g[c]);
            if (u->parent == nullptr) {  // root
                u->fall_back = u;
                continue;
            }

            u->fall_back = u->parent->fall_back;
            while (u->fall_back->g[u->c] == nullptr) {
                if (u->fall_back == u->fall_back->fall_back) break;
                u->fall_back = u->fall_back->fall_back;
            }
            if ((u->fall_back->g[u->c] != nullptr) && (u->fall_back->g[u->c] != u)) u->fall_back = u->fall_back->g[u->c];
            u->weight += u->fall_back->weight;
        }
    }

    static void build_next(aho_corasick_t* root) {
        queue<aho_corasick_t*> q;
        q.push(root);
        while (!q.empty()) {
            aho_corasick_t* u = q.front();
            q.pop();
            for (int c = 0; c < 12; c++)
                if (u->g[c]) q.push(u->g[c]);
            for (int c = 0; c < 12; c++) {
                if (u->g[c] != nullptr) {
                    u->next[c] = u->g[c];
                    continue;
                }
                u->next[c] = u->fall_back;
                while (u->next[c]->g[c] == nullptr) {
                    if (u->next[c] == u->next[c]->fall_back) break;
                    u->next[c] = u->next[c]->fall_back;
                }
                if (u->next[c]->g[c]) u->next[c] = u->next[c]->g[c];
            }
        }
    }

    void do_dp(const int& mask) {
        if (dp[mask] >= 0) {
            for (int i = 0; i < 12; i++)
                if ((mask & (1 << i)) == 0) {
                    int new_mask = mask ^ (1 << i);
                    if (next[i]->dp[new_mask] < dp[mask] + next[i]->weight) {
                        next[i]->dp[new_mask] = dp[mask] + next[i]->weight;
                        next[i]->trace[new_mask] = {this, mask};
                    }
                }
        }
        for (int i = 0; i < 12; i++)
            if (g[i]) g[i]->do_dp(mask);
    }

    aho_corasick_t* find_best(const int& mask) {
        aho_corasick_t* best = this;
        for (int i = 0; i < 12; i++) {
            if (!g[i]) continue;
            auto res = g[i]->find_best(mask);
            if (res->dp[mask] > best->dp[mask]) best = res;
        }
        return best;
    }
};
aho_corasick_t* aho = new aho_corasick_t();

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) w[i].input();
    for (int i = 1; i <= n; i++)
        if (w[i].c) {
            aho_corasick_t::add(aho, w[i].s, w[i].c);
            reverse(w[i].s.begin(), w[i].s.end());
            aho_corasick_t::add(aho, w[i].s, w[i].c);
        }
    aho_corasick_t::build_fall_back(aho);
    aho_corasick_t::build_next(aho);
    aho->dp[0] = 0;
    for (int i = 0; i < (1 << 12); i++) aho->do_dp(i);
    int mask = (1 << 12) - 1;
    auto node = aho->find_best(mask);
    while (mask > 0) {
        auto [new_node, new_mask] = node->trace[mask];
        cout << char('a' + __lg(new_mask ^ mask));
        node = new_node;
        mask = new_mask;
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