#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  int n, k;
  cin >> n >> k;
  string a;
  cin >> a;
  string res = a;
  for (int i = k; i < n; ++i) {
    res[i] = res[i - k];
  }
  if (res < a) {
    int p = k - 1;
    while (p >= 0 && res[p] == '9') {
      res[p] = '0';
      --p;
    }
    assert(p >= 0);
    ++res[p];
    for (int i = k; i < n; ++i) {
      res[i] = res[i - k];
    }
    assert(res >= a);
  }
  cout << n << '\n' << res << '\n';
}