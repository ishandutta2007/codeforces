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
  int ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by >> cx >> cy;
  if ((bx - ax) * (cx - ax) < 0 || (by - ay) * (cy - ay) < 0) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}