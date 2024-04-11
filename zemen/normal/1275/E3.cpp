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
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    bool has0 = false;
    int sum = 0;
    int ceven = 0;
    for (auto c : s) {
      sum += c - '0';
      ceven += (c - '0') % 2 == 0;
      if (c == '0') {
        has0 = true;
      }
    }
    if (has0 && sum % 3 == 0 && ceven > 1) {
      cout << "red\n";
    } else {
      cout << "cyan\n";
    }
  }
}