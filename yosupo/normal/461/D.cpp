#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <complex>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>
#include <valarray>
#include <list>
 
using namespace std; 
typedef long long ll;

template <int SIZE>
struct UnionFind {
    int i2g[SIZE];
    std::vector<int> g2i[SIZE];
    inline void init() {
        for (int i = 0; i < SIZE; ++i) {
            i2g[i] = i;
            g2i[i].assign(1, i);
        }
    }
 
    inline void merge(int ia, int ib) {
        if (same(ia, ib)) return;
        if (g2i[i2g[ia]].size() < g2i[i2g[ib]].size()) swap(ia, ib);
        int ga = i2g[ia], gb = i2g[ib];
        for (int j : g2i[gb]) i2g[j] = ga;
        g2i[ga].insert(g2i[ga].end(), g2i[gb].begin(), g2i[gb].end());
        g2i[gb].clear();
    }
 
    inline bool same(int ia, int ib) {
        return i2g[ia] == i2g[ib];
    }
};


UnionFind<202000> uf[2];

int main() {
    uf[0].init(); uf[1].init();
    int n, m;
    cin >> n >> m;
    int sz[2] = {(n+1)/2, n/2};
    for (int q = 0; q < m; q++) {
        int a, b; string c;
        cin >> a >> b >> c; a--; b--;
        int i = abs(a-b), j = n-1-abs(a+b-n+1);
        if (j < i) swap(i, j);
        bool odd = i%2;
        i /= 2; j /= 2; j++;
        if (c == "x") {
            uf[odd].merge(i, j);
            uf[odd].merge(i+sz[odd]+1, j+sz[odd]+1);
        } else {
            uf[odd].merge(i, j+sz[odd]+1);
            uf[odd].merge(i+sz[odd]+1, j);
        }
    }
    int es = (n+1)/2, os = n/2;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < sz[i]+1; j++) {
            if (uf[i].same(j, j+sz[i]+1)) {
                printf("0\n");
                return 0;
            }
        }
    }
    const ll MD = 1e9+7;
    int r = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2*sz[i]+2; j++) {
            if (uf[i].g2i[j].size()) r++;
        }
    }
    r -= 4;
    r /= 2;
    ll res = 1;
    for (int i = 0; i < r; i++) {
        res *= 2;
        res %= MD;
    }
    cout << res << endl;
    return 0;
}