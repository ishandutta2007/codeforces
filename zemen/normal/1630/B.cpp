#pragma GCC optimize("Ofast,no-stack-protector")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n, k;
  cin >> n >> k;
  int bd = (n + k + 1) / 2;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  auto b = a;
  sort(b.begin(), b.end());
  pair<int, int> best{b[0], b.back()};
  for (int i = 0; i + bd <= n; ++i) {
    pair<int, int> cur{b[i], b[i + bd - 1]};
    if (cur.second - cur.first < best.second - best.first) {
      best = cur;
    }
  }
  cout << best.first << ' ' << best.second << '\n';
  int bal = 0;
  int l = 0;
  for (int i = 0; i < n; ++i) {
    bal += a[i] >= best.first && a[i] <= best.second ? 1 : -1;
    if (bal > 0 && k > 1) {
      --k;
      cout << l + 1 << ' ' << i + 1 << '\n';
      bal = 0;
      l = i + 1;
    }
  }
  assert(bal > 0);
  cout << l + 1 << ' ' << n << '\n';
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