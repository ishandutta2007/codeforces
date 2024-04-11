#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  int n;
  cin >> n;
  vector<int> a(n);
  vector<pair<int, int>> v;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    v.emplace_back(a[i], i);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  set<int> bad;
  int p = n - 1;
  while (v[p].first * 2 < v[0].first) {
    bad.insert(v[p].second);
    --p;
  }
  vector<int> res(n);
  for (auto pp : v) {
    while (p < (int) v.size() && v[p].first * 2 >= pp.first) {
      bad.erase(v[p].second);
      ++p;
    }
    int id = pp.second;
    auto pos = bad.lower_bound(id);
    if (bad.empty()) {
      res[id] = 10 * n;
    } else if (pos != bad.end()) {
      res[id] = *pos - id;
    } else {
      res[id] = n - id + *bad.begin();
    }
    //cerr << id << ' ' << res[id] << '\n';
  }
  for (int it = 0; it < 2; ++it) {
    for (int i = n - 2; i >= 0; --i) {
      res[i] = min(res[i], res[i + 1] + 1);
    }
    res[n - 1] = min(res[n - 1], res[0] + 1);
  }
  for (int i = 0; i < n; ++i) {
    cout << (res[i] >= 2 * n ? -1 : res[i]) << ' ';
  }
  cout << '\n';
}