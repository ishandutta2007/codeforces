//#define NDEBUG

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <cassert>
#include <numeric>

using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> P;
template <int N>
struct UnionFind {
    int ig[N];
    vector<int> gi[N];
    void init() {
        for (int i = 0; i < N; ++i) {
            ig[i] = i;
            gi[i] = {i};
        }
    }
 
    void merge(int a, int b) {
        if (same(a, b)) return;
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

const int MN = 330;
UnionFind<MN> uf;
int a[MN];
int g[MN][MN];
int main() {
    uf.init();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
    }
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') {
                uf.merge(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = uf.same(i, j);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (!uf.same(i, j)) continue;
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
    for (int i = 0; i < n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n-1]);
}