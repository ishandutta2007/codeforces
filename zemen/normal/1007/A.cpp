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
  multiset<int> s;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    s.insert(a[i]);
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    while (!s.empty() && *s.begin() <= a[i]) {
      s.erase(s.begin());
    }
    if (s.empty()) {
      cout << i << '\n';
      return 0;
    }
    s.erase(s.begin());
  }
}