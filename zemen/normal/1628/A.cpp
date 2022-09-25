#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<int>> pos(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    pos[a[i]].push_back(i);
  }
  vector<int> b;
  int r = 0;
  while (r < n) {
    int to = r;
    for (int m = 0; ; ++m) {
      auto it = lower_bound(pos[m].begin(), pos[m].end(), r);
      if (it == pos[m].end()) {
        b.push_back(m);
        break;
      }
      to = max(to, *it);
    }
    r = to + 1;
  }
  cout << b.size() << '\n';
  for (auto x : b) {
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
    solve();
  }
}