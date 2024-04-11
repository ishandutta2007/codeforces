//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
//#undef LOCAL





#include <array>

#include <cassert>

#include <chrono>

#include <cstdint>

#include <type_traits>



namespace yosupo {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

} // namespace internal

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) { return __builtin_ctz(n); }
// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned long n) { return __builtin_ctzl(n); }
// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned long long n) { return __builtin_ctzll(n); }

// @param n `1 <= n`
// @return maximum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsr(unsigned int n) {
    return 8 * (int)sizeof(unsigned int) - 1 - __builtin_clz(n);
}
// @param n `1 <= n`
// @return maximum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsr(unsigned long n) {
    return 8 * (int)sizeof(unsigned long) - 1 - __builtin_clzl(n);
}
// @param n `1 <= n`
// @return maximum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsr(unsigned long long n) {
    return 8 * (int)sizeof(unsigned long long) - 1 - __builtin_clzll(n);
}

} // namespace yosupo

namespace yosupo {

struct Xoshiro256StarStar {
  public:
    using result_type = uint64_t;
    Xoshiro256StarStar() : Xoshiro256StarStar(0) {}
    explicit Xoshiro256StarStar(uint64_t seed) {
        // use splitmix64
        // Reference: http://xoshiro.di.unimi.it/splitmix64.c
        for (int i = 0; i < 4; i++) {
            uint64_t z = (seed += 0x9e3779b97f4a7c15);
            z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
            z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
            s[i] = z ^ (z >> 31);
        }
    }

    static constexpr result_type min() { return 0; }
    static constexpr result_type max() { return -1; }

    result_type operator()() {
        const uint64_t result_starstar = rotl(s[1] * 5, 7) * 9;

        const uint64_t t = s[1] << 17;

        s[2] ^= s[0];
        s[3] ^= s[1];
        s[1] ^= s[2];
        s[0] ^= s[3];

        s[2] ^= t;

        s[3] = rotl(s[3], 45);

        return result_starstar;
    }

  private:
    // Use xoshiro256**
    // Refereces: http://xoshiro.di.unimi.it/xoshiro256starstar.c
    static uint64_t rotl(const uint64_t x, int k) {
        return (x << k) | (x >> (64 - k));
    }

    std::array<uint64_t, 4> s;
};

namespace internal {

// random choice from [0, upper]
template <class G> uint64_t uniform(uint64_t upper, G& gen) {
    static_assert(std::is_same<uint64_t, typename G::result_type>::value, "");
    static_assert(G::min() == 0, "");
    static_assert(G::max() == uint64_t(-1), "");
    if (!(upper & (upper + 1))) {
        // b = 00..0011..11
        return gen() & upper;
    }
    int log = bsr(upper);
    uint64_t mask = (log == 63) ? ~0ULL : (1ULL << (log + 1)) - 1;
    while (true) {
        uint64_t r = gen() & mask;
        if (r <= upper) return r;
    }
}

} // namespace internal

Xoshiro256StarStar& global_gen() {
    static Xoshiro256StarStar gen(
        std::chrono::steady_clock::now().time_since_epoch().count());
    return gen;
}

template <class T, class G> T uniform(T lower, T upper, G& gen) {
    return T(lower + internal::uniform(uint64_t(upper - lower), gen));
}
template <class T> T uniform(T lower, T upper) {
    return uniform(lower, upper, global_gen());
}

template <class G> bool uniform_bool(G& gen) {
    return internal::uniform(1, gen) == 1;
}
bool uniform_bool() { return uniform_bool(global_gen()); }

template <class T, class G>
std::pair<T, T> uniform_pair(T lower, T upper, G& gen) {
    assert(upper - lower >= 1);
    T a, b;
    do {
        a = uniform(lower, upper, gen);
        b = uniform(lower, upper, gen);
    } while (a == b);
    if (a > b) std::swap(a, b);
    return {a, b};
}
template <class T> std::pair<T, T> uniform_pair(T lower, T upper) {
    return uniform_pair(lower, upper, global_gen());
}

} // namespace yosupo
using namespace yosupo;




#include <algorithm>


