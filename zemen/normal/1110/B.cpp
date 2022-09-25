#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  int res = n;
  vector<int> d;
  for (int i = 0; i < n - 1; ++i) {
    d.push_back(b[i + 1] - b[i] - 1);
  }
  sort(d.begin(), d.end());
  for (int i = 0; i < n - k; ++i) {
    res += d[i];
  }
  cout << res << '\n';
}