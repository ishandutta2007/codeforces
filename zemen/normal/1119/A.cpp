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
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int p = n - 1;
  while (a[0] == a[p]) {
    --p;
  }
  int q = 0;
  while (a[q] == a.back()) {
    ++q;
  }
  cout << max(p, n - 1 - q) << '\n';
}