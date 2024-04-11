#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int N = 100;
bitset<N> d[N][N];

using Graph = vector<vector<int>>;

void dfs(const Graph& g, vector<int>& dist, int u, int prev = -1, int d = 0) {
  dist[u] = d;
  for (int v : g[u]) {
    if (v != prev) {
      dfs(g, dist, v, u, d + 1);
    }
  }
}

bool check(const Graph& g) {
  int n = (int) g.size();
  vector<vector<int>> dist(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    dfs(g, dist[i], i);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        bool real = dist[i][k] == dist[j][k];
        if (real != bool(d[i][j][k])) {
          return false;
        }
      }
    }
  }
  return true;
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      string s;
      cin >> s;
      for (int k = 0; k < n; ++k) {
        d[i][j][k] = d[j][i][k] = s[k] == '1';
      }
    }
  }
  vector<int> ord;
  bitset<N> alive;
  for (int i = 0; i < n; ++i) {
    alive[i] = true;
  }
  int alive_count = n;
  while (alive_count > 0) {
    bitset<N> nonleaf;
    for (int v1 = 0; v1 < n; ++v1) {
      for (int v2 = 0; v2 < v1; ++v2) {
        if (!alive[v1] || !alive[v2]) {
          continue;
        }
        bitset<N> mask = alive & d[v1][v2];
        mask[v1] = mask[v2] = false;
        for (int x = 0; x < n; ++x) {
          if (!mask[x] || !d[v1][x][v2]) {
            continue;
          }
          mask &= d[v1][x];
          mask[x] = false;
        }
        if (mask.count() == 1) {
          int u = mask._Find_first();
          nonleaf[u] = true;
        }
      }
    }
    bool nice = false;
    for (int u = 0; u < n; ++u) {
      if (!nonleaf[u] && alive[u]) {
        nice = true;
        alive[u] = false;
        --alive_count;
        ord.push_back(u);
      }
    }
    if (!nice) {
      cout << "No\n";
      return;
    }
  }
  reverse(ord.begin(), ord.end());
  vector<pair<int, int>> es;
  es.emplace_back(ord[0], ord[1]);
  for (int ii = 2; ii < n; ++ii) {
    int u = ord[ii];
    bool added = false;
    for (auto e : es) {
      if (d[u][e.first][e.second]) {
        es.emplace_back(e.second, u);
        added = true;
        break;
      }
      if (d[u][e.second][e.first]) {
        es.emplace_back(e.first, u);
        added = true;
        break;
      }
    }
    if (!added) {
      cout << "No\n";
      return;
    }
  }
  vector<vector<int>> g(n);
  for (auto e : es) {
    g[e.first].push_back(e.second);
    g[e.second].push_back(e.first);
  }
  if (!check(g)) {
    cout << "No\n";
    return;
  }
  cout << "Yes\n";
  for (auto [u, v] : es) {
    cout << u + 1 << ' ' << v + 1 << '\n';
  }
}

signed main() {
#ifdef LOCAL
  assert(freopen("f.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}