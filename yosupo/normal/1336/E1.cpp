//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
//#undef LOCAL




#include <algorithm>

#include <array>

#include <bitset>

#include <cassert>

#include <complex>

#include <cstdio>

#include <cstring>

#include <iostream>

#include <map>

#include <numeric>

#include <queue>

#include <set>

#include <string>

#include <unordered_map>

#include <unordered_set>

#include <vector>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

// bit op
int popcnt(uint x) { return __builtin_popcount(x); }
int popcnt(ull x) { return __builtin_popcountll(x); }
int bsr(uint x) { return 31 - __builtin_clz(x); }
int bsr(ull x) { return 63 - __builtin_clzll(x); }
int bsf(uint x) { return __builtin_ctz(x); }
int bsf(ull x) { return __builtin_ctzll(x); }


template <uint MD> struct ModInt {
    using M = ModInt;
    static constexpr uint get_mod() { return MD; }
    const static M G;
    uint v;
    ModInt(ll _v = 0) { set_v(uint(_v % MD + MD)); }
    M& set_v(uint _v) {
        v = (_v < MD) ? _v : _v - MD;
        return *this;
    }
    explicit operator bool() const { return v != 0; }
    M operator-() const { return M() - *this; }
    M operator+(const M& r) const { return M().set_v(v + r.v); }
    M operator-(const M& r) const { return M().set_v(v + MD - r.v); }
    M operator*(const M& r) const { return M().set_v(uint(ull(v) * r.v % MD)); }
    M operator/(const M& r) const { return *this * r.inv(); }
    M& operator+=(const M& r) { return *this = *this + r; }
    M& operator-=(const M& r) { return *this = *this - r; }
    M& operator*=(const M& r) { return *this = *this * r; }
    M& operator/=(const M& r) { return *this = *this / r; }
    bool operator==(const M& r) const { return v == r.v; }
    M pow(ll n) const {
        M x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    M inv() const { return pow(MD - 2); }
    friend ostream& operator<<(ostream& os, const M& r) { return os << r.v; }
};
// using Mint = ModInt<998244353>;
// template<> const Mint Mint::G = Mint(3);

struct Scanner {
    FILE* fp = nullptr;
    char line[(1 << 15) + 1];
    size_t st = 0, ed = 0;
    void reread() {
        memmove(line, line + st, ed - st);
        ed -= st;
        st = 0;
        ed += fread(line + ed, 1, (1 << 15) - ed, fp);
        line[ed] = '\0';
    }
    bool succ() {
        while (true) {
            if (st == ed) {
                reread();
                if (st == ed) return false;
            }
            while (st != ed && isspace(line[st])) st++;
            if (st != ed) break;
        }
        if (ed - st <= 50) reread();
        return true;
    }
    template <class T, enable_if_t<is_same<T, string>::value, int> = 0>
    bool read_single(T& ref) {
        if (!succ()) return false;
        while (true) {
            size_t sz = 0;
            while (st + sz < ed && !isspace(line[st + sz])) sz++;
            ref.append(line + st, sz);
            st += sz;
            if (!sz || st != ed) break;
            reread();
        }
        return true;
    }
    template <class T, enable_if_t<is_integral<T>::value, int> = 0>
    bool read_single(T& ref) {
        if (!succ()) return false;
        bool neg = false;
        if (line[st] == '-') {
            neg = true;
            st++;
        }
        ref = T(0);
        while (isdigit(line[st])) {
            ref = 10 * ref + (line[st++] - '0');
        }
        if (neg) ref = -ref;
        return true;
    }
    template <class T> bool read_single(V<T>& ref) {
        for (auto& d : ref) {
            if (!read_single(d)) return false;
        }
        return true;
    }
    void read() {}
    template <class H, class... T> void read(H& h, T&... t) {
        bool f = read_single(h);
        assert(f);
        read(t...);
    }
    Scanner(FILE* _fp) : fp(_fp) {}
};

struct Printer {
  public:
    template <bool F = false> void write() {}
    template <bool F = false, class H, class... T>
    void write(const H& h, const T&... t) {
        if (F) write_single(' ');
        write_single(h);
        write<true>(t...);
    }
    template <class... T> void writeln(const T&... t) {
        write(t...);
        write_single('\n');
    }

    Printer(FILE* _fp) : fp(_fp) {}
    ~Printer() { flush(); }

  private:
    static constexpr size_t SIZE = 1 << 15;
    FILE* fp;
    char line[SIZE], small[50];
    size_t pos = 0;
    void flush() {
        fwrite(line, 1, pos, fp);
        pos = 0;
    }
    void write_single(const char& val) {
        if (pos == SIZE) flush();
        line[pos++] = val;
    }
    template <class T, enable_if_t<is_integral<T>::value, int> = 0>
    void write_single(T val) {
        if (pos > (1 << 15) - 50) flush();
        if (val == 0) {
            write_single('0');
            return;
        }
        if (val < 0) {
            write_single('-');
            val = -val; // todo min
        }
        size_t len = 0;
        while (val) {
            small[len++] = char('0' + (val % 10));
            val /= 10;
        }
        for (size_t i = 0; i < len; i++) {
            line[pos + i] = small[len - 1 - i];
        }
        pos += len;
    }
    void write_single(const string& s) {
        for (char c : s) write_single(c);
    }
    void write_single(const char* s) {
        size_t len = strlen(s);
        for (size_t i = 0; i < len; i++) write_single(s[i]);
    }
    template <class T> void write_single(const V<T>& val) {
        auto n = val.size();
        for (size_t i = 0; i < n; i++) {
            if (i) write_single(' ');
            write_single(val[i]);
        }
    }
};
using Mint = ModInt<998244353>;

Scanner sc = Scanner(stdin);
Printer pr = Printer(stdout);

V<Mint> solve(int m, V<ull> v) {
    int n = int(v.size());
    V<Mint> ans(m + 1);
    if (n <= 20) {
        for (uint f = 0; f < (1<<n); f++) {
            ull z = 0;
            for (int i = 0; i < n; i++) {
                if (f & (1 << i)) z ^= v[i];
            }
            ans[popcnt(f) + popcnt(z)] += Mint(1);
        }
    } else {
        int k = m - n;
        VV<Mint> dp(n + 1, V<Mint>(1 << k));
        dp[0][0] = Mint(1);
        for (auto x: v) {
            for (int i = n - 1; i >= 0; i--) {
                for (int j = 0; j < (1 << k); j++) {
                    dp[i + 1][j ^ x] += dp[i][j];
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            for (uint j = 0; j < (1 << k); j++) {
                ans[i + popcnt(j)] += dp[i][j];
            }
        }
    }
    return ans;
}

int main() {
    int n, m;
    sc.read(n, m);
    V<ull> d(m);
    for (int ph = 0; ph < n; ph++) {
        ull a;
        sc.read(a);
        for (int i = m - 1; i >= 0; i--) {
            if (!(a & (1ULL << i))) continue;
            if (d[i] == 0) {
                d[i] = a;
                break;
            } else {
                a ^= d[i];
            }
        }
    }
    for (int ph = 0; ph < 100; ph++) {
        for (int i = 1; i < m; i++) {
            if (d[i] == 0 && d[i - 1]) {
                // swap i, i - 1
                swap(d[i], d[i - 1]);
                for (auto& a: d) {
                    bool f1 = (a >> i) & 1;
                    bool f0 = (a >> (i - 1)) & 1;
                    if (f1) a ^= 3ULL << (i - 1);
                    if (f0) a ^= 3ULL << (i - 1);
                }
            }
        }
    }
    int rnk = 0;
    while (rnk < m && !d[rnk]) rnk++;
    V<ull> base;
    for (int i = rnk; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (d[j] & (1ULL << i)) d[j] ^= d[i];
        }
        base.push_back(d[i] - (d[i] >> rnk << rnk));
    }
    Mint off = Mint(2).pow(n - (m - rnk));
    V<Mint> ans = solve(m, base);
    for (auto x: ans) {
        pr.write((x * off).v);
        pr.write(' ');
    }
    pr.writeln();
}