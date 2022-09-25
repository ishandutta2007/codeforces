#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 3005;
vector<int> g[maxn];
int up[maxn][maxn];
int cnt[maxn][maxn];
ll d[maxn][maxn];

void dfs(int u, int st, int pr = -1) {
  up[st][u] = pr;
  cnt[st][u] = 1;
  for (int v : g[u]) {
    if (v == pr) {
      continue;
    }
    dfs(v, st, u);
    cnt[st][u] += cnt[st][v];
  }
}

ll calc(int u, int v) {
  auto& res = d[u][v];
  if (res != -1) {
    return res;
  }
  res = 0;
  for (int it = 0; it < 2; ++it) {
    for (int w : g[u]) {
      if (u != v && w == up[v][u]) {
        continue;
      }
      res = max(res, calc(w, v) + cnt[v][w] * cnt[w][v]);
    }
    swap(u, v);
  }
  return res;
}

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int u = 0; u < n; ++u) {
    dfs(u, u);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      d[i][j] = -1;
    }
  }
  ll res = 0;
  for (int u = 0; u < n; ++u) {
    res = max(res, calc(u, u));
  }
  cout << res << '\n';
}