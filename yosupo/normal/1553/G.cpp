#pragma GCC target("avx,avx2")
//#pragma GCC optimize("Ofast")
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

#include <iostream>
#include <iterator>
#include <utility>
#include <vector>


#include <array>
#include <cstdint>
#include <tuple>
#include <vector>
#include <set>
#include <map>


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

#include <vector>
#include <algorithm>

namespace yosupo {

struct BitVec {
  public:
    BitVec() : BitVec(0) {}
    explicit BitVec(size_t _n) : n(_n), d((n + B - 1) / B) {}
    size_t size() const { return n; }

    void reset() { fill(d.begin(), d.end(), 0); }
    void reset(size_t i) { set(i, false); }
    BitVec& set() {
        for (auto& x : d) {
            x = -1ULL;
        }
        erase_last();
        return *this;
    }
    BitVec& set(size_t i, bool f = true) {
        assert(i < n);
        if (f) {
            d[i / B] |= 1ULL << (i % B);
        } else {
            d[i / B] &= ~(1ULL << (i % B));
        }
        return *this;
    }
    bool test(size_t i) const {
        assert(i < n);
        return (d[i / B] >> (i % B) & 1) != 0;
    }

    size_t count() const {
        size_t sm = 0;
        for (auto x : d) sm += popcnt(x);
        return sm;
    }
    bool any() const {
        for (auto& x : d)
            if (x) return true;
        return false;
    }
    int find_first() const {
        auto m = d.size();
        for (size_t i = 0; i < m; i++) {
            if (d[i]) return int(i * B + ::yosupo::bsf(d[i]));
        }
        return int(size());
    }

    BitVec& flip() {
        op1(std::bit_not<unsigned long long>());
        if (n % B) d.back() &= ~(-1ULL << (n % B));
        return *this;
    }
    BitVec& flip(size_t i) {
        return set(i, !test(i));
    }

    BitVec& operator~() const { return BitVec(*this).flip(); }
    BitVec& operator&=(const BitVec& r) {
        return op2(r, std::bit_and<unsigned long long>());
    }
    BitVec& operator|=(const BitVec& r) {
        return op2(r, std::bit_or<unsigned long long>());
    }
    BitVec& operator^=(const BitVec& r) {
        return op2(r, std::bit_xor<unsigned long long>());
    }
    BitVec& operator<<=(const size_t& s) {
        auto block = s / B, rem = s % B;
        if (d.size() <= block) {
            reset();
            return *this;
        }
        for (size_t i = d.size() - 1; i > block; i--) {
            if (rem == 0)
                d[i] = d[i - block];
            else
                d[i] = d[i - block] << rem | d[i - block - 1] >> (B - rem);
        }
        d[block] = d[0] << rem;
        erase_last();
        fill(d.begin(), d.begin() + block, 0ULL);
        return *this;
    }
    BitVec& operator>>=(const size_t& s) {
        auto block = s / B, rem = s % B;
        if (d.size() <= block) {
            reset();
            return *this;
        }
        for (size_t i = 0; i < d.size() - block - 1; i++) {
            if (rem == 0)
                d[i] = d[i + block];
            else
                d[i] = d[i + block + 1] << (B - rem) | d[i + block] >> rem;
        }
        d[d.size() - block - 1] = d.back() >> rem;
        fill(d.begin() + d.size() - block, d.end(), 0ULL);
        return *this;
    }
    BitVec operator&(const BitVec& r) const { return BitVec(*this) &= r; }
    BitVec operator|(const BitVec& r) const { return BitVec(*this) |= r; }
    BitVec operator^(const BitVec& r) const { return BitVec(*this) ^= r; }
    BitVec operator<<(const size_t& s) const { return BitVec(*this) <<= s; }
    BitVec operator>>(const size_t& s) const { return BitVec(*this) >>= s; }
    bool operator==(const BitVec& r) const { return d == r.d; }
    bool operator!=(const BitVec& r) const { return !(d == r.d); }

    void push_back(bool f) {
        if (n % B == 0) d.push_back(0);
        set(n, f);
        n++;
    }

    BitVec substr(size_t st, size_t le) const {
        assert(st + le <= n);
        BitVec res(le);
        size_t i = 0;
        while (i < le) {
            res.d[i / B] |= d[(st + i) / B] >> ((st + i) % B) << (i % B);
            i += std::min(B - i % B, B - (st + i) % B);
        }
        res.erase_last();
        return res;
    }
    bool substr_match(size_t st, const BitVec& pat) const {
        size_t le = pat.size();
        assert(st + le <= n);
        size_t i = 0;
        while (i < le) {
            size_t u = std::min({le - i, B - i % B, B - (st + i) % B});
            unsigned long long z = pat.d[i / B] >> (i % B) ^ d[(st + i) / B] >> ((st + i) % B);
            if (z << (B - u)) return false;
            i += u;
        }
        return true;
    }

    const std::vector<unsigned long long>& raw_data() const { return d; }

  private:
    static constexpr size_t B = 64;
    size_t n;
    std::vector<unsigned long long> d;
    void erase_last() {
        if (n % B) d.back() &= (unsigned long long)(-1) >> (B - n % B);
    }

    template <class OP> BitVec& op1(OP op) {
        for (auto& x : d) x = op(x);
        return *this;
    }

