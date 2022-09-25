#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 100100;
vector<int> g[maxn];
int deg[maxn];

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if (u > v) {
      swap(u, v);
    }
    g[u].push_back(v);
    ++deg[u];
    ++deg[v];
  }
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    g[i].reserve(deg[i]);
    res += ll(g[i].size()) * (deg[i] - (int) g[i].size());
  }
  cout << res << '\n';
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int u;
    cin >> u;
    --u;
    res -= ll(g[u].size()) * (deg[u] - (int) g[u].size());
    for (int v : g[u]) {
      res += deg[v] - 2 * (int) g[v].size() - 1;
      g[v].push_back(u);
    }
    g[u].clear();
    cout << res << '\n';
  }
}