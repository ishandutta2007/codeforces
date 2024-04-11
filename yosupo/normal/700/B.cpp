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

const int MN = 200200;
int n, k;
vector<int> g[MN];
int sz[MN];
int rt[MN];
void dfs(int p, int b) {
    rt[p] = b;
    for (int d: g[p]) {
        if (d == b) continue;
        dfs(d, p);
        sz[p] += sz[d];
    }
}
int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < 2*k; i++) {
        int x;
        scanf("%d", &x); x--;
        sz[x]++;
    }
    for (int i = 0; i < n-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1);
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        ans += min(sz[i], 2*k-sz[i]);
    }
    cout << ans << endl;
    return 0;
}