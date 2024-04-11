#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#undef LOCAL
#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

#ifdef LOCAL
#define show(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define show(x) true
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

struct UnionFind {
    V<int> p, r;
    int gn;
    UnionFind(int n = 0) : p(n, -1), r(n, 1), gn(n) {}
    void merge(int a, int b) {
        int x = group(a), y = group(b);
        if (x == y) return;  // same
        gn--;
        if (r[x] < r[y]) {
            p[x] = y;
        } else {
            p[y] = x;
            if (r[x] == r[y]) r[x]++;
        }
    }
    int group(int a) {
        if (p[a] == -1) return a;
        return p[a] = group(p[a]);
    }
    bool same(int a, int b) { return group(a) == group(b); }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    int m = int(s.size());
    if (s.front() == '1') {
        cout << 0 << endl;
        return 0;
    }
    string s_base = s;

    auto flip = [&](int p) {
        if (s[p] == '?') return;
        s[p] = (s[p] == '0' ? '1' : '0');
    };
    Mint sm;
    for (int k = m - 1; k >= 1; k--) {
        s = s_base;
        flip(m - 1);
        if (m > 1) flip(0);
        flip(k - 1);
        if (k > 1) flip(0);

        int gc = ((m + 1) / 2 - 1 + (k + 1) / 2 - 1);
        auto uf = UnionFind(2 * (gc + 1));
        bool er = false;

        show(s);
        show(gc);
        for (int i = 0; i < m; i++) {
            int aid = gc;
            if (1 <= i && i <= m - 2) {
                aid = min(i - 1, m - 2 - i);
            }
            int bid = gc;
            if (1 <= i && i <= k - 2) {
                bid = ((m + 1) / 2 - 1 + min(i - 1, k - 2 - i));
            }
            show(i);
            show(aid);
            show(bid);
            if (s[i] == '0') {
                uf.merge(aid * 2, bid * 2);
                uf.merge(aid * 2 + 1, bid * 2 + 1);
            }
            if (s[i] == '1') {
                uf.merge(aid * 2, bid * 2 + 1);
                uf.merge(aid * 2 + 1, bid * 2);
            }
        }

        for (int i = 0; i <= gc; i++) {
            if (uf.same(i * 2, i * 2 + 1)) {
                er = true;
                break;
            }
        }

        if (er) continue;
        assert(uf.gn % 2 == 0);
        show(k);
        sm += Mint(2).pow(uf.gn / 2 - 1);
    }
    cout << sm << endl;
    return 0;
}