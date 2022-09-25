#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    string s;
    cin >> s;
    bool sos = s.back() == 'A';
    int block = 0;
    for (auto c : s) {
      if (c == 'A') {
        ++block;
      } else {
        if (block == 0) {
          sos = true;
        } else {
          --block;
        }
      }
    }
    cout << (sos ? "NO" : "YES") << '\n';
  }
}