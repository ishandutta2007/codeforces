#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
  }
  for (int i = 0; i < n; ++i) {
    cin >> a[i].second;
  }
  sort(a.begin(), a.end());

  a.emplace_back(1e9 + 1e6, 0);
  ll sum = 0;
  priority_queue<int> o;
  int px = 0;
  ll res = 0;
  for (auto [x, c] : a) {
    while (!o.empty() && px < x) {
      sum -= o.top();
      o.pop();
      res += sum;
      ++px;
    }
    px = x;
    sum += c;
    o.push(c);
  }
  cout << res << '\n';
}