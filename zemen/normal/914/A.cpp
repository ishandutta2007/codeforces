#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  int n;
  cin >> n;
  int res = -1e9;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x < 0) {
      res = max(res, x);
    } else {
      int sx = sqrt(x);
      while (sx * sx < x)
        ++sx;
      while (sx * sx > x)
        --sx;
      if (sx * sx != x)
        res = max(res, x);
    }
  }
  cout << res << '\n';
}