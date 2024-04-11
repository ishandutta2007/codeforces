#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

ll up(ll a, ll b) {
  return (a + b - 1) / b;
}

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  int m;
  ll n, a, d;
  cin >> n >> m >> a >> d;
  vector<ll> t(m);
  for (int i = 0; i < m; ++i) {
    cin >> t[i];
  }
  t.push_back(n * a);
  sort(t.begin(), t.end());
  reverse(t.begin(), t.end());

  ll T = 1;
  ll res = 0;
  while (true) {
    ll t1 = up(T, a);
    if (t1 > n)
      t1 = 2e18;
    else
      t1 *= a;

    while (!t.empty() && t.back() < T)
      t.pop_back();
    ll t2 = t.empty() ? 2e18 : t.back();

    if (min(t1, t2) == 2e18)
      break;

    bool sh = false;
    if (t1 < t2) {
      //cerr << "otseka\n";
      ll block = up(d + 1, a) * a;
      ll cnt = (t2 - t1) / block - 3;
      if (cnt > 0) {
        sh = true;
        res += cnt;
        T = t1 + cnt * block;
      }
    }

    if (!sh) {
      T = min(t1, t2) + d + 1;
      ++res;
    }
  }
  cerr << "time " << T << '\n';
  cout << res << '\n';
}