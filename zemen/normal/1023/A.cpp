#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  int n, m;
  string s, t;
  cin >> n >> m >> s >> t;
  while (!s.empty() && !t.empty() && s.back() == t.back()) {
    s.pop_back();
    t.pop_back();
  }
  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());
  while (!s.empty() && !t.empty() && s.back() == t.back()) {
    s.pop_back();
    t.pop_back();
  }
  if (s == "*" || (s.empty() && t.empty())) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}