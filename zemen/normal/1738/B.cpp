#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int ii = 0; ii < tn; ++ii) {
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
      cin >> a[i];
    }
    bool ok = true;
    for (int i = 0; i + 2 < k; ++i) {
      if (a[i + 1] - a[i] > a[i + 2] - a[i + 1]) {
        ok = false;
      }
    }
    if (k > 1) {
      ll x = a[1] - a[0];
      ll cnt = n - k + 1;
      if (x * cnt < a[0]) {
        ok = false;
      }
    }
    cout << (ok ? "Yes" : "No") << '\n';
  }
}