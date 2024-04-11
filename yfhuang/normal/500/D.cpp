#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>

using namespace std;

const int N = 400010;

vector < pair <int, int> > g[N];
int sz[N];
long long pairs[N];
int n;

void dfs(int v, int pr) {
    sz[v] = 1;
    int cnt = g[v].size();
    for (int j = 0; j < cnt; j++) {
        int u = g[v][j].first;
        if (u == pr) {
            continue;
        }
        dfs(u, v);
        sz[v] += sz[u];
        pairs[g[v][j].second] = sz[u] * 1LL * (n - sz[u]);
    }
}

int from[N], to[N], cost[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        g[i].clear();
    }
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d %d", from + i, to + i, cost + i);
        from[i]--; to[i]--;
        g[from[i]].push_back(make_pair(to[i], i));
        g[to[i]].push_back(make_pair(from[i], i));
    }
    dfs(0, -1);
    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += pairs[i] * cost[i];
    }
    int tt;
    scanf("%d", &tt);
    double q = 6.0 / n / (n - 1);
    while (tt--) {
        int foo, bar;
        scanf("%d %d", &foo, &bar);
        foo--;
        ans -= pairs[foo] * (cost[foo] - bar);
        cost[foo] = bar;
        printf("%.17f\n", q * ans);
    }
    return 0;
}