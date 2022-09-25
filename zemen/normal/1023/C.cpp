#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  int n, k;
  string s;
  cin >> n >> k >> s;
  int ban = 0;
  int bal = 0;
  for (auto c : s) {
    if (c == '(') {
      ++bal;
      if (k < n) {
        k += 2;
        ban = bal;
      } else {
        cout << c;
      }
    } else {
      if (ban == bal) {
        --ban;
      } else {
        cout << c;
      }
      --bal;
    }
  }
  cout << '\n';
}