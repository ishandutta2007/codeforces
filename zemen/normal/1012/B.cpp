#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

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
  assert(freopen("b.in", "r", stdin));
#endif
  int n, m, q;
  cin >> n >> m >> q;
  DSU dsu(n + m);
  int c = n + m - 1;
  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    if (dsu.join(x, y + n)) {
      --c;
    }
  }
  cout << c << '\n';
}