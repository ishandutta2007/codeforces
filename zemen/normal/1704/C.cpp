#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int ii = 0; ii < tn; ++ii) {
    int n, m;
    cin >> n >> m;
    vector<int> pos(m);
    for (int i = 0; i < m; ++i) {
      cin >> pos[i];
    }
    sort(pos.begin(), pos.end());
    vector<int> a;
    for (int i = 0; i < m - 1; ++i) {
      a.push_back(pos[i + 1] - pos[i] - 1);
    }
    a.push_back(n + pos[0] - pos.back() - 1);
    sort(a.rbegin(), a.rend());
    int turns = 0;
    int res = 0;
    for (int x : a) {
      x -= turns * 2;
      if (x <= 0) {
        break;
      }
      ++res;
      ++turns;
      x -= 2;
      if (x > 0) {
        res += x;
        ++turns;
      }
    }
    cout << n - res << '\n';
  }
}