#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("m.in", "r", stdin));
#endif
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  cout << 2 * (max(2, 1 + abs(x1 - x2)) + max(2, 1 + abs(y1 - y2))) << '\n';
}