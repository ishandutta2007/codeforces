#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  int n, m;
  cin >> n >> m;
  ll res = 0;
  for (int i = 0; i < m; ++i) {
    ll a = (n + (m - i) % m) / m;
    for (int j = 0; j < m; ++j) {
      ll b = (n + (m - j) % m) / m;
      if ((i * i + j * j) % m == 0) {
        res += a * b;
      }
    }
  }
  cout << res << '\n';
}