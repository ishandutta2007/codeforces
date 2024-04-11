#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    int n;
    cin >> n;
    int mx1 = 0, mx2 = 0;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      if (a > mx1) {
        mx2 = mx1;
        mx1 = a;
      } else {
        mx2 = max(mx2, a);
      }
    }
    cout << mx1 + mx2 << '\n';
  }
}