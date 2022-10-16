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
template <typename inputable_t> inputable_t& PREFERED_OPERATOR(inputable_t& var, const single_input_operation_t& op) {cin >> var; return var;}
template <typename container_t> container_t& PREFERED_OPERATOR(container_t& a, const array_input_operation_t& op) { switch (op) { case ARRAY_INPUT: { for (auto&& x : a) x | NEXT_INPUT; break; } case INDEX_1: { a | REVERSE; a.emplace_back(); a | REVERSE; break; } default: assert(0); } return a; }
template <typename container_t> container_t& PREFERED_OPERATOR(container_t& a, const array_output_operation_t& op) {switch (op) { case INDEX_0: { a | REVERSE; a.pop_back(); a | REVERSE; break; } case OUTPUT_1LINE: { for (auto&& x : a) cout << x << ' '; cout << '\n'; break; } case OUTPUT_1PER_LINE: { for (auto&& x : a) cout << x << '\n'; cout << '\n'; break; } default: assert(0); } return a; }
}  // namespace
// clang-format on

constexpr bool MULTI_TEST = 0;
// #define SKIP_ASSERT
#ifdef SKIP_ASSERT
#define assert(x) (x)
#endif
using hash_t = int64_t;
constexpr hash_t base = 31;
constexpr hash_t mod = 999'999'937;
hash_t power[1000001];
void prepare_hash() {
    power[0] = hash_t(1);
    for (int i = 1; i <= 1'000'000; i++) {
        (power[i] = power[i - 1] * base) %= mod;
    }
}
constexpr int64_t dp_base = 1e9 + 7;
class word_t {
public:
    string s;
    vector<int> order;
    vector<hash_t> hashes;
    vector<int64_t> dp;
    void input() { cin >> s; }

    void prepare() {
        static int is_same[1000001];
        is_same[s.size() - 1] = 0;
        for (int i = int(s.size()) - 2; i >= 0; i--) {
            if (s[i] == s[i + 1]) is_same[i] = is_same[i + 1] + 1;
            else is_same[i] = 0;
        }
        order.reserve(s.size());
        for (int i = 0; i <= s.size(); i++) order.emplace_back(i);
        auto compare = [this](const int& a, const int& b) -> bool {
            if (a < b) {
                if (a + is_same[a] >= b) return 0;  // equal, b != s.size() in this case
                else {
                    if (a + is_same[a] + 1 == s.size()) {
                        assert(b == s.size());
                        return 1;  // less because shorter
                    } else {
                        return s[a + is_same[a] + 1] < s[a];
                    }
                }
            } else {
                assert(a != b);
                if (b + is_same[b] >= a) return 0;  // equal, a != s.size() in this case
                else {
                    if (b + is_same[b] + 1 == s.size()) {
                        assert(a == s.size());
                        return 0;  // greater because longer
                    } else {
                        return s[b] < s[b + is_same[b] + 1];
                    }
                }
            }
        };
        sort(order.begin(), order.end(), compare);
        // cerr << s << '\n';
        // for (auto&& i : order) cerr << i << ' ' << s.substr(0, i) + s.substr(min(i + 1, (int)s.size())) << '\n';
        // cerr << '\n';
        hashes.reserve(s.size());
        hashes.resize(s.size(), hash_t(0));
        hashes[0] = s[0];
        for (int i = 1; i < s.size(); i++) hashes[i] = ((hashes[i - 1] * base) + s[i]) % mod;
    }

    int get_length(int id) { return s.size() - (id != s.size()); }

    hash_t get_hash(int l, int r) {
        assert(l <= r);
        assert(r < s.size());
        hash_t res(0);
        if (l) res = hashes[l - 1];
        (res *= power[r - l + 1]) %= mod;
        (res = mod - res) %= mod;
        (res += hashes[r]) %= mod;
        return res;
    }

    hash_t get_string_hash(int id, int prefix_length) {
        assert(prefix_length >= 1);
        assert(prefix_length <= get_length(id));
        if (prefix_length - 1 < id) return hashes[prefix_length - 1];
        hash_t res(0);
        if (id) res = hashes[id - 1];
        int remaining_length = prefix_length - id;
        (res *= power[remaining_length]) %= mod;
        (res += get_hash(id + 1, id + remaining_length)) %= mod;
        return res;
    }

    // pos from 0
    char get_string_char(int id, int pos) {
        assert(pos < get_length(id));
        if (pos < id) return s[pos];
        return s[pos + 1];
    }

    void make_dp(int value) {
        dp.reserve(order.size());
        dp.resize(order.size());
        for (auto&& x : dp) x = value;
    }
};

// < 0 for less, = 0 for equal, > 0 for greater
int compare(word_t& a, int id_a, word_t& b, int id_b) {
    int length_a = a.get_length(id_a);
    int length_b = b.get_length(id_b);
    int low = 1, high = min(length_a, length_b), mid, res = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a.get_string_hash(id_a, mid) == b.get_string_hash(id_b, mid)) {
            res = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (res == min(length_a, length_b)) {
        if (length_a < length_b) return -1;
        else if (length_a == length_b) return 0;
        else return 1;
    } else {
        if (a.get_string_char(id_a, res) < b.get_string_char(id_b, res)) return -1;
        else return 1;
    }
}

int n;
vector<word_t> words;
void solve() {
    prepare_hash();
    cin >> n;
    words.resize(n);
    for (auto&& w : words) w.input();
    for (auto&& w : words) w.prepare();

    words[0].make_dp(1);
    for (int i = 1; i < words.size(); i++) {
        auto& w = words[i];
        auto& prev = words[i - 1];
        w.make_dp(0);
        auto& order = w.order;
        auto& prev_order = prev.order;
        auto& dp = w.dp;
        auto& prev_dp = prev.dp;
        int k = 0;
        int64_t sum = 0;
        for (int j = 0; j < order.size(); j++) {
            while ((k < prev_order.size()) && (compare(prev, prev_order[k], w, order[j]) <= 0)) {
                (sum += prev_dp[k]) %= dp_base;
                k++;
            }
            dp[j] = sum;
        }
    }
    int64_t ans = 0;
    for (auto&& x : words.back().dp) (ans += x) %= dp_base;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    if constexpr (MULTI_TEST) cin >> t;
    while (t--) solve();
}