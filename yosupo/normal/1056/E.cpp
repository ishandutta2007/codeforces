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

namespace H2mod {
using M0 = ModInt<TEN(9) + 7>;
using M1 = ModInt<TEN(9) + 9>;
vector<M0> powB0{1}, powiB0{1};
vector<M1> powB1{1}, powiB1{1};
M0 B0 = rand() % TEN(9) + 1, iB0 = B0.inv();
M1 B1 = rand() % TEN(9) + 1, iB1 = B1.inv();
struct H {
    static void expand(int N) {
        while (int(powB0.size()) <= N) {
            powB0.push_back(powB0.back() * B0);
            powiB0.push_back(powiB0.back() * iB0);
            powB1.push_back(powB1.back() * B1);
            powiB1.push_back(powiB1.back() * iB1);
        }
    }
    M0 d0;
    M1 d1;
    static H make(int x) { return H{x, x}; }
    H operator+(const H& r) const { return H{d0 + r.d0, d1 + r.d1}; }
    H operator-(const H& r) const { return H{d0 - r.d0, d1 - r.d1}; }
    H operator<<(int s) const { return H{d0 * powB0[s], d1 * powB1[s]}; }
    H operator>>(int s) const { return H{d0 * powiB0[s], d1 * powiB1[s]}; }
    bool operator==(const H& r) const {
        return (d0.v == r.d0.v && d1.v == r.d1.v);
    }
};
}  // namespace H2mod
template <class H> struct HashStr {
    vector<H> v;
    string s;
    HashStr(string s) : s(s) {
        int N = (int)s.size();
        H::expand(N);
        v.resize(N + 1);
        v[0] = H::make(0);
        for (int i = 1; i <= N; i++) {
            v[i] = v[i - 1] + (H::make(s[i - 1]) << (i - 1));
        }
    }
    H get(int l, int r) { return (v[r] - v[l]) >> l; }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;
    string s, t;
    cin >> s >> t;
    int n = int(t.size());
    int c0 = 0, c1 = 0;
    for (char c: s) {
        if (c == '0') c0++;
        else c1++;
    }
    auto t_hs = HashStr<H2mod::H>(t);
    int ans = 0;
    for (int l0 = 1; l0 <= n; l0++) {
        if (n <= ll(l0) * c0) break;
        int l1 = (n - l0 * c0) / c1;
        if (l0 * c0 + l1 * c1 != n) continue;
        bool f0 = false, f1 = false, f = true;
        H2mod::H h0, h1;
        int st = 0;
        for (auto c: s) {
            if (c == '0') {
                auto h = t_hs.get(st, st + l0);
                st += l0;
                if (!f0) {
                    f0 = true;
                    h0 = h;
                    continue;
                }
                if (!(h0 == h)) {
                    f = false;
                    break;
                }
            } else {
                auto h = t_hs.get(st, st + l1);
                st += l1;
                if (!f1) {
                    f1 = true;
                    h1 = h;
                    continue;
                }
                if (!(h1 == h)) {
                    f = false;
                    break;
                }
            }
        }
        if (!(h0 == h1) && f) {
            assert(st == n);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}