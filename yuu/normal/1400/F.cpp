#include <bits/stdc++.h>
using namespace std;
// clang-format off
namespace {  // forbidden c++
// must be an operator that execute from left to right to make sense.
// need concept to use <<, >>, so we use | for now
#define PREFERED_OPERATOR operator|
enum general_operation_t {REVERSE, };
enum comparable_operation_t {SORT, UNIQUE, PREFIX_MIN, PREFIX_MAX, };
enum integer_operation_t {PREFIX_AND, PREFIX_OR, PREFIX_XOR, };
enum number_operation_t {PREFIX_SUM, PREFIX_PROD, };
enum single_input_operation_t {NEXT_INPUT, };
enum array_input_operation_t {ARRAY_INPUT, INDEX_1, };
// enum single_output_operation_t {OUTPUT, OUTPUT_SP, OUTPUT_LN, };
enum array_output_operation_t {OUTPUT_1LINE, OUTPUT_1PER_LINE, INDEX_0, };
template <typename container_t> container_t& PREFERED_OPERATOR(container_t& a, const general_operation_t& op) { switch (op) {case REVERSE: reverse(a.begin(), a.end()); break; default: assert(false);}; return a;}
template <typename container_t> container_t& PREFERED_OPERATOR(container_t& a, const comparable_operation_t& op) { switch (op) { case SORT: {sort(a.begin(), a.end()); break;}; case UNIQUE: {sort(a.begin(), a.end()); a.erase(unique(a.begin(), a.end()), a.end()); break;} case PREFIX_MIN: { for (size_t i = 1; i < a.size(); i++) a[i] = min(a[i], a[i - 1]); break;} case PREFIX_MAX: { for (size_t i = 1; i < a.size(); i++) a[i] = max(a[i], a[i - 1]); break;} default: assert(false);} return a;}
template <typename container_t> container_t& PREFERED_OPERATOR(container_t& a, const number_operation_t& op) { switch (op) { case PREFIX_SUM: { for (size_t i = 1; i < a.size(); i++) a[i] += a[i - 1]; break; } case PREFIX_PROD: { for (size_t i = 1; i < a.size(); i++) a[i] *= a[i - 1]; break; } default: assert(false);} return a;}
template <typename container_t> container_t& PREFERED_OPERATOR(container_t& a, const integer_operation_t& op) { switch (op) { case PREFIX_AND: { for (size_t i = 1; i < a.size(); i++) a[i] &= a[i - 1]; break; } case PREFIX_OR: { for (size_t i = 1; i < a.size(); i++) a[i] |= a[i - 1]; break; } case PREFIX_XOR: { for (size_t i = 1; i < a.size(); i++) a[i] ^= a[i - 1]; break; } default: break;} return a;}
template <typename T> T& operator|(T& var, const single_input_operation_t& op) {cin >> var; return var;}
template <typename container_t> container_t& PREFERED_OPERATOR(container_t& a, const array_input_operation_t& op) { switch (op) { case ARRAY_INPUT: { for (auto&& x : a) x | NEXT_INPUT; break; } case INDEX_1: { a | REVERSE; a.emplace_back(); a | REVERSE; break; } default: assert(0); } return a; }
template <typename container_t> container_t& PREFERED_OPERATOR(container_t& a, const array_output_operation_t& op) {switch (op) { case INDEX_0: { a | REVERSE; a.pop_back(); a | REVERSE; break; } case OUTPUT_1LINE: { for (auto&& x : a) cout << x << ' '; cout << '\n'; break; } case OUTPUT_1PER_LINE: { for (auto&& x : a) cout << x << '\n'; cout << '\n'; break; } default: assert(0); } return a; }
}  // namespace
// clang-format on
constexpr bool MULTI_TEST = 0;
string s;
int x;
string current_str;
vector<int> prefix_sum;
vector<string> avails;
bool check() {
    for (auto&& a : prefix_sum) {
        if (prefix_sum.back() - a > 0) {
            if ((prefix_sum.back() - a != x) && ((x % (prefix_sum.back() - a) == 0))) return false;
        }
    }
    return true;
}
void generate_strings(int current_sum = 1, int current_digit = 1) {
    if (!check()) return;
    if (current_sum == x) {
        current_str.push_back(current_digit);
        prefix_sum.push_back(prefix_sum.back() + current_digit);
        if (check()) {
            avails.push_back(current_str);
            // for (auto&& x : current_str) cerr << char(x + '0');
            // cerr << '\n';
        }
        current_str.pop_back();
        prefix_sum.pop_back();
    } else {
        current_str.push_back(current_digit);
        prefix_sum.push_back(prefix_sum.back() + current_digit);
        generate_strings(current_sum + 1, 1);
        current_str.pop_back();
        prefix_sum.pop_back();
        if (current_digit != 9) generate_strings(current_sum + 1, current_digit + 1);
    }
}

