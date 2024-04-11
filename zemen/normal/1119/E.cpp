#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int p = n - 1, q = 0;
  ll res = 0;
  for (int i = n - 1; i >= 0; --i) {
    p = min(p, i);
    while (a[i] >= 2 && p >= 0) {
      if (a[p] % 2 == 0) {
        --p;
      } else {
        --a[p];
        a[i] -= 2;
        ++res;
      }
    }
    while (a[i] >= 2 && q <= i) {
      ll d = min(a[i] / 2, a[q]);
      if (q == i) {
        d = a[i] / 3;
      }
      a[i] -= d * 2;
      a[q] -= d;
      res += d;
      if (d == 0) {
        ++q;
      }
    }
  }
  cout << res << '\n';
}