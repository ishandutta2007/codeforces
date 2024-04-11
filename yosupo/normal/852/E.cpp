#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;


template <uint MD> struct ModInt {
    using M = ModInt;
    uint v;
    ModInt() : v{0} {}
    ModInt(ll _v) { set_v(_v % MD + MD); }
    M& set_v(uint _v) {
        v = (_v < MD) ? _v : _v - MD;
        return *this;
    }
    explicit operator bool() const { return v != 0; }
    M operator-() const { return M(0) - *this; }
    M operator+(const M& r) const { return M().set_v(v + r.v); }
    M operator-(const M& r) const { return M().set_v(v + MD - r.v); }
    M operator*(const M& r) const { return M().set_v(ull(v) * r.v % MD); }
    M operator/(const M& r) const { return *this * r.inv(); }
    M& operator+=(const M& r) { return *this = *this + r; }
    M& operator-=(const M& r) { return *this = *this - r; }
    M& operator*=(const M& r) { return *this = *this * r; }
    M& operator/=(const M& r) { return *this = *this / r; }
    M pow(ll n) const {
        M x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    M inv() const { return (*this).pow(MD - 2); }
    friend ostream& operator<<(ostream& os, const M& r) { return os << r.v; }
};
using Mint = ModInt<TEN(9) + 7>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;
    int n;
    cin >> n;
    VV<int> g(n);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        g[a].push_back(b); g[b].push_back(a);
    }

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    int lc = 0;
    for (int i = 0; i < n; i++) if (g[i].size() == 1) lc++;

    cout << Mint(2).pow(n - lc) * Mint(n - lc) + Mint(2).pow(n - lc + 1) * Mint(lc) << endl;
    return 0;
}