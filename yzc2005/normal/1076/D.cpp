#include <bits/stdc++.h>
const int N = 3e5 + 5;
int n, m, k, pre[N];
std::vector<std::pair<int, int>> g[N];
std::vector<int> gg[N];
long long dis[N]; 
std::map<std::pair<int, int>, int> id;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; ++i) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    g[x].emplace_back(y, z);
    g[y].emplace_back(x, z);
    id[std::make_pair(x, y)] = i; 
    id[std::make_pair(y, x)] = i; 
  }
  memset(dis, 0x3f, sizeof dis);
  dis[1] = 0;
  std::priority_queue<std::pair<long long, int>> pq;
  pq.push({0, 1});
  while (!pq.empty()) {
    auto pr = pq.top(); 
    pq.pop();
    int u = pr.second;
    if (-pr.first != dis[u]) {
      continue;
    }
    for (auto pr : g[u]) {
      int v = pr.first, w = pr.second;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        pre[v] = u;
        pq.push({-dis[v], v});
      }
    }
  }
  for (int i = 2; i <= n; ++i) {
    gg[pre[i]].emplace_back(i);
  }
  printf("%d\n", std::min(k, n - 1));
  if (!k) return 0;
  std::queue<int> que;
  que.push(1);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (auto v : gg[u]) {
      printf("%d ", id[std::make_pair(u, v)]);
      if (!--k) {
        return 0;
      }
      que.push(v);
    }
  }
  return 0;
}