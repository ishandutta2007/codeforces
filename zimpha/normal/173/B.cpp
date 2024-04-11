#include <cstdio>
#include <queue>
#include <vector>

const int N = 4000 + 10;

std::vector<int> edges[N];
char s[N];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    for (int j = 0; j < m; ++j) {
      if (s[j] == '#') {
        edges[i].push_back(j + n);
        edges[j + n].push_back(i);
      }
    }
  }
  std::vector<int> dis(n + m, -1);
  std::queue<int> queue;
  queue.push(0);
  dis[0] = 0;
  while (!queue.empty()) {
    int u = queue.front();
    queue.pop();
    for (auto &v: edges[u]) {
      if (dis[v] == -1) {
        dis[v] = dis[u] + 1;
        queue.push(v);
      }
    }
  }
  printf("%d\n", dis[n - 1]);
  return 0;
}