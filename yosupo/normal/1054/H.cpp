#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
template <class T> using VVV = V<VV<T>>;

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

const int MD = 490019;
const int A = 982, B = 499; // A * B + 1 == MD
using Mint = ModInt<MD>;

Mint c;
V<Mint> cpow;
void first() {
    cpow = V<Mint>(MD - 1);
    cpow[0] = 1;
    for (int i = 1; i < MD - 1; i ++) {
        cpow[i] = cpow[i-1] * c;
    }
}

Mint c_pow(ll i, ll j) {
    return cpow[j * j * j % (MD - 1) * i * i % (MD - 1)];
};

Mint solve(const V<Mint>& va, const V<Mint>& vb, ll a, ll b) {
    int n = int(va.size()), m = int(vb.size());
    ll a2 = a * a % (MD - 1), b3 = b * b * b % (MD - 1);
    Mint a_sm, b_sm;
    for (ll i = 0; i < n; i++) {
        ll f = (A*i + a) * (A*i + a) * b3 % (MD - 1);
        a_sm += va[i] * cpow[f];
    }
    for (ll i = 0; i < m; i++) {
        ll f = (B*i + b) * (B*i + b) * (B*i + b) % (MD - 1) * a2 % (MD - 1);
        b_sm += vb[i] * cpow[f];
    }
    return a_sm * b_sm / c_pow(a, b);
}

Mint solve(V<int> _a, V<int> _b) {
    int n = int(_a.size()), m = int(_b.size());
    VV<Mint> a(A), b(B);
    for (int i = 0; i < n; i++) {
        a[i % A].push_back(Mint(_a[i]));
    }
    for (int i = 0; i < m; i++) {
        b[i % B].push_back(Mint(_b[i]));
    }

    Mint sm;
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < B; j++) {
            sm += solve(a[i], b[j], i, j);
        }
    }
    return sm;
}

Mint naive(V<int> a, V<int> b) {
    int n = int(a.size()), m = int(b.size());
    Mint sm;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sm += Mint(a[i]) * Mint(b[j]) * c_pow(i, j);
        }
    }
    return sm;
}

ll rand_int(ll l, ll r) { //[l, r]
    static mt19937 gen(114514);
    return uniform_int_distribution<ll>(l, r)(gen);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;

    int n, m, _c;
//    n = 100000; m = 100000;
//    _c = rand_int(1, 400000);
    cin >> n >> m >> _c;
    c = Mint(_c);
    first();
    V<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        //a[i] = rand_int(0, 1000);
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        //b[i] = rand_int(0, 1000);
        cin >> b[i];
    }
    cout << solve(a, b) << endl;
    return 0;
}