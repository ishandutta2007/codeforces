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
    int n, x;
    cin >> n >> x;
    const int inf = 1e9 + 100;
    int mn = inf, mx = -inf;
    int res = 0;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      mn = min(mn, a);
      mx = max(mx, a);
      if (mx - mn > 2 * x) {
        mn = mx = a;
        ++res;
      }
    }
    cout << res << '\n';
  }
}