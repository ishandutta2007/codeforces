#include <cstdio>
#include <vector>
#include <queue>

const int N = 3000 + 10;

std::vector<int> succ[N], pred[N];
int succ_best[N][3], pred_best[N][3];
int succ_dis[N][N], pred_dis[N][N];
int n, m;

void bfs(int src, int *dis, std::vector<int> edges[]) {
  for (int i = 0; i < n; ++i) dis[i] = -1;
  std::queue<int> queue;
  dis[src] = 0;
  queue.push(src);
  while (!queue.empty()) {
    int u = queue.front();
    queue.pop();
    for (auto &v: edges[u]) if (dis[v] == -1) {
      dis[v] = dis[u] + 1;
      queue.push(v);
    }
  }
}

void solve(int best[N][3], int dis[N][N], std::vector<int> edges[]) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) best[i][j] = -1;
    bfs(i, dis[i], edges);
    for (int j = 0; j < n; ++j) if (dis[i][j] != -1 && i != j) {
      int v = j;
      for (int k = 0; k < 3 && v != -1; ++k) {
        if (best[i][k] == -1 || dis[i][best[i][k]] < dis[i][v]) {
          std::swap(v, best[i][k]);
        }
      }
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    succ[u - 1].push_back(v - 1);
    pred[v - 1].push_back(u - 1);
  }
  solve(succ_best, succ_dis, succ);
  solve(pred_best, pred_dis, pred);
  // a -> b -> c -> d
  int best = -1;
  std::vector<int> ret;
  for (int b = 0; b < n; ++b) {
    for (int c = 0; c < n; ++c) if (succ_dis[b][c] != -1 && b != c) {
      for (int ia = 0; ia < 3; ++ia) for (int id = 0; id < 3; ++id) {
        int a = pred_best[b][ia], d = succ_best[c][id];
        if (a == -1 || d == -1) continue;
        if (a == c || a == d || d == b) continue;
        int now = succ_dis[a][b] + succ_dis[b][c] + succ_dis[c][d];
        if (best < now) {
          best = now;
          ret = {a + 1, b + 1, c + 1, d + 1};
        }
      }
    }
  }
  printf("%d %d %d %d\n", ret[0], ret[1], ret[2], ret[3]);
  return 0;
}