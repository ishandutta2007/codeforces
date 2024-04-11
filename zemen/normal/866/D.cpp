#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  int n;
  cin >> n;
  multiset<int> s, t;
  s.insert(1e9);
  t.insert(1e9);
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    int p;
    cin >> p;
    auto is = s.begin();
    auto it = t.begin();
    if (p <= min(*is, *it)) {
      s.insert(p);
      continue;
    }
    res += p - min(*is, *it);
    if (*is <= *it) {
      s.erase(is);
      t.insert(p);
    } else {
      s.insert(*it);
      t.erase(it);
      t.insert(p);
    }
  }
  cout << res << '\n';
}