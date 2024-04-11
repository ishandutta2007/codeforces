//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
//#undef LOCAL


#include <algorithm>
#include <cassert>
#include <vector>


#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder


#include <unistd.h>
#include <algorithm>
#include <array>
#include <cassert>
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
int popcnt(unsigned long n) { return __builtin_popcountll(n); }

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

    template <class T, std::enable_if_t<std::is_same<T, char>::value>* = nullptr>
    bool read_single(T& ref) {
        if (!skip_space(50)) return false;
        ref = top();
        st++;
        return true;
    }

    template <class T, internal::is_signed_int_t<T>* = nullptr, std::enable_if_t<!std::is_same<T, char>::value>* = nullptr>
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
    template <class U, internal::is_unsigned_int_t<U>* = nullptr, std::enable_if_t<!std::is_same<U, char>::value>* = nullptr>
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
        if (pos) {
            auto res = ::write(fd, line, pos);
            assert(res != -1);
            pos = 0;
        }
    }

  private:
    static std::array<std::array<char, 2>, 100> small;
    static std::array<unsigned long long, 20> tens;

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
              std::enable_if_t<sizeof(U) <= 8>* = nullptr>
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

    template <
        class U,
        std::enable_if_t<internal::is_unsigned_int128<U>::value>* = nullptr>
    void write_unsigned(U uval) {
        static char buf[50];
        size_t len = 0;
        while (uval > 0) {
            buf[len++] = char((uval % 10) + '0');
            uval /= 10;
        }
        std::reverse(buf, buf + len);
        memcpy(line + pos, buf, len);
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

using Pi = pair<int, int>;
Pi op(Pi a, Pi b) { return max(a, b); }
Pi e() { return Pi(-1, -1); }


Scanner sc = Scanner(stdin);
Printer pr = Printer(stdout);

int main() {
    int n, q;
    sc.read(n, q);

    V<Pi> p(n);
    for (int i = 0; i < n; i++) {
        sc.read(p[i].first);
        p[i].first--;
        p[i].second = i;
    }
    p.push_back({n, n});

    V<int> nx(n + 1, n + 1);
    {
        V<int> st;
        st.push_back(n);
        for (int i = n - 1; i >= 0; i--) {
            while (p[st.back()] < p[i]) st.pop_back();
            nx[i] = st.back();
            st.push_back(i);
        }
    }
    dbg(nx);

    auto seg = atcoder::segtree<Pi, op, e>(p);

    V<ll> a(n + 1), b(n + 1);
    for (int i = 0; i < n; i++) {
        sc.read(a[i]);
    }
    for (int i = 0; i < n; i++) {
        sc.read(b[i]);
    }


    VV<Pi> buf(n);
    auto add_q = [&](int l, int r) {
        dbg(l, r);
        if (r - l == 1) return;
        int m = seg.prod(l + 1, r).second;
        buf[m].push_back({l, r});
        dbg("add_q", l, r);
    };
    V<int> xs(q);
    {
        set<int> st;
        st.insert(0);
        st.insert(n);
        add_q(0, n);

        for (int ph = 0; ph < q; ph++) {
            sc.read(xs[ph]);
            xs[ph]--;
            int i = xs[ph];
            if (!i) continue;
            if (st.count(i)) {
                st.erase(i);
                auto it = st.lower_bound(i);
                int l = *prev(it);
                int r = *it;
                add_q(l, r);
            } else {
                auto it = st.lower_bound(i);
                int l = *prev(it);
                int r = *it;
                add_q(l, r);
                add_q(l, i);
                add_q(i, r);
                st.insert(i);
            }
        }
    }

    struct D {
        deque<ll> d;
        ll off = 0;
        void pf(ll x) { d.push_front(x - off); }
        void pb(ll x) { d.push_back(x - off); }

        ll f() { return d.front() + off; }
        ll b() { return d.back() + off; }

        V<ll> val() const {
            V<ll> a;
            for (auto x : d) {
                a.push_back(x + off);
            }
            return a;
        }
    };
    map<Pi, ll> ques;
    V<ll> one(n);
    using P = pair<D, D>;
    auto solve = [&](auto self, int l, int r) -> P {
        dbg(l, r);
        if (l + 1 == r) {
            D ld, rd;
            ll c = a[l];
            if (nx[l] == r) c = min(c, b[l]);

            one[l] = c;
            ld.d = {0, c};
            rd.d = {c, 0};
            return P(ld, rd);
        }
        int m = seg.prod(l + 1, r).second;
        auto ld = self(self, l, m);
        auto rd = self(self, m, r);

        for (auto pi: buf[m]) {
            ll c = ld.second.d[pi.first - l] + ld.second.off + rd.first.d[pi.second - m] + rd.first.off;
            ques[pi] = c;
        }

        rd.first.off += ld.first.b();
        ld.second.off += rd.second.f();

        P d;
        if (m - l < r - m) {
            ld.first.d.pop_back();
            ld.second.d.pop_back();
            for (int i = m - 1; i >= l; i--) {
                rd.first.pf(ld.first.b());
                rd.second.pf(ld.second.b());
                ld.first.d.pop_back();
                ld.second.d.pop_back();
            }
            d = std::move(rd);
        } else {
            rd.first.d.pop_front();
            rd.second.d.pop_front();
            for (int i = m + 1; i <= r; i++) {
                ld.first.pb(rd.first.f());
                ld.second.pb(rd.second.f());
                rd.first.d.pop_front();
                rd.second.d.pop_front();
            }
            d = std::move(ld);
        }

        if (nx[l] == r) {
            ll c = min(d.first.b(), b[l]);
            d.first.d.pop_back();
            d.second.d.pop_front();
            d.first.pb(c);
            d.second.pf(c);
        }
        dbg(l, r, d.first.val(), d.second.val());

        return d;
    };

    solve(solve, 0, n);

    auto calc_q = [&](int l, int r) {
        if (r - l == 1) return one[l];
        dbg("calc_q", l, r);
        assert(ques.count({l, r}));
        ll c = ques[{l, r}];
        if (nx[l] == r) c = min(c, b[l]);
        return c;
    };

    ll answer = calc_q(0, n);
    set<int> st;
    st.insert(0);
    st.insert(n);
    for (int i : xs) {
        if (i) {
            if (st.count(i)) {
                st.erase(i);
                auto it = st.lower_bound(i);
                int l = *prev(it);
                int r = *it;
                answer -= calc_q(l, i);
                answer -= calc_q(i, r);
                answer += calc_q(l, r);
            } else {
                auto it = st.lower_bound(i);
                int l = *prev(it);
                int r = *it;
                answer -= calc_q(l, r);
                answer += calc_q(l, i);
                answer += calc_q(i, r);
                st.insert(i);
            }
        }

        pr.writeln(answer);
    }
    return 0;
}