#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

ll calc(ll n) {
  if (n <= 0) {
    return 0;
  }
  ll x = ll(sqrtl(n));
  while (x * x > n) {
    --x;
  }
  while ((x + 1) * (x + 1) <= n) {
    ++x;
  }
  ll res = (x - 1) * 3;
  for (int i = 0; i < 3; ++i) {
    if (x * (x + i) <= n) {
      ++res;
    }
  }
  return res;
}

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  //for (int i = 1; i <= 1000; ++i) {
    //int s = int(sqrt(i));
    //if (i % s == 0) {
      //cout << i << ' ' << s << 'x' << (i / s) << '\n';
    //}
  //}
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    ll l, r;
    cin >> l >> r;
    cout << calc(r) - calc(l - 1) << '\n';
  }
}