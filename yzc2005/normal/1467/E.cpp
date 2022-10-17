#include <bits/stdc++.h>
#define EB emplace_back
const int N = 2e5 + 5;
int n, a[N], id[N], eid[N], dfn, sum[N], ans;
std::vector<int> g[N], nodes[N], dfns[N];
long long cur;
void dfs(int u, int fa) {
  id[u] = ++dfn;
  for (auto v : g[u]) if (v != fa) dfs(v, u);
  eid[u] = dfn; 
}
int prefix(int u, int x) {return std::upper_bound(dfns[a[u]].begin(), dfns[a[u]].end(), x) - dfns[a[u]].begin();}
int get(int u, int l, int r) {return prefix(u, r) - prefix(u, l - 1);}
void calc() {for (int u = 1; u <= n; ++u) cur += get(u, id[u] + 1, eid[u]);}
void dfs1(int u, int fa) {
  ans += !cur;
  for (auto v : g[u]) if (v != fa) {
    int delta = get(u, id[v], eid[v]) - get(v, 1, id[v] - 1) - get(v, eid[v] + 1, n);
    cur -= delta, dfs1(v, u), cur += delta;
  }
}
void work() {
  for (int i = 0; i < n; ++i) if (!nodes[i].empty()) {
    for (auto u : nodes[i]) dfns[i].EB(id[u]);
    std::sort(dfns[i].begin(), dfns[i].end());
  }
}
int main() {
  std::cin >> n; std::vector<int> p;
  for (int i = 1; i <= n; ++i) std::cin >> a[i], p.EB(a[i]);
  std::sort(p.begin(), p.end()), p.erase(std::unique(p.begin(), p.end()), p.end());
  for (int i = 1; i <= n; ++i) a[i] = std::lower_bound(p.begin(), p.end(), a[i]) - p.begin(), nodes[a[i]].EB(i);
  for (int i = 1, u, v; i < n; ++i) std::cin >> u >> v, g[u].EB(v), g[v].EB(u);
  dfs(1, 0), work(), calc(), dfs1(1, 0);
  return printf("%d", ans), 0;
}