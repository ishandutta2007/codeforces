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
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

int n;
VV<int> g;
V<int> sz;

void dfs_sz(int p, int b = -1) {
    sz[p] = 1;
    for (int d: g[p]) {
        if (d == b) continue;
        dfs_sz(d, p);
        sz[p] += sz[d];
    }
}

V<int> ans;
void dfs(int p, int b = -1) {
    for (int d: g[p]) {
        if (d == b) continue;
        if (sz[d] % 2 == 0) dfs(d, p);
    }
    ans.push_back(p);
    for (int d: g[p]) {
        if (d == b) continue;
        if (sz[d] % 2) dfs(d, p);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    g = VV<int>(n);
    sz = V<int>(n);
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p; p--;
        if (p >= 0) {
            g[p].push_back(i);
            g[i].push_back(p);
        }
    }

    dfs_sz(0);
    dfs(0);

    for (int d: ans) {
        cout << d+1 << endl;
    }
    return 0;
}