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


const int MD = 1001001;

int factor[MD];
void first() {
    fill(begin(factor), end(factor), -1);
    for (int i = 2; i < MD; i++) {
        if (factor[i] != -1) continue;
        for (int j = i; j < MD; j += i) {
            factor[j] = i;
        }
    }
}


int main() {
    first();

    V<int> id2v[300];
    map<V<int>, int> vs;
    int id[MD];
    for (int i = 1; i < MD; i++) {
        map<int, int> mp;
        int x = i;
        while (factor[x] != -1) {
            mp[factor[x]]++;
            x /= factor[x];
        }
        V<int> v;
        for (auto p: mp) {
            v.push_back(p.second);
        }
        sort(begin(v), end(v));
        if (vs.count(v)) {
            id[i] = vs[v];
        } else {
            int nid = int(vs.size());
            vs[v] = nid;
            id[i] = nid;
            id2v[nid] = v;
        }
    }
    int C = vs.size();
//    cout << "C:" << C << endl;

    static Mint to1[MD][25], to0[MD][25];
    to0[0][0] = 1;
    for (int i = 1; i < 30; i++) {
        to1[0][i] = 1;
    }
    for (int i = 1; i < MD; i++) {
        Mint sm0, sm1;
        for (int j = 0; j < 25; j++) {
            sm0 += to0[i-1][j];
            sm1 += to1[i-1][j];
            to0[i][j] = sm0;
            to1[i][j] = sm1;
        }
    }

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int r, n;
        scanf("%d %d", &r, &n);
        V<int> v = id2v[id[n]];
        Mint co[11]; co[0] = 1;
        int nw = 1;
        for (int d: v) {
            for (int i = nw; i >= 0; i--) {
                co[i] = co[i]*to0[r][d];
                if (i) co[i] += co[i-1]*to1[r][d];
            }
            nw++;
        }
        Mint ans = 0;
        for (int i = 0; i < 11; i++) {
//            cout << co[i].v << ", ";
            ans += co[i] * Mint(1<<i);
        }
//        cout << endl;

        printf("%d\n", ans.v);
    }

    return 0;

}