#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>

const int N = 50 + 10;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

char grid[N][N];
int dis[2][N][N];
int n;

void bfs(int sx, int sy, int dis[N][N]) {
  std::queue<std::pair<int, int>> queue;
  for (int i = 0; i < n; ++i) {
    std::fill(dis[i], dis[i] + n, -1);
  }
  queue.emplace(sx, sy);
  dis[sx][sy] = 0;
  while (!queue.empty()) {
    int x = queue.front().first;
    int y = queue.front().second;
    queue.pop();
    for (int i = 0; i < 4; ++i) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
      if (grid[xx][yy] == '1') continue;
      if (dis[xx][yy] == -1) {
        dis[xx][yy] = dis[x][y] + 1;
        queue.emplace(xx, yy);
      }
    }
  }
}

int main() {
  int sx, sy, ex, ey;
  scanf("%d%d%d%d%d", &n, &sx, &sy, &ex, &ey);
  --sx, --sy, --ex, --ey;
  for (int i = 0; i < n; ++i) scanf("%s", grid[i]);
  bfs(sx, sy, dis[0]);
  bfs(ex, ey, dis[1]);
  int ret = 1e9;
  for (int x1 = 0; x1 < n; ++x1) for (int y1 = 0; y1 < n; ++y1) {
    if (dis[0][x1][y1] == -1) continue;
    for (int x2 = 0; x2 < n; ++x2) for (int y2 = 0; y2 < n; ++y2) {
      if (dis[1][x2][y2] == -1) continue;
      int now = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
      if (ret > now) ret = now;
    }
  }
  printf("%d\n", ret);
  return 0;
}