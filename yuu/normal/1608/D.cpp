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

// necessary condition: # of WW and # of BB must be equal
// if they both appear 0 time, only 1 type of WB or BW is allowed

namespace {
// https://github.com/chemthan/chemthan/blob/master/Math/NTT.cpp
// Really need to write my own stuff
template <const int mod, const int maxf>
struct NTT {
    int rts[maxf + 1];
    int bitrev[maxf];
    int iv[maxf + 1];

    int fpow(int a, int k) {
        if (!k) return 1;
        int res = a, tmp = a;
        k--;
        while (k) {
            if (k & 1) {
                res = (long long)res * tmp % mod;
            }
            tmp = (long long)tmp * tmp % mod;
            k >>= 1;
        }
        return res;
    }
    int prt() {
        vector<int> dvs;
        for (int i = 2; i * i < mod; i++) {
            if ((mod - 1) % i) continue;
            dvs.push_back(i);
            if (i * i != mod - 1) dvs.push_back((mod - 1) / i);
        }
        for (int i = 2; i < mod; i++) {
            int flag = 1;
            for (int j = 0; j < dvs.size(); j++) {
                if (fpow(i, dvs[j]) == 1) {
                    flag = 0;
                    break;
                }
            }
            if (flag) return i;
        }
        assert(0);
        return -1;
    }
    NTT() {
        int k = 0;
        while ((1 << k) < maxf) k++;
        bitrev[0] = 0;
        for (int i = 1; i < maxf; i++) {
            bitrev[i] = bitrev[i >> 1] >> 1 | ((i & 1) << k - 1);
        }
        int pw = fpow(prt(), (mod - 1) / maxf);
        rts[0] = 1;
        for (int i = 1; i <= maxf; i++) {
            rts[i] = (long long)rts[i - 1] * pw % mod;
        }
        for (int i = 1; i <= maxf; i <<= 1) {
            iv[i] = fpow(i, mod - 2);
        }
    }
    void dft(int a[], int n, int sign) {
        int d = 0;
        while ((1 << d) * n != maxf) d++;
        for (int i = 0; i < n; i++) {
            if (i < (bitrev[i] >> d)) {
                swap(a[i], a[bitrev[i] >> d]);
            }
        }
        for (int len = 2; len <= n; len <<= 1) {
            int delta = maxf / len * sign;
            for (int i = 0; i < n; i += len) {
                int* w = sign > 0 ? rts : rts + maxf;
                for (int k = 0; k + k < len; k++) {
                    int &a1 = a[i + k + (len >> 1)], &a2 = a[i + k];
                    int t = (long long)*w * a1 % mod;
                    a1 = a2 - t;
                    a2 = a2 + t;
                    a1 += a1 < 0 ? mod : 0;
                    a2 -= a2 >= mod ? mod : 0;
                    w += delta;
                }
            }
        }
        if (sign < 0) {
            int in = iv[n];
            for (int i = 0; i < n; i++) {
                a[i] = (long long)a[i] * in % mod;
            }
        }
    }
    void multiply(int a[], int b[], int na, int nb, int c[]) {
        static int fa[maxf], fb[maxf];
        int n = na + nb - 1;
        while (n != (n & -n)) n += n & -n;
        for (int i = 0; i < n; i++) fa[i] = fb[i] = 0;
        for (int i = 0; i < na; i++) fa[i] = a[i];
        for (int i = 0; i < nb; i++) fb[i] = b[i];
        dft(fa, n, 1), dft(fb, n, 1);
        for (int i = 0; i < n; i++) fa[i] = (long long)fa[i] * fb[i] % mod;
        dft(fa, n, -1);
        for (int i = 0; i < n; i++) c[i] = fa[i];
    }
    vector<int> multiply(vector<int> a, vector<int> b) {
        static int fa[maxf], fb[maxf], fc[maxf];
        int na = a.size(), nb = b.size();
        for (int i = 0; i < na; i++) fa[i] = a[i];
        for (int i = 0; i < nb; i++) fb[i] = b[i];
        multiply(fa, fb, na, nb, fc);
        int k = na + nb - 1;
        vector<int> res(k);
        for (int i = 0; i < k; i++) res[i] = fc[i];
        return res;
    }
};
}  // namespace

int n;
int cnt[3][3];
int char_val[256];
constexpr int base = 998244353;  // 2^20 * 476 + 1
NTT<base, 1 << 18> ntt;
int way_00[1 << 18];
int way_11[1 << 18];
int ntt_res[1 << 18];
int64_t way_22[1 << 18];

namespace {
int64_t f[200001];
int64_t r[200001];
int64_t p2[200001];

int64_t power(int64_t a, int64_t x) {
    int64_t res = 1;
    while (x) {
        if (x % 2) (res *= a) %= base;
        (a *= a) %= base;
        x /= 2;
    }
    return res;
}

void prepare() {
    f[0] = 1;
    for (int i = 1; i <= 200000; i++) (f[i] = f[i - 1] * i) %= base;
    r[200000] = power(f[200000], base - 2);
    for (int i = 200000; i >= 1; i--) (r[i - 1] = r[i] * i) %= base;
    p2[0] = 1;
    for (int i = 1; i <= 200000; i++) (p2[i] = p2[i - 1] + p2[i - 1]) %= base;
}

int64_t C(int n, int k) {
    if (n < k) return 0;
    return ((f[n] * r[k]) % base * r[n - k]) % base;
}
}  // namespace

void solve() {
    prepare();
    cin >> n;
    char_val['W'] = 0;
    char_val['B'] = 1;
    char_val['?'] = 2;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        cnt[char_val[s[0]]][char_val[s[1]]]++;
    }
    int can_make_00 = cnt[0][2] + cnt[2][0];
    for (int i = 0; i <= can_make_00; i++) way_00[i + cnt[0][0]] = C(can_make_00, i);
    int can_make_11 = cnt[1][2] + cnt[2][1];
    for (int i = 0; i <= can_make_11; i++) way_11[n - i - cnt[1][1]] = C(can_make_11, i);
    ntt.multiply(way_00, way_11, n + 1, n + 1, ntt_res);
    const int k = cnt[2][2];
    for (int i = 0; i <= k * 2; i++) way_22[i] = C(k * 2, i);
    int64_t ans = 0;
    for (int i = 0; i <= n * 2; i++) {
        if (i == n) ntt_res[i] -= way_00[0] * way_11[n];  // must always have at least 1 pair of 00 and 11
        if (ntt_res[i] == 0) continue;
        int defecit = n - i;
        if (abs(defecit) > k) continue;
        (ans += way_22[k + defecit] * ntt_res[i]) %= base;
    }
    if (way_00[0] * way_11[n]) {
        // can start with 0 of both pair
        if (cnt[2][2]) {
            // equal distribution to have at least 1 pair, since this was not calculated above
            for (int i = 1; i * 2 <= k; i++) {
                (ans += (C(cnt[2][2], i) * C(cnt[2][2] - i, i)) % base * p2[cnt[2][2] - i * 2]) %= base;
            }
        }
        // have only of 01 or 10
        assert(cnt[0][0] == 0);
        assert(cnt[1][1] == 0);
        if ((cnt[0][1] == 0) && (cnt[0][2] == 0) && (cnt[2][1] == 0)) (ans += 1) %= base;
        if ((cnt[1][0] == 0) && (cnt[2][0] == 0) && (cnt[1][2] == 0)) (ans += 1) %= base;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    if constexpr (MULTI_TEST) cin >> t;
    while (t--) solve();
}