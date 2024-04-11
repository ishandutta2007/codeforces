#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2")
//#undef LOCAL


#include <unistd.h>
#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
#include <cstring>
#include <sstream>
#include <string>
#include <type_traits>
#include <vector>


namespace yosupo {

namespace internal {

int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

}  // namespace internal

int bsf(unsigned int n) { return __builtin_ctz(n); }
int bsf(unsigned long n) { return __builtin_ctzl(n); }
int bsf(unsigned long long n) { return __builtin_ctzll(n); }
int bsf(unsigned __int128 n) {
    unsigned long long low = (unsigned long long)(n);
    unsigned long long high = (unsigned long long)(n >> 64);
    return low ? __builtin_ctzll(low) : 64 + __builtin_ctzll(high);
}

int bsr(unsigned int n) {
    return 8 * (int)sizeof(unsigned int) - 1 - __builtin_clz(n);
}
int bsr(unsigned long n) {
    return 8 * (int)sizeof(unsigned long) - 1 - __builtin_clzl(n);
}
int bsr(unsigned long long n) {
    return 8 * (int)sizeof(unsigned long long) - 1 - __builtin_clzll(n);
}
int bsr(unsigned __int128 n) {
    unsigned long long low = (unsigned long long)(n);
    unsigned long long high = (unsigned long long)(n >> 64);
    return high ? 127 - __builtin_clzll(high) : 63 - __builtin_ctzll(low);
}

int popcnt(unsigned int n) { return __builtin_popcount(n); }
int popcnt(unsigned long n) { return __builtin_popcountl(n); }
int popcnt(unsigned long long n) { return __builtin_popcountll(n); }

}  // namespace yosupo

#include <cassert>
#include <numeric>
#include <type_traits>

namespace yosupo {

namespace internal {

template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral =
    typename std::conditional<std::is_integral<T>::value ||
                                  internal::is_signed_int128<T>::value ||
                                  internal::is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                 std::is_signed<T>::value) ||
                                                    is_signed_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value,
    make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value,
                              std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;

template <class T>
using is_integral_t = std::enable_if_t<is_integral<T>::value>;

template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

}  // namespace internal

}  // namespace yosupo

namespace yosupo {

struct Scanner {
  public:
    Scanner(const Scanner&) = delete;
    Scanner& operator=(const Scanner&) = delete;

    Scanner(FILE* fp) : fd(fileno(fp)) {}

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

    int close() { return ::close(fd); }

  private:
    static constexpr size_t SIZE = 1 << 15;

    int fd = -1;
    std::array<char, SIZE> line;
    size_t st = 0, ed = 0;
    bool eof = false;

    bool read_single(std::string& ref) {
        if (!skip_space()) return false;
        ref = "";
        while (true) {
            char c = top();
            if (c <= ' ') break;
            ref += c;
            st++;
        }
        return true;
    }
    bool read_single(double& ref) {
        std::string s;
        if (!read_single(s)) return false;
        ref = std::stod(s);
        return true;
    }

    template <class T,
              std::enable_if_t<std::is_same<T, char>::value>* = nullptr>
    bool read_single(T& ref) {
        if (!skip_space(50)) return false;
        ref = top();
        st++;
        return true;
    }

    template <class T,
              internal::is_signed_int_t<T>* = nullptr,
              std::enable_if_t<!std::is_same<T, char>::value>* = nullptr>
    bool read_single(T& sref) {
        using U = internal::to_unsigned_t<T>;
        if (!skip_space(50)) return false;
        bool neg = false;
        if (line[st] == '-') {
            neg = true;
            st++;
        }
        U ref = 0;
        do {
            ref = 10 * ref + (line[st++] & 0x0f);
        } while (line[st] >= '0');
        sref = neg ? -ref : ref;
        return true;
    }
    template <class U,
              internal::is_unsigned_int_t<U>* = nullptr,
              std::enable_if_t<!std::is_same<U, char>::value>* = nullptr>
    bool read_single(U& ref) {
        if (!skip_space(50)) return false;
        ref = 0;
        do {
            ref = 10 * ref + (line[st++] & 0x0f);
        } while (line[st] >= '0');
        return true;
    }

    bool reread() {
        if (ed - st >= 50) return true;
        if (st > SIZE / 2) {
            std::memmove(line.data(), line.data() + st, ed - st);
            ed -= st;
            st = 0;
        }
        if (eof) return false;
        auto u = ::read(fd, line.data() + ed, SIZE - ed);
        if (u == 0) {
            eof = true;
            line[ed] = '\0';
            u = 1;
        }
        ed += u;
        return true;
    }

