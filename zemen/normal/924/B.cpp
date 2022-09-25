#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  ll U;
  cin >> n >> U;
  vector<ll> e(n);
  for (int i = 0; i < n; ++i) {
    cin >> e[i];
  }
  int k = 0;
  ld best = -1;
  for (int i = 0; i + 2 < n; ++i) {
    k = max(k, i);
    while (k + 1 < n && e[k + 1] - e[i] <= U) {
      ++k;
    }
    if (i + 1 < k) {
      ld cur = (e[k] - e[i + 1]) / ld(e[k] - e[i]);
      best = max(best, cur);
    }
  }
  cout << fixed;
  cout.precision(12);
  if (best < 0) {
    cout << -1 << '\n';
  } else {
    cout << best << '\n';
  }
}