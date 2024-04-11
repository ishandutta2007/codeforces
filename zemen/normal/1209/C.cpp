#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n;
  string s;
  cin >> n >> s;
  for (int b = 0; b < 10; ++b) {
    string res;
    int da = 0, db = b;
    for (auto c : s) {
      int d = c - '0';
      if (d == b && db == b) {
        res += '2';
      } else if (d <= b) {
        if (da > d) {
          break;
        }
        res += '1';
        da = d;
      } else {
        if (db > d) {
          break;
        }
        res += '2';
        db = d;
      }
    }
    if (res.size() == s.size()) {
      cout << res << '\n';
      return;
    }
  }
  cout << "-\n";
}

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}