    char top() {
        if (st == ed) {
            bool f = reread();
            assert(f);
        }
        return line[st];
    }

    bool skip_space(unsigned int token_len = 0) {
        while (true) {
            while (st != ed && line[st] <= ' ') st++;
            if (ed - st > token_len) return true;
            for (auto i = st; i < ed; i++) {
                if (line[i] <= ' ') return true;
            }
            if (!reread()) return false;
        }
    }
};

struct Printer {
  public:
    template <char sep = ' ', bool F = false> void write() {}
    template <char sep = ' ', bool F = false, class H, class... T>
    void write(const H& h, const T&... t) {
        if (F) write_single(sep);
        write_single(h);
        write<true>(t...);
    }
    template <char sep = ' ', class... T> void writeln(const T&... t) {
        write<sep>(t...);
        write_single('\n');
    }

    Printer(FILE* _fp) : fd(fileno(_fp)) {}
    ~Printer() { flush(); }

    int close() {
        flush();
        return ::close(fd);
    }

    void flush() {
        if (pos) {
            auto res = ::write(fd, line.data(), pos);
            assert(res != -1);
            pos = 0;
        }
    }

  private:
    static std::array<std::array<char, 2>, 100> small;
    static std::array<unsigned long long, 20> tens;

    static constexpr size_t SIZE = 1 << 15;
    int fd;
    std::array<char, SIZE> line;
    size_t pos = 0;
    std::stringstream ss;

    template <class T,
              std::enable_if_t<std::is_same<char, T>::value>* = nullptr>
    void write_single(const T& val) {
        if (pos == SIZE) flush();
        line[pos++] = val;
    }

    template <class T,
              internal::is_signed_int_t<T>* = nullptr,
              std::enable_if_t<!std::is_same<char, T>::value>* = nullptr>
    void write_single(const T& val) {
        using U = internal::to_unsigned_t<T>;
        if (val == 0) {
            write_single('0');
            return;
        }
        if (pos > SIZE - 50) flush();
        U uval = val;
        if (val < 0) {
            write_single('-');
            uval = -uval;
        }
        write_unsigned(uval);
    }

    template <class U, internal::is_unsigned_int_t<U>* = nullptr>
    void write_single(U uval) {
        if (uval == 0) {
            write_single('0');
            return;
        }
        if (pos > SIZE - 50) flush();

        write_unsigned(uval);
    }

    template <class U, internal::is_unsigned_int_t<U>* = nullptr>
    static int calc_len(U x) {
        int i = (bsr(x) * 3 + 3) / 10;
        if (x < tens[i])
            return i;
        else
            return i + 1;
    }

    template <class U,
              internal::is_unsigned_int_t<U>* = nullptr,
              std::enable_if_t<8 >= sizeof(U)>* = nullptr>
    void write_unsigned(U uval) {
        size_t len = calc_len(uval);
        pos += len;

        char* ptr = line.data() + pos;
        while (uval >= 100) {
            ptr -= 2;
            memcpy(ptr, small[uval % 100].data(), 2);
            uval /= 100;
        }
        if (uval >= 10) {
            memcpy(ptr - 2, small[uval].data(), 2);
        } else {
            *(ptr - 1) = char('0' + uval);
        }
    }

    template <
        class U,
        std::enable_if_t<internal::is_unsigned_int128<U>::value>* = nullptr>
    void write_unsigned(U uval) {
        static std::array<char, 50> buf;
        size_t len = 0;
        while (uval > 0) {
            buf[len++] = char((uval % 10) + '0');
            uval /= 10;
        }
        std::reverse(buf.begin(), buf.begin() + len);
        memcpy(line.data() + pos, buf.data(), len);
        pos += len;
    }

    void write_single(const std::string& s) {
        for (char c : s) write_single(c);
    }
    void write_single(const char* s) {
        size_t len = strlen(s);
        for (size_t i = 0; i < len; i++) write_single(s[i]);
    }
    template <class T> void write_single(const std::vector<T>& val) {
        auto n = val.size();
        for (size_t i = 0; i < n; i++) {
            if (i) write_single(' ');
            write_single(val[i]);
        }
    }
};

std::array<std::array<char, 2>, 100> Printer::small = [] {
    std::array<std::array<char, 2>, 100> table;
    for (int i = 0; i <= 99; i++) {
        table[i][1] = char('0' + (i % 10));
        table[i][0] = char('0' + (i / 10 % 10));
    }
    return table;
}();
std::array<unsigned long long, 20> Printer::tens = [] {
    std::array<unsigned long long, 20> table;
    for (int i = 0; i < 20; i++) {
        table[i] = 1;
        for (int j = 0; j < i; j++) {
            table[i] *= 10;
        }
    }
    return table;
}();

}  // namespace yosupo

