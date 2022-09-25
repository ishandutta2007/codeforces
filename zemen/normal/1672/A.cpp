#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    int n;
    cin >> n;
    int sum = 0;
    for (int j = 0; j < n; ++j) {
      int a;
      cin >> a;
      sum += a - 1;
    }
    cout << (sum % 2 ? "errorgorn" : "maomao90") << '\n';
  }
}