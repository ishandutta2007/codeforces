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
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}

/**
 * QuickFind
 */
struct UnionFind {
    vector<int> ig;
    vector<vector<int>> gi;
    int gn;
    UnionFind(int N) {
        ig.resize(N);
        gi.resize(N);
        for (int i = 0; i < N; i++) {
            ig[i] = i;
            gi[i] = {i};
        }
        gn = N;
    }
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
    bool same(int a, int b) {
        return ig[a] == ig[b];
    }
};

const int MN = 200200;
int n;
int a[MN];
bool used[MN];
int par(int p) {
    if (used[p]) return p;
    used[p] = true;
    return par(a[p]);
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i); a[i]--;
    }
    int ans = 0;
    int rt = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == i) rt = i;
    }
    if (rt == -1) {
        rt = par(0);
        ans++;
        a[rt] = rt;
        fill_n(used, MN, false);
    }
    UnionFind uf(n);
    for (int i = 0; i < n; i++) {
        uf.merge(i, a[i]);
    }
    for (int i = 0; i < n; i++) {
        if (uf.same(rt, i)) continue;
        int nw = par(i);
        ans++;
        a[nw] = rt;
        uf.merge(rt, i);
    }
    printf("%d\n", ans);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]+1);
    }
    printf("\n");
    return 0;
}