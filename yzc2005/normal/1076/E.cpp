#include <bits/stdc++.h>
const int N = 3e5 + 5;
int n, m, dep[N];
std::vector<int> g[N];
std::vector<std::pair<int, int>> f[N];
long long sum[N], ans[N];
void add(int p, int x) {
  while (p <= n) {
    sum[p] += x;
    p += p & -p;
  }
}
void add(int l, int r, int x) {
  add(l, x);
  add(r + 1, -x);
}
long long query(int p) {
  long long res = 0;
  while (p) {
    res += sum[p];
    p -= p & -p;
  }
  return res;
}
void dfs(int u, int fa) {
  for (auto pr : f[u]) {
    int d = std::min(n, pr.first + dep[u]);
    add(dep[u], d, pr.second);
  }
  ans[u] = query(dep[u]);
  for (auto v : g[u]) {
    if (v != fa) {
      dep[v] = dep[u] + 1;
      dfs(v, u);
    }
  }
  for (auto pr : f[u]) {
    int d = std::min(n, pr.first + dep[u]);
    add(dep[u], d, -pr.second);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    int u, d, x;
    scanf("%d%d%d", &u, &d, &x);
    f[u].emplace_back(d, x);
  }
  dep[1] = 1;
  dfs(1, 0);
  for (int i = 1; i <= n; ++i) {
    printf("%lld ", ans[i]);
  } 
  return 0;
}