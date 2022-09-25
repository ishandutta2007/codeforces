#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 100100;
vector<int> g[maxn];
set<int> unused;

void dfs(int u) {
  unused.erase(u);
  auto ptr = g[u].begin();
  int v = 0;
  while (true) {
    auto it = unused.lower_bound(v);
    if (it == unused.end()) {
      break;
    }
    v = *it;
    while (ptr != g[u].end() && *ptr < v) {
      ++ptr;
    }
    if (ptr != g[u].end() && *ptr == v) {
      ++v;
      continue;
    }
    dfs(v);
  }
}

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < n; ++i) {
    sort(g[i].begin(), g[i].end());
    unused.insert(i);
  }
  int res = -1;
  for (int i = 0; i < n; ++i) {
    if (unused.count(i)) {
      dfs(i);
      ++res;
    }
  }
  cout << res << '\n';
}