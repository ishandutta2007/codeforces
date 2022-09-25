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
  if (n % 2 == 0) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  vector<int> a(n * 2);
  int c = 1;
  for (int i = 0; i < n; ++i) {
    if (i % 2) {
      a[i + n] = c++;
      a[i] = c++;
    } else {
      a[i] = c++;
      a[i + n] = c++;
    }
  }
  for (int x : a) {
    cout << x << ' ';
  }
  cout << '\n';
}