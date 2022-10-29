#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>

const int N = 2000 + 10;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int dis[N][N];

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n, m, k;
  std::cin >> n >> m >> k;
  memset(dis, -1, sizeof(dis));
  std::queue<std::pair<int, int>> queue;
  for (int i = 0, x, y; i < k; ++i) {
    std::cin >> x >> y;
    --x, --y;
    dis[x][y] = 0;
    queue.emplace(x, y);
  }
  while (!queue.empty()) {
    int x = queue.front().first;
    int y = queue.front().second;
    queue.pop();
    for (int i = 0; i < 4; ++i) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
      if (dis[xx][yy] == -1) {
        dis[xx][yy] = dis[x][y] + 1;
        queue.emplace(xx, yy);
      }
    }
  }
  int ret = -1, ret_x = -1, ret_y = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (ret < dis[i][j]) {
        ret = dis[i][j];
        ret_x = i;
        ret_y = j;
      }
    }
  }
  printf("%d %d\n", ret_x + 1, ret_y + 1);
  return 0;
}