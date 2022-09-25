#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int ii = 0; ii < tn; ++ii) {
    int n, m;
    cin >> n >> m;
    auto read = [&](int n) {
      vector<pair<int, ll>> res;
      for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ll cnt = 1;
        while (x % m == 0) {
          cnt *= m;
          x /= m;
        }
        if (!res.empty() && res.back().first == x) {
          res.back().second += cnt;
        } else {
          res.emplace_back(x, cnt);
        }
      }
      return res;
    };
    auto a = read(n);
    int k;
    cin >> k;
    auto b = read(k);
    cout << (a == b ? "Yes" : "No") << '\n';
  }
}