#pragma GCC optimize("Ofast,no-stack-protector")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 2002000;
vector<pair<int, int>> g[maxn];
vector<char> used;
string res;

void dfs(int u) {
  used[u] = true;
  for (auto [v, id] : g[u]) {
    if (used[v]) {
      continue;
    }
    res[id] = '0';
    dfs(v);
  }
}

struct DSU {
  vector<int> col, rk;

  DSU(int n): col(n), rk(n) {
    iota(col.begin(), col.end(), 0);
  }

  int get(int u) {
    if (u == col[u]) {
      return u;
    }
    return col[u] = get(col[u]);
  }

  bool join(int u, int v) {
    u = get(u), v = get(v);
    if (u == v) {
      return false;
    }
    if (rk[u] > rk[v]) {
      swap(u, v);
    }
    if (rk[u] == rk[v]) {
      ++rk[v];
    }
    col[u] = v;
    return true;
  }
};

int n, m;
vector<pair<int, int>> es;

bool solve(int root) {
  used.assign(n, false);
  res.assign(m, '1');
  dfs(root);
  DSU dsu(n);
  for (int i = 0; i < m; ++i) {
    if (res[i] == '1') {
      if (!dsu.join(es[i].first, es[i].second)) {
        return false;
      }
    }
  }
  dsu = DSU(n);
  for (int i = 0; i < m; ++i) {
    if (res[i] == '0') {
      assert(dsu.join(es[i].first, es[i].second));
    }
  }
  return true;
}

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int ii = 0; ii < tn; ++ii) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      g[i].clear();
    }
    es.clear();
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      es.emplace_back(u, v);
      g[u].emplace_back(v, i);
      g[v].emplace_back(u, i);
    }
    int u = 0;
    for (int i = 0; i < n; ++i) {
      if (g[i].size() < g[u].size()) {
        u = i;
      }
    }
    while (!solve(u)) {
      u = (u + 1) % n;
    }
    cout << res << '\n';
  }
}