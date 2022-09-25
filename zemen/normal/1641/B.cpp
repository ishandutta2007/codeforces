#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<pair<int, int>> op;
  vector<int> lens;
  for (int i = 0; i < n; i += 2) {
    int j = i + 1;
    while (j < n && a[j] != a[i]) {
      ++j;
    }
    if (j == n) {
      cout << -1 << '\n';
      return;
    }
    int sh = 2 * (int) op.size() + j - i;
    for (int k = i + 1; k < j; ++k) {
      op.emplace_back(sh + k, a[k]);
    }
    lens.push_back(2 * (j - i));
    reverse(a.begin() + i + 1, a.begin() + j + 1);
  }
  cout << op.size() << '\n';
  for (auto [p, c] : op) {
    cout << p << ' ' << c << '\n';
  }
  cout << lens.size() << '\n';
  for (auto x : lens) {
    cout << x << ' ';
  }
  cout << '\n';
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