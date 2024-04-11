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
  vector<int> a(n);
  int num1 = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    num1 += a[i] == 1;
  }
  int res = 0;
  if (num1 == 0) {
    int best = 1e9;
    for (int l = 0; l < n; ++l) {
      int g = a[l];
      for (int r = l + 1; r < n; ++r) {
        g = __gcd(g, a[r]);
        if (g == 1) {
          best = min(best, r - l);
          break;
        }
      }
    }
    if (best == 1e9) {
      cout << -1 << '\n';
      return 0;
    }
    res = best;
    num1 = 1;
  }
  res += n - num1;
  cout << res << '\n';
}