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

uint normalize(uint p) {
    while (true) {
        bool update = false;
        for (int i = 0; i < 32; i++) {
            if (!(p & (1U << i))) continue;
            for (int j = i + 1; j < 32; j++) {
                if (!(p & (1U << j))) continue;
                int k = i ^ j;
                if (p & (1U << k)) continue;
                update = true;
                p |= (1U << k);
            }
        }
        if (!update) break;
    }
    return p;
}

uint merge(uint p, int x) {
    if (p == 1 || x == 0 || p & (1U << x)) return 1;
    return normalize(p | (1U << x));
}

uint merge2(uint p, uint q) {
    if (p == 1 || q == 1) return 1;
    if (p & q) return 1;
    return normalize(p | q);
}

set<uint> st;
void dfs(uint p) {
    if (st.count(p)) return;
    st.insert(p);
    for (int i = 0; i < 32; i++) {
        if (p & (1U << i)) continue;
        dfs(merge(p, i));
    }
}

int M;
V<array<int, 32>> merge_to;
VV<int> merge_two;
void init() {
    dfs(0);
                  ;
    V<uint> vs = {st.begin(), st.end()};
    M = int(st.size());
    merge_to.resize(M);
    merge_two = VV<int>(M, V<int>(M));
    auto get_i = [&](uint u) {
        return int(lower_bound(vs.begin(), vs.end(), u) - vs.begin());
    };
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < 32; j++) {
            merge_to[i][j] = get_i(merge(vs[i], j));
        }
        for (int j = 0; j < M; j++) {
            merge_two[i][j] = get_i(merge2(vs[i], vs[j]));
        }
    }
}

int main() {
    init();

    int n, m;
    sc.read(n, m);
    V<int> a(m), b(m), w(m);
    for (int i = 0; i < m; i++) {
        sc.read(a[i], b[i], w[i]); a[i]--; b[i]--;
        if (a[i] > b[i]) swap(a[i], b[i]);
    }


    V<int> ones(n, -1);
    for (int i = 0; i < m; i++) {
        if (a[i] == 0) ones[b[i]] = w[i];
    }
    struct E {
        int to, dist;
    };
    VV<E> g(n);
    for (int i = 0; i < m; i++) {
        if (a[i] == 0) continue;
        if (ones[a[i]] != -1 && ones[b[i]] != -1) continue;
        g[a[i]].push_back({b[i], w[i]});
        g[b[i]].push_back({a[i], w[i]});
    }

    V<int> bases(n, 0);
    V<int> he(n, -1);
    V<int> dps(n, 0);
    auto dfs = [&](auto self, int r, int p) -> void {
        for (auto e: g[p]) {
            int d = e.to;
            if (he[d] == -1) {
                dps[d] = dps[p] + 1;
                he[d] = he[p] ^ e.dist;
                self(self, r, d);
            } else if (dps[p] < dps[d]) {
                //cycle
                int ed = he[d] ^ he[p] ^ e.dist;
                             ;
                                                     ;
                bases[r] = merge_to[bases[r]][he[d] ^ he[p] ^ e.dist];
            }
        }
    };
    for (int i = 0; i < n; i++) {
        if (ones[i] != -1) {
            he[i] = 0;
            dfs(dfs, i, i);
        }
    }

    V<Mint> dp(M);
    dp[0] = Mint(1);
    for (int ph = 0; ph < m; ph++) {
        if (ones[a[ph]] != -1 && ones[b[ph]] != -1) {
            //bridge
            V<Mint> ndp = dp; // no use
            // use one
            int bc = merge_two[bases[a[ph]]][bases[b[ph]]];
            for (int i = 0; i < M; i++) {
                ndp[merge_two[bc][i]] += Mint(2) * dp[i];
            }
            // both
            bc = merge_to[bc][ones[a[ph]] ^ ones[b[ph]] ^ w[ph]];
            for (int i = 0; i < M; i++) {
                ndp[merge_two[bc][i]] += dp[i];
            }
            dp = ndp;
            ones[a[ph]] = ones[b[ph]] = -1;
                                        ;
        }
    }
    for (int i = 0; i < n; i++) {
        if (ones[i] == -1) continue;
                               ;
        V<Mint> ndp = dp;
        int ba = bases[i];
        for (int j = 0; j < M; j++) {
            ndp[merge_two[ba][j]] += dp[j];
        }
        dp = ndp;
    }

    Mint sm = 0;
    for (int i = 0; i < M; i++) {
        if (i == 1) continue;
        sm += dp[i];
    }
    pr.writeln(sm.v);
    return 0;
}