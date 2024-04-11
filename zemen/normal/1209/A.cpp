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
  sort(a.begin(), a.end());
  int res = 0;
  while (!a.empty()) {
    vector<int> b;
    int x = a[0];
    for (int y : a) {
      if (y % x != 0) {
        b.push_back(y);
      }
    }
    a = b;
    ++res;
  }
  cout << res << '\n';
}