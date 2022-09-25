#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  int tn;
  cin >> tn;
  for (int ii = 0; ii < tn; ++ii) {
    ll a, b, n;
    cin >> a >> b >> n;
    int res = 0;
    while (max(a, b) <= n) {
      ++res;
      if (a > b) {
        swap(a, b);
      }
      a += b;
    }
    cout << res << '\n';
  }
}