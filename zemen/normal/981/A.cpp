#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

bool pal(string s) {
  string t = s;
  reverse(t.begin(), t.end());
  return t == s;
}

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  string s;
  cin >> s;
  int res = 0;
  for (int i = 0; i < (int) s.size(); ++i) {
    for (int j = i + 1; j <= (int) s.size(); ++j) {
      if (!pal(s.substr(i, j))) {
        res = max(res, j - i);
      }
    }
  }
  cout << res << '\n';
}