#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, m, a[N][N];
char s[N][N];
vector<pair<int, int>> g[N][N];
void dfs(int x, int y, int z) {
  if (x < 1 || x > n || y < 1 || y > m) return;
  if (s[x][y] == 'X' || a[x][y]) return;
  a[x][y] = z;
  dfs(x - 1, y - 1, 5 - z);
  dfs(x - 1, y + 1, 5 - z);
  dfs(x + 1, y - 1, 5 - z);
  dfs(x + 1, y + 1, 5 - z);
  for (auto p : g[x][y]) dfs(p.first, p.second, 5 - z);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
  for (int i = 2; i < n; ++i) {
    for (int j = 2; j < m; ++j) {
      if (s[i][j] != 'X') continue;
      int cnt = 0;
      cnt += (s[i - 1][j] == '.');
      cnt += (s[i + 1][j] == '.');
      cnt += (s[i][j - 1] == '.');
      cnt += (s[i][j + 1] == '.');
      if (cnt == 2) {
        if (s[i - 1][j] == '.' && s[i + 1][j] == '.') {
          g[i - 1][j].emplace_back(i + 1, j);
          g[i + 1][j].emplace_back(i - 1, j);
        } else if (s[i][j - 1] == '.' && s[i][j + 1] == '.') {
          g[i][j - 1].emplace_back(i, j + 1);
          g[i][j + 1].emplace_back(i, j - 1);
        }
      }
      if (cnt & 1) return puts("NO"), 0;
    }
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (s[i][j] == '.' && !a[i][j]) dfs(i, j, 1);
  puts("YES");
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (s[i][j] == 'X') {
        if (s[i - 1][j] == '.') a[i][j] += a[i - 1][j];
        if (s[i + 1][j] == '.') a[i][j] += a[i + 1][j];
        if (s[i][j - 1] == '.') a[i][j] += a[i][j - 1];
        if (s[i][j + 1] == '.') a[i][j] += a[i][j + 1];
        assert(a[i][j] % 5 == 0);
      }
      printf("%d%c", a[i][j], " \n"[j == m]);
    }
  }
  return 0;
}