#include <bitset>


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
    template <class T, enable_if_t<is_integral<T>::value>* = nullptr>
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
    int read_unsafe() { return 0; }
    template <class H, class... T> int read_unsafe(H& h, T&... t) {
        bool f = read_single(h);
        if (!f) return 0;
        return 1 + read_unsafe(t...);
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
    template <class T, enable_if_t<is_integral<T>::value>* = nullptr>
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
    void write_single(__int128 val) {
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

Scanner sc = Scanner(stdin);
Printer pr = Printer(stdout);

using P = pair<int, bool>;
V<P> gen_a(int n) {
    V<P> a(6 * n);
    V<int> b(6 * n);
    for (int i = 0; i < 6 * n; i++) {
        a[i] = {i, false};
        b[i] = i;
    }
    for (int i = 0; i < 2 * n; i++) {
        int x = uniform(0, int(b.size()) - 3);
        if (i % 2 == 0) {
            for (int j = 0; j < 3; j++) {
                a[b[x + j]].second = true;
            }
        }
        b.erase(b.begin() + x, b.begin() + x + 3);
    }
    return a;
}

struct T {
    bool type;
    int x, y, z;
};

V<T> solve(int n, V<P> a) {
    V<T> evs;
    while (a.size()) {
        int m = int(a.size());
        bool f = false;
        for (int i = 0; i + 2 < m; i++) {
            if (a[i].second && a[i + 1].second && a[i + 2].second) {
                evs.push_back({true, a[i].first, a[i + 1].first, a[i + 2].first});
                a.erase(a.begin() + i, a.begin() + i + 3);
                f = true;
                break;
            }
        }
        if (f) continue;
        int mi1 = TEN(9), ma1 = -1;
        for (int i = 0; i < m; i++) {
            if (a[i].second) {
                mi1 = min(mi1, i);
                ma1 = max(ma1, i);
            }
        }
        for (int i = mi1 + 1; i + 2 < ma1; i++) {
            if (!a[i].second && !a[i + 1].second && !a[i + 2].second) {
                evs.push_back({false, a[i].first, a[i + 1].first, a[i + 2].first});
                a.erase(a.begin() + i, a.begin() + i + 3);
                f = true;
                break;
            }
        }
        if (f) continue;
        for (int i = 0; i + 2 < m; i++) {
            if (!a[i].second && !a[i + 1].second && !a[i + 2].second) {
                evs.push_back({false, a[i].first, a[i + 1].first, a[i + 2].first});
                a.erase(a.begin() + i, a.begin() + i + 3);
                f = true;
                break;
            }
        }
        assert(f);
    }

    /*for (auto e: evs) {
        dbg(e.type, e.x, e.y, e.z);
    }*/
    assert(!evs.back().type);

    reverse(evs.begin(), evs.end());
    for (int i = 0; i < 2 * n; i++) {
        bool expect = (i % 2) == 1;
        if (evs[i].type == expect) continue;
        int j = i;
        while (evs[j].type != expect) j++;
        // j -> i
        for (int k = j - 2; k >= i - 1; k--) {
            // (k, k + 1, k + 2) = (F F T) or (T T F)
            // swap(k + 1, k + 2) 
            auto e0 = evs[k], e1 = evs[k + 1], e2 = evs[k + 2];
            //dbg(k, k + 1, k + 2);
            assert(e0.type == e1.type && e1.type != e2.type);
            bool f = e0.type;
            V<int> vs = {e0.x, e0.y, e0.z, e1.x, e1.y, e1.z};
            sort(vs.begin(), vs.end());
            e0 = {f, vs[0], vs[1], vs[2]};
            e1 = {f, vs[3], vs[4], vs[5]};

            if (e1.x < e2.x && e2.z < e1.z) swap(e0, e1);

            evs[k] = e0;
            evs[k + 1] = e2;
            evs[k + 2] = e1;
        }
    }
    reverse(evs.begin(), evs.end());

    return evs;
}


int main() {
    /*for (int ph = 0; ph < 100000; ph++) {
        auto res = solve();
    }*/

    int n;
    sc.read(n);

    V<P> a(6 * n);
    for (int i = 0; i < 6 * n; i++) {
        a[i].first = i;
    }
    for (int i = 0; i < 3 * n; i++) {
        int x;
        sc.read(x);
        x--;
        a[x].second = true;
    }

    auto evs = solve(n, a);

    for (auto e: evs) {
        pr.writeln(e.x + 1, e.y + 1, e.z + 1);
    }
}