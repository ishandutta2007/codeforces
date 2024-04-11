#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int t, n, a, b, x, y;
int dep[N], dis;
vector<int> g[N];
void dfs(int u, int fa) {
  for (auto v : g[u]) {
    if (v ^ fa) {
      dep[v] = dep[u] + 1;
      dfs(v, u);
    }
  }
}
void dfs1(int u, int fa, int d) {
  dis = max(dis, d);
  for (auto v : g[u]) {
    if (v ^ fa) {
      dfs1(v, u, d + 1);
    }
  }
}
int main() {
  for (scanf("%d", &t); t; --t) {
    scanf("%d%d%d%d%d", &n, &a, &b, &x, &y);
    for (int i = 1; i <= n; ++i) {
      g[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dep[a] = dis = 0;
    dfs(a, 0);
    if (dep[b] <= x || x >= y) {
      puts("Alice");
    } else {
      int u = max_element(dep + 1, dep + n + 1) - dep;
      dfs1(u, 0, 0);
      if (min(y, dis) > x * 2) {
        puts("Bob");
      } else {
        puts("Alice");
      }
    }
  }
  return 0;
}