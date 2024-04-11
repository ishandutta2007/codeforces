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
  vector<int> a(2 * n);
  for (int i = 0; i < 2 * n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  ll res = ll(a[2 * n - 1] - a[n]) * ll(a[n - 1] - a[0]);
  for (int i = 0; i < n; ++i) {
    res = min(res, ll(a[2 * n - 1] - a[0]) * ll(a[i + n - 1] - a[i]));
  }
  cout << res << '\n';
}