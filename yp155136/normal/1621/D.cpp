#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 506;

ll a[N][N];
ll pre[N][N];
int n;

ll QQ(int x1, int y1, int x2, int y2) {
  return pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
}

ll Q(int x1, int y1, int x2, int y2) {
  if (x1 == x2) {
    // ll v1 = pre[x2][y2] - pre[x1][y1 - 1];
    // ll v2 = pre[x2][2 * n] - v1;
    ll v1 = QQ(x1, y1, x2, y2);
    ll v2 = QQ(x1, 1, x2, 2 * n) - v1 + a[x1][y1] + a[x2][y2];
    return min(v1, v2);
  }
  else if (y1 == y2) {
    ll v1 = QQ(x1, y1, x2, y2);
    ll v2 = QQ(1, y1, 2 * n, y2) - v1 + a[x1][y1] + a[x2][y2];
    return min(v1, v2);
  }
}

void go() {
  cin >> n;
  ll ans = 0;
  for (int i = 1; i <= 2 * n; ++i) {
    for (int j = 1; j <= 2 * n; ++j) {
      cin >> a[i][j];
      if (i >= n + 1 && j >= n + 1) {
        ans += a[i][j];
        a[i][j] = 0;
      }
      pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
    }
  }
  ll mn = (1ll << 60);
  for (int i = 1; i <= 2 * n; ++i) {
    for (int j = 1; j <= 2 * n; ++j) {
      if (i <= n && j <= n) continue;
      if (i >= n + 1 && j >= n + 1) continue;
      if (i <= n) {
        if (i != 1 && i != n) continue;
        mn = min(mn, Q(i, n, i, j) + Q(i, j, n + 1, j) - a[i][j]);
      }
      else if (j <= n) {
        if (j != 1 && j != n) continue;
        mn = min(mn, Q(n, j, i, j) + Q(i, j, i, n + 1) - a[i][j]);
      }
    }
  }
  cout << ans + mn << '\n';
}

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    go();
  }
}