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
        if (is_same_group(ia, ib)) return;
        if (g2i[i2g[ia]].size() < g2i[i2g[ib]].size()) swap(ia, ib);
        int ga = i2g[ia], gb = i2g[ib];
        for (int j : g2i[gb]) i2g[j] = ga;
        g2i[ga].insert(g2i[ga].end(), g2i[gb].begin(), g2i[gb].end());
        g2i[gb].clear();
    }
 
    inline bool is_same_group(int ia, int ib) {
        return i2g[ia] == i2g[ib];
    }
};

const int MN = 303000;
UnionFind<MN> u;
int s[MN];
vector<int> g[MN];
bool used[MN];
int v, ma;

void dfs(int i, int b, int dis) {
    if (ma < dis) {
        ma = dis;
        v = i;
    }
    for (int d: g[i]) {
        if (d == b) continue;
        dfs(d, i, dis+1);
    }
}

int main() {
    u.init();
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y); x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
        u.merge(x, y);
    }
    for (int i = 0; i < n; i++) {
        if (used[u.i2g[i]]) continue;
        used[u.i2g[i]] = true;
        v = ma = -1;
        dfs(i, -1, 0);
        dfs(v, -1, 0);
        s[u.i2g[i]] = ma;
    }
    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int x;
            scanf("%d", &x); x--;
            printf("%d\n", s[u.i2g[x]]);
        } else {
            int x, y;
            scanf("%d %d", &x, &y); x--; y--;
            if (u.is_same_group(x, y)) continue;
            int d1 = s[u.i2g[x]], d2 = s[u.i2g[y]];
            int dd = max((d1+1)/2+(d2+1)/2+1, max(d1, d2));
            u.merge(x, y);
            s[u.i2g[x]] = dd;
        }
    }
    return 0;
}