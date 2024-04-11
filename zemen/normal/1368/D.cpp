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
  const int B = 20;
  vector<int> cnt(B);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    for (int j = 0; j < B; ++j) {
      if (x & (1 << j)) {
        ++cnt[j];
      }
    }
  }
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    int x = 0;
    for (int j = 0; j < B; ++j) {
      if (cnt[j]-- > 0) {
        x += 1 << j;
      }
    }
    res += ll(x) * ll(x);
  }
  cout << res << '\n';
}