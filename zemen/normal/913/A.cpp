#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  int n, m;
  cin >> n >> m;
  if (n >= 30) {
    cout << m << '\n';
  } else {
    cout << m % (1 << n) << '\n';
  }
}