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
  string color = "blue";
  bool locked = false;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    if (s == "lock") {
      locked = true;
    } else if (s == "unlock") {
      locked = false;
    } else if (!locked) {
      color = s;
    }
  }
  cout << color << '\n';
}