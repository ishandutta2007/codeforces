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
Scanner sc(stdin);
Printer pr(stdout);

struct Nimber64;
Nimber64 mul_naive(Nimber64 l, Nimber64 r);
struct Nimber64 {
    const static V<ull> factor;
    const static array<array<unsigned char, 256>, 256> small;
    const static array<array<array<Nimber64, 256>, 8>, 8> precalc;
    ull v;
    Nimber64() : v(0) {}
    Nimber64(ull _v) : v(_v) {}
    const Nimber64 operator+(Nimber64 r) const {
        return v ^ r.v;
    }
    const Nimber64 operator*(Nimber64 r) const {
        Nimber64 ans;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                ull x = (v >> (8 * i)) % 256;
                ull y = (r.v >> (8 * j)) % 256;
                ans += precalc[i][j][small[x][y]];
            }
        }
        return ans;
    }
    bool operator==(Nimber64 r) const {
        return v == r.v;
    }
    Nimber64& operator+=(Nimber64 r) { return *this = *this + r; }
    Nimber64& operator*=(Nimber64 r) { return *this = *this * r; }

    Nimber64 pow(ull n) const {
        Nimber64 x = *this, r = 1;
        while (n) {
            if (n & 1) r = r * x;
            x = x * x;
            n >>= 1;
        }
        return r;
    }

    ull discrete_logarithm(Nimber64 y) {
        ull rem = 0, mod = 1;
        for (ull p : factor) {
            ull STEP = 1;
            while (STEP * STEP < p) STEP *= 2;
            auto inside = [&](Nimber64 x, Nimber64 y) {
                unordered_map<ull, int> mp;
                Nimber64 big = 1; // x^m
                for (int i = 0; i < int(STEP); i++) {
                    mp[y.v] = i;
                    y *= x;
                    big *= x;
                }
                Nimber64 now = 1;
                for (int step = 0; step < int(p + 10); step += STEP) {
                    now *= big;
                    // check [step + 1, step + STEP]
                    if (mp.find(now.v) != mp.end()) {
                        return (step + STEP) - mp[now.v];
                    }
                }
                return ull(-1);
            };

            ull q = ull(-1) / p;
            ull res = inside((*this).pow(q), y.pow(q));
            if (res == ull(-1)) {
                return ull(-1);
            }
            res %= p;
            // mod p = v
            if (mod == 1) {
                rem = res;
                mod = p;
            } else {
                while (rem % p != res) rem += mod;
                mod *= p;
            }
        }
        return rem;
    }
};
const V<ull> Nimber64::factor = {
    6700417, 65537, 641, 257, 17, 5, 3,
};

Nimber64 mul_naive(Nimber64 l, Nimber64 r) {
    ull a = l.v, b = r.v;
    if (a < b) swap(a, b);
    if (b == 0) return 0;
    if (b == 1) return a;
    int p = 32;
    while (max(a, b) < (1ULL << p)) p /= 2;
    ull power = 1ULL << p;
    if (a >= power && b >= power) {
        Nimber64 ans;
        ans += mul_naive(a % power, b % power);
        ans += mul_naive(a / power, b % power).v * power;
        ans += mul_naive(a % power, b / power).v * power;
        auto x = mul_naive(a / power, b / power);
        ans += x.v * power;
        ans += mul_naive(x.v, power / 2);
        return ans;
    } else {
        return Nimber64(mul_naive(a / power, b).v * power) + mul_naive(a % power, b);
    }
};

const array<array<unsigned char, 256>, 256> Nimber64::small = []() {
    array<array<unsigned char, 256>, 256> small;
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            small[i][j] = (unsigned char)(mul_naive(i, j).v);
        }
    }
    return small;
}();

const array<array<array<Nimber64, 256>, 8>, 8> Nimber64::precalc = []() {
    array<array<array<Nimber64, 256>, 8>, 8> precalc;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 256; k++) {
                precalc[i][j][k] = mul_naive(mul_naive(1ULL << (8 * i), 1ULL << (8 * j)), k);
            }
        }
    }
    return precalc;
}();

int main() {
    int t;
    sc.read(t);
    for (int i = 0; i < t; i++) {
        ull x, y;
        sc.read(x, y);
        Nimber64 a = x, b = y;
        ull c = a.discrete_logarithm(b);
        if (c == ull(-1)) {
            pr.writeln(-1);
        } else {
            assert(a.pow(c) == b);
            pr.writeln(c);
        }
    }
    return 0;
}