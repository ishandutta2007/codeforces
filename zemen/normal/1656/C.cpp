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
    bool has1 = false;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i] == 1) {
        has1 = true;
      }
    }
    if (!has1) {
      cout << "YES\n";
      continue;
    }
    sort(a.begin(), a.end());
    bool ok = true;
    for (int i = 0; i < n - 1; ++i) {
      if (a[i + 1] == a[i] + 1) {
        ok = false;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}