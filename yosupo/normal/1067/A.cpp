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

V<int> a;
Mint solve(int p, int q, int b);

Mint dp_sm[100100][202][2];
bool vis_sm[100100][202][2];
Mint solve_sm(int p, int up, int b) {
    if (up == 1) return 0;
    if (vis_sm[p][up][b]) return dp_sm[p][up][b];
    vis_sm[p][up][b] = true;
    return dp_sm[p][up][b] = solve(p, up - 1, b) + solve_sm(p, up - 1, b);
}

Mint dp[100100][202][2];
bool vis[100100][202][2];
Mint solve(int p, int q, int b) {
    if (p == -1) {
        if (b == 1) return 1;
        return 0;
    }
    if (vis[p][q][b]) return dp[p][q][b];
    vis[p][q][b] = true;
    Mint& sm = dp[p][q][b]; sm = 0;
    if (a[p] != -1) {
        int i = a[p];
        if (b || i >= q) sm = solve(p - 1, i, i <= q);
    } else {
        if (b == 0) {
            sm = solve(p - 1, q, true);
            sm += solve_sm(p - 1, 201, false);
            sm -= solve_sm(p - 1, q + 1, false);
            //q+1, ...
        } else {
            sm += solve_sm(p - 1, q + 1, true);
            sm += solve_sm(p - 1, 201, false);
            sm -= solve_sm(p - 1, q + 1, false);
        }
    }
    return sm;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;

    int n;
    cin >> n;
    a = V<int>(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << solve(n - 1, 0, 1) << endl;
    return 0;
}