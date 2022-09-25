#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct pt {
  int x, y, i;
};

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  int n;
  cin >> n;
  vector<pt> px(n), py(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    px[i] = py[i] = {x, y, i};
  }
  sort(px.begin(), px.end(), [](const pt& a, const pt& b) {
    return a.x < b.x;
  });
  sort(py.begin(), py.end(), [](const pt& a, const pt& b) {
    return a.y < b.y;
  });
  int xl = px.front().x;
  int xr = px.back().x;
  int yl = py.front().y;
  int yr = py.back().y;
  int f3 = 0, f4 = xr - xl + yr - yl;
  for (auto p : px) {
    f3 = max(f3, p.x - xl + p.y - yl);
    f3 = max(f3, xr - p.x + p.y - yl);
    f3 = max(f3, xr - p.x + yr - p.y);
    f3 = max(f3, p.x - xl + yr - p.y);
  }
  cout << f3 * 2;
  for (int i = 4; i <= n; ++i) {
    cout << ' ' << f4 * 2;
  }
  cout << '\n';
}