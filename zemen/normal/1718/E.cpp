#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

vector<vector<int>> g[2];
vector<vector<pair<int, int>>> by_col[2][2];
const int maxs = 200200;
bool used[2][2][maxs];
int max_coord[2];

struct Match {
  int coord, u, v;
};
int mtv[2][maxs];

vector<Match> matches;
bool try_match(int coord, int u, int v) {
  bool used0 = used[0][coord][u];
  bool used1 = used[1][coord][v];
  if (used0 != used1) {
    return false;
  }
  if (used0) {
    return mtv[coord][u] == v;
  }

  auto& g0 = by_col[0][coord][u];
  auto& g1 = by_col[1][coord][v];
  if (g0.size() != g1.size()) {
    return false;
  }
  for (int i = 0; i < (int) g0.size(); ++i) {
    if (g0[i].first != g1[i].first) {
      return false;
    }
  }
  matches.push_back(Match{coord, u, v});
  used[0][coord][u] = true;
  used[1][coord][v] = true;
  mtv[coord][u] = v;
  for (int i = 0; i < (int) g0.size(); ++i) {
    if (!try_match(!coord, g0[i].second, g1[i].second)) {
      return false;
    }
  }
  return true;
}

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  max_coord[0] = n;
  max_coord[1] = m;

  for (int id = 0; id < 2; ++id) {
    g[id].assign(n, vector<int>(m));
    by_col[id][0].resize(n);
    by_col[id][1].resize(m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> g[id][i][j];
        if (g[id][i][j]) {
          by_col[id][0][i].emplace_back(g[id][i][j], j);
          by_col[id][1][j].emplace_back(g[id][i][j], i);
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      sort(by_col[id][0][i].begin(), by_col[id][0][i].end());
    }
    for (int i = 0; i < m; ++i) {
      sort(by_col[id][1][i].begin(), by_col[id][1][i].end());
    }
  }

  int coord = n <= m ? 0 : 1;
  for (int i = 0; i < max_coord[coord]; ++i) {
    if (!used[0][coord][i]) {
      bool ok = false;
      for (int j = 0; j < max_coord[coord]; ++j) {
        if (!used[1][coord][j]) {
          matches.clear();
          if (try_match(coord, i, j)) {
            ok = true;
            break;
          } else {
            for (auto& match : matches) {
              used[0][match.coord][match.u] = false;
              used[1][match.coord][match.v] = false;
            }
          }
        }
      }
      if (!ok) {
        cout << -1 << '\n';
        return 0;
      }
    }
  }
  int j = 0;
  for (int i = 0; i < max_coord[!coord]; ++i) {
    if (!used[0][!coord][i]) {
      while (j < max_coord[!coord] && used[1][!coord][j]) {
        ++j;
      }
      assert(j < max_coord[!coord]);
      used[0][!coord][i] = true;
      used[1][!coord][j] = true;
      mtv[!coord][i] = j;
    }
  }

  struct Op {
    int t, u, v;
  };
  vector<Op> res;
  for (int coord = 0; coord < 2; ++coord) {
    vector<char> used(max_coord[coord]);
    //for (int i = 0; i < max_coord[coord]; ++i) {
      //cerr << mtv[coord][i] << ' ';
    //}
    //cerr << '\n';
    for (int i = 0; i < max_coord[coord]; ++i) {
      int u = i;
      if (used[u] || mtv[coord][u] == u) {
        continue;
      }
      while (!used[u]) {
        used[u] = true;
        u = mtv[coord][u];
        if (u != i) {
          res.push_back(Op{coord, i, u});
        }
      }
    }
  }
  cout << res.size() << '\n';
  for (auto x : res) {
    cout << x.t + 1 << ' ' << x.u + 1 << ' ' << x.v + 1 << '\n';
  }
}