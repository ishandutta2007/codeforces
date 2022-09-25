#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  int n;
  cin >> n;
  vector<int> a(n);
  ll c1 = 0, c2 = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ll x = a[i] / 2;
    ll y = a[i] - a[i] / 2;
    if (i % 2) {
      swap(x, y);
    }
    c1 += x;
    c2 += y;
  }
  cout << min(c1, c2) << '\n';
}