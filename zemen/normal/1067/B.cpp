#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 100100;
const int inf = 1e9;
vector<int> g[maxn];
vector<int> from;
vector<int> d;
int n;

int bfs(int u) {
  d.assign(n, inf);
  from.assign(n, -1);
  d[u] = 0;
  queue<int> o;
  o.push(u);
  while (!o.empty()) {
    u = o.front();
    o.pop();
    for (int v : g[u]) {
      if (d[v] == inf) {
        d[v] = d[u] + 1;
        from[v] = u;
        o.push(v);
      }
    }
  }
  return u;
}

bool check(int u, int k) {
  if (k == 0) {
    return g[u].empty();
  }
  if ((int) g[u].size() < 3) {
    return false;
  }
  for (int v : g[u]) {
    auto it = find(g[v].begin(), g[v].end(), u);
    assert(it != g[v].end());
    g[v].erase(it);
    if (!check(v, k - 1)) {
      return false;
    }
  }
  return true;
}

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  int k;
  cin >> n >> k;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int u = bfs(0);
  int v = bfs(u);
  if (d[v] != 2 * k) {
    cout << "No\n";
    return 0;
  }
  for (int i = 0; i < k; ++i) {
    v = from[v];
  }
  cout << (check(v, k) ? "Yes" : "No") << '\n';
}