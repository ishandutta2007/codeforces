#pragma GCC optimize("Ofast,no-stack-protector")
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
    vector<int> a(n);
    ll sum = 0;
    bool fail = false;
    for (int j = 0; j < n; ++j) {
      cin >> a[j];
      if (j > 0 && sum == 0 && a[j] != 0) {
        fail = true;
      }
      sum += a[j];
      if (sum < 0) {
        fail = true;
      }
    }
    if (sum != 0) {
      fail = true;
    }
    cout << (fail ? "No" : "Yes") << '\n';
  }
}