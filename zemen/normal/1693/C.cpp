#pragma GCC optimize("Ofast,no-stack-protector")
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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> rg(n);
  vector<int> deg(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    rg[v].push_back(u);
    ++deg[u];
  }
  const int inf = 1e9;
  vector<int> dist(n, inf), mx(n, -1);
  dist.back() = 0;
  using elem = pair<int, int>;
  priority_queue<elem, vector<elem>, greater<elem>> o;
  o.emplace(0, n - 1);
  while (!o.empty()) {
    auto [cdist, u] = o.top();
    o.pop();
    if (cdist != dist[u]) {
      continue;
    }
    for (int v : rg[u]) {
      mx[v] = max(mx[v], dist[u] + 1);
      --deg[v];
      int ndist = deg[v] + mx[v];
      if (ndist < dist[v]) {
        dist[v] = ndist;
        o.emplace(ndist, v);
      }
    }
  }
  //for (int i = 0; i < n; ++i) {
    //cerr << dist[i] << ' ';
  //}
  //cerr << '\n';
  cout << dist.front() << '\n';
}