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
  set<int> s;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    s.insert(x);
  }
  int x = 1;
  while (int(s.size()) < 25) {
    if (!s.count(x)) {
      s.insert(x);
    }
    ++x;
  }
  cout << *s.rbegin() - 25 << '\n';
}