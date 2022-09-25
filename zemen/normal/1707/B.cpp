#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = 1;
  }
  vector<pair<int, int>> b;
  for (int iter = 0; iter < n - 1; ++iter) {
    int c0 = 0;
    b.clear();
    for (int i = 0; i < (int) a.size(); ++i) {
      if (i + 1 < (int) a.size()) {
        b.emplace_back(a[i + 1].first - a[i].first, 1);
      }
      c0 += a[i].second - 1;
    }
    if (c0 > 0) {
      b.emplace_back(0, c0);
    }
    sort(b.begin(), b.end());
    a.clear();
    for (auto [x, cnt] : b) {
      if (a.empty() || a.back().first != x) {
        a.emplace_back(x, cnt);
      } else {
        a.back().second += cnt;
      }
    }
  }
  assert(a.size() == 1 && a[0].second == 1);
  cout << a[0].first << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}