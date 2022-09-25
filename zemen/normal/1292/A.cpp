#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  set<int> bad;

  int n, q;
  cin >> n >> q;
  array<vector<char>, 2> a{{vector<char>(n), vector<char>(n)}};

  auto is_bad = [&](int x) {
    return (a[0][x] + a[0][x + 1] > 0) && (a[1][x] + a[1][x + 1] > 0);
  };

  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    a[x][y] ^= 1;
    if (y - 1 >= 0) {
      bad.erase(y - 1);
      if (is_bad(y - 1)) {
        bad.insert(y - 1);
      }
    }
    if (y + 1 < n) {
      bad.erase(y);
      if (is_bad(y)) {
        bad.insert(y);
      }
    }
    if (bad.empty()) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}