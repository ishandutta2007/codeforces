#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int ii = 0; ii < tn; ++ii) {
    int n, m;
    cin >> n >> m;
    vector<string> res(n, string(m, '0'));
    res[0][0] = res[0][m - 1] = res[n - 1][0] = res[n - 1][m - 1] = '1';
    for (int i = 2; i + 2 < n; i += 2) {
      res[i][0] = res[i][m - 1] = '1';
    }
    for (int j = 2; j + 2 < m; j += 2) {
      res[0][j] = res[n - 1][j] = '1';
    }
    for (auto& s : res) {
      cout << s << '\n';
    }
    cout << '\n';
  }
}