#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  int n, s;
  cin >> n >> s;
  --s;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  bool ok = a[s];
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    if (i > s && b[i] && a[i] && b[s]) {
      ok = true;
    }
  }
  ok &= a[0];
  cout << (ok ? "YES" : "NO") << '\n';
}