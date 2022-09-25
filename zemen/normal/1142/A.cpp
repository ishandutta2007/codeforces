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
  assert(freopen("a.in", "r", stdin));
#endif
  ll n, k, a, b;
  cin >> n >> k >> a >> b;
  ll vmin = n * k, vmax = 1;
  for (ll x = 0; x < n; ++x) {
    for (int sgn : {1, -1}) {
      ll c = k * x + sgn * b - a;
      c %= n * k;
      if (c < 0) {
        c += n * k;
      }
      ll g = gcd(c, n * k);
      vmin = min(vmin, n * k / g);
      vmax = max(vmax, n * k / g);
    }
  }
  cout << vmin << ' ' << vmax << '\n';
}