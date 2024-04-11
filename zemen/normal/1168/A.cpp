#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int l = -1, r = m;
  while (l + 1 < r) {
    int c = (l + r) / 2;
    int x = 0;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      int y = -1;
      if (a[i] + c >= m) {
        if (a[i] + c - m >= x) {
          y = x;
        } else {
          y = max(x, a[i]);
        }
      } else {
        if (a[i] + c < x) {
          ok = false;
          break;
        } else {
          y = max(x, a[i]);
        }
      }
      x = y;
    }
    if (ok) {
      r = c;
    } else {
      l = c;
    }
  }
  cout << r << '\n';
}