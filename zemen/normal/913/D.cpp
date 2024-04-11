#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  int n, T;
  cin >> n >> T;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; ++i) {
    int a, t;
    cin >> a >> t;
    v[i] = {a, t};
  }
  int l = 0, r = n + 1;
  vector<pair<int, int>> ans;
  while (l + 1 < r) {
    int k = (l + r) / 2;
    vector<pair<int, int>> b;
    for (int i = 0; i < n; ++i) {
      if (v[i].first >= k) {
        b.emplace_back(v[i].second, i);
      }
    }
    if ((int) b.size() < k) {
      r = k;
      continue;
    }
    nth_element(b.begin(), b.begin() + k - 1, b.end());
    b.resize(k);
    ll sum = 0;
    for (int i = 0; i < k; ++i) {
      sum += b[i].first;
    }
    if (sum > T) {
      r = k;
    } else {
      l = k;
      ans = b;
    }
  }
  cout << l << '\n';
  cout << l << '\n';
  for (auto x : ans) {
    cout << x.second + 1 << ' ';
  }
  cout << '\n';
}