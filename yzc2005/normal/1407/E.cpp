#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<std::pair<int, int>>> e(n);
  for (int i = 1; i <= m; ++i) {
    int u, v, t;
    std::cin >> u >> v >> t;
    --u;
    --v;
    e[v].push_back({u, t});
  }
  std::vector<int> dis(n, 1e9), color(n, -1);
  std::queue<int> que;
  dis[n - 1] = 0;
  que.push(n - 1);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (auto p : e[u]) {
      int v = p.first, t = p.second;
      if (dis[v] == 1e9) {
        if (color[v] == -1) {
          color[v] = t ^ 1;
        } else if (color[v] == t) {
          dis[v] = dis[u] + 1;
          que.push(v); 
        }
      }
    }
  } 
  std::cout << (dis[0] == 1e9 ? -1 : dis[0]) << "\n";
  for (int i = 0; i < n; ++i) {
    std::cout << abs(color[i]);
  }
  std::cout << "\n";
  return 0;
}