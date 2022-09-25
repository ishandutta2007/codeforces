#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

multiset<ll> s;
ll x = 0;

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<ll> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  for (int i = 0; i < n; ++i) {
    ll t;
    cin >> t;
    s.insert(v[i] + x);
    x += t;
    ll cur = (ll) s.size() * t;
    while (!s.empty() && *s.begin() <= x) {
      cur -= x - *s.begin();
      s.erase(s.begin());
    }
    cout << cur << ' ';
  }
  cout << '\n';
}