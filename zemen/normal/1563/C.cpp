#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
  }
  for (int i = 0; i < n; ++i) {
    if (p[i] % 2 != i % 2) {
      cout << -1 << '\n';
      return;
    }
  }

  auto get_pos = [&](int x) {
    auto it = find(p.begin(), p.end(), x);
    assert(it != p.end());
    return it - p.begin();
  };

  vector<int> ops;
  auto move = [&](int x) {
    //cerr << "move " << x << '\n';
    assert(x % 2 && x > 0 && x <= n);
    ops.push_back(x);
    reverse(p.begin(), p.begin() + x);
  };

  for (int a = n - 2; a >= 0; a -= 2) {
    move(get_pos(a + 1) + 1);
    move(get_pos(a));
    move(get_pos(a) + 2);
    move(3);
    move(a + 2);
  }

  assert(is_sorted(p.begin(), p.end()));
  assert((int) ops.size() <= (5 * n) / 2);
  cout << ops.size() << '\n';
  for (auto x : ops) {
    cout << x << ' ';
  }
  cout << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}