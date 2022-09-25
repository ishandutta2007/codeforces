#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 10010;
vector<pair<int, int>> a[maxn];
int d[maxn];
bool res[maxn];

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < q; ++i) {
    int l, r, x;
    cin >> l >> r >> x;
    --l;
    a[l].emplace_back(r, x);
  }
  d[0] = n;
  for (int l = 0; l < n; ++l) {
    for (auto p : a[l]) {
      int r = p.first, x = p.second;
      for (int j = n - x; j >= 0; --j) {
        d[j + x] = max(d[j + x], min(d[j], r));
      }
    }
    for (int i = 0; i <= n; ++i) {
      res[i] |= d[i] > l;
    }
  }
  vector<int> ans;
  for (int i = 1; i <= n; ++i) {
    if (res[i]) {
      ans.push_back(i);
    }
  }
  cout << (int) ans.size() << '\n';
  for (int x : ans) {
    cout << x << ' ';
  }
  cout << '\n';
}