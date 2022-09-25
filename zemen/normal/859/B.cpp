#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  int n;
  cin >> n;
  int res = 1e9;
  for (int a = 1; a <= n; ++a) {
    int b = 1;
    while (a * b < n)
      ++b;
    if (a + b - 1 <= n) {
      res = min(res, 2 * (a + b));
    }
  }
  cout << res << '\n';
}