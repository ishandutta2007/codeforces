#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> x(n), p(n);
  struct E {
    ll da, db, x;
    bool operator<(const E& other) const {
      return x < other.x;
    }
  };
  vector<E> delta;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> p[i];
    ll l = x[i] - p[i];
    ll r = x[i] + p[i];
    delta.push_back(E{+1, -l, l});
    delta.push_back(E{-1, +l, x[i]});
    delta.push_back(E{-1, +r, x[i]});
    delta.push_back(E{+1, -r, r});
  }
  sort(delta.begin(), delta.end());
  const ll infl = 2e18;

  ll L = infl, R = -infl;
  ll a = 0, b = 0;
  for (int i = 0; i < (int) delta.size(); ++i) {
    auto& [da, db, x] = delta[i];
    a += da;
    b += db;
    if (i + 1 == (int) delta.size() || delta[i + 1].x > x) {
      ll val = a * x + b;
      //cerr << x << ' ' << val << '\n';
      if (val > m) {
        ll r = val - m;
        L = min(L, x - r);
        R = max(R, x + r);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (x[i] - p[i] <= L && x[i] + p[i] >= R) {
      cout << '1';
    } else {
      cout << '0';
    }
  }
  cout << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int ii = 0; ii < tn; ++ii) {
    solve();
  }
}