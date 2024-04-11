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

    bool skip_space(int token_len = 0) {
        while (true) {
            while (st != ed && line[st] <= ' ') st++;
            if (ed - st > token_len) return true;
            for (int i = st; i < ed; i++) {
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

#include <cassert>
#include <vector>


#include <cassert>
#include <numeric>
#include <type_traits>

namespace atcoder {

namespace internal {

#ifndef _MSC_VER
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
using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                                  is_signed_int128<T>::value ||
                                                  is_unsigned_int128<T>::value,
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

#else

template <class T> using is_integral = typename std::is_integral<T>;

template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                              std::make_unsigned<T>,
                                              std::common_type<T>>::type;

#endif

template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

template <class T> struct fenwick_tree {
    using U = internal::to_unsigned_t<T>;

  public:
    fenwick_tree() : _n(0) {}
    fenwick_tree(int n) : _n(n), data(n) {}

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n) {
            data[p - 1] += U(x);
            p += p & -p;
        }
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

  private:
    int _n;
    std::vector<U> data;

    U sum(int r) {
        U s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};

}  // namespace atcoder

using namespace yosupo;
using namespace atcoder;

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
using D = double;
const D PI = acos(D(-1)), EPS = 1e-10;

int sgn(D a) { return (a < -EPS) ? -1 : (a > EPS); }
int sgn(D a, D b) { return sgn(a - b); }
struct P {
    D x, y;
    P(D _x = D(), D _y = D()) : x(_x), y(_y) {}
    P operator+(const P& r) const { return {x + r.x, y + r.y}; }
    P operator-(const P& r) const { return {x - r.x, y - r.y}; }
    P operator*(const P& r) const {
        return {x * r.x - y * r.y, x * r.y + y * r.x};
    }

    P operator*(const D& r) const { return {x * r, y * r}; }
    P operator/(const D& r) const { return {x / r, y / r}; }

    P& operator+=(const P& r) { return *this = *this + r; }
    P& operator-=(const P& r) { return *this = *this - r; }
    P& operator*=(const P& r) { return *this = *this * r; }
    P& operator*=(const D& r) { return *this = *this * r; }
    P& operator/=(const D& r) { return *this = *this / r; }

    P operator-() const { return {-x, -y}; }

    bool operator<(const P& r) const {
        return 2 * sgn(x, r.x) + sgn(y, r.y) < 0;
    }
    bool operator==(const P& r) const { return sgn((*this - r).rabs()) == 0; }
    bool operator!=(const P& r) const { return !(*this == r); }

    D norm() const { return x * x + y * y; }
    D abs() const { return sqrt(norm()); }
    D rabs() const { return max(std::abs(x), std::abs(y)); }  // robust abs
    D arg() const { return atan2(y, x); }

    pair<D, D> to_pair() const { return {x, y}; }
    static P polar(D le, D th) { return {le * cos(th), le * sin(th)}; }
};
ostream& operator<<(ostream& os, const P& p) {
    return os << "P(" << p.x << ", " << p.y << ")";
}

struct L {
    P s, t;
    L(P _s = P(), P _t = P()) : s(_s), t(_t) {}
    P vec() const { return t - s; }
    D abs() const { return vec().abs(); }
    D arg() const { return vec().arg(); }
};
ostream& operator<<(ostream& os, const L& l) {
    return os << "L(" << l.s << ", " << l.t << ")";
}

D crs(P a, P b) { return a.x * b.y - a.y * b.x; }
D dot(P a, P b) { return a.x * b.x + a.y * b.y; }
int sgncrs(P a, P b) {
    D cr = crs(a, b);
    if (abs(cr) <= (a.rabs() + b.rabs()) * EPS) return 0;
    return (cr < 0) ? -1 : 1;
}

int ccw(P b, P c) {
    int s = sgncrs(b, c);
    if (s) return s;
    if (!sgn(c.rabs()) || !sgn((c - b).rabs())) return 0;
    if (dot(b, c) < 0) return 2;
    if (dot(-b, c - b) < 0) return -2;
    return 0;
}
int ccw(P a, P b, P c) { return ccw(b - a, c - a); }
int ccw(L l, P p) { return ccw(l.s, l.t, p); }
/**
 * ()
 */

P project(const L& l, const P& p) {
    P v = l.vec();
    return l.s + v * dot(v, p - l.s) / v.norm();
}

bool insSL(const L& s, const L& l) {
    int a = ccw(l, s.s), b = ccw(l, s.t);
    return (a % 2 == 0 || b % 2 == 0 || a != b);
}

bool insSS(const L& s, const L& t) {
    int a = ccw(s, t.s), b = ccw(s, t.t);
    int c = ccw(t, s.s), d = ccw(t, s.t);
    if (a * b <= 0 && c * d <= 0) return true;
    return false;
}

D distLP(const L& l, const P& p) {
    return abs(crs(l.vec(), p - l.s)) / l.abs();
}

D distSP(const L& s, const P& p) {
    P q = project(s, p);
    if (ccw(s, q) == 0)
        return (p - q).abs();
    else
        return min((s.s - p).abs(), (s.t - p).abs());
}

D distSS(const L& s, const L& t) {
    if (insSS(s, t)) return 0;
    return min(
        {distSP(s, t.s), distSP(s, t.t), distSP(t, s.s), distSP(t, s.t)});
}

int crossLL(const L& l, const L& m, P& r) {
    D cr1 = crs(l.vec(), m.vec()), cr2 = crs(l.vec(), l.t - m.s);
    if (sgncrs(l.vec(), m.vec()) == 0) {
        r = l.s;
        if (sgncrs(l.vec(), l.t - m.s)) return 0;
        return -1;
    }
    r = m.s + m.vec() * cr2 / cr1;
    return 1;
}

int crossSS(L l, L m, P& r) {
    int u = crossLL(l, m, r);
    if (u == 0) return 0;
    if (u == -1) {
        r = max(min(l.s, l.t), min(m.s, m.t));
        P q = min(max(l.s, l.t), max(m.s, m.t));
        return (q < r) ? 0 : (q == r ? 1 : -1);
    }
    if (ccw(l, r) == 0 && ccw(m, r) == 0) return 1;
    return 0;
}
using Pol = V<P>;

D area2(const Pol& pol) {
    D u = 0;
    if (!pol.size()) return u;
    P a = pol.back();
    for (auto b : pol) u += crs(a, b), a = b;
    return u;
}

V<pair<P, int>> insPolL(Pol pol, L l) {
    using Pi = pair<P, int>;
    V<Pi> v;
    P a, b = pol.back();
    for (auto now: pol) {
        a = b; b = now;
        P p;
        if (crossLL({a, b}, l, p) != 1) continue;
        int sa = ccw(l, a) % 2, sb = ccw(l, b) % 2;
        if (sa > sb) swap(sa, sb);
        if (sa != 1 && sb == 1) v.push_back({p, 1});
        if (sa == -1 && sb != -1) v.push_back({p, 2});
    }
    sort(v.begin(), v.end(), [&](Pi x, Pi y){
        return dot(l.vec(), x.first - l.s) < dot(l.vec(), y.first - l.s);
    });
    int m = int(v.size());
    V<Pi> res;
    for (int i = 0; i < m; i++) {
        if (i) v[i].second ^= v[i - 1].second;
        if (!res.empty() && res.back().first == v[i].first) res.pop_back();
        res.push_back(v[i]);
    }
    return res;
}

int contains(const Pol& pol, P p) {
    if (!pol.size()) return 0;
    int in = -1;
    P _a, _b = pol.back();
    for (auto now : pol) {
        _a = _b;
        _b = now;
        P a = _a, b = _b;
        if (ccw(a, b, p) == 0) return 1;
        if (a.y > b.y) swap(a, b);
        if (!(a.y <= p.y && p.y < b.y)) continue;
        if (sgn(a.y, p.y) ? (crs(a - p, b - p) > 0) : (a.x > p.x)) in *= -1;
    }
    return in + 1;
}

Pol convex_down(const V<P>& ps) {
    assert(ps.size() >= 2);
    Pol dw;
    for (P d : ps) {
        size_t n;
        while ((n = dw.size()) > 1) {
            if (ccw(dw[n - 2], dw[n - 1], d) == 1) break;
            dw.pop_back();
        }
        dw.push_back(d);
    }
    return dw;
}

Pol convex(V<P> ps) {
    sort(ps.begin(), ps.end());
    ps.erase(unique(ps.begin(), ps.end()), ps.end());
    if (ps.size() <= 1) return ps;
    Pol dw = convex_down(ps);
    reverse(ps.begin(), ps.end());
    Pol up = convex_down(ps);
    dw.insert(dw.begin(), up.begin() + 1, up.end() - 1);
    return dw;
}

Pol convex_cut(const Pol& po, const L& l) {
    if (!po.size()) return Pol{};
    Pol q;
    P a, b = po.back();
    for (auto now : po) {
        a = b;
        b = now;
        if ((ccw(l, a) % 2) * (ccw(l, b) % 2) < 0) {
            P buf;
            crossLL(l, L(a, b), buf);
            q.push_back(buf);
        }
        if (ccw(l, b) != -1) q.push_back(b);
    }
    return q;
}

D diameter(const Pol& p) {
    int n = int(p.size());
    if (n == 2) return (p[1] - p[0]).abs();
    int x = 0, y = 0;
    for (int i = 1; i < n; i++) {
        if (p[i] < p[x]) x = i;
        if (p[y] < p[i]) y = i;
    }
    D ans = 0;
    int sx = x, sy = y;
    /*
    do {
        ...
    } while (sx != x || sy != y);
    1
    */
    while (sx != y || sy != x) {
        ans = max(ans, (p[x] - p[y]).abs());
        int nx = (x + 1 < n) ? x + 1 : 0, ny = (y + 1 < n) ? y + 1 : 0;
        if (crs(p[nx] - p[x], p[ny] - p[y]) < 0)
            x = nx;
        else
            y = ny;
    }
    return ans;
}
struct C {
    P p;
    D r;
    C(P _p = P(), D _r = D()) : p(_p), r(_r) {}
};

int crossCL(const C& c, const L& l, L& r) {
    D u = distLP(l, c.p);
    int si = sgn(u, c.r);
    if (si == 1) return 0;
    P v = project(l, c.p);
    P di = (si == 0) ? P(0, 0) : l.vec() * (sqrt(c.r * c.r - u * u) / l.abs());
    r = L(v - di, v + di);
    if (si == 0) return 1;
    return 2;
}

int crossCS(const C& c, const L& s, L& l) {
    if (!crossCL(c, s, l)) return 0;
    bool f1 = !ccw(s, l.s), f2 = !ccw(s, l.t);
    if (f1 && f2) return 2;
    if (!f1 && !f2) return 0;
    if (f1)
        l.t = l.s;
    else
        l.s = l.t;
    return 1;
}

int crossCC(const C& c, const C& d, D& l, D& r) {
    if (c.p == d.p) {
        assert(sgn(c.r - d.r));  // prohibit same circles
        return 0;
    }
    D di = (c.p - d.p).abs(), bth = (d.p - c.p).arg();
    D costh = (c.r * c.r + di * di - d.r * d.r) / (2 * c.r * di);
    int ty = min(sgn(c.r + d.r, di), sgn(di, abs(c.r - d.r)));
    if (ty == -1) return 0;
    if (ty == 0) costh = sgn(costh);
    D th = acos(costh);
    l = bth - th;
    r = bth + th;
    return ty + 1;
}

int tangent(const C& c, const P& p, P& p1, P& p2) {
    D di = (c.p - p).abs();
    int si = sgn(c.r, di);
    if (si == 1) return 0;
    D th = acos(min(D(1), c.r / di));
    D ar = (p - c.p).arg();
    p1 = c.p + P::polar(c.r, ar - th);
    p2 = c.p + P::polar(c.r, ar + th);
    if (si == 0) return 1;
    return 2;
}

int tangent(const C& c, const C& d, L& l, L& r, bool inter) {
    D di = (d.p - c.p).abs(), ar = (d.p - c.p).arg();
    if (sgn(di) == 0) {
        assert(sgn(c.r - d.r));  // prohibit same circles
        return 0;
    }
    D costh = c.r + (inter ? d.r : -d.r);
    int si = sgn(abs(costh), di);
    costh /= di;
    if (si == 1)
        return 0;
    else if (si == 0)
        costh = sgn(costh);
    D th = acos(costh);
    P base;
    base = P::polar(1, ar - th);
    l = L(c.p + base * c.r, d.p + base * d.r * (inter ? -1 : 1));
    base = P::polar(1, ar + th);
    r = L(c.p + base * c.r, d.p + base * d.r * (inter ? -1 : 1));
    if (si == 0) return 1;
    return 2;
}

C circum_circle(P a, P b, P c) {
    b -= a;
    c -= a;
    D s = 2 * crs(b, c);
    D x = (b - c).norm(), y = c.norm(), z = b.norm();
    D S = x + y + z;
    P r = (b * (S - 2 * y) * y + c * z * (S - 2 * z)) / (s * s);
    return C(r + a, r.abs());
}

C smallest_circle(const Pol& p, int i, array<P, 3> q, int j) {
    if (i == int(p.size())) {
        switch (j) {
            case 0:
                return C(P(0, 0), -1);
            case 1:
                return C(q[0], 0);
            case 2:
                return C((q[0] + q[1]) / D(2.0), (q[0] - q[1]).abs() / D(2.0));
            case 3:
                return circum_circle(q[0], q[1], q[2]);
        }
        assert(false);
    }
    C c = smallest_circle(p, i + 1, q, j);
    if (sgn((p[i] - c.p).abs(), c.r) == 1) {
        q[j] = p[i];
        return smallest_circle(p, i + 1, q, j + 1);
    }
    return c;
}
/*C smallest_circle(Pol p) {
    random_shuffle(begin(p), end(p));
    return smallest_circle(p, 0, array<P, 3>(), 0);
}*/

D area2CT(const C& c, const P& _a, const P& _b) {
    P a = _a - c.p, b = _b - c.p;
    D r = c.r;
    if (a == b) return 0;
    auto single = [&](P x, P y, bool tri) {
        if (tri)
            return crs(x, y);
        else
            return r * r * ((y * P(x.x, -x.y)).arg());
    };
    bool ia = sgn(a.abs(), r) != 1, ib = sgn(b.abs(), r) != 1;
    if (ia && ib) return single(a, b, true);
    L l;
    if (!crossCS(C(P(0, 0), r), L(a, b), l)) return single(a, b, false);
    return single(a, l.s, ia) + single(l.s, l.t, true) + single(l.t, b, ib);
}

D area2CPol(const C& c, const Pol& po) {
    D sm = 0;
    P a, b = po.back();
    for (auto p : po) {
        a = b;
        b = p;
        sm += area2CT(c, a, b);
    }
    return sm;
}

/*
// pcp1, p2
int tangent(const C& c, const P& p, P& p1, P& p2) {
    D di = (c.p - p).abs();
    int si = sgn(c.r, di);
    if (si == 1) return 0;
    D th = acos(min(D(1), c.r / di));
    D ar = (p - c.p).arg();
    p1 = c.p + P::polar(c.r, ar - th);
    p2 = c.p + P::polar(c.r, ar + th);
    if (si == 0) return 1;
    return 2;
}
*/

Scanner sc = Scanner(stdin);

int main() {
    int n;
    ll k;
    sc.read(n, k);

    V<P> ps;
    for (int i = 0; i < n; i++) {
        ll x, y;
        sc.read(x, y);
        ps.push_back(P(x, y));
    }

    auto check = [&](D md) {
        C c = C(P(0, 0), md);
        int rem = 0;
        using R = pair<D, int>;
        V<R> rs;
        for (auto p: ps) {
            if (p.abs() < md + 1e-8) {
                continue;
            }
            P c1, c2;
            tangent(c, p, c1, c2);

            D ar1 = c1.arg();
            D ar2 = c2.arg();

            rs.push_back({ar1, rem});
            rs.push_back({ar2, rem});
            rem++;
        }

        sort(rs.begin(), rs.end());

        ll sum = 1LL * n * (n - 1) / 2;

        V<int> pos(rem, -1);
        fenwick_tree<int> fw(2 * rem);
        for (int i = 0; i < 2 * rem; i++) {
            auto r = rs[i];
            int idx = r.second;

            if (pos[idx] == -1) {
                //first
                pos[idx] = i;
            } else {
                //second
                sum -= fw.sum(pos[idx], i);
                fw.add(pos[idx], -1);
                fw.add(i, 1);
            }
        }
        return sum;
    };

    D lw = 1e-9, up = 1e5;
    for (int i = 0; i < 40; i++) {
        D md = (lw + up) / 2;

        if (check(md) < k) {
            lw = md;
        } else {
            up = md;
        }
    }

    printf("%.20Lf\n", (long double)(lw));
    return 0;
}