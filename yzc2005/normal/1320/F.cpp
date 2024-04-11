#include <bits/stdc++.h>
const int N = 4e5 + 5;
const int dx[] = {1, -1, 0, 0, 0, 0}, dy[] = {0, 0, 1, -1, 0, 0}, dz[] = {0, 0, 0, 0, 1, -1};
std::vector<int> sensors[N];
int n, m, k, a[N], c; 
inline int id(int x, int y, int z) {
  return (x - 1) * m * k + (y - 1) * k + z;
}
inline bool in(int x, int y, int z) {
  return x >= 1 && x <= n && y >= 1 && y <= m && z >= 1 && z <= k;
}
void color(int d, int x, int y, int z, int c) {
  if (!in(x, y, z)) {
    if (c) {
      puts("-1");
      exit(0);
    }
    return;
  }
  int t = id(x, y, z);
  auto erase = [&]() {
    while (!sensors[t].empty()) {
      int d = sensors[t].back();
      sensors[t].pop_back();
      color(d, x + dx[d], y + dy[d], z + dz[d], a[t]);
    }
    a[t] = 0;
  };
  if (!c) {
    if (a[t] > 0) {
      erase();
    } else {
      a[t] = 0;
    }
    color(d, x + dx[d], y + dy[d], z + dz[d], c);
  } else if (a[t] == -1 || a[t] == c) {
    a[t] = c;
    sensors[t].push_back(d);
  } else if (!a[t]) {
    color(d, x + dx[d], y + dy[d], z + dz[d], c);
  } else {
    erase();
    color(d, x + dx[d], y + dy[d], z + dz[d], c);
  }
}
int main() {
  std::memset(a, -1, sizeof(a));
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= k; ++j) {
      scanf("%d", &c);
      color(0, 1, i, j, c);
    }
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= k; ++j) {
      scanf("%d", &c);
      color(1, n, i, j, c);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      scanf("%d", &c);
      color(2, i, 1, j, c);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      scanf("%d", &c);
      color(3, i, m, j, c);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &c);
      color(4, i, j, 1, c);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &c);
      color(5, i, j, k, c);
    }
  }
  for (int i = 1; i <= n * m * k; ++i) {
    printf("%d ", std::max(a[i], 0));
  }
  return 0;
}