#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 100100;
vector<int> g[maxn];
vector<int> res;

void dfs(int u, int s = 1, int prev = -1) {
  res[u] = (int) g[u].size() * s;
  for (int v : g[u]) {
    if (v != prev) {
      dfs(v, -s, u);
    }
  }
}

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int ii = 0; ii < tn; ++ii) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      g[i].clear();
    }
    res.assign(n, 0);
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfs(0);
    for (int i = 0; i < n; ++i) {
      cout << res[i] << ' ';
    }
    cout << '\n';
  }
}