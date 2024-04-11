#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

uint MD;
struct ModInt {
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
using Mint = ModInt;

const int B = 200200;
V<Mint> fact(B), iFac(B), inv(B), inv_sm(B);
void first() {
    fact[0] = Mint(1);
    for (int i = 1; i < B; i++) fact[i] = fact[i - 1] * Mint(i);
    for (int i = 0; i < B; i++) iFac[i] = fact[i].inv();
    for (int i = 1; i < B; i++) inv[i] = Mint(i).inv();
    for (int i = 1; i < B; i++) inv_sm[i] = inv_sm[i - 1] + inv[i];
}

Mint C(int n, int k) {
    if (n < k || k < 0) return 0;
    return fact[n] * iFac[k] * iFac[n-k];
}

map<int, int> mp;
void dfs(int l, int r, int h) {
    if (l == r) {
        mp[1]++;
        return;
    }
    if (h <= 1) {
        mp[r - l + 1]++;
        return;
    }
    int md = (l + r) / 2;
    dfs(l, md, h-1);
    dfs(md + 1, r, h-1);
}

int main() {
    int n, h;
    cin >> n >> h >> MD;
    first();
    dfs(0, n-1, h);

    auto two = [&](int l1, int l2) {
        Mint ans = 0;
/*        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                ans += fact[l1 + l2 - i - j] * C(l1 + l2, i + j) * fact[i + j] * Mint(i - 1) / Mint(i + j) / Mint(2);
            }
        }
        cerr << "Two " << l1 << " " << l2 << " " << ans << endl;
        return ans * iFac[l1 + l2];*/
        for (int i = 1; i <= l1; i++) {
            ans += Mint(i - 1) * (inv_sm[i + l2] - inv_sm[i]);
            /*for (int j = 1; j <= l2; j++) {
                ans += Mint(i - 1) / Mint(i + j);
            }*/
        }
        return ans / Mint(2);
    };
    using P = pair<int, int>;
    V<P> ps;
    for (auto p: mp) {
        //cout << p.first << " " << p.second << endl;
        ps.push_back(p);
    }
    int k = int(ps.size());
    Mint ans = 0;
    for (int i = 0; i < k; i++) {
        int c1, f1;
        tie(c1, f1) = ps[i];
        ans += Mint(f1) * Mint(c1) * Mint(c1 - 1) / Mint(4);
        ans += Mint(f1) * Mint(f1 - 1) * two(c1, c1);
        for (int j = i + 1; j < k; j++) {
            int c2, f2;
            tie(c2, f2) = ps[j];
            ans += Mint(f1) * Mint(f2) * (two(c1, c2) + two(c2, c1));
        }
    }
    cout << ans << endl;
    return 0;
}