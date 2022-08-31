//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
//#undef LOCAL
#include <bits/stdc++.h>

using namespace std;
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

template <uint MD> struct ModInt {
    using M = ModInt;
    const static M G;
    uint v;
    ModInt(ll _v = 0) { set_v(_v % MD + MD); }
    M& set_v(uint _v) {
        v = (_v < MD) ? _v : _v - MD;
        return *this;
    }
    explicit operator bool() const { return v != 0; }
    M operator-() const { return M() - *this; }
    M operator+(const M& r) const { return M().set_v(v + r.v); }
    M operator-(const M& r) const { return M().set_v(v + MD - r.v); }
    M operator*(const M& r) const { return M().set_v(ull(v) * r.v % MD); }
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
// template<> const Mint Mint::G = Mint(3);
const int MN = 10000;
V<Mint> fact(MN), iFac(MN);
void init() {
    fact[0] = Mint(1);
    for (int i = 1; i < MN; i++) {
        fact[i] = fact[i - 1] * Mint(i);
    }
    for (int i = 0; i < MN; i++) {
        iFac[i] = fact[i].inv();
    }
}

Mint C(int n, int k) {
    if (n < k || k < 0) return Mint(0);
    return fact[n] * iFac[k] * iFac[n - k];
}

V<Mint> solve(V<int> g) {
    int n = int(g.size());
    V<Mint> dp0(n + 1);
    V<Mint> dp1(n + 1);
    dp1[0] = Mint(1);
    for (int tm = 0; tm < n; tm++) {
        V<Mint> ndp(n + 1);
        // use
        if (tm && g[tm-1] == 0 && g[tm] == 0) {
            for (int i = 0; i < n; i++) {
                ndp[i + 1] += dp0[i];
            }
        }
        // non use
        for (int i = 0; i <= n; i++) {
            ndp[i] += dp1[i];
        }
        dp0 = dp1;
        dp1 = ndp;
    }
    return dp1;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    init();
    int h, w, n;
    cin >> h >> w >> n;

    V<int> gy(h), gx(w);
    for (int i = 0; i < n; i++) {
        int r0, c0, r1, c1;
        cin >> r0 >> c0 >> r1 >> c1;
        r0--; c0--; r1--; c1--;
        gy[r0] = 1;
        gx[c0] = 1;
        gy[r1] = 1;
        gx[c1] = 1;
    }

    auto dpy = solve(gy);
    auto dpx = solve(gx);
    int remy = 0, remx = 0;
    for (auto d: gy) if (!d) remy++;
    for (auto d: gx) if (!d) remx++;

/*    dbg(dpy);
    dbg(dpx);
    dbg(remy);
    dbg(remx);*/

    Mint ans = Mint(0);
    for (int twoy = 0; twoy <= h; twoy++) {
        for (int twox = 0; twox <= w; twox++) {
            Mint buf = 1;
            buf *= dpy[twoy] * C(remx - 2 * twox, twoy);
            buf *= dpx[twox] * C(remy - 2 * twoy, twox);
            ans += buf * fact[twoy] * fact[twox];
        }
    }
    cout << ans << endl;
    return 0;
}