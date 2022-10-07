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
    vector<int> a(n);
    int k = n;
    vector<vector<int>> g(n);
    vector<int> q;
    vector<int> res;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
      if (a[i] < i && k == n) {
        k = i;
      }
      if (a[i] == -1 || a[i] == n) {
        q.push_back(i);
      } else {
        g[a[i]].push_back(i);
      }
    }
    while (!q.empty()) {
      int u = -1;
      for (auto x : q) {
        if (g[x].empty()) {
          res.push_back(x);
        } else {
          u = x;
        }
      }
      if (u != -1) {
        res.push_back(u);
        q = g[u];
      } else {
        q.clear();
      }
    }
    cout << k << '\n';
    for (auto x : res) {
      cout << x + 1 << ' ';
    }
    cout << '\n';
  }
}