#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  int n;
  cin >> n;
  vector<int> a(n);
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    v[i] = {a[i], i};
  }
  sort(v.begin(), v.end());
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    int pos = v[(i + 1) % n].second;
    int val = v[i].first;
    b[pos] = val;
  }
  for (int i = 0; i < n; ++i) {
    cout << b[i] << ' ';
  }
  cout << '\n';
}