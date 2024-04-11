#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n, m, dgr[N], dep[N];
vector<int> g[N];

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) 
    dgr[i] = dep[i] = 0, g[i].clear();
  for (int i = 1; i <= m; ++i) {
    int u, v; cin >> u >> v;
    g[u].emplace_back(v), ++dgr[v];
  }
  queue<int> que;
  for (int i = 1; i <= n; ++i)
    if (!dgr[i]) que.push(i);
  vector<int> p;
  while (!que.empty()) {
    int u = que.front(); que.pop();
    if (dep[u] == 2) 
      p.emplace_back(u);
    for (auto v : g[u]) {
      if (dep[u] != 2)
        dep[v] = max(dep[v], dep[u] + 1);
      if (!--dgr[v]) que.push(v);
    }
  }
  cout << p.size() << endl;
  for (auto u : p) cout << u << " ";
  cout << "\n";
}

int main() {
  int tt; cin >> tt;
  while (tt--) solve();
  return 0;
}