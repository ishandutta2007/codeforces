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
  vector<pair<ll, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
  }
  for (int i = 0; i < n; ++i) {
    cin >> a[i].second;
  }
  sort(a.rbegin(), a.rend());
  vector<ll> got;
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    bool ok = false;
    for (ll m : got) {
      if ((a[i].first & m) == a[i].first) {
        ok = true;
        break;
      }
    }
    if (i + 1 < n && a[i].first == a[i + 1].first) {
      ok = true;
    }
    if (a[i].first == 0) {
      ok = true;
    }
    if (ok) {
      got.push_back(a[i].first);
      res += a[i].second;
    }
  }
  if (got.size() <= 1) {
    res = 0;
  }
  cout << res << '\n';
}