#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

ll gcd(ll a, ll b) {
  while (a && b) {
    if (a >= b) {
      a %= b;
    } else {
      b %= a;
    }
  }
  return a + b;
}

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  ll l[2], r[2], t[2], len[2];
  for (int i = 0; i < 2; ++i) {
    cin >> l[i] >> r[i] >> t[i];
    ++r[i];
    len[i] = r[i] - l[i];
  }
  ll g = gcd(t[0], t[1]);
  l[0] %= g;
  l[1] %= g;
  ll res = 0;
  for (ll sh : {-g, 0ll, g}) {
    res = max(res, min(l[0] + sh + len[0], l[1] + len[1]) - max(l[0] + sh, l[1]));
  }
  cout << res << '\n';
}