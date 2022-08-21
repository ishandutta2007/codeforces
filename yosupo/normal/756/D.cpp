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

const int MN = 5050;

int nx[MN][26];
Mint dp[MN][MN];


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int n;
    cin >> n;
    string s;
    cin >> s;
    fill_n(nx[n], 26, n);
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            nx[i][j] = nx[i+1][j];
        }
        nx[i][s[i]-'a'] = i;
    }
    for (int i = 0; i < n; i++) {
        dp[i][n] = Mint(1);
    }
    for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j >= 0; j--) {
            for (int k = 0; k < 26; k++) {
                int ni = nx[i][k];
                dp[i][j] += dp[ni][j+1];
            }
        }
    }
    cout << dp[0][0].v << endl;
    return 0;
}