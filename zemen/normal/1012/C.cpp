#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 5005;
const int maxk = maxn / 2;
int d[maxn][maxk][3];
const int inf = 1e9 + 7;

void uin(int& a, int b) {
  a = min(a, b);
}

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < maxk; ++j) {
      for (int k = 0; k < 3; ++k) {
        d[i][j][k] = inf;
      }
    }
  }
  d[0][0][2] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < maxk; ++j) {
      for (int k = 0; k < 3; ++k) {
        if (d[i][j][k] == inf) {
          continue;
        }
        uin(d[i + 1][j][min(k + 1, 2)], d[i][j][k]);
        if (k == 2) {
          int cost = 0;
          if (i > 0) {
            cost += max(0, a[i - 1] - a[i] + 1);
          }
          if (i + 1 < n) {
            cost += max(0, a[i + 1] - a[i] + 1);
          }
          uin(d[i + 1][j + 1][0], d[i][j][k] + cost);
        } else if (k == 1) {
          int cost = 0;
          cost += max(0, min(a[i - 1], a[i - 2] - 1) - a[i] + 1);
          if (i + 1 < n) {
            cost += max(0, a[i + 1] - a[i] + 1);
          }
          uin(d[i + 1][j + 1][0], d[i][j][k] + cost);
        }
      }
    }
  }
  vector<int> res((n + 1) / 2 + 1, inf);
  for (int j = 0; j < (int) res.size(); ++j) {
    for (int k = 0; k < 3; ++k) {
      res[j] = min(res[j], d[n][j][k]);
    }
  }
  for (int i = 1; i < (int) res.size(); ++i) {
    cout << res[i] << ' ';
  }
  cout << '\n';
}