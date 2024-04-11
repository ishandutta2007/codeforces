#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 1 << 20;
vector<pair<int, int>> g[maxn];
vector<int> ptr;
vector<char> used;
vector<int> path;
bool fail;

void dfs(int u) {
  if (g[u].size() % 2 != 0) {
    fail = true;
  }
  while (ptr[u] < (int) g[u].size()) {
    auto p = g[u][ptr[u]++];
    int v = p.first;
    int id = p.second;
    if (used[id]) {
      continue;
    }
    used[id] = used[id ^ 1] = true;
    dfs(v);
    path.push_back(id ^ 1);
    path.push_back(id);
  }
}

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<pair<int, int>> es;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    es.emplace_back(a, b);
  }
  int L = -1, R = 21;
  vector<int> best_path;
  while (L + 1 < R) {
    int C = (L + R) / 2;
    int mod = 1 << C;
    for (int i = 0; i < mod; ++i) {
      g[i].clear();
    }
    used.assign(2 * n, 0);
    ptr.assign(1 << C, 0);
    path.clear();
    fail = false;
    for (int i = 0; i < n; ++i) {
      g[es[i].first % mod].emplace_back(es[i].second % mod, 2 * i);
      g[es[i].second % mod].emplace_back(es[i].first % mod, 2 * i + 1);
    }
    dfs(es[0].first % mod);
    if ((int) path.size() == 2 * n && !fail) {
      best_path = path;
      L = C;
    } else {
      R = C;
    }
  }
  cout << L << '\n';
  for (auto u : best_path) {
    cout << u + 1 << ' ';
  }
  cout << '\n';
}