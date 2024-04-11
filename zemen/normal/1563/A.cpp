#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(int a, int b) {
  vector<int> res;
  for (int k = 0; k <= a + b; ++k) {
    for (int t : {0, 1}) {
      int x = (a + b + t) / 2;
      if ((x + k) % 2 != a % 2) {
        continue;
      }

      int mn;
      if (x - k < 0) {
        mn = k - x;
      } else {
        mn = x - k;
      }

      int mx;
      if (x + k > a + b) {
        mx = (a + b) * 2 - (x + k);
      } else {
        mx = x + k;
      }

      if (a < mn || a > mx) {
        continue;
      }
      res.push_back(k);
      break;
    }
  }

  cout << res.size() << '\n';
  for (int x : res) {
    cout << x << ' ';
  }
  cout << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    int a, b;
    cin >> a >> b;
    solve(a, b);
  }
}