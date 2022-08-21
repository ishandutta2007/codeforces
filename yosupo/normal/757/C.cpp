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

const int MD = 1001001;

vector<ll> s[MD];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        map<int, int> mp;
        for (int j = 0; j < k; j++) {
            int x;
            scanf("%d", &x); x--;
            mp[x]++;
        }
        for (auto p: mp) {
            s[p.first].push_back(p.second*ll(n)+i);
        }
    }

/*    for (int i = 0; i < m; i++) {
        cout << "PR " << i << ":";
        for (int d: s[i]) {
            cout << d << ", ";
        }
        cout << endl;
    }*/

    sort(s, s+m);
    int ba = 0;
    Mint ans = 1;
    for (int i = 1; i < m; i++) {
        bool same = true;
        if (s[i-1].size() != s[i].size()) same = false;
        else {
            int X = int(s[i].size());
            for (int j = 0; j < X; j++) {
                if (s[i-1][j] != s[i][j]) {
                    same = false;
                    break;
                }
            }
        }
        if (!same) {
            int len = i-ba;
            for (int j = 1; j <= len; j++) {
                ans *= Mint(j);
            }
            ba = i;
        }
    }
    int len = m-ba;
    for (int j = 1; j <= len; j++) {
        ans *= Mint(j);
    }
    cout << ans.v << endl;
    return 0;
}