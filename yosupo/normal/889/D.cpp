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



#include <unistd.h>

struct Scanner {
    int fd = -1;
    char line[(1 << 15) + 1];
    size_t st = 0, ed = 0;
    void reread() {
        memmove(line, line + st, ed - st);
        ed -= st;
        st = 0;
        ed += ::read(fd, line + ed, (1 << 15) - ed);
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
        if (ed - st <= 50) {
            bool sep = false;
            for (size_t i = st; i < ed; i++) {
                if (isspace(line[i])) {
                    sep = true;
                    break;
                }
            }
            if (!sep) reread();
        }
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
            ref = 10 * ref + (line[st++] & 0xf);
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
    Scanner(FILE* fp) : fd(fileno(fp)) {}
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
            small[len++] = char(0x30 | (val % 10));
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



// bit op
int popcnt(uint x) { return __builtin_popcount(x); }
int popcnt(ull x) { return __builtin_popcountll(x); }
int bsr(uint x) { return 31 - __builtin_clz(x); }
int bsr(ull x) { return 63 - __builtin_clzll(x); }
int bsf(uint x) { return __builtin_ctz(x); }
int bsf(ull x) { return __builtin_ctzll(x); }

//binary gcd
ll gcd(ll _a, ll _b) {
    ull a = abs(_a), b = abs(_b);
    if (a == 0) return b;
    if (b == 0) return a;
    int shift = bsf(a|b);
    a >>= bsf(a);
    do {
        b >>= bsf(b);
        if (a > b) swap(a, b);
        b -= a;
    } while (b);
    return (a << shift);
}

/// g:gcd(a, b), ax+by=g
struct EG { ll g, x, y; };
EG ext_gcd(ll a, ll b) {
    if (b == 0) {
        if (a >= 0) return EG{a, 1, 0};
        else return EG{-a, -1, 0};
    } else {
        auto e = ext_gcd(b, a % b);
        return EG{e.g, e.y, e.x - a / b * e.y};
    }
}


ll inv_mod(ll x, ll md) {
    auto z = ext_gcd(x, md).x;
    return (z % md + md) % md;
}

template<class T, class U>
T pow_mod(T x, U n, T md) {
    T r = 1 % md;
    x %= md;
    while (n) {
        if (n & 1) r = (r * x) % md;
        x = (x * x) % md;
        n >>= 1;
    }
    return r;
}

// (rem, mod)
pair<ll, ll> crt(const V<ll>& b, const V<ll>& c) {
    int n = int(b.size());
    ll r = 0, m = 1;
    for (int i = 0; i < n; i++) {
        auto eg = ext_gcd(m, c[i]);
        ll g = eg.g, im = eg.x;
        if ((b[i] - r) % g) return {0, -1};
        ll tmp = (b[i] - r) / g * im % (c[i] / g);
        r += m * tmp;
        m *= c[i] / g;
    }
    return {(r % m + m) % m, m};
}

Scanner sc = Scanner(stdin);
Printer pr = Printer(stdout);

struct P {
    ll x, y;
    bool operator<(const P& r) const {
        return tie(x, y) < tie(r.x, r.y);
    }
    bool operator==(const P& r) const {
        return x == r.x && y == r.y;
    }
    bool operator!=(const P& r) const {
        return !(*this == r);
    }
};
ostream& operator<<(ostream& os, const P& p) {
    return os << "P(" << p.x << ", " << p.y << ")";
}

int main() {
    int n;
    sc.read(n);

    V<P> v(n);
    for (int i = 0; i < n; i++) {
        ll x, y;
        sc.read(x, y);
        x += TEN(6);
        y += TEN(6);
        x *= 2 * n;
        y *= 2 * n;
        v[i] = P{x, y};
    }

    {
        ll sx = 0, sy = 0;
        for (auto p: v) {
            sx += p.x;
            sy += p.y;
        }
        sx /= n;
        sy /= n;
        for (auto& p: v) {
            p.x -= sx;
            p.y -= sy;
        }
    }

    {
        multiset<P> st;
        for (auto p : v) {
            if (p == P{0, 0}) continue;
            auto it = st.find(P{-p.x, -p.y});
            if (it != st.end()) {
                st.erase(it);
                continue;
            }
            st.insert(p);
        }
        v = V<P>(st.begin(), st.end());
    }

    n = int(v.size());
          ;

    if (v.empty()) {
        pr.writeln(-1);
        return 0;
    }

    V<P> arg;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            auto pi = v[i], pj = v[j];
            P mid = P{(pi.x + pj.x) / 2, (pi.y + pj.y) / 2};
            assert((mid != P{0, 0}));
            ll g = gcd(mid.x, mid.y);
            mid.x /= g;
            mid.y /= g;
            if (mid < P{0, 0}) {
                mid.x *= -1;
                mid.y *= -1;
            }
            arg.push_back(mid);
        }
    }
    sort(arg.begin(), arg.end());

    {
        V<P> true_arg;
        int lw = 0;
        while (lw < int(arg.size())) {
            int up = lw;
            while (up < int(arg.size()) && arg[lw] == arg[up]) up++;
            if (up - lw >= n / 2) true_arg.push_back(arg[lw]);
            lw = up;
        }
        arg = true_arg;
    }
            ;

    int ans = 0;

    for (auto ar: arg) {
        V<ll> val;
        for (auto p: v) {
            val.push_back(ar.x * p.y - ar.y * p.x);
        }
        sort(val.begin(), val.end());
                    ;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (val[i] + val[n - 1 - i]) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
    }
    pr.writeln(ans);
    return 0;
}