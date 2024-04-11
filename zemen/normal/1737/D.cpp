#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 1005;
int n;
int d[maxn][maxn];
ll dw[maxn][maxn];

void solve() {
  int m;
  cin >> n >> m;
  const ll infl = 1e18;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      d[i][j] = n;
      dw[i][j] = infl;
    }
    d[i][i] = 0;
  }
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    d[u][v] = 1;
    d[v][u] = 1;
    dw[u][v] = min(dw[u][v], ll(w));
    dw[v][u] = min(dw[v][u], ll(w));
  }
  for (int k = 0; k < n; ++k) {
    for (int u = 0; u < n; ++u) {
      for (int v = 0; v < n; ++v) {
        d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
      }
    }
  }

  ll best = 1e18;
  for (int u = 0; u < n; ++u) {
    for (int v = 0; v < n; ++v) {
      if (u == v || dw[u][v] == infl) {
        continue;
      }
      best = min(best, (d[0][u] + d[n - 1][v] + 1) * dw[u][v]);
      for (int k = 0; k < n; ++k) {
        best = min(best, (d[u][k] + d[0][k] + d[n - 1][k] + 2) * dw[u][v]);
      }
    }
  }
  cout << best << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}