#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a.begin(), a.end());
  if (sum + a[0] * (n - 2) > 0 || sum + a[n - 1] * (n - 2) < 0) {
    cout << "INF\n";
    return;
  }
  ll prod = 0;
  int d0 = -1;
  for (int i = 1; i < n; ++i) {
    prod += a[i] * a[0];
    ++d0;
  }
  int dn = 0;
  ll res = prod - (d0 * a[0] + dn * a[n - 1] + sum) * a[1];
  //cerr << a[1] << ' ' << res << '\n';
  for (int i = 1; i + 1 < n - 1; ++i) {
    --d0;
    ++dn;
    prod -= a[i] * a[0];
    prod += a[i] * a[n - 1];
    ll cur = prod - (d0 * a[0] + dn * a[n - 1] + sum) * a[i + 1];
    //cerr << a[i + 1] << ' ' << cur << '\n';
    res = max(res, cur);
  }
  cout << res << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("f.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}