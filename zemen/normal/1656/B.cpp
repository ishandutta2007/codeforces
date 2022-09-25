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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int r = 0;
    bool ok = false;
    for (int i = 0; i < n; ++i) {
      while (r < n && a[r] < a[i] + k) {
        ++r;
      }
      if (r < n && a[i] + k == a[r]) {
        ok = true;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}