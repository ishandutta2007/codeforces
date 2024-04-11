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


template<uint MD>
struct ModInt {
    using M = ModInt;
    uint v;
    ModInt() : v{0} {}
    ModInt(ll v) : v{normS(v%MD+MD)} {}
    explicit operator bool() const {return v != 0;}
    static uint normS(uint x) {return (x<MD)?x:x-MD;};
    static M make(uint x) {M m; m.v = x; return m;}
    static M inv(const M &x) {return x.pow(MD-2); }
    M operator+(const M &r) const {return make(normS(v+r.v));}
    M operator-(const M &r) const {return make(normS(v+MD-r.v));}
    M operator*(const M &r) const {return make(ull(v)*r.v%MD);}
    M operator/(const M &r) const {return *this*inv(r);}
    M& operator+=(const M &r) {return *this=*this+r;}
    M& operator-=(const M &r) {return *this=*this-r;}
    M& operator*=(const M &r) {return *this=*this*r;}
    M& operator/=(const M &r) {return *this=*this/r;}
    M pow(ll n) const {
        M x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
};
using Mint = ModInt<TEN(9)+9>;

// c^0 + c^1 + c^2 + ... + c^(fr-1)
Mint f(Mint c, ll fr) {
    if (fr == 0) return Mint(0);
    if (fr % 2) return f(c, fr-1) * c + Mint(1);
    Mint u = f(c, fr/2);
    return u + u * c.pow(fr/2);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    ll n, a, b, k;
    cin >> n >> a >> b >> k; n++;
    Mint offset = Mint(a).pow(n-1);
    Mint c = Mint::inv(Mint(a)) * Mint(b);

    string s;
    cin >> s;
    ll fr = n/k;

    Mint ans = Mint(0);

    Mint single = Mint(0);
    Mint base = Mint(1);
    for (ll i = 0; i < k; i++) {
        if (s[i] == '+') single += base;
        else single -= base;
        base *= c;
    }
    ans += single * f(c.pow(k), fr);

    {
        Mint base = c.pow(fr*k);
        for (ll i = fr*k; i < n; i++) {
            if (s[i-fr*k] == '+') ans += base;
            else ans -= base;
            base *= c;
        }
    }

    cout << (ans * offset).v << endl;
    return 0;
}