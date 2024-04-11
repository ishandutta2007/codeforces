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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;

    VV<Mint> mat(n, V<Mint>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            //x = 1;
            mat[i][j] = Mint(x) / Mint(100);
        }
    }

    using ST = pair<V<int>, Mint>;
    V<ST> sts;
    sts.push_back(ST({0}, Mint(1)));

    for (int ph = 0; ph < n; ph++) {
        V<ST> nsts;
        for (int f = 1; f < (1 << n); f++) {
            Mint freq = 1;
            for (int i = 0; i < n; i++) {
                if ((f >> i) & 1) {
                    freq *= mat[ph][i];
                } else {
                    freq *= Mint(1) - mat[ph][i];
                }
            }
            for (auto st: sts) {
                V<int> nst;
                for (auto d: st.first) {
                    for (int i = 0; i < n; i++) {
                        if ((d >> i) & 1) continue;
                        if (!((f >> i) & 1)) continue;
                        nst.push_back(d ^ (1 << i));
                    }
                }
                if (nst.empty()) continue;
                sort(nst.begin(), nst.end());
                nst.erase(unique(nst.begin(), nst.end()), nst.end());
                nsts.push_back({nst, st.second * freq});
            }
        }
        sort(nsts.begin(), nsts.end(), [&](const ST& l, const ST& r) {
            return l.first < r.first;
        });

        sts.clear();
        for (auto st: nsts) {
            if (sts.size() && sts.back().first == st.first) {
                sts.back().second += st.second;
            } else {
                sts.push_back(st);
            }
        }
        dbg(ph, nsts.size());
        //dbg(nst);
    }

    dbg(sts);

    Mint ans = (sts.empty() ? Mint(0) : sts[0].second);

    cout << ans << endl;

    return 0;
}