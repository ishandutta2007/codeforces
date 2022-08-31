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
using Mint = ModInt<TEN(9) + 7>;
// template<> const Mint Mint::G = Mint(3);

ll gcd(ll a, ll b) {
    while (b) {
        ll c = a % b;
        a = b;
        b = c;
    }
    return a;
}

using P = pair<ll, int>;

VV<P> dp;
V<ll> a;
VV<int> g;
Mint sm;

void dfs(int p, int b) {
    if (b == -1) {
        sm += a[p];
        dp[p].push_back({a[p], 1});
    } else {
        V<P> buf;
        buf.push_back({a[p], 1});
        for (auto pa: dp[b]) {
            buf.push_back({gcd(pa.first, a[p]), pa.second});
        }
        sort(buf.begin(), buf.end());
        for (auto pa: buf) {
            sm += Mint(pa.first * pa.second);
            if (dp[p].size() && dp[p].back().first == pa.first) {
                dp[p].back().second += pa.second;
            } else {
                dp[p].push_back(pa);
            }
        }
    }
//    dbg(p, dp[p]);
    for (int d: g[p]) {
        if (d == b) continue;
        dfs(d, p);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    a = V<ll>(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    g = VV<int>(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y; 
        cin >> x >> y; x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dp = VV<P>(n);
    dfs(0, -1);
    cout << sm << endl;
    return 0;
}