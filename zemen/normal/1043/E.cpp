#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 300300;
vector<int> g[maxn];
int x[maxn];
int y[maxn];

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  ll sx = 0;
  struct E {
    int x, y, id;

    bool operator<(const E& e) const {
      return y - x < e.y - e.x;
    }
  };
  vector<E> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
    sx += x[i];
    a[i] = {x[i], y[i], i};
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  sort(a.begin(), a.end());

  vector<ll> ans(n);
  for (int i = 0; i < n; ++i) {
    auto&& e = a[i];
    sx -= e.x;

    ans[e.id] = sx + ll(n - i - 1) * e.y + ll(i) * e.x;
    for (auto v : g[e.id]) {
      ans[e.id] -= min(e.x + y[v], e.y + x[v]);
    }

    sx += e.y;
  }
  for (auto x : ans) {
    cout << x << ' ';
  }
  cout << '\n';
}