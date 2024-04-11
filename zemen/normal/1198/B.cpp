#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = -1;
  }
  int q;
  cin >> q;
  vector<pair<int, int>> remax;
  for (int i = 0; i < q; ++i) {
    int t;
    cin >> t;
    if (t == 1) {
      int p, x;
      cin >> p >> x;
      --p;
      a[p] = {x, i};
    } else {
      int x;
      cin >> x;
      while (!remax.empty() && remax.back().second <= x) {
        remax.pop_back();
      }
      remax.emplace_back(i, x);
    }
  }
  for (int i = 0; i < n; ++i) {
    auto it = lower_bound(remax.begin(), remax.end(), pair<int, int>{a[i].second, 0});
    if (it != remax.end()) {
      a[i].first = max(a[i].first, it->second);
    }
    cout << a[i].first << ' ';
  }
  cout << '\n';
}