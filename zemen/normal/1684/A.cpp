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
    string s;
    cin >> s;
    if ((int) s.size() == 2) {
      cout << s[1] << '\n';
    } else {
      cout << *min_element(s.begin(), s.end()) << '\n';
    }
  }
}