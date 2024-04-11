#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct Edge {
  int u, v, w;
  
  bool operator<(const Edge& e) const {
    return w > e.w;
  }
};

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

signed main() {
#ifdef LOCAL
  assert(freopen("f.in", "r", stdin));
#endif
  int n, m;
  scanf("%d%d", &n, &m);
  vector<Edge> es;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    --u, --v;
    es.push_back(Edge{u, v, w});
  }
  sort(es.begin(), es.end());
  DSU dsu(n + 1);
  ll res = 0;
  for (auto e : es) {
    int c1 = dsu.get(e.u);
    int c2 = dsu.get(e.v);
    int badc = dsu.get(n);
    if (c1 == badc && c2 == badc)
      continue;
    res += e.w;
    if (c1 == c2) {
      dsu.join(c1, badc);
    } else {
      dsu.join(c1, c2);
    }
  }
  cout << res << '\n';
}