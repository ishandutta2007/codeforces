#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void fail() {
  cout << -1 << '\n';
  exit(0);
}

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  int n, m, ta, tb, k;
  cin >> n >> m >> ta >> tb >> k;
  vector<int> a(n);
  vector<int> b(m);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  if (k >= min(n, m)) {
    fail();
  }
  ll res = 0;
  for (int c = 0; c <= k; ++c) {
    int t = a[c] + ta;
    auto p = lower_bound(b.begin(), b.end(), t);
    if (p + k - c >= b.end()) {
      fail();
    }
    res = max(res, *(p + k - c) + ll(tb));
  }
  cout << res << '\n';
}