#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 2005;
int a[maxn];
int d[maxn][5];

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 4; ++j) {
      d[i][j + 1] = max(d[i][j + 1], d[i][j]);
      bool inc = (a[i] == 2) == (j % 2);
      d[i + 1][j] = max(d[i + 1][j], d[i][j] + inc);
    }
  }
  int mx = 0;
  for (int j = 0; j < 4; ++j) {
    mx = max(mx, d[n][j]);
  }
  cout << mx << '\n';
}