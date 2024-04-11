#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  int n;
  cin >> n;
  bool x = 0;
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (a % 2) {
      if (x) {
        a = (a + 1) / 2;
      } else {
        a = (a - 1) / 2;
      }
      x ^= 1;
    } else {
      a /= 2;
    }
    cout << a << '\n';
    sum += a;
  }
  assert(sum == 0);
}