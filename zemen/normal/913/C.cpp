#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  int n, l;
  cin >> n >> l;
  vector<ll> a(30);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = n; i < 30; ++i) {
    a[i] = a[i - 1] * 2;
  }

  for (int i = 0; i < 29; ++i) {
    a[i + 1] = min(a[i + 1], a[i] * 2);
  }
  ll res = 1e18, cur = 0;
  for (int i = 29; i >= 0; --i) {
    if (l & (1 << i)) {
      cur += a[i];
    }
    res = min(res, cur + a[i]);
  }
  res = min(res, cur);
  cout << res << '\n';
}