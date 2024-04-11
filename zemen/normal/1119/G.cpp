#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("g.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  scanf("%d%d", &n, &m);
  set<pair<int, int>, greater<pair<int, int>>> h;
  int H = 0;
  for (int i = 0; i < m; ++i) {
    int x;
    scanf("%d", &x);
    h.emplace(x, i);
    H += x;
  }
  int res = (H + n - 1) / n;
  int delta = res * n - H;
  if (delta > 0) {
    auto p = *h.begin();
    h.erase(h.begin());
    p.first += delta;
    h.insert(p);
  }
  vector<int> a(m);
  vector<vector<int>> atk(m);
  for (int iter = 0; iter < m; ++iter) {
    int L = 0, R = n + 1;
    while (L + 1 < R) {
      int C = (L + R) / 2;
      auto it = h.begin();
      int cur = 0;
      int rem = m;
      while (it != h.end() && cur < res) {
        if (cur + ll(it->first / C) * rem < res) {
          break;
        }
        cur += it->first / C;
        ++it;
        --rem;
      }
      if (cur >= res) {
        L = C;
      } else {
        R = C;
      }
    }
    int c = a[iter] = L;
    auto it = h.begin();
    int cur = 0;
    while (cur < res) {
      auto p = *it;
      it = h.erase(it);
      while (p.first >= c) {
        atk[iter].push_back(p.second);
        p.first -= c;
        if (++cur >= res) {
          break;
        }
      }
      h.insert(p);
    }
  }
  for (auto p : h) {
    assert(p.first == 0);
  }

  cout << res << '\n';
  for (int i = 0; i < m; ++i) {
    cout << a[i] << ' ';
  }
  cout << '\n';
  for (int i = 0; i < res; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << atk[j][i] + 1 << ' ';
    }
    cout << '\n';
  }
}