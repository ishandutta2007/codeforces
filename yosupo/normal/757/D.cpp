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
int bsr(int x) { return 31 - __builtin_clz(x); }

template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

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
    ModInt() : v{0} {}
    ModInt(ll v) : v{normS(v%MD+MD)} {}
    static uint normS(const uint &x) {return (x<MD)?x:x-MD;};
    static ModInt make(const uint &x) {ModInt m; m.v = x; return m;}
    ModInt operator+(const ModInt &r) const {return make(normS(v+r.v));}
    ModInt operator-(const ModInt &r) const {return make(normS(v+MD-r.v));}
    ModInt operator*(const ModInt &r) const {return make((ull)v*r.v%MD);}
    ModInt& operator+=(const ModInt &r) {return *this=*this+r;}
    ModInt& operator-=(const ModInt &r) {return *this=*this-r;}
    ModInt& operator*=(const ModInt &r) {return *this=*this*r;}
    static ModInt inv(const ModInt &x) {
        return pow(ModInt(x), MD-2);
    }
};
using Mint = ModInt<TEN(9)+7>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int n;
    cin >> n;
    string s;
    cin >> s;
    V<int> nx1(n+1); nx1[n] = n;
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == '1') nx1[i] = i;
        else nx1[i] = nx1[i+1];
    }

    static Mint dp[80][1<<20];
    for (int f = 0; f < (1<<20); f++) {
        if (f && __builtin_popcount(f+1) == 1) dp[n][f] = 1;
    }
    for (int i = n-1; i >= 0; i--) {
        int u = nx1[i];
        for (int f = 0; f < (1<<20); f++) {
            dp[i][f] = 0;
            if (f && __builtin_popcount(f+1) == 1) dp[i][f] = 1;
        }
        int d = 0;
        for (int j = u+1; j <= min(n, u+5); j++) {
            if (s[j-1] == '1') d++;
            if (d > 20) break;
            for (int f = 0; f < (1<<20); f++) {
                dp[i][f] += dp[j][f | (1<<(d-1))];
            }
            d *= 2;
        }
    }

    Mint ans = 0;
    for (int i = 0; i < n; i++) {
        ans += dp[i][0];
    }
    cout << ans.v << endl;
    return 0;

}