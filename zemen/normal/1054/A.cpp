#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  int x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  int r1 = abs(x - y) * t1;
  int r2 = abs(x - y) * t2 + abs(z - x) * t2 + t3 * 3;
  cerr << r1 << ' ' << r2 << '\n';
  if (r2 <= r1) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}