#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  int res = 0;
  for (int it = 0; it < 2; ++it) {
    for (int s = 0; s < 2 * n - 1; s += 4) {
      for (int i = 0; i < n; ++i) {
        int j = s - i;
        if (j >= 0 && j < n) {
          res ^= a[i][j];
          ++i;
        }
      }
    }
    
    vector<vector<int>> b(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        b[n - 1 - j][i] = a[i][j];
      }
    }
    a = b;
  }
  cout << res << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}