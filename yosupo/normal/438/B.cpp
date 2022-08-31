#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>

using namespace std;
typedef tuple<int, int, int> T;
typedef long long ll;
const int MN = 100010;
int n, m;
#include <vector>

template <int SIZE>
struct UnionField {
    using uint = unsigned int;
    int i2g[SIZE];
    std::vector<int> g2i[SIZE];
    inline void init() {
        for (int i = 0; i < SIZE; ++i) {
            i2g[i] = i;
            g2i[i].assign(1, i);
        }
    }
 
    inline void merge(uint ia, uint ib) {
        if (g2i[i2g[ia]].size() < g2i[i2g[ib]].size()) {
            uint ic = ia;
            ia = ib;
            ib = ic;
        }
        int ga = i2g[ia], gb = i2g[ib];
        for (int j : g2i[gb]) i2g[j] = ga;
        g2i[ga].insert(g2i[ga].end(), g2i[gb].begin(), g2i[gb].end());
        g2i[gb].clear();
    }
    inline int gsize(uint ia) {
        return g2i[i2g[ia]].size();
    }

    inline bool is_same_group(uint ia, uint ib) {
        return i2g[ia] == i2g[ib];
    }
};

UnionField<MN> uf;
int main() {
    uf.init();
    cin >> n >> m;
    int d[MN];
    for (int i = 0; i < n; i++) {
        scanf("%d", d+i);
    }
    vector<T> v;
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        v.push_back(T(min(d[a], d[b]), a, b));
    }
    sort(v.begin(), v.end(), greater<T>());
    ll res = 0;
    for (T t: v) {
        int r, a, b;
        tie(r, a, b) = t;
        if (!uf.is_same_group(a, b)) {
            res += (ll)(uf.gsize(a))*uf.gsize(b)*r;
            uf.merge(a, b);
        }
    }
    printf("%.20f\n", (double)(res)*2/n/(n-1));
    return 0;
}