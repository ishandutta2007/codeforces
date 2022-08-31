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

const int MN = 1100100;
int n, m, k;
string s;
char buf[MN];
int main() {
    scanf("%d %d", &n, &k);
    scanf("%s", buf);
    s = buf;
    m = (int)s.size();

    Mint dp[26];
    int ls[26];
    fill_n(ls, 26, -1);
    for (int i = 0; i < m; i++) {
        Mint sm = 1;
        for (int j = 0; j < k; j++) {
            sm += dp[j];
        }
        dp[s[i]-'a'] = sm;
        ls[s[i]-'a'] = i;
    }
    using P = pair<int, int>;
    vector<int> idx(k);
    for (int i = 0; i < k; i++) {
        idx[i] = i;
    }
    sort(idx.begin(), idx.end(), [&](const int &l, const int &r){
        return ls[l] < ls[r];
    });

    for (int i = 0; i < n; i++) {
        Mint sm = 1;
        for (int j = 0; j < k; j++) {
            sm += dp[j];
        }
        dp[idx[i%k]] = sm;
    }
    Mint sm = 1;
    for (int i = 0; i < k; i++) {
        sm += dp[i];
    }
    printf("%d\n", sm.value());
    return 0;
}