#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  ll n;
  cin >> n;
  ll n_ = n;
  vector<ll> p;
  for (ll i = 2; i * i <= n_; ++i) {
    if (n_ % i == 0) {
      p.push_back(i);
      while (n_ % i == 0) {
        n_ /= i;
      }
    }
  }
  if (n_ > 1) {
    p.push_back(n_);
  }
  if (n == 1 || p.size() > 1) {
    cout << 1 << '\n';
  } else {
    cout << p[0] << '\n';
  }
}