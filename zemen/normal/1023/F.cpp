#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int inf = 1e9 + 7;
const int maxn = 500500;
const int LG = 20;
vector<int> g[maxn];
int p[maxn][LG];
int val[maxn][LG];
int in[maxn];
int out[maxn];
int timer;

void pre(int u, int prev) {
  in[u] = timer++;
  p[u][0] = prev;
  //cerr << "pr " << u+1 << ' ' << prev+1 << '\n';
  val[u][0] = inf;
  for (int i = 0; i < LG - 1; ++i) {
    p[u][i + 1] = p[p[u][i]][i];
    val[u][i + 1] = inf;
  }
  for (int v : g[u]) {
    if (v == prev) {
      continue;
    }
    pre(v, u);
  }
  out[u] = timer;
}

bool is_prev(int u, int v) {
  return in[u] <= in[v] && out[v] <= out[u];
}

void put(int u, int v, int x) {
  //cerr << "put " << u+1 << ' ' << v+1 << ' ' << x << '\n';
  for (int iter = 0; iter < 2; ++iter) {
    for (int d = LG - 1; d >= 0; --d) {
      int w = p[u][d];
      if (!is_prev(w, v)) {
        val[u][d] = min(val[u][d], x);
        u = w;
      }
    }
    if (!is_prev(u, v)) {
      val[u][0] = min(val[u][0], x);
      u = p[u][0];
    }
    //cerr << u+1 << ' ' << v+1 << '\n';
    swap(u, v);
  }
  assert(u == v);
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

signed main() {
#ifdef LOCAL
  assert(freopen("f.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k, m;
  cin >> n >> k >> m;
  DSU dsu(n);

  vector<pair<int, int>> es;
  for (int i = 0; i < k; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
    es.emplace_back(u, v);
    assert(dsu.join(u, v));
  }
  vector<tuple<int, int, int>> qs;
  for (int i = 0; i < m; ++i) {
    int u, v, x;
    cin >> u >> v >> x;
    --u, --v;
    if (dsu.join(u, v)) {
      g[u].push_back(v);
      g[v].push_back(u);
    }
    qs.emplace_back(u, v, x);
  }
  pre(0, 0);

  dsu = DSU(n);
  for (auto e : es) {
    assert(dsu.join(e.first, e.second));
  }
  for (auto q : qs) {
    int u, v, x;
    tie(u, v, x) = q;
    if (!dsu.join(u, v)) {
      put(u, v, x);
    }
  }
  for (int d = LG - 2; d >= 0; --d) {
    for (int u = 0; u < n; ++u) {
      val[u][d] = min(val[u][d], val[u][d + 1]);
      int w = p[u][d];
      val[w][d] = min(val[w][d], val[u][d + 1]);
    }
  }

  ll res = 0;
  for (auto e : es) {
    int u = e.first, v = e.second;
    if (!is_prev(v, u)) {
      swap(u, v);
    }
    if (val[u][0] == inf) {
      cout << -1 << '\n';
      return 0;
    }
    res += val[u][0];
  }
  cout << res << '\n';
}