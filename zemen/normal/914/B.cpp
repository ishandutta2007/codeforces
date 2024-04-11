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
  set<int> s;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (s.count(x))
      s.erase(x);
    else
      s.insert(x);
  }
  cout << (s.empty() ? "Agasa" : "Conan") << '\n';
}