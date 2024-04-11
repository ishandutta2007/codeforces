#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  int tn;
  cin >> tn;
  for (int ii = 0; ii < tn; ++ii) {
    int n;
    cin >> n;
    vector<char> has(4);
    int cx = 0, cy = 0;
    bool nc = false;
    for (int i = 0; i < 3; ++i) {
      int x, y;
      cin >> x >> y;
      has[(x % 2) * 2 + (y % 2)] = true;
      int sides = (x == 1 || x == n) + (y == 1 || y == n);
      if (sides == 2) {
        cx = x;
        cy = y;
      }
      if (sides == 0) {
        nc = true;
      }
    }
    if (nc) {
      cx = cy = 0;
    }
    int x, y;
    cin >> x >> y;
    bool res = !has[(x % 2) * 2 + (y % 2)] || (cx && x != cx && y != cy);
    cout << (res ? "NO" : "YES") << '\n';
  }
}