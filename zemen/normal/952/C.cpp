#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int iter = 0; iter < n; ++iter) {
    for (int i = 0; i < (int) a.size() - 1; ++i) {
      if (abs(a[i] - a[i + 1]) > 1) {
        cout << "NO\n";
        return 0;
      }
    }
    int p = 0;
    for (int i = 0; i < (int) a.size(); ++i) {
      if (a[i] > a[p]) {
        p = i;
      }
    }
    a.erase(a.begin() + p);
  }
  cout << "YES\n";
}