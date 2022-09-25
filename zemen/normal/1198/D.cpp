#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 51;
int d[maxn][maxn][maxn][maxn];

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  int n;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int dx = 1; dx <= n; ++dx) {
    for (int dy = 1; dy <= n; ++dy) {
      for (int x1 = 0; x1 + dx <= n; ++x1) {
        for (int y1 = 0; y1 + dy <= n; ++y1) {
          int x2 = x1 + dx, y2 = y1 + dy;
          int& res = d[x1][x2][y1][y2] = max(x2 - x1, y2 - y1);
          if (dx == 1 && dy == 1 && a[x1][y1] == '.') {
            res = 0;
          }
          for (int xc = x1 + 1; xc < x2; ++xc) {
            res = min(res, d[x1][xc][y1][y2] + d[xc][x2][y1][y2]);
          }
          for (int yc = y1 + 1; yc < y2; ++yc) {
            res = min(res, d[x1][x2][y1][yc] + d[x1][x2][yc][y2]);
          }
        }
      }
    }
  }
  cout << d[0][n][0][n] << '\n';
}