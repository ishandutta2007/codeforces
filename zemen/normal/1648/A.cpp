#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  const int C = 1e5 + 1000;
  vector<vector<pair<int, int>>> by_col(C);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int c;
      cin >> c;
      by_col[c].emplace_back(i, j);
    }
  }
  ll res = 0;
  for (auto& v : by_col) {
    vector<int> x((int) v.size());
    vector<int> y((int) v.size());
    for (int i = 0; i < (int) v.size(); ++i) {
      x[i] = v[i].first;
      y[i] = v[i].second;
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    for (int i = 0; i < (int) v.size() - 1; ++i) {
      ll w = ll(i + 1) * ll((int) v.size() - i - 1);
      //cerr << "add " << w << ' ' << x[i + 1] << ' ' << x[i] << '\n';
      res += (x[i + 1] - x[i]) * w;
      res += (y[i + 1] - y[i]) * w;
    }
  }
  cout << res << '\n';
}