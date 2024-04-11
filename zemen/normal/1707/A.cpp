#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  reverse(a.begin(), a.end());
  int x = 0;
  string res;
  for (int y : a) {
    if (y > x) {
      if (x == q) {
        res += '0';
      } else {
        res += '1';
        ++x;
      }
    } else {
      res += '1';
    }
  }
  reverse(res.begin(), res.end());
  cout << res << '\n';
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
    solve();
  }
}