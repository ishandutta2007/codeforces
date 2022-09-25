#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    ll x;
    cin >> x;
    if (x % 14 >= 1 && x % 14 <= 6 && x >= 14) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}