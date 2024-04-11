#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 300300;
int w[maxn];
vector<pair<int, int>> g[maxn];
ll res = 0;

ll mx1[maxn];
ll w1[maxn];
ll mx2[maxn];

ll dfs1(int u, int prev = -1) {
  mx1[u] = mx2[u] = w[u];
  for (auto [v, c] : g[u]) {
    if (v == prev) {
      continue;
    }
    auto x = dfs1(v, u);
    if (x < c) {
      x = 0;
    } else {
      x += w[u] - c;
    }
    if (x > mx1[u]) {
      mx2[u] = mx1[u];
      mx1[u] = x;
      w1[u] = v;
    } else if (x > mx2[u]) {
      mx2[u] = x;
    }
  }
  res = max(res, mx1[u]);
  //cerr << u << ' ' << mx1[u] << '\n';
  return mx1[u];
}

void dfs2(int u, int prev = -1, ll up = 0) {
  up += w[u];
  res = max(res, up);
  for (auto [v, c] : g[u]) {
    if (v == prev) {
      continue;
    }
    ll nup = up;
    if (v == w1[u]) {
      nup = max(nup, mx2[u]);
    } else {
      nup = max(nup, mx1[u]);
    }
    if (nup < c) {
      nup = 0;
    } else {
      nup -= c;
    }
    dfs2(v, u, nup);
  }
}

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }
  for (int i = 0; i < n - 1; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    --u, --v;
    g[u].emplace_back(v, c);
    g[v].emplace_back(u, c);
  }
  dfs1(0);
  dfs2(0);
  cout << res << '\n';
}