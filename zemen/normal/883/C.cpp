#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct Tariff {
  ll a, t, p;

  bool operator<(const Tariff& o) const {
    return t < o.t;
  }
};

Tariff d[3];

ll up(ll a, ll b) {
  return (a + b - 1) / b;
}

ll solve(ll f, ll t) {
  ll rem = d[0].t * f - t;
  ll delta = d[0].t - d[1].t;
  if (rem <= 0)
    return 0;
  if (delta <= 0 || d[1].t * f > t)
    return 5e18;
  ll b = up(rem, delta);
  return up(b, d[1].a) * d[1].p;
}

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  ll f, T;
  d[0].a = 1;
  d[0].p = 0;
  cin >> f >> T >> d[0].t;
  for (int i = 1; i <= 2; ++i) {
    cin >> d[i].a >> d[i].t >> d[i].p;
  }

  ll res = 5e18;
  for (int i = 0; i < 3; ++i) {
    if (d[i].t * f <= T)
      res = min(res, d[i].p * up(f, d[i].a));
  }
  if (res == 5e18) {
    cout << -1 << '\n';
    return 0;
  }

  for (int iter = 0; iter < 2; ++iter) {
    for (int i = 0; i <= f; ++i) {
      ll f1 = f - i;
      ll t1 = T - d[2].t * i;
      ll p1 = d[2].p * up(i, d[2].a);
      if (t1 >= 0)
        res = min(res, solve(f1, t1) + p1);
    }
    swap(d[1], d[2]);
  }
  cout << res << '\n';
}