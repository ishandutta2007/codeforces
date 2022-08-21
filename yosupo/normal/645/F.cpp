#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}

/// x^n
template<class T>
T pow(T x, ll n) {
    T r = 1;
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
    ModInt() : v(0) {}
    ModInt(ll v) : v(normS(v%MD+MD)) {}
    uint value() {return v;}
    static uint normS(const uint &x) {return (x<MD)?x:x-MD;};
    static ModInt make(const uint &x) {ModInt m; m.v = x; return m;}
    const ModInt operator+(const ModInt &r) const {return make(normS(v+r.v));}
    const ModInt operator-(const ModInt &r) const {return make(normS(v+normS(MD-r.v)));}
    const ModInt operator*(const ModInt &r) const {return make((ull)v*r.v%MD);}
    ModInt& operator+=(const ModInt &r) {return *this=*this+r;}
    ModInt& operator-=(const ModInt &r) {return *this=*this-r;}
    ModInt& operator*=(const ModInt &r) {return *this=*this*r;}
    static ModInt inv(const ModInt &x) {
        return pow(ModInt(x), MD-2);
    }
};
const ll MD = 1e9+7;
using Mint = ModInt<MD>;

const int MN = 200100;
const int D = 1001001;

int k;
Mint comb[MN];

Mint sm;

Mint kei[D+1];

int co[D+1];

void cop(int x) {
    sm -= comb[co[x]] * kei[x];
    co[x]++;
    sm += comb[co[x]] * kei[x];
}

void addn(int x) {
    for (int i = 1; i*i <= x; i++) {
        if (x % i == 0) {
            cop(i);
            if (i*i != x) cop(x/i);
        }
    }
}

Mint fact[MN], ifac[MN];

void init() {
    for (int i = 1; i <= D; i++) {
        kei[i] = Mint(i) - kei[i];
        for (int j = 2*i; j <= D; j += i) {
            kei[j] += kei[i];
        }
    }
    fact[0] = 1;
    for (int i = 1; i < MN; i++) {
        fact[i] = fact[i-1] * i;
    }
    for (int i = 0; i < MN; i++) {
        ifac[i] = Mint::inv(fact[i]);
    }
    for (int i = 0; i < k; i++) {
        comb[i] = 0;
    }
    for (int i = k; i < MN; i++) {
        comb[i] = fact[i]*ifac[k]*ifac[i-k];
    }
}

int main() {
    int n, q;
    scanf("%d %d %d", &n, &k, &q);
    init();
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        addn(x);
    }
    for (int i = 0; i < q; i++) {
        int x;
        scanf("%d", &x);
        addn(x);
        printf("%d\n", sm.v);
    }
    return 0;
}