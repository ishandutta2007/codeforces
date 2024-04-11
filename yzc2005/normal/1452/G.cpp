#include <bits/stdc++.h>
const int N = 2e5 + 5;
int n, k, a[N], f[N], max[N], id[N], ans[N];
std::vector<int> g[N];
bool banned[N];
void dfs1(int u, int fa) {
  f[u] = 1e9;
  for (auto v : g[u]) {
    if (v != fa) {
      dfs1(v, u);
      f[u] = std::min(f[u], f[v] + 1);
    }
  }
  if (banned[u]) {
    f[u] = 0;
  }
}
void dfs2(int u, int fa) {
  for (auto v : g[u]) {
    if (v != fa) {
      f[v] = std::min(f[v], f[u] + 1);
      dfs2(v, u);
    }
  }
}
void dfs(int u, int dep, int val) {
  if (max[u] >= dep) {
    return;
  }
  max[u] = dep;
  ans[u] = std::max(ans[u], val);
  if (--dep) {
    for (auto v : g[u]) {
      dfs(v, dep, val);
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  scanf("%d", &k);
  for (int i = 1; i <= k; ++i) {
    scanf("%d", &a[i]);
    banned[a[i]] = true;
  } 
  dfs1(1, 0);
  dfs2(1, 0);
  std::iota(id + 1, id + n + 1, 1);
  std::sort(id + 1, id + n + 1, [&](int u, int v) {
    return f[u] > f[v];
  });
  for (int i = 1; i <= n; ++i) {
    int u = id[i];
    dfs(u, f[u], f[u]);
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d ", ans[i]);
  }
  return 0;
}