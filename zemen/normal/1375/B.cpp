#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x = 4;
      if (i == 0 || i + 1 == n) {
        --x;
      }
      if (j == 0 || j + 1 == m) {
        --x;
      }
      if (a[i][j] > x) {
        cout << "NO\n";
        return;
      }
      a[i][j] = x;
    }
  }
  cout << "YES\n";
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
}

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}