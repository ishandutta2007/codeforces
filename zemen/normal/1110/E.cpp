#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int v0[2], vn[2];
  vector<int> v[2];
  for (int i = 0; i < 2; ++i) {
    int pr = 0;
    for (int j = 0; j < n; ++j) {
      int x;
      cin >> x;
      if (j == 0) {
        v0[i] = x;
      } else {
        v[i].push_back(x - pr);
      }
      if (j == n - 1) {
        vn[i] = x;
      }
      pr = x;
    }
    sort(v[i].begin(), v[i].end());
  }
  if (v0[0] == v0[1] && vn[0] == vn[1] && v[0] == v[1]) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}