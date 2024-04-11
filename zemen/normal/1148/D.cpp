#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  vector<int> up, down;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    if (a[i] < b[i]) {
      up.push_back(i);
    } else {
      down.push_back(i);
    }
  }
  cout << max(up.size(), down.size()) << '\n';
  if (up.size() > down.size()) {
    sort(up.begin(), up.end(), [&a](int i, int j) {
      return a[i] > a[j];
    });
    for (int x : up) {
      cout << x+1 << ' ';
    }
    cout << '\n';
  } else {
    sort(down.begin(), down.end(), [&a](int i, int j) {
      return a[i] < a[j];
    });
    for (int x : down) {
      cout << x+1 << ' ';
    }
    cout << '\n';
  }
}