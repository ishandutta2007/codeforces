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

const int MN = 100100;
const int MM = 100100;



int n, m;
int u[MM], v[MM];

vector<int> g[MN];
int dis[MN];
int dfs(int p) {
    if (dis[p] != -1) return dis[p];
    int ans = 1;
    for (int d: g[p]) {
        ans = max(ans, dfs(d)+1);
    }
    return dis[p] = ans;
}

bool calc(int md) {
    for (int i = 0; i < MN; i++) {
        g[i].clear();
    }
    fill_n(dis, MN, -1);
    for (int i = 0; i < md; i++) {
        g[v[i]].push_back(u[i]);
    }
    for (int i = 0; i < n; i++) {
        if (dfs(i) == n) return true;
    }
    return false;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", u+i, v+i); u[i]--; v[i]--;
    }
    int l = 0, r = m+1;
    while (r-l > 1) {
        int md = (l+r)/2;
        if (!calc(md)) {
            l = md;
        } else {
            r = md;
        }
    }
    if (r == m+1) r = -1;
    printf("%d\n", r);
    return 0;
}