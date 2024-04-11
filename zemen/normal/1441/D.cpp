#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 200200;
vector<int> col;
vector<int> g[maxn];
int d[maxn][2];
int ans;

void dfs(int u, int prev = -1) {
  d[u][0] = d[u][1] = 0;
  if (col[u] >= 0) {
    d[u][col[u]] = 1;
  }
  for (int v : g[u]) {
    if (v == prev) {
      continue;
    }
    dfs(v, u);
    ans = max(ans, d[u][0] + d[v][1]);
    ans = max(ans, d[u][1] + d[v][0]);
    for (int i = 0; i < 2; ++i) {
      d[u][i] = max(d[u][i], d[v][i]);
    }
    if (col[u] >= 0) {
      d[u][col[u]] = max(d[u][col[u]], d[v][col[u] ^ 1] + 1);
    }
  }
}

void solve() {
  int n;
  cin >> n;
  col.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> col[i];
    --col[i];
    g[i].clear();
  }
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  ans = 0;
  dfs(0);
  ans = ans / 2 + 1;
  cout << ans << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}