#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  string s;
  cin >> s;
  int x = 0;
  for (auto c : s) {
    x += c == 'a';
  }
  int res = min((int) s.size(), x * 2 - 1);
  cout << res << '\n';
}