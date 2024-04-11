#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  int n;
  ll p, q, r;
  cin >> n >> p >> q >> r;
  vector<ll> a(n), pr(n), sf(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    pr[i] = a[i] * p;
    if (i)
      pr[i] = max(pr[i], pr[i - 1]);
  }
  for (int i = n - 1; i >= 0; --i) {
    sf[i] = a[i] * r;
    if (i + 1 < n)
      sf[i] = max(sf[i], sf[i + 1]);
  }
  ll ans = -5e18;
  for (int i = 0; i < n; ++i) {
    ans = max(ans, pr[i] + sf[i] + a[i] * q);
  }
  cout << ans << '\n';
}