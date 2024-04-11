#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

ll solve(ll n) {
  ll nn = n;
  ll k = 2;
  while (nn % 2 == 0) {
    nn /= 2;
    k *= 2;
  }
  if (k < ll(2e9) && n >= k * (k + 1) / 2) {
    return k;
  }
  if (nn > 1 && nn < ll(2e9) && n >= nn * (nn + 1) / 2) {
    return nn;
  }
  return -1;
}

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    ll n;
    cin >> n;
    cout << solve(n) << '\n';
  }
}