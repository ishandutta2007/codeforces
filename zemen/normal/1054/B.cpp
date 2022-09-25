#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  int n;
  cin >> n;
  vector<int> a(n);
  int mx = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] > mx) {
      cout << i + 1 << '\n';
      return 0;
    }
    mx = max(mx, a[i] + 1);
  }
  cout << -1 << '\n';
}