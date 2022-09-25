#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  ll n, k;
  cin >> n >> k;
  ll mn = max(1ll, k - n);
  ll mx = min(n, k - 1ll);
  ll res = mn <= mx ? (mx - mn + 1) / 2 : 0;
  cout << res << '\n';
}