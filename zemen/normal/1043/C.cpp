#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  string s;
  cin >> s;
  int n = s.size();
  vector<int> flip(n);
  for (int i = 1; i < n; ++i) {
    if (s[i] == 'a') {
      flip[i] ^= 1;
      flip[i-1] ^= 1;
    }
  }
  for (int x : flip) {
    cout << x << ' ';
  }
  cout << '\n';
}