#include <array>
#include <cassert>
#include <chrono>
#include <cstdint>
#include <type_traits>


namespace yosupo {

struct Xoshiro256StarStar {
  public:
    using result_type = uint64_t;
    Xoshiro256StarStar() : Xoshiro256StarStar(0) {}
    explicit Xoshiro256StarStar(uint64_t seed) {
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
    static uint64_t rotl(const uint64_t x, int k) {
        return (x << k) | (x >> (64 - k));
    }

    std::array<uint64_t, 4> s;
};

namespace internal {

template <class G> uint64_t uniform(uint64_t upper, G& gen) {
    static_assert(std::is_same<uint64_t, typename G::result_type>::value, "");
    static_assert(G::min() == 0, "");
    static_assert(G::max() == uint64_t(-1), "");
    if (!(upper & (upper + 1))) {
        return gen() & upper;
    }
    int log = bsr(upper);
    uint64_t mask = (log == 63) ? ~0ULL : (1ULL << (log + 1)) - 1;
    while (true) {
        uint64_t r = gen() & mask;
        if (r <= upper) return r;
    }
}

}  // namespace internal

Xoshiro256StarStar& global_gen() {
    static Xoshiro256StarStar gen(
        std::chrono::steady_clock::now().time_since_epoch().count());
    return gen;
}

template <class T, class G> T uniform(T lower, T upper, G& gen) {
    return T(lower + internal::uniform(uint64_t(upper) - uint64_t(lower), gen));
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

}  // namespace yosupo
using namespace yosupo;

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

#ifdef LOCAL

ostream& operator<<(ostream& os, __int128_t x) {
    if (x < 0) {
        os << "-";
        x *= -1;
    }
    if (x == 0) {
        return os << "0";
    }
    string s;
    while (x) {
        s += char(x % 10 + '0');
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return os << s;
}
ostream& operator<<(ostream& os, __uint128_t x) {
    if (x == 0) {
        return os << "0";
    }
    string s;
    while (x) {
        s += char(x % 10 + '0');
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return os << s;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p);
template <class T> ostream& operator<<(ostream& os, const V<T>& v);
template <class T> ostream& operator<<(ostream& os, const deque<T>& v);
template <class T, size_t N>
ostream& operator<<(ostream& os, const array<T, N>& a);
template <class T> ostream& operator<<(ostream& os, const set<T>& s);
template <class T, class U>
ostream& operator<<(ostream& os, const map<T, U>& m);

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    return os << "P(" << p.first << ", " << p.second << ")";
}

template <class T> ostream& operator<<(ostream& os, const V<T>& v) {
    os << "[";
    bool f = false;
    for (auto d : v) {
        if (f) os << ", ";
        f = true;
        os << d;
    }
    return os << "]";
}

template <class T> ostream& operator<<(ostream& os, const deque<T>& v) {
    os << "[";
    bool f = false;
    for (auto d : v) {
        if (f) os << ", ";
        f = true;
        os << d;
    }
    return os << "]";
}
template <class T, size_t N>
ostream& operator<<(ostream& os, const array<T, N>& a) {
    os << "[";
    bool f = false;
    for (auto d : a) {
        if (f) os << ", ";
        f = true;
        os << d;
    }
    return os << "]";
}

template <class T> ostream& operator<<(ostream& os, const set<T>& s) {
    os << "{";
    bool f = false;
    for (auto d : s) {
        if (f) os << ", ";
        f = true;
        os << d;
    }
    return os << "}";
}

template <class T, class U>
ostream& operator<<(ostream& os, const map<T, U>& s) {
    os << "{";
    bool f = false;
    for (auto p : s) {
        if (f) os << ", ";
        f = true;
        os << p.first << ": " << p.second;
    }
    return os << "}";
}

struct PrettyOS {
    ostream& os;
    bool first;

    template <class T> auto operator<<(T&& x) {
        if (!first) os << ", ";
        first = false;
        os << x;
        return *this;
    }
};
template <class... T> void dbg0(T&&... t) {
    (PrettyOS{cerr, true} << ... << t);
}
#define dbg(...)                                            \
    do {                                                    \
        cerr << __LINE__ << " : " << #__VA_ARGS__ << " = "; \
        dbg0(__VA_ARGS__);                                  \
        cerr << endl;                                       \
    } while (false);
#else
#define dbg(...)
#endif

struct AASSTree {
    struct Node;
    typedef Node* NP;
    static Node last_d;
    static NP last;
    struct Node {
        NP l, r;
        int level, sz;

        int len, lens;
        Node() : l(nullptr), r(nullptr), level(0), sz(0) {}
        Node(int vv) : l(last), r(last), level(1), sz(1) {
            len = lens = vv;
        }
        //new
        static NP make() { return new Node(); }
        static NP make(int vv) { return new Node(vv); }

        void update() {
            sz = 1 + l->sz + r->sz;
            lens = len;
            if (l != last) {
                lens += l->lens;
            }
            if (r != last) {
                lens += r->lens;
            }
        }
        void push() {
        }
    } * n;

    static tuple<int, int, int> lb(NP n, int x) {
        if (n == last) assert(false);
        if (x < n->l->lens) return lb(n->l, x);
        x -= n->l->lens;
        if (x < n->len) return {n->l->sz, x, n->len};
        x -= n->len;
        auto res = lb(n->r, x);
        get<0>(res) += n->l->sz + 1;
        return res;
    }
    tuple<int, int, int> lb(int v) { return lb(n, v); }

    AASSTree() : n(last) {}
    AASSTree(NP _n) : n(_n) {}
    static void clear(NP n) {
        if (n == last) return;
        clear(n->l);
        clear(n->r);
        delete n;
    }
    void clear() {
        clear(n);
        n = last;
    }

    //
    int sz() { return n->sz; }
    void merge(AASSTree r) { n = merge(n, r.n); }
    AASSTree split(int k) {
        auto y = split(n, k);
        n = y.first;
        return AASSTree(y.second);
    }
    void insert(int k, int x) { n = insert(n, k, x); }
    void remove(int k) { n = remove(n, k); }

    // AAskew/split
    // splitpull
    static NP skew(NP n) {
        if (n->level == n->l->level) {
            NP L = n->l;
            n->push();
            L->push();
            n->l = L->r;
            L->r = n;
            n->update();
            L->update();
            return L;
        }
        return n;
    }
    static NP pull(NP n) {
        if (n->level == n->r->level && n->r->level == n->r->r->level) {
            NP R = n->r;
            n->push();
            R->push();
            n->r = R->l;
            R->l = n;
            R->level++;
            n->update();
            R->update();
            return R;
        }
        return n;
    }

    static NP leftdown(NP n) {
        assert(n->l->level < n->level);
        if (n->l->level == n->level - 1) return n;
        n->level--;
        if (n->r->level == n->level) {
            n = pull(n);
        } else {
            n->r->level--;
            n->r = skew(n->r);
            n->r->r = skew(n->r->r);
            n = pull(n);
            n->r = pull(n->r);
        }
        return n;
    }
    static NP rightdown(NP n) {
        assert(n->r->level <= n->level);
        if (n->r->level >= n->level - 1) return n;
        n->level--;
        n = skew(n);
        n->r = skew(n->r);
        n = pull(n);
        return n;
    }
    static NP superleftdown(NP n) {
        if (n->l->level == n->level - 1) return n;
        if (n->level != n->r->level && n->r->level != n->r->r->level) {
            n->level--;
            return superleftdown(n);
        }
        n = leftdown(n);
        n->l = superleftdown(n->l);
        n = leftdown(n);
        return n;
    }
    static NP superrightdown(NP n) {
        if (n->r->level >= n->level - 1) return n;
        n = rightdown(n);
        n->r = superrightdown(n->r);
        n = rightdown(n);
        return n;
    }

    static NP insert(NP n, int k, int x) {
        if (n == last) {
            assert(k == 0);
            return Node::make(x);
        }
        n->push();
        if (k <= n->l->sz) {
            n->l = insert(n->l, k, x);
            n->update();
        } else {
            n->r = insert(n->r, k - (n->l->sz + 1), x);
            n->update();
        }
        n = skew(n);
        n = pull(n);
        return n;
    }
    // pair<0,0>
    static pair<NP, NP> at0_with_remove(NP n) {
        n->push();
        if (n->l == last) {
            return {n, n->r};
        }
        auto x = at0_with_remove(n->l);
        n->l = x.second;
        n->update();
        x.second = leftdown(n);
        return x;
    }
    static NP remove(NP n, int k) {
        assert(n != last);
        n->push();
        if (k == n->l->sz) {
            if (n->level == 1) {
                auto nn = n->r;
                delete n;
                return nn;
            }
            auto x = at0_with_remove(n->r);
            NP nn = x.first;
            nn->push();
            nn->l = n->l;
            nn->r = x.second;
            nn->level = n->level;
            nn->update();
            delete n;
            return rightdown(nn);
        }
        if (k < n->l->sz) {
            n->l = remove(n->l, k);
            n->update();
            return leftdown(n);
        } else {
            n->r = remove(n->r, k - (n->l->sz + 1));
            n->update();
            return rightdown(n);
        }
    }
    static NP merge(NP l, NP r) {
        if (l == last) return r;
        if (r == last) return l;
        if (l->level == r->level) {
            auto x = at0_with_remove(r);
            NP n = x.first;
            n->push();
            n->r = x.second;
            n->l = l;
            n->level = l->level + 1;
            n->update();
            return rightdown(n);
        }
        NP n;
        l->push();
        r->push();
        if (l->level > r->level) {
            l->push();
            l->r = merge(l->r, r);
            l->update();
            n = l;
        } else {
            r->push();
            r->l = merge(l, r->l);
            r->update();
            n = r;
        }
        n = skew(n);
        n = pull(n);
        return n;
    }
    static pair<NP, NP> split(NP n, int k) {
        if (n == last) return {last, last};
        n->push();
        if (k <= n->l->sz) {
            auto y = split(n->l, k);
            n->l = y.second;
            n->update();
            n = superleftdown(n);
            y.second = n;
            return y;
        } else {
            auto y = split(n->r, k - (n->l->sz + 1));
            n->r = y.first;
            n->update();
            n = superrightdown(n);
            y.first = n;
            return y;
        }
    }
};
typename AASSTree::Node AASSTree::last_d = AASSTree::Node();
typename AASSTree::NP AASSTree::last = &AASSTree::last_d;

using Tree = AASSTree;

Scanner sc = Scanner(stdin);
Printer pr = Printer(stdout);

const int BS = 200;
const int BN = (100000 + BS - 1) / BS;
const int N = BS * BN;

int b[N];
bool lazy[N] = {};
V<Tree> fw(BN);

void reconstruct(int bi) {
    fw[bi].clear();
    fw[bi].insert(0, N + 1);
    int l = bi * BS, r = l + BS;
    for (int i = r - 1; i >= l; i--) {
        int idx, pos, len;
        tie(idx, pos, len) = fw[bi].lb(b[i]);
        fw[bi].remove(idx);
        fw[bi].insert(idx, pos);
        fw[bi].insert(idx + 1, len - pos - 1);
    }
}

void cng(int i, int x) {
    b[i] = x;
    lazy[i / BS] = true;
}

int que(int i) {
    int p = b[i];
    i++;

    while (i % BS) {
        if (p >= b[i]) p++;
        i++;
    }
    int bi = i / BS;

    while (bi < BN) {
        if (lazy[bi]) {
            reconstruct(bi);
            lazy[bi] = false;
        }
        auto node = fw[bi].lb(p);
        p += get<0>(node);
        bi++;
    }

    return p;
}

int main() {
    int n;

    //n = 100000;
    sc.read(n);

    for (int i = 0; i < n; i++) {
        //b[i] = uniform(0, i);
        
        sc.read(b[i]);
        b[i] = i - b[i];
    }
    for (int i = n; i < N; i++) {
        b[i] = i;
    }

    for (int i = 0; i < BN; i++) {
        lazy[i] = true;
    }


    int q;

    //q = 100000;
    sc.read(q);

    for (int ph = 0; ph < q; ph++) {
        
        int ty;

        //ty = uniform(1, 2);
        sc.read(ty);

        if (ty == 1) {
            int i, x;

            //i = uniform(0, n - 1);
            //x = uniform(0, i);

            sc.read(i, x);
            i--;

            cng(i, i - x);
        } else {
            int i;

            // i = uniform(0, n - 1);

            sc.read(i);
            i--;

            pr.writeln(que(i) + 1);
        }
    }

    for (int i = 0; i < BN; i++) {
        fw[i].clear();
    }
    return 0;
}