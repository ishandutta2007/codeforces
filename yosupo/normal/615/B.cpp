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

const int MN = 100100;


vector<int> g[MN];

int dp[MN];
bool used[MN] = {};

int dfs(int p) {
    if (used[p]) return dp[p];
    used[p] = true;
    int ma = 1;
    for (int d: g[p]) {
        if (p <= d) continue;
        ma = max(ma, 1+dfs(d));
    }
    return dp[p] = ma;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    ll re = 0;
    for (int i = 1; i <= n; i++) {
        re = max(re, (ll)g[i].size() * dfs(i));
    }
    cout << re << endl;
    return 0;
}