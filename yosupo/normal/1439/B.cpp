//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
//#undef LOCAL


#include <unistd.h>
#include <algorithm>
#include <array>
#include <cctype>
#include <cstring>
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

int bsr(unsigned int n) {
    return 8 * (int)sizeof(unsigned int) - 1 - __builtin_clz(n);
}
int bsr(unsigned long n) {
    return 8 * (int)sizeof(unsigned long) - 1 - __builtin_clzl(n);
}
int bsr(unsigned long long n) {
    return 8 * (int)sizeof(unsigned long long) - 1 - __builtin_clzll(n);
}

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

  private:
    static constexpr size_t SIZE = 1 << 15;

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

    template <class T, internal::is_signed_int_t<T>* = nullptr>
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
    template <class U, internal::is_unsigned_int_t<U>* = nullptr>
    bool read_single(U& ref) {
        if (!skip_space(50)) return false;
        ref = 0;
        do {
            ref = 10 * ref + (line[st++] & 0x0f);
        } while (line[st] >= '0');
        return true;
    }

    int fd = -1;
    char line[SIZE];
    size_t st = 0, ed = 0;
    bool eof = false;
    bool reread() {
        if (ed - st >= 50) return true;
        if (st > SIZE / 2) {
            std::memmove(line, line + st, ed - st);
            ed -= st;
            st = 0;
        }
        if (eof) return false;
        auto u = ::read(fd, line + ed, SIZE - ed);
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

    Printer(FILE* _fp) : fd(fileno(_fp)) {}
    ~Printer() { flush(); }

    void flush() {
        ::write(fd, line, pos);
        pos = 0;
    }

  private:
    static std::array<std::array<char, 2>, 100> small;
    static std::array<unsigned long long, 20> tens;

    static int calc_len(unsigned long long x) {
        int i = (bsr(x) * 3 + 3) / 10;
        if (x < tens[i])
            return i;
        else
            return i + 1;
    }

    static constexpr size_t SIZE = 1 << 15;
    int fd;
    char line[SIZE];
    size_t pos = 0;
    void write_single(const char& val) {
        if (pos == SIZE) flush();
        line[pos++] = val;
    }

    template <class T, internal::is_signed_int_t<T>* = nullptr>
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

    template <class U,
              internal::is_unsigned_int_t<U>* = nullptr,
              std::enable_if_t<sizeof(U) == 4>* = nullptr>
    void write_unsigned(U uval) {
        write_unsigned(uint64_t(uval));
    }

    template <class U,
              internal::is_unsigned_int_t<U>* = nullptr,
              std::enable_if_t<sizeof(U) == 8>* = nullptr>
    void write_unsigned(U uval) {
        size_t len = calc_len(uval);
        pos += len;

        char* ptr = line + pos;
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

#include <iostream>
#include <iterator>
#include <utility>
#include <vector>


#include <array>
#include <cstdint>
#include <tuple>
#include <vector>


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

namespace yosupo {

namespace internal {

constexpr int THRESHOLD_HASH = 100;

uint64_t get_seed(int i) {
    static std::array<uint64_t, THRESHOLD_HASH> seed = []() {
        std::array<uint64_t, THRESHOLD_HASH> _seed;
        for (auto& x : _seed) {
            x = yosupo::uniform(uint64_t(0), uint64_t(-1));
        }
        return _seed;
    }();
    static std::vector<uint64_t> long_seed;

    if (i < THRESHOLD_HASH) return seed[i];

    while (THRESHOLD_HASH + int(long_seed.size()) <= i) {
        long_seed.push_back(yosupo::uniform(uint64_t(0), uint64_t(-1)));
    }

    return long_seed[i - THRESHOLD_HASH];
}

template <int I = 1> struct Hasher32 {
    uint64_t v = get_seed(0);

    template <class T,
              is_integral_t<T>* = nullptr,
              std::enable_if_t<sizeof(T) == 4>* = nullptr>
    Hasher32<I + 1> update(T x) const {
        return Hasher32<I + 1>{v + uint32_t(x) * get_seed(I)};
    }
    template <class T,
              is_integral_t<T>* = nullptr,
              std::enable_if_t<sizeof(T) == 1>* = nullptr>
    Hasher32<I + 1> update(T x) const {
        return update(uint32_t(x));
    }
    template <class T,
              is_integral_t<T>* = nullptr,
              std::enable_if_t<sizeof(T) == 8>* = nullptr>
    Hasher32<I + 2> update(T x) const {
        return update(uint32_t(x)).update(uint32_t(uint64_t(x) >> 32));
    }
    template <class T,
              is_integral_t<T>* = nullptr,
              std::enable_if_t<sizeof(T) == 16>* = nullptr>
    Hasher32<I + 4> update(T x) const {
        return update(uint64_t(x)).update(uint64_t((__uint128_t)(x) >> 64));
    }
    uint32_t digest() const { return uint32_t(v >> 32); }
};

template <class T, is_integral_t<T>* = nullptr> uint32_t hash32(const T& x) {
    return Hasher32<>{}.update(x).digest();
}

template <class S, class T> uint32_t hash32(const std::pair<S, T>& x) {
    return Hasher32<>{}.update(x.first).update(x.second).digest();
}

template <int I = 0,
          class H,
          class T,
          std::enable_if_t<(I != std::tuple_size<T>::value)>* = nullptr>
uint32_t hash32_tuple(const H& h, const T& x) {
    return hash32_tuple<I + 1>(h.update(std::get<I>(x)), x);
}

template <int I,
          class H,
          class T,
          std::enable_if_t<(I == std::tuple_size<T>::value)>* = nullptr>
uint32_t hash32_tuple(const H& h, const T&) {
    return h.digest();
}

template <class... Args> uint32_t hash32(const std::tuple<Args...>& x) {
    return hash32_tuple(Hasher32<>{}, x);
}

}  // namespace internal

template <class T> struct UniversalHash32 {
    uint32_t operator()(const T& x) { return internal::hash32(x); }
};

}  // namespace yosupo

namespace yosupo {

template <class K, class H = UniversalHash32<K>>
struct IncrementalHashSet {
  private:
    struct Iterator {
      public:
        using difference_type = int;
        using value_type = K;
        using pointer = K*;
        using reference = K&;
        using iterator_category = std::forward_iterator_tag;

        IncrementalHashSet& _mp;
        unsigned int _pos;
        Iterator(IncrementalHashSet& mp, unsigned int pos) : _mp(mp), _pos(pos) {}

        K operator*() const { return _mp.keys[_pos]; }

        Iterator& operator++() {
            _pos = _mp.next_bucket(_pos + 1);
            return *this;
        }
        Iterator operator++(int) {
            auto result = *this;
            ++*this;
            return result;
        }

        bool operator==(const Iterator& rhs) const { return _pos == rhs._pos; }
        bool operator!=(const Iterator& rhs) const { return !(*this == rhs); }
    };

  public:
    IncrementalHashSet(size_t s) : mask((1 << s) - 1), filled(0), used(mask + 1), keys(mask + 1) {}
    IncrementalHashSet() : IncrementalHashSet(2) {}

    Iterator begin() { return Iterator(*this, next_bucket(0)); }
    Iterator end() { return Iterator(*this, mask + 1); }
    using iterator = Iterator;

    void insert(const K& k) {
        unsigned int i = H()(k) & mask;
        while (used[i] && keys[i] != k) {
            i = (i + 1) & mask;
        }
        if (!used[i]) {
            if (filled * 2 > mask) {
                rehash();
                return this->insert(k);
            }
            filled++;
            used[i] = true;
            keys[i] = k;
        }
    }

    Iterator find(const K& k) {
        unsigned int i = H()(k) & mask;
        while (used[i] && keys[i] != k) {
            i = (i + 1) & mask;
        }
        if (!used[i]) return end();
        return Iterator(*this, i);
    }

  private:
    unsigned int mask, filled;  // data.size() == 1 << s

    std::vector<bool> used;
    std::vector<K> keys;

    void rehash() {
        unsigned int pmask = mask;
        mask = mask * 2 + 1;
        filled = 0;
        auto pused = std::exchange(used, std::vector<bool>(mask + 1));
        auto pkeys = std::exchange(keys, std::vector<K>(mask + 1));
        for (unsigned int i = 0; i <= pmask; i++) {
            if (pused[i]) {
                this->insert(pkeys[i]);
            }
        }
    }

    unsigned int next_bucket(unsigned int i) const {
        while (i <= mask && !used[i]) i++;
        return i;
    }
};

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

Scanner sc = Scanner(stdin);
Printer pr = Printer(stdout);

void solve() {
    int n, m, k;
    sc.read(n, m, k);

    //VV<int> g(n);
    V<IncrementalHashSet<int>> g(n);
    V<int> deg(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        sc.read(a, b);
        a--; b--;
        //g[a].push_back(b);
        //g[b].push_back(a);
        g[a].insert(b);
        g[b].insert(a);
        deg[a]++;
        deg[b]++;
    }
    /*for (int i = 0; i < n; i++) {
        sort(g[i].begin(), g[i].end());
    }*/

    V<bool> used(n);
    queue<int> que;
    for (int i = 0; i < n; i++) {
        if (deg[i] < k) {
            que.push(i);
        }
    }

    while (que.size()) {
        int p = que.front(); que.pop();
        if (used[p]) continue;

        if (deg[p] == k - 1) {
            V<int> near;
            near.push_back(p);
            for (auto q: g[p]) {
                if (used[q]) continue;
                near.push_back(q);
            }

            bool ok = [&]() {
                for (int i = 0; i < k; i++) {
                    for (int j = i + 1; j < k; j++) {
                        int x = near[i], y = near[j];
                        /*if (!binary_search(g[x].begin(), g[x].end(), y)) {
                            return false;
                        }*/
                        if (g[x].find(y) == g[x].end()) {
                            return false;
                        }
                    }
                }
                return true;
            }();

            if (ok) {
                pr.writeln(2);
                for (int d: near) {
                    pr.write(d + 1);
                    pr.write(' ');
                }
                pr.writeln();
                return;
            }
        }

        used[p] = true;
        for (auto q : g[p]) {
            if (used[q]) continue;
            deg[q]--;
            if (deg[q] == k - 1) que.push(q);
        }
    }

    V<int> rem;
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        rem.push_back(i);
    }

    if (rem.empty()) {
        pr.writeln(-1);
        return;
    }
    pr.writeln(1, rem.size());
    for (int d : rem) {
        pr.write(d + 1);
        pr.write(' ');
    }
    pr.writeln();
}

int main() {
    int t;
    sc.read(t);
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}