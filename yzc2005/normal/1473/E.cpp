#include <bits/stdc++.h>
const int N = 8e5 + 5;
int n, m;
std::vector<std::pair<int, int>> g[N];
long long dis[N];
std::priority_queue<std::pair<long long, int>> que; 
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    auto add = [&](int u, int v, int w) {
      g[u].emplace_back(v + n, 0);
      g[u].emplace_back(v, w);
      g[u].emplace_back(v + 2 * n, 2 * w);
      g[u].emplace_back(v + 3 * n, w);
      g[u + n].emplace_back(v + n, w);
      g[u + n].emplace_back(v + 3 * n, 2 * w);
      g[u + 2 * n].emplace_back(v + 2 * n, w);
      g[u + 2 * n].emplace_back(v + 3 * n, 0);
      g[u + 3 * n].emplace_back(v + 3 * n, w);
    };
    add(u, v, w);
    add(v, u, w);
  }
  memset(dis, 0x3f, sizeof(dis));
  dis[1] = 0;
  que.push({-0, 1});
  while (!que.empty()) {
    auto cur = que.top(); 
    que.pop();
    int u = cur.second;
    long long d = -cur.first;
    if (d != dis[u]) 
      continue;
    for (auto p : g[u]) {
      int v, w;
      std::tie(v, w) = p;
      if (dis[v] <= dis[u] + w)
        continue;
      dis[v] = dis[u] + w;
      que.push({-dis[v], v});
    }
  }
  for (int i = 2; i <= n; ++i) 
    printf("%lld ", dis[n * 3 + i]);
  return 0;
}