// TODO(template)
class aho_corasick_t {
public:
    inline static int node_count;
    inline static aho_corasick_t* node_by_id[10000];
    aho_corasick_t *parent, *fall_back;
    char c;
    aho_corasick_t* g[10];
    aho_corasick_t* next[10];
    int node_id;
    bool end_point, suffix_end_point;

    aho_corasick_t(aho_corasick_t* parent = nullptr, char c = -1)
            : parent(parent), fall_back(nullptr), c(c), end_point(0), suffix_end_point(0), node_id(++node_count) {
        assert(node_id <= 10000);
        node_by_id[node_id] = this;
        for (int i = 1; i <= 9; i++) g[i] = nullptr;
        for (int i = 1; i <= 9; i++) next[i] = nullptr;
    }

    static void add(aho_corasick_t* root, const string& s) {
        for (auto&& c : s) {
            if (root->g[c] == nullptr) root->g[c] = new aho_corasick_t(root, c);
            root = root->g[c];
        }
        root->end_point = 1;
    }

    static void build_fall_back(aho_corasick_t* root) {
        queue<aho_corasick_t*> q;
        q.push(root);
        while (!q.empty()) {
            aho_corasick_t* u = q.front();
            q.pop();
            for (int c = 1; c <= 9; c++)
                if (u->g[c]) q.push(u->g[c]);
            u->suffix_end_point = u->end_point;
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
            u->suffix_end_point = u->suffix_end_point || u->fall_back->suffix_end_point;
            for (int c = 1; c <= 9; c++)
                if (u->g[c]) q.push(u->g[c]);
        }
    }

    static void build_next(aho_corasick_t* root) {
        queue<aho_corasick_t*> q;
        q.push(root);
        while (!q.empty()) {
            aho_corasick_t* u = q.front();
            q.pop();
            for (int c = 1; c <= 9; c++)
                if (u->g[c]) q.push(u->g[c]);
            for (int c = 1; c <= 9; c++) {
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
};
int f[5001];
int g[5001];
void solve() {
    cin >> s;
    cin >> x;
    prefix_sum.push_back(0);
    generate_strings(1, 1);
    // cerr << avails.size() << '\n';  // 29 max at x = 20
    aho_corasick_t* aho = new aho_corasick_t();
    for (auto&& s : avails) aho_corasick_t::add(aho, s);
    aho_corasick_t::build_fall_back(aho);
    aho_corasick_t::build_next(aho);
    // cerr << aho_corasick_t::node_count << '\n'; // around 5k for 19
    int& m = aho_corasick_t::node_count;
    assert(m <= 5000);
    for (int i = 1; i <= m; i++) f[i] = 1e9;
    f[aho->node_id] = 0;
    for (auto&& c : s) {
        c -= '0';
        for (int i = 1; i <= m; i++) g[i] = f[i] + 1;  // to stay, delete the current character
        for (int i = 1; i <= m; i++)
            if (f[i] < 1e9) {
                if (aho_corasick_t::node_by_id[i]->next[c]->suffix_end_point) continue;  // would reach a bad state
                int j = aho_corasick_t::node_by_id[i]->next[c]->node_id;
                g[j] = min(g[j], f[i]);
            }
        for (int i = 1; i <= m; i++) f[i] = g[i];
    }
    cout << *min_element(f + 1, f + m + 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    if constexpr (MULTI_TEST) cin >> t;
    while (t--) solve();
}