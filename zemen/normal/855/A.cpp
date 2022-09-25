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
  set<string> was;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    if (was.count(s))
      cout << "YES\n";
    else
      cout << "NO\n";
    was.insert(s);
  }
}