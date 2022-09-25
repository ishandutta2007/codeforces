#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  string s;
  cin >> s;
  int x = 0;
  for (auto c : s) {
    x += c != 'a';
  }
  string t = s.substr(0, (int) s.size() - x / 2);
  string t2 = t;
  for (auto c : t) {
    if (c != 'a') {
      t2.push_back(c);
    }
  }
  if (t2 == s) {
    cout << t << '\n';
  } else {
    cout << ":(\n";
  }
}