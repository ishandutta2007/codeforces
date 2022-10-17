#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<std::vector<std::pair<int, int>>> g(n);
  for (int i = 1; i < n; ++i) {
    int u, v, w;
    std::cin >> u >> v >> w;
    --u;
    --v;
    g[u].push_back(std::make_pair(v, w));
    g[v].push_back(std::make_pair(u, w));
  }
  std::vector<int> sz(n);
  std::vector<long long> w(n);
  long long ans = 0;
  std::function<void(int, int)> dfs = [&](int u, int fa) {
    sz[u] = 1;
    std::vector<int> adj;
    for (auto p : g[u]) {
      int v = p.first, l = p.second;
      if (v == fa) {
        continue;
      }
      w[v] += l * 2;
      dfs(v, u);
      w[u] += w[v];
      sz[u] += sz[v];
      ans += l * sz[v];  
      adj.push_back(v); 
    }
    std::sort(adj.begin(), adj.end(), [&](int u, int v) {
      return w[u] * sz[v] < w[v] * sz[u];
    });
    long long sum = 0;
    for (auto v : adj) {
      ans += sum * sz[v];
      sum += w[v];
    }
  }; 
  dfs(0, -1);
  std::cout << std::setprecision(20) << 1.0 * ans / (n - 1) << "\n";
  return 0;
}