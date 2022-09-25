#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 100100;
vector<int> g[maxn];
int deg[maxn];
bool del[maxn];

bool check(int u) {
  vector<int> to;
  for (int v : g[u]) {
    if (!del[v]) {
      to.push_back(v);
    }
  }
  for (int v : to) {
    auto it = g[v].begin();
    for (int w : to) {
      if (w >= v) {
        break;
      }
      it = lower_bound(it, g[v].end(), w);
      if (it == g[v].end() || *it != w) {
        return false;
      }
    }
  }
  to.push_back(u);
  cout << 2 << '\n';
  for (int u : to) {
    cout << u + 1 << ' ';
  }
  cout << '\n';
  return true;
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    g[i].clear();
    del[i] = false;
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> q;
  for (int i = 0; i < n; ++i) {
    sort(g[i].begin(), g[i].end());
    deg[i] = (int) g[i].size();
    if (deg[i] < k) {
      q.push_back(i);
    }
  }
  for (int ii = 0; ii < (int) q.size(); ++ii) {
    int u = q[ii];
    assert(!del[u]);
    if (deg[u] == k - 1 && ll(k) * (k - 1) / 2 <= m && check(u)) {
      return;
    }
    del[u] = true;
    for (int v : g[u]) {
      if (!del[v] && deg[v]-- == k) {
        q.push_back(v);
      }
    }
  }
  if ((int) q.size() == n) {
    cout << -1 << '\n';
    return;
  }
  cout << 1 << ' ' << n - (int) q.size() << '\n';
  for (int i = 0; i < n; ++i) {
    if (!del[i]) {
      cout << i + 1 << ' ';
    }
  }
  cout << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}