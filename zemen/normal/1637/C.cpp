#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

ll solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  bool ones = true;
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (i == 0 || i == n - 1) {
      continue;
    }
    res += (a[i] + 1) / 2;
    if (a[i] > 1) {
      ones = false;
    }
  }
  if ((n == 3 && a[1] % 2) || ones) {
    return -1;
  }
  return res;
}

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    cout << solve() << '\n';
  }
}