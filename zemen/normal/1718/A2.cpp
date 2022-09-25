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
  int tn;
  cin >> tn;
  for (int ii = 0; ii < tn; ++ii) {
    int n;
    cin >> n;
    vector<int> d(n + 1);
    map<int, int> pos;
    pos[0] = 0;
    int x = 0;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      x ^= a;
      d[i + 1] = d[i] + 1;
      if (pos.count(x)) {
        d[i + 1] = min(d[i + 1], d[pos[x]] + i - pos[x]);
      }
      pos[x] = i + 1;
    }
    cout << d[n] << '\n';
  }
}