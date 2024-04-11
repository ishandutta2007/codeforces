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
    rng(int r) : l(0), r(r) {}
    rng(int l, int r) : l(l), r(r) {}
    A begin() { return A{l}; }
    A end() { return A{r}; }
};

template<class T>
T pow(T x, ll n, T r = 1) {
    while (n) {
        if (n & 1) r *= x;
        x *= x;
        n >>= 1;
    }
    return r;
}

template<uint MD>
struct ModInt {
    uint v;
    ModInt() : v{0} {}
    ModInt(ll v) : v{normS(v%MD+MD)} {}
    explicit operator bool() const {return v != 0;}
    static uint normS(const uint &x) {return (x<MD)?x:x-MD;};
    static ModInt make(const uint &x) {ModInt m; m.v = x; return m;}
    static ModInt inv(const ModInt &x) {return pow(ModInt(x), MD-2);} 
    ModInt operator+(const ModInt &r) const {return make(normS(v+r.v));}
    ModInt operator-(const ModInt &r) const {return make(normS(v+MD-r.v));}
    ModInt operator*(const ModInt &r) const {return make((ull)v*r.v%MD);}
    ModInt operator/(const ModInt &r) const {return *this*inv(r);}
    ModInt& operator+=(const ModInt &r) {return *this=*this+r;}
    ModInt& operator-=(const ModInt &r) {return *this=*this-r;}
    ModInt& operator*=(const ModInt &r) {return *this=*this*r;}
    ModInt& operator/=(const ModInt &r) {return *this=*this/r;}
};
template<uint MD> string to_string(ModInt<MD> m) {return to_string(m.v);}
using Mint = ModInt<TEN(9)+7>;

Mint fact[10000];
Mint iFac[10000];
void first() {
    fact[0] = 1;
    for (int i: rng(1, 10000)) {
        fact[i] = fact[i-1] * i;
    }
    for (int i: rng(10000)) {
        iFac[i] = Mint(1) / fact[i];
    }
}

ll chk(ll x) {
    ll y = 1;
    for (ll i = 2; i*i <= x; i++) {
        if (x % i) continue;
        int c = 0;
        while (x % i == 0) {
            c = 1-c;
            x /= i;
        }
        if (c) y *= i;
    }
    return y * x;
}

const int MN = 310;

Mint C(int n, int k) {
    if (n < k || n < 0) return 0;
    return fact[n] * iFac[k] * iFac[n-k];
}


Mint solve(V<int> v) {
    int n = int(v.size());
    Mint ans = 1;
    for (int d: v) {
        ans *= fact[d];
    }

    V<Mint> dp(MN);
    int dsm = v.back();
    dp[v.back()-1] = 1;
    v.pop_back();
    for (int d: v) {
//        cout << "Start " << d << endl;
        V<Mint> ndp(MN);
        for (int k = 0; k <= dsm-1; k++) {
            for (int x = 1; x <= d; x++) {
                Mint base = C(d-1, x-1);
                for (int y = 0; y <= x; y++) {
                    if (k < y) continue;
                    if (dsm+1-k < x-y) continue;
                    ndp[k - y + (d - x)] += dp[k] * base * C(k, y) * C(dsm+1-k, x-y);
                }
            }
        }
        dsm += d;
        dp = ndp;
/*        for (int i: rng(10)) {
            cout << dp[i].v << ", ";
        }
        cout << endl;*/
    }
    return ans * dp[0];
}

int main() {
    first();
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int n;
    cin >> n;
    map<ll, int> mp;
    for (int i: rng(n)) {
        ll a;
        cin >> a;
        mp[chk(a)]++;
    }
    V<int> v;
    for (auto p: mp) {
        v.push_back(p.second);
    }
    cout << solve(v).v << endl;
    return 0;
}