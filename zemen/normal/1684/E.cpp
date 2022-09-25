#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n, k;
  cin >> n >> k;
  map<int, int> cnt;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    cnt[a]++;
  }
  vector<pair<int, int>> by_cnt;
  for (auto [x, cnt] : cnt) {
    by_cnt.emplace_back(cnt, x);
  }
  sort(by_cnt.begin(), by_cnt.end());
  int ops = 0;
  int r = 0;
  int holes = 0;
  int res = (int) by_cnt.size();
  int best = res;
  for (int mex = 0; mex <= n; ++mex) {
    if (!cnt.count(mex)) {
      ++holes;
    } else {
      pair<int, int> cur{cnt[mex], mex};
      if (r == (int) by_cnt.size() || cur < by_cnt[r]) {
        ops -= cur.first;
      } else {
        --res;
      }
      assert(ops >= 0);
    }
    if (holes > k) {
      break;
    }

    while (r < (int) by_cnt.size()) {
      if (by_cnt[r].second <= mex) {
        ++r;
        continue;
      }
      if (ops + by_cnt[r].first > k) {
        break;
      }
      --res;
      ops += by_cnt[r].first;
      ++r;
    }

    best = min(best, res);
    //cerr << "mex: " << mex << ' ' << res << '\n';
  }
  cout << best << '\n';
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