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
  for (int ii = 0; ii < tn; ++ii) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int res = a.back() - a.front();
    for (int i = 0; i + 1 < n; ++i) {
      res = max(res, a[i] - a[i + 1]);
    }
    if (n > 1) {
      res = max(res, a.back() - *min_element(a.begin(), a.end() - 1));
      res = max(res, *max_element(a.begin() + 1, a.end()) - a.front());
    }
    cout << res << '\n';
  }
}