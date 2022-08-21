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

struct UnionFind {
    vector<int> ig;
    vector<vector<int>> gi;
    int gn;
    UnionFind(int N) {
        ig.resize(N); gi.resize(N);
        for (int i = 0; i < N; i++) {
            ig[i] = i; gi[i] = {i};
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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int n;
    cin >> n;
    UnionFind uf(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a; a--;
        uf.merge(i, a);
    }
    cout << uf.gn << endl;
    return 0;
}