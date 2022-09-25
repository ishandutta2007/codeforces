#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

bool bit(int n, int k) {
  return (n >> k) & 1;
}

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  //int n = 9;
  //for (int i = 0; i < (1 << n); ++i) {
    //bool sos = false;
    //for (int j = 0; j < n; ++j) {
      //for (int k = 1; j + 2 * k < n; ++k) {
        //if (bit(i, j) == bit(i, j + k) && bit(i, j) == bit(i, j + 2 * k)) {
          //sos = true;
        //}
      //}
    //}
    //if (!sos) {
      //cout << bitset<9>(i) << '\n';
    //}
  //}

  string s;
  cin >> s;
  int n = (int) s.size();
  ll res = n * ll(n + 1) / 2;
  for (int r = 0; r < (int) s.size(); ++r) {
    for (int l = r; l >= 0; --l) {
      bool ok = true;
      for (int k = 1; l + 2 * k <= r; ++k) {
        if (s[l] == s[l + k] && s[l] == s[l + 2 * k]) {
          ok = false;
          break;
        }
      }
      if (!ok) {
        break;
      } else {
        --res;
      }
    }
  }
  cout << res << '\n';
}