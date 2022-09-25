#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<int> b;
  for (int i = 0; i < m; ++i) {
    int x1, x2, y;
    cin >> x1 >> x2 >> y;
    if (x1 > 1) {
      continue;
    }
    b.push_back(x2);
  }
  sort(b.begin(), b.end());
  m = (int) b.size();

  int res = 1e9;
  int p = 0;
  for (int i = 0; i <= n; ++i) {
    int x = i == n ? 1e9 : a[i];
    while (p < m && b[p] < x) {
      ++p;
    }
    //cerr << i << ' ' << m - p << '\n';
    res = min(res, i + m - p);
  }
  cout << res << '\n';
}