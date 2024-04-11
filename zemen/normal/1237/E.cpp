#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  int n;
  cin >> n;
  if (n < 3) {
    cout << 1 << '\n';
    return 0;
  }
  vector<int> v{-1, 0};
  while ((int) v.size() * 2 - 1 <= n) {
    int m = (int) v.size();
    for (int i = 0; i < m; ++i) {
      v.push_back(v[i]);
    }
    int s = 0;
    for (int i = m / 2; i < m - 1; ++i) {
      s += v[i];
    }
    s += m / 2 - 1;
    assert(v[m - 1] == 0);
    v[m - 1] = s % 2;

    s = 0;
    for (int i = m + 1; i < m + m / 2; ++i) {
      s += v[i];
    }
    s += m / 2 - 1;
    v[m] = (s + 1) % 2;
  }
  int s = 0;
  for (int i = 1; i < (int) v.size(); ++i) {
    s += v[i];
  }
  int r = n - ((int) v.size() - 1);
  cout << (r == s || r == s + 1) << '\n';
}