#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int ii = 0; ii < tn; ++ii) {
    int n;
    cin >> n;
    vector<int> a(n), p(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
      p[a[i]] = i;
    }

    int res = 0;
    auto go = [&](bool bw) {
      int c = p[0];
      bool mx = true;
      int l = 0, r = n - 1;
      while (bw ? c > 0 : c < n - 1) {
        if (mx) {
          while (bw ? p[r] >= c : p[r] <= c) {
            --r;
          }
          c = p[r];
          ++res;
        } else {
          while (bw ? p[l] >= c : p[l] <= c) {
            ++l;
          }
          c = p[l];
          ++res;
        }
        mx ^= 1;
      }
    };
    go(false);
    go(true);
    cout << res << '\n';
  }
}