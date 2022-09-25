#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  int n;
  cin >> n;
  using pt = array<int, 4>;
  vector<pt> v(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> v[i][j];
    }
    v[i][3] = i + 1;
  }
  sort(v.begin(), v.end());

  for (int j : {2, 1, 0}) {
    vector<pt> v2;
    for (int l = 0; l < (int) v.size(); ++l) {
      int r = l + 1;
      while (r < (int) v.size() && equal(v[l].begin(), v[l].begin() + j, v[r].begin())) {
        ++r;
      }
      for (int i = l; i + 1 < r; i += 2) {
        cout << v[i].back() << ' ' << v[i + 1].back() << '\n';
      }
      if ((r - l) % 2) {
        v2.push_back(v[r - 1]);
      }
      l = r - 1;
    }
    v = v2;
  }
}