    template <class OP> BitVec& op2(const BitVec& r, OP op) {
        assert(n == r.n);
        for (size_t i = 0; i < d.size(); i++) d[i] = op(d[i], r.d[i]);
        return *this;
    }
};

namespace internal {

template <class H> auto update(const H& h, const BitVec& bs) {
    return update(h, bs.raw_data());
}

}  // namespace internal

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

struct DynHasher32 {
    int len = 0;
    uint64_t v = get_seed(0);

    DynHasher32 update32(uint32_t x) const {
        return DynHasher32{len + 1, v + x * get_seed(len)};
    }

    DynHasher32 to_dyn() const { return *this; }
    uint32_t digest() const { return uint32_t(v >> 32); }
};

template <int I = 1> struct Hasher32 {
    uint64_t v = get_seed(0);

    Hasher32<I + 1> update32(uint32_t x) const {
        return Hasher32<I + 1>{v + x * get_seed(I)};
    }

    DynHasher32 to_dyn() const { return DynHasher32{I, v}; }
    uint32_t digest() const { return uint32_t(v >> 32); }
};

template <class H,
          class T,
          is_integral_t<T>* = nullptr,
          std::enable_if_t<4 >= sizeof(T)>* = nullptr>
auto update(const H& h, const T& x) {
    return h.update32(uint32_t(x));
}
template <class H,
          class T,
          is_integral_t<T>* = nullptr,
          std::enable_if_t<sizeof(T) == 8>* = nullptr>
auto update(const H& h, const T& x) {
    return update(update(h, uint32_t(x)), uint32_t(uint64_t(x) >> 32));
}
template <class H,
          class T,
          is_integral_t<T>* = nullptr,
          std::enable_if_t<sizeof(T) == 16>* = nullptr>
auto update(const H& h, const T& x) {
    return update(update(h, uint64_t(x)), uint64_t((__uint128_t)(x) >> 64));
}

template <class H, class S, class T>
auto update(const H& h, const std::pair<S, T>& x) {
    return update(update(h, x.first), x.second);
}

template <int I,
          class H,
          class T,
          std::enable_if_t<(I == std::tuple_size<T>::value)>* = nullptr>
auto update(const H& h, const T&) {
    return h;
}
template <int I = 0,
          class H,
          class T,
          std::enable_if_t<(I != std::tuple_size<T>::value)>* = nullptr>
auto update(const H& h, const T& x) {
    return update<I + 1>(update(h, std::get<I>(x)), x);
}

template <int I = 0,
          class H,
          class T,
          int N>
auto update(const H& h, const std::array<T, N>& x) {
    return I == N ? h : update<I + 1>(update(h, x[I]), x);
}

template <class H, class T> auto update(const H& h, const std::vector<T>& v) {
    auto h2 = update(h, v.size()).to_dyn();
    for (const auto& x : v) {
        h2 = update(h2, x);
    }
    return h2;
}

template <class H, class T> auto update(const H& h, const std::set<T>& s) {
    auto h2 = update(h, s.size()).to_dyn();
    for (const auto& x : s) {
        h2 = update(h2, x);
    }
    return h2;
}

template <class H, class T, class U> auto update(const H& h, const std::map<T, U>& m) {
    auto h2 = update(h, m.size()).to_dyn();
    for (const auto& x : m) {
        h2 = update(h2, x);
    }
    return h2;
}

}  // namespace internal

template <class T> struct UniversalHash32 {
    uint32_t operator()(const T& x) {
        return internal::update(internal::Hasher32<>{}, x).digest();
    }
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

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

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

const int D = TEN(6) + 10;

int main() {
    int n, q;
    sc.read(n, q);

    VV<int> vals1(D), vals2(D);

    for (int i = 0; i < n; i++) {
        int a;
        sc.read(a);

        vals1[a].push_back(i);
        vals2[a].push_back(i);
        vals2[a + 1].push_back(i);
    }

    atcoder::dsu ans0(n);

    V<int> top(D, -1);
    for (int g = 2; g < D; g++) {
        V<int> vs;
        for (int i = g; i < D; i += g) {
            for (int k : vals1[i]) {
                vs.push_back(k);
            }
        }
        int m = int(vs.size());
        if (m == 0) continue;
        top[g] = vs.front();
        for (int i = 0; i < m - 1; i++) {
            ans0.merge(vs[i], vs[i + 1]);
        }
    }

    VV<int> list(n);
    for (int g = 2; g < D; g++) {
        if (top[g] == -1) continue;
        int id = ans0.leader(top[g]);
        for (int i = g; i < D; i += g) {
            for (int k : vals2[i]) {
                list[k].push_back(id);
            }
        }
    }
    using P = pair<int, int>;

    IncrementalHashSet<P> hs;
    for (auto v : list) {
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for (int a : v) {
            for (int b : v) {
                if (a < b) {
                    hs.insert({a, b});
                }
            }
        }
    }
    dbg(list);

    for (int ph = 0; ph < q; ph++) {
        int s, t;
        sc.read(s, t);
        s--; t--;
        s = ans0.leader(s);
        t = ans0.leader(t);
        if (s > t) swap(s, t);

        if (s == t) {
            pr.writeln(0);
            continue;
        }

        if (hs.find({s, t}) != hs.end()) {
            pr.writeln(1);
            continue;
        }

        dbg(s, t);
        pr.writeln(2);
    }
    return 0;
}