#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n, m;
  cin >> n >> m;
  map<int, int> cnt;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  set<pair<int, int>> bad;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    bad.emplace(x, y);
  }

  auto is_bad = [&](int x, int y) {
    if (x > y) {
      swap(x, y);
    }
    return x == y || bad.count({x, y});
  };

  map<int, vector<int>> by_cnt;
  for (auto [x, c] : cnt) {
    by_cnt[c].push_back(x);
  }
  for (auto& p : by_cnt) {
    sort(p.second.rbegin(), p.second.rend());
  }
  ll res = 0;
  for (auto& [cnt1, v1] : by_cnt) {
    for (auto& [cnt2, v2] : by_cnt) {
      int cur = 0;
      for (auto x : v1) {
        bool best = true;
        for (auto y : v2) {
          if (is_bad(x, y)) {
            best = false;
          } else {
            cur = max(cur, x + y);
            break;
          }
        }
        if (best) {
          break;
        }
      }
      res = max(res, cur * ll(cnt1 + cnt2));
    }
  }
  cout << res << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}