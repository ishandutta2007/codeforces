#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  int b, k;
  cin >> b >> k;
  vector<int> a(k);
  for (int i = 0; i < k; ++i) {
    cin >> a[i];
  }
  int res = 0;
  if (b % 2 == 0) {
    res = a[k - 1];
  } else {
    for (int i = 0; i < k; ++i) {
      res += a[i];
    }
  }
  cout << (res % 2 ? "odd" : "even") << '\n';
}