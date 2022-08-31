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
typedef long long ll;
typedef unsigned long long ull;

const ll MD = 1e9+7;

/**
 * UnionFindQuickFind
 *
 * templateint N
 *
 * See_Also: http://topcoder.g.hatena.ne.jp/iwiwi/20131226/1388062106
 */
template <int N>
struct UnionFind {
    int ig[N];
    vector<int> gi[N];
    int gn;
    /// UnionFindn
    void init(int n = N) {
        for (int i = 0; i < n; ++i) {
            ig[i] = i;
            gi[i] = {i};
        }
        gn = n;
    }

    /// ab
    void merge(int a, int b) {
        if (same(a, b)) return;
        gn--;
        int x = ig[a], y = ig[b];
        if (gi[x].size() < gi[y].size()) swap(x, y);
        for (int j: gi[y]) {
            ig[j] = x;
        }
        gi[x].insert(gi[x].end(), gi[y].begin(), gi[y].end());
        gi[y].clear();
    }
    /// ab
    bool same(int a, int b) {
        return ig[a] == ig[b];
    }
    /// 
    int group_num() {
        return gn;
    }
};

// x^n % md
ll pow_mod(ll x, ll n, ll md) {
    ll r = 1;
    while (n) {
        if (n & 1) r = (r * x) % md;
        x = (x * x) % md;
        n >>= 1;
    }
    return r;
}

const int MN = 100100;
UnionFind<2*MN> uf;
typedef pair<int, int> P;

int main() {
    int n, m;
    cin >> n >> m;
    uf.init(2*n);
    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t; a--; b--;
        if (t == 1) {
            uf.merge(a, b);
            uf.merge(a+n, b+n);
        } else {
            uf.merge(a, b+n);
            uf.merge(a+n, b);
        }
    }

    for (int i = 0; i < n; i++) {
        if (uf.same(i, i+n)) {
            cout << 0 << endl;
            return 0;
        }
    }

    ll gn = uf.group_num();
    cout << pow_mod(2, gn/2-1, MD) << endl;
    return 0;
}