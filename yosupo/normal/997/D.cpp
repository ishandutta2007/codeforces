//#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2")
//#undef LOCAL
#include <bits/stdc++.h>
using namespace std;

#pragma region template

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

#ifdef LOCAL
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

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    return os << "P(" << p.first << ", " << p.second << ")";
}

template <class T> ostream& operator<<(ostream& os, const V<T>& v) {
    os << "[";
    for (auto d : v) os << d << ", ";
    return os << "]";
}

struct Scanner {
    FILE* fp = nullptr;
    char line[1 << 15];
    size_t st = 0, ed = 0;
    void reread() {
        memmove(line, line + st, ed - st);
        ed -= st;
        st = 0;
        ed += fread(line + ed, 1, (1 << 15) - ed, fp);
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
    template <bool F> void writeln() { write_single('\n'); }
    template <bool F = false, class H, class... T>
    void writeln(const H& h, const T&... t) {
        if (F) write_single(' ');
        write_single(h);
        writeln<true>(t...);
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
            val = -val;  // todo min
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

#pragma endregion

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
using Mint = ModInt<998244353>;
template<> const Mint Mint::G = Mint(3);

const int MK = 40;
const int MN = 4040;
Mint cy0[MK];
Mint cy1[MK];

void calc(int n, VV<int> tr, Mint cy[MK]) {
    static Mint dp[2][MN][MN];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[0][i][j] = Mint(0);
        }
        dp[0][i][i] = Mint(1);
    }
    for (int tm = 0; tm < MK; tm++) {
        int ty = tm % 2;
        for (int i = 0; i < n; i++) {
            ull sum = 0;
            for (int j = 0; j < n; j++) {
                dp[1 - ty][i][j] = Mint(0);
                sum += ull(dp[ty][i][j].v) * ull(dp[ty][i][j].v);
                if (j % 8 == 0) sum %= 998244353;
                //cy[tm] += dp[ty][i][j] * dp[ty][i][j];
            }
            cy[tm] += Mint(sum);
        }
        for (int i = 0; i < n; i++) {
            for (int j: tr[i]) {
                for (int k = 0; k < n; k++) {
                    dp[1 - ty][i][k] += dp[ty][j][k];
                }
            }
        }
/*        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k: tr[j]) {
                    dp[1 - ty][i][k] += dp[ty][i][j];
                }
            }
        }*/
        /*for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = ndp[i][j];
            }
        }*/
    }
}

V<Mint> fact, iFac;
void init() {
    fact = V<Mint>(MN + 1);
    fact[0] = Mint(1);
    for (int i = 1; i <= MN; i++) {
        fact[i] = fact[i - 1] * Mint(i);
    }
    iFac = V<Mint>(MN + 1);
    iFac[MN] = fact[MN].inv();
    for (int i = MN; i >= 1; i--) {
        iFac[i - 1] = iFac[i] * Mint(i);
    }
    assert(fact[2929] * iFac[2929] == 1);
}

Mint C(int n, int k) {
    if (n < k || k < 0) return Mint(0);
    return fact[n] * iFac[k] * iFac[n - k];
}

int main() {
    init();
    Scanner sc(stdin);
    Printer pr(stdout);
    int n, m, k;
    sc.read(n, m, k);
    
    if (k % 2) {
        pr.writeln(0);
        return 0;
    }
    k /= 2;
    VV<int> tr0(n), tr1(m);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        sc.read(a, b); a--; b--;
        //a = i; b = i + 1;
        tr0[a].push_back(b);
        tr0[b].push_back(a);
    }
    for (int i = 0; i < m - 1; i++) {
        int a, b;
        sc.read(a, b); a--; b--;
        //a = i; b = i + 1;
        tr1[a].push_back(b);
        tr1[b].push_back(a);
    }

    calc(n, tr0, cy0);
    calc(m, tr1, cy1);

    Mint sum = Mint(0);
    for (int l = 0; l <= k; l++) {
        sum += C(2 * k, 2 * l) * cy0[l] * cy1[k - l];
    }
    pr.writeln(sum.v);
    return 0;
}