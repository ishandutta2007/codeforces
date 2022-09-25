#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  map<int, int> mp;
  for (int iter = 0; iter < 2; ++iter) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      mp[x] = max(mp[x], y);
    }
  }
  ll res = 0;
  for (auto p : mp) {
    res += p.second;
  }
  cout << res << '\n';
}