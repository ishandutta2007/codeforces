#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int ii = 0; ii < tn; ++ii) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    ll res = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      res += a[i];
      a[i] += i + 1;
    }
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < k; ++i) {
      res += n - k + i + 1 - a[i];
    }
    cout << res << '\n';
  }
}