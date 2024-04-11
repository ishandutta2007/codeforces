#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  int x = 0;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    x ^= a[i];
  }
  if (x == 0) {
    cout << "DRAW\n";
    return;
  }
  for (int b = 30; b >= 0; --b) {
    int c1 = 0;
    if (x & (1 << b)) {
      for (int i = 0; i < n; ++i) {
        if (a[i] & (1 << b)) {
          ++c1;
        }
      }
      int c0 = n - c1;
      if (c0 % 2 == 0 && c1 % 4 == 3) {
        cout << "LOSE\n";
      } else {
        cout << "WIN\n";
      }
      return;
    }
  }
}

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}