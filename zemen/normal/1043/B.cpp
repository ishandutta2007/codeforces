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
  vector<int> a(n + 1), s(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i+1];
  }
  for (int i = 0; i < n; ++i) {
    s[i] = a[i + 1] - a[i];
  }
  vector<int> res;
  for (int k = 1; k <= n; ++k) {
    bool ok = true;
    for (int i = 0; i + k < n; ++i) {
      if (s[i] != s[i + k]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      res.push_back(k);
    }
  }
  cout << (int) res.size() << '\n';
  for (int x : res) {
    cout << x << ' ';
  }
  cout << '\n';
}