#include <cstdio>
#include <cstring>
#include <queue>

const int N = 2000 + 10;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {-1, 1, 0, 0};

char grid[N][N];
int dis[N][N];

int main() {
  int n, m, r, c, x, y;
  scanf("%d%d%d%d%d%d", &n, &m, &r, &c, &x, &y);
  for (int i = 0; i < n; ++i) {
    scanf("%s", grid[i]);
  }
  --r, --c;
  std::deque<std::pair<int, int>> queue;
  memset(dis, -1, sizeof(dis));
  queue.emplace_back(r, c);
  dis[r][c] = 0;
  while (!queue.empty()) {
    int x = queue.front().first;
    int y = queue.front().second;
    queue.pop_front();
    for (int i = 0; i < 4; ++i) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= n || yy < 0 || yy >= m) {
        continue;
      }
      if (grid[xx][yy] == '*') {
        continue;
      }
      if (dis[xx][yy] == -1 || dis[xx][yy] > dis[x][y] + (i == 0)) {
        dis[xx][yy] = dis[x][y] + (i == 0);
        if (i == 0) queue.emplace_back(xx, yy);
        else queue.emplace_front(xx, yy);
      }
    }
  }
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (dis[i][j] != -1) {
        int l = dis[i][j], r = j - c + l;
        ret += (l <= x && r <= y);
      }
    }
  }
  printf("%d\n", ret);
  return 0;
}