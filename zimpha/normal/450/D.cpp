#include <cstdio>
#include <queue>
#include <algorithm>

using i64 = long long;
using pii = std::pair<i64, int>;

const int N = 1e5 + 10, M = 4e5 + 10;
const i64 inf = 1e18;

int from[M], to[M], weight[M];
std::vector<int> edges[N];
i64 dis[N];
int n, m;

void dijkstra() {
  std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
  for (int i = 0; i < n; ++i) dis[i] = inf;
  dis[0] = 0;
  pq.emplace(0, 0);
  while (!pq.empty()) {
    i64 d = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if (dis[u] < d) continue;
    for (auto &e: edges[u]) {
      int v = from[e] + to[e] - u;
      i64 w = weight[e] + dis[u];
      if (dis[v] > w) {
        dis[v] = w;
        pq.emplace(dis[v], v);
      }
    }
  }
}

int main() {
  int k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", from + i, to + i, weight + i);
    --from[i], --to[i];
  }
  for (int i = m; i < m + k; ++i) {
    scanf("%d%d", to + i, weight + i);
    from[i] = 0;
    --to[i];
  }
  for (int i = 0; i < m + k; ++i) {
    edges[from[i]].push_back(i);
    edges[to[i]].push_back(i);
  }
  dijkstra();
  std::vector<int> deg(n);
  for (int u = 0; u < n; ++u) {
    for (auto &e: edges[u]) {
      int v = from[e] + to[e] - u;
      if (dis[v] == dis[u] + weight[e]) ++deg[v];
    }
  }
  int ret = 0;
  for (int i = m; i < m + k; ++i) {
    if (weight[i] != dis[to[i]]) ++ret;
    else if (deg[to[i]] > 1) {
      ++ret;
      --deg[to[i]];
    }
  }
  printf("%d\n", ret);
  return 0;
}