#include <bits/stdc++.h>
using i64 = long long;
const int N = 300005;
int n, m, x, fa[N], p[N], to[N * 2];
i64 a[N];
std::set<int> g[N];
int get(int x) {
  if (x == fa[x]) return x;
  return fa[x] = get(fa[x]);
}
int main() {
  scanf("%d%d%d", &n, &m, &x);
  for (int i = 1; i <= n; ++i) fa[i] = i, scanf("%lld", &a[i]);
  for (int i = 1, u, v; i <= m; ++i) {
    scanf("%d%d", &u, &v);
    to[i * 2] = v, to[i * 2 + 1] = u;
    g[u].emplace(i * 2), g[v].emplace(i * 2 + 1);
  }
  std::priority_queue<std::pair<long long, int>> nodes;
  for (int i = 1; i <= n; ++i) nodes.emplace(a[i], i); 
  for (int t = 1; t < n; ++t) {
    auto p = nodes.top(); nodes.pop();
    int u = p.second;
    if (get(u) != u || p.first != a[u]) {--t; continue;}
    assert(!g[u].empty());
    int v = *g[u].begin();
    while (get(to[v]) == u) 
      g[u].erase(v), v = *g[u].begin();
    ::p[t] = v / 2, v = get(to[v]);
    fa[v] = u, a[u] += a[v] - x;
    if (a[u] < 0) return puts("NO"), 0;
    if (g[u].size() < g[v].size()) std::swap(g[u], g[v]);
    for (auto x : g[v]) g[u].emplace(x);
    nodes.emplace(a[u], u);
  }
  puts("YES");
  for (int i = 1; i < n; ++i) printf("%d\n", p[i]);
  return 0;
}