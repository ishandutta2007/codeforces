#include <bits/stdc++.h>
#include <ostream>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template <uint MD> struct ModInt {
    using M = ModInt;
    uint v;
    ModInt() : v(0) {}
    ModInt(ll _v) { set_v(_v % MD + MD); }
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

const int MD = 51;

V<ll> factor(ll n) {
    V<ll> res;
    for (ll i = 2; i*i <= n; i++) {
        while (n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }
    if (n > 1) res.push_back(n);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; int tm; cin >> n >> tm;

    auto fa = factor(n);
    map<ll, int> mp;
    for (ll d: fa) mp[d]++;

    VV<Mint> dp(MD, V<Mint>(MD)), ndp(MD, V<Mint>(MD));
    for (int i = 0; i < MD; i++) dp[i][i] = Mint(1);
    V<Mint> inv_i(MD + 1);
    for (int i = 0; i <= MD; i++) inv_i[i] = Mint(i).inv();

    for (int ph = 0; ph < tm; ph++) {
        for (int i = 0; i < MD; i++) {
            for (int j = 0; j <= i; j++) {
                ndp[i][j] = Mint(0);
                for (int k = j; k <= i; k++) {
                    ndp[i][j] += dp[i][k] * inv_i[k + 1];
                }
            }
        }
        swap(dp, ndp);
    }

    Mint ans = 1;
    for (auto p: mp) {
        int cnt = p.second;
        Mint g = Mint(p.first);
        Mint sm = 0, f = 1;
        for (int i = 0; i <= cnt; i++) {
            sm += dp[cnt][i] * f;
            f *= g;
        }
        ans *= sm;
    }

    cout << ans << endl;
    return 0;
}