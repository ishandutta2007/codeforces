#pragma GCC optimize("Ofast,no-stack-protector")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  vector<int> until(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    until[a[i]] = i;
  }
  a[n] = 0;
  until[0] = n + 10;

  int res = n;

  int r1 = until[a[0]];
  int r2 = r1;
  if (r1 == 0) {
    ++res;
    //cerr << "recover " << 0 << '\n';
  }

  for (int i = 1; i <= n; ++i) {
    if (i > r1) {
      if (r2 > r1) {
        r1 = r2;
        --res;
        //cerr << "drop1 " << i << '\n';
      } else {
        res -= 2;
        //cerr << "drop2 " << i << '\n';
        r1 = r2 = until[a[i]];
        if (r1 == i) {
          ++res;
          //cerr << "recover " << i << '\n';
        }
      }
    }

    r2 = max(r2, until[a[i]]);
  }
  cout << res << '\n';
}