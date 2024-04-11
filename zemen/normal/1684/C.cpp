#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  int l = -1, r = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    vector<int> b = a[i];
    sort(b.begin(), b.end());
    vector<int> bad;
    for (int j = 0; j < m; ++j) {
      if (b[j] != a[i][j]) {
        bad.push_back(j);
      }
    }
    if (bad.empty()) {
      continue;
    } else if (bad.size() > 2) {
      cout << -1 << '\n';
      return;
    } else {
      assert(bad.size() == 2);
      if (l == -1) {
        l = bad[0];
        r = bad[1];
      }
      if (l != bad[0] || r != bad[1]) {
        cout << -1 << '\n';
        return;
      }
    }
  }
  if (l == -1) {
    cout << 1 << ' ' << 1 << '\n';
    return;
  }
  for (int i = 0; i < n; ++i) {
    swap(a[i][l], a[i][r]);
    if (!is_sorted(a[i].begin(), a[i].end())) {
      cout << -1 << '\n';
      return;
    }
  }
  cout << l + 1 << ' ' << r + 1 << '\n';
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