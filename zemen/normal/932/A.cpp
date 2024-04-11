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
  string t = s;
  reverse(t.begin(), t.end());
  cout << s << t << '\n';
}