#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int maxn = 1000100;
vector<pair<int, int>> g[maxn];
int dist[maxn];
bool used[maxn];
int h[maxn];
int n;

void go(vector<int> m) {
  assert(!m.empty());
  for (int u : m) {
    used[u] = true;
  }
  for (int dig = 0; dig < 10; ++dig) {
    vector<int> to;
    for (int u : m) {
      for (auto p : g[u]) {
        int v = p.first;
        if (used[v] || dist[v] != dist[u] + 1 || p.second != dig) {
          continue;
        }
        h[v] = (ll(h[u]) * 10 + dig) % mod;
        to.push_back(v);
      }
    }
    if (to.empty()) {
      continue;
    }
    sort(to.begin(), to.end());
    to.erase(unique(to.begin(), to.end()), to.end());
    go(to);
  }
}

signed main() {
#ifdef LOCAL
  assert(freopen("f.in", "r", stdin));
#endif
  int m;
  cin >> n >> m;
  int t = n;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if (i + 1 < 10) {
      g[u].emplace_back(v, i + 1);
      g[v].emplace_back(u, i + 1);
    } else {
      int w = i + 1;
      vector<int> e;
      while (w) {
        e.push_back(w % 10);
        w /= 10;
      }
      reverse(e.begin(), e.end());
      int s = u;
      for (int i = 0; i < (int) e.size(); ++i) {
        if (i + 1 == (int) e.size()) {
          g[s].emplace_back(u, e[i]);
          g[s].emplace_back(v, e[i]);
        } else {
          g[s].emplace_back(t, e[i]);
          if (i == 0) {
            g[v].emplace_back(t, e[i]);
          }
          s = t++;
        }
      }
    }
  }

  for (int i = 1; i < t; ++i) {
    dist[i] = 1e9;
  }
  vector<int> o{0};
  for (int ii = 0; ii < (int) o.size(); ++ii) {
    int u = o[ii];
    for (auto p : g[u]) {
      int v = p.first;
      if (dist[v] > dist[u] + 1) {
        dist[v] = dist[u] + 1;
        o.push_back(v);
      }
    }
  }
  go({0});
  for (int i = 1; i < n; ++i) {
    cout << h[i] << '\n';
  }
}