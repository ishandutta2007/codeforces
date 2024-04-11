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
  for (int ii = 0; ii < tn; ++ii) {
    int n, z;
    cin >> n >> z;
    int res = 0;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      res = max(res, a | z);
    }
    cout << res << '\n';
  }
}