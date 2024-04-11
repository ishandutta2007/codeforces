#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int ii = 0; ii < tn; ++ii) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int l = -1, r = -2;
    for (int i = 0; i < n - 1; ++i) {
      if (a[i] == a[i + 1]) {
        if (l == -1) {
          l = i + 1;
        }
        r = i;
      }
    }
    if (l > r) {
      cout << 0 << '\n';
    } else {
      cout << max(1, r - l) << '\n';
    }
  }
}