#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  ll s = 2 * accumulate(a.begin(), a.end(), 0);
  int mx = *max_element(a.begin(), a.end());
  cout << max<ll>(mx, (s + n) / n) << '\n';
}