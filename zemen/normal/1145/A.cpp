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
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int x = n; x >= 1; x /= 2) {
    for (int l = 0; l + x <= n; l += x) {
      if (is_sorted(a.begin() + l, a.begin() + l + x)) {
        cout << x << '\n';
        return 0;
      }
    }
  }
}