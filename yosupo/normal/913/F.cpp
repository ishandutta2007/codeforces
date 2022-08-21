#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

struct rng {
    struct A {
        int n;
        const bool operator!=(A r) { return n != r.n; }
        A& operator++() { n++; return *this; }
        int operator*() { return n; }
    };
    int l, r;
    rng(int r) : l(0), r(max(0, r)) {}
    rng(int l, int r) : l(l), r(max(l, r)) {}
    A begin() { return A{l}; }
    A end() { return A{r}; }
};

template<class T>
T pow(T x, ll n, T r) {
    while (n) {
        if (n & 1) r *= x;
        x *= x;
        n >>= 1;
    }
    return r;
}
template<class T> T pow(T x, ll n) { return pow(x, n, T(1)); }

template<uint MD>
struct ModInt {
    uint v;
    ModInt() : v{0} {}
    ModInt(ll v) : v{normS(v%MD+MD)} {}
    explicit operator bool() const {return v != 0;}
    static uint normS(uint x) {return (x<MD)?x:x-MD;};
    static ModInt make(uint x) {ModInt m; m.v = x; return m;}
    static ModInt inv(const ModInt &x) {return pow(ModInt(x), MD-2);} 
    ModInt operator+(const ModInt &r) const {return make(normS(v+r.v));}
    ModInt operator-(const ModInt &r) const {return make(normS(v+MD-r.v));}
    ModInt operator*(const ModInt &r) const {return make(ull(v)*r.v%MD);}
    ModInt operator/(const ModInt &r) const {return *this*inv(r);}
    ModInt& operator+=(const ModInt &r) {return *this=*this+r;}
    ModInt& operator-=(const ModInt &r) {return *this=*this-r;}
    ModInt& operator*=(const ModInt &r) {return *this=*this*r;}
    ModInt& operator/=(const ModInt &r) {return *this=*this/r;}
};
template<uint MD> string to_string(ModInt<MD> m) {return to_string(m.v);}
using Mint = ModInt<998244353>;

const int MN = 2020;

Mint powP[MN];
Mint pow1P[MN];

Mint f[MN][MN];
Mint g[MN][MN];

Mint dp[MN];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    int n;
    int a, b;
    cin >> n >> a >> b;
    Mint p = Mint(a) / Mint(b);
    Mint np = Mint(1) - p;

    powP[0] = Mint(1);
    pow1P[0] = Mint(1);
    for (int i = 1; i < MN; i++) {
        powP[i] = powP[i-1] * p;
        pow1P[i] = pow1P[i-1] * np;
    }
    
    for (int i = 0; i <= n; i++) {
        g[i][i] = Mint(1);        
    }

    for (int i = 1; i <= n; i++) {
        g[i][0] = Mint(1);
        for (int j = 1; j < i; j++) {
            g[i][j] += g[i-1][j] * powP[j];
            g[i][j] += g[i-1][j-1] * pow1P[i-j];
        }
    }

    f[1][1] = Mint(1);
    for (int i = 2; i <= n; i++) {
        f[i][i] = Mint(1);
        for (int j = 1; j < i; j++) {
            f[i][j] = f[j][j] * g[i][j];
            f[i][i] -= f[i][j];
        }
    }
/*
    cout << "DEBUG" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << g[i][j].v << " ";
        }
        cout << endl;
    }
    cout << "DEBUG2" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << f[i][j].v << " ";
        }
        cout << endl;
    }*/


    dp[0] = Mint(0);
    dp[1] = Mint(0);
    dp[2] = Mint(1);
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            Mint x = Mint(j) * Mint(i-j) + Mint(j * (j-1) / 2);
            dp[i] += f[i][j] * (x + dp[j] + dp[i-j]);
        }
        dp[i] += f[i][i] * Mint(i * (i-1) / 2);
        dp[i] /= Mint(1) - f[i][i];
    }
/*
    cout << "last" << endl;
    for (int i = 0; i <= n; i++) {
        cout << dp[i].v << endl;
    }*/ cout << dp[n].v << endl;
    return 0;
}