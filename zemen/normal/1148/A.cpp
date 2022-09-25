#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  ll a, b, c;
  cin >> a >> b >> c;
  ll res = c * 2;
  if (a == b) {
    res += a + b;
  } else {
    res += 2 * min(a, b) + 1;
  }
  cout << res << '\n';
}