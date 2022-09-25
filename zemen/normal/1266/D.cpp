#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  int n, m;
  cin >> n >> m;
  vector<pair<ll, int>> bal(n);
  for (int i = 0; i < n; ++i) {
    bal[i].second = i;
  }
  for (int i = 0; i < m; ++i) {
    int u, v, d;
    cin >> u >> v >> d;
    --u, --v;
    bal[u].first += d;
    bal[v].first -= d;
  }
  sort(bal.begin(), bal.end());
  struct E {
    int u, v;
    ll d;
  };
  vector<E> es;
  int l = 0, r = n - 1;
  while (true) {
    while (l < r && bal[l].first >= 0) {
      ++l;
    }
    while (l < r && bal[r].first <= 0) {
      --r;
    }
    if (l >= r) {
      break;
    }
    ll delta = min(-bal[l].first, bal[r].first);
    es.push_back(E{bal[r].second, bal[l].second, delta});
    bal[l].first += delta;
    bal[r].first -= delta;
  }
  cout << es.size() << '\n';
  for (auto e : es) {
    cout << e.u + 1 << ' ' << e.v + 1 << ' ' << e.d << '\n';
  }
}