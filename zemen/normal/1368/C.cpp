#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  int n;
  cin >> n;
  ++n;
  cout << 1 + 3 * n << '\n';
  cout << "0 0\n";
  for (int i = 1; i <= n; ++i) {
    cout << i << ' ' << i << '\n';
    cout << i << ' ' << i - 1 << '\n';
    cout << i - 1 << ' ' << i << '\n';
  }
}