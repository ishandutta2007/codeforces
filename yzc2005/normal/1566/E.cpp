#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, f[N], g[N], ans;
vector<int> adj[N];
void dfs1(int u, int fa) {
  bool flag = false;
  f[u] = 0;
  for (auto v : adj[u]) {
    if (v == fa) continue;
    dfs1(v, u);
    f[u] += f[v], flag |= !g[v];
  }
  if (flag) --f[u], g[u] = true;
  else ++f[u], g[u] = false;
}
void dfs2(int u, int fa, int sum) {
  bool is_leaf = true;
  int new_sum = 0;
  for (auto v : adj[u]) 
    if (v != fa) is_leaf = false, new_sum += f[v];
  for (auto v : adj[u])
    if (v != fa) dfs2(v, u, sum + new_sum - f[v]);
  if (is_leaf) ans = min(ans, sum + 1);
}
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) adj[i].clear();
  for (int i = 1; i < n; ++i) {
    int u, v; 
    scanf("%d%d", &u, &v);
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  dfs1(1, 0), ans = 1e9, dfs2(1, 0, 0);
  printf("%d\n", ans);
}
int main() {
  int t; scanf("%d", &t);
  while (t--) solve();
  return 0;
}