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


template <uint MD> struct ModInt {
    using M = ModInt;
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

using Mint = ModInt<TEN(9) + 7>;
Scanner sc = Scanner(stdin);
Printer pr = Printer(stdout);

int main() {
    int n, m;
    sc.read(n, m);
    VV<int> grass(n);
    for (int i = 0; i < n; i++) {
        int a;
        sc.read(a); a--;
        grass[a].push_back(i);
    }
    VV<int> cows(n);
    for (int i = 0; i < m; i++) {
        int f, h;
        sc.read(f, h); f--;
        cows[f].push_back(h);
    }

    using P = pair<int, Mint>;
    V<P> dp0(n + 1, P(0, Mint(1)));
    V<P> dp1(n, P(0, Mint(-1)));
    auto add = [&](P a, P b) {
        if (a.first > b.first) {
            return a;
        }
        if (a.first < b.first) {
            return b;
        }
        return P(a.first, a.second + b.second);
    };
    auto mrg = [&](P a, P b) {
        return P(a.first + b.first, a.second * b.second);
    };
    auto solve = [&](V<int> gr, V<int> cw) {
                   ;
        // non-use
        V<P> ndp0 = dp0;
        V<P> ndp1 = dp1;

        V<int> sml(n + 1), smr(n + 1);
        for (int d: cw) {
            if (d > int(gr.size())) continue;
            sml[gr[d - 1] + 1]++;
            smr[gr[int(gr.size()) - d]]++;
        }
        for (int i = 1; i <= n; i++) sml[i] += sml[i - 1];
        for (int i = n - 1; i >= 0; i--) smr[i] += smr[i + 1];
                     ;
        // single-use(dp0)
        for (int i = 0; i <= n; i++) {
            if (smr[i]) ndp0[i] = add(ndp0[i], mrg(dp0[i], P(1, smr[i])));
            if (sml[i]) ndp0[i] = add(ndp0[i], mrg(dp0[i], P(1, sml[i])));
        }
        // single-use(dp1)
        for (int i = 0; i < n; i++) {
            if (smr[i + 1]) ndp1[i] = add(ndp1[i], mrg(dp1[i], P(1, smr[i + 1])));
            if (sml[i]) ndp1[i] = add(ndp1[i], mrg(dp1[i], P(1, sml[i])));
        }

        // twice-use(dp0)
        for (int i = 1; i < n; i++) {
            int u = min(sml[i], smr[i]);
            int x = sml[i] * smr[i] - u;
            if (x) {
                ndp0[i] = add(ndp0[i], mrg(dp0[i], P(2, x)));
            }
        }
        // twice-use(dp1)
        for (int i = 1; i < n - 1; i++) {
            int u = min(sml[i], smr[i + 1]);
            int x = sml[i] * smr[i + 1] - u;
            if (x) {
                ndp1[i] = add(ndp1[i], mrg(dp1[i], P(2, x)));
            }
        }
        dp0 = ndp0;
        dp1 = ndp1;
    };

    for (int i = 0; i < n; i++) {
        solve(grass[i], cows[i]);
    }
            ;
            ;
    P ans = P(-1, Mint(0));
    for (auto x: dp0) {
        ans = add(ans, x);
    }
    for (auto x: dp1) {
        ans = add(ans, x);
    }

    pr.writeln(ans.first, ans.second.v);

    return 0;
}