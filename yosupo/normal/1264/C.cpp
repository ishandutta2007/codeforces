# 1 "main.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "main.cpp"



# 1 "/Users/yosupo/Programs/Algorithm/expander/dummy_include/bits/stdc++.h" 1
       

#include <bits/stdc++.h>
# 5 "main.cpp" 2
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

# 1 "/Users/yosupo/Programs/Algorithm/src/util/fast_io.h" 1
       
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
            succ();
            size_t sz = 1;
            while (st + sz < ed && !isspace(line[st + sz])) sz++;
            ref.append(line + st, sz);
            st += sz;
            if (st != ed) break;
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
    template <class T, enable_if_t<is_same<T, string>::value, int> = 0>
    void write_single(const T& val) {
        for (char c : val) write_single(c);
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
            val = -val;
        }
        size_t len = 0;
        while (val) {
            small[len++] = char('0' + (val % 10));
            val /= 10;
        }
        reverse(small, small + len);
        memcpy(line + pos, small, len);
        pos += len;
    }
    template <class T> void write_single(const V<T>& val) {
        auto n = val.size();
        for (size_t i = 0; i < n; i++) {
            if (i) write_single(' ');
            write_single(val[i]);
        }
    }
};
# 15 "main.cpp" 2
# 40 "main.cpp"
template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    return os << "P(" << p.first << ", " << p.second << ")";
}

template <class T> ostream& operator<<(ostream& os, const V<T>& v) {
    os << "[";
    for (auto d : v) os << d << ", ";
    return os << "]";
}

# 1 "/Users/yosupo/Programs/Algorithm/src/math/modint.h" 1
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
# 52 "main.cpp" 2
using Mint = ModInt<998244353>;

int main() {
    Scanner sc = Scanner(stdin);
    Printer pr = Printer(stdout);
    int n, q;
    sc.read(n, q);
    V<Mint> a(n);
    {
        Mint i100 = Mint(100).inv();
        for (int i = 0; i < n; i++) {
            int x;
            sc.read(x);
            a[i] = Mint(x) * i100;
        }
    }

    V<Mint> mul(n + 1), mul_sm(n + 1);
    mul[0] = Mint(1);
    mul_sm[0] = Mint(0);
    for (int i = 0; i < n; i++) {
        mul[i + 1] = mul[i] * a[i];
        mul_sm[i + 1] = mul_sm[i] + mul[i];
    }

    Mint ans = Mint(0);
    auto effect = [&](int l, int r, Mint f) {
        Mint res = mul_sm[r] - mul_sm[l];
        res /= mul[r];
        ans += f * res;
    };

    effect(0, n, 1);
    set<int> s;
    s.insert(0); s.insert(n);
    for (int tm = 0; tm < q; tm++) {
        int p;
        sc.read(p); p--;
        if (s.count(p)) {
            int bk = *prev(s.lower_bound(p));
            int nx = *next(s.lower_bound(p));
            effect(bk, p, Mint(-1));
            effect(p, nx, Mint(-1));
            effect(bk, nx, Mint(1));
            s.erase(p);
        } else {
            s.insert(p);
            int bk = *prev(s.lower_bound(p));
            int nx = *next(s.lower_bound(p));
            effect(bk, nx, Mint(-1));
            effect(bk, p, Mint(1));
            effect(p, nx, Mint(1));
        }
        pr.writeln(ans.v);
    }
    return 0;
}