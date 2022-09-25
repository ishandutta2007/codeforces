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
  for (int ii = 0; ii < tn; ++ii) {
    int n, m;
    string a, b;
    cin >> n >> m >> a >> b;
    bool fail = false;
    if (n == m) {
      fail = a != b;
    } else {
      if (a.substr(n - m + 1) != b.substr(1)) {
        fail = true;
      }
      auto l = *min_element(a.begin(), a.begin() + n - m + 1);
      auto r = *max_element(a.begin(), a.begin() + n - m + 1);
      if (b[0] > r || b[0] < l) {
        fail = true;
      }
    }
    cout << (fail ? "NO" : "YES") << '\n';
  }
}