#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

const int N = 30;

char s[N][N];

void rotate(char a[N][N], int &n, int &m) {
  char tmp[N][N];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      tmp[j][n - i - 1] = a[i][j];
    }
  }
  std::swap(n, m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      a[i][j] = tmp[i][j];
    }
  }
}

std::string flat(char a[N][N], int x, int y) {
  std::string s(x * y, ' ');
  for (int i = 0; i < x; ++i) {
    for (int j = 0; j < y; ++j) {
      s[i * y + j] = a[i][j];
    }
  }
  return s;
}

std::string repr(char a[N][N], int x, int y) {
  std::string ret = flat(a, x, y);
  for (int i = 0; i < 3; ++i) {
    rotate(a, x, y);
    if (x == y || i == 1) {
      ret = std::min(ret, flat(a, x, y));
    }
  }
  return ret;
}

bool check(int x, int y, int n, int m) {
  std::vector<std::string> all;
  for (int i = 0; i < n; i += x) {
    for (int j = 0; j < m; j += y) {
      char tmp[N][N];
      for (int u = 0; u < x; ++u) {
        for (int v = 0; v < y; ++v) {
          tmp[u][v] = s[i + u][j + v];
        }
      }
      all.push_back(repr(tmp, x, y));
    }
  }
  std::sort(all.begin(), all.end());
  for (size_t i = 1; i < all.size(); ++i) {
    if (all[i] == all[i - 1]) return false;
  }
  return true;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }
  int best = n * m, best_x = n, best_y = m;
  int ret = 0;
  for (int x = 1; x <= n; ++x) if (n % x == 0) {
    for (int y = 1; y <= m; ++y) if (m % y == 0) {
      if (check(x, y, n, m)) {
        ++ret;
        if (best > x * y || (best == x * y && x < best_x)) {
          best = x * y;
          best_x = x;
          best_y = y;
        }
      }
    }
  }
  printf("%d\n%d %d\n", ret, best_x, best_y);
  return 0;
}