#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  ll x0, y0, ax, ay, bx, by, xs, ys, t;
  cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;

  using pt = pair<ll, ll>;
  auto dist = [](pt a, pt b) {
    return llabs(a.first - b.first) + llabs(a.second - b.second);
  };

  pt st{xs, ys};
  vector<pt> p{{x0, y0}};
  while (true) {
    ll x = p.back().first;
    ll y = p.back().second;
    x = ax * x + bx;
    y = ay * y + by;
    pt c{x, y};
    if (x - xs > t || y - ys > t) {
      break;
    }
    p.push_back(c);
  }
  //for (auto c : p) {
    //cerr << c.first << ' '<< c.second << '\n';
  //}
  int res = 0;
  for (int i = 0; i < (int) p.size(); ++i) {
    for (int j = i; j < (int) p.size(); ++j) {
      ll ct = min(dist(st, p[i]), dist(st, p[j])) + dist(p[i], p[j]);
      if (ct <= t) {
        res = max(res, j - i + 1);
      }
    }
  }
  cout << res << '\n';
}