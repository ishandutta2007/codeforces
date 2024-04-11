#include <bits/stdc++.h>
const int N = 3e5 + 5;
int n, k, rt, u[N], v[N], x[N], y[N], fa[N], in[N], pa[N];
int que[N], l = 1, r, nxt[N], prv[N];
std::vector<int> p, g[N], nodes[N];
int find(int x) {return x == pa[x] ? x : pa[x] = find(pa[x]);}
void unite(int x, int y) {pa[find(x)] = find(y);}
void solve(int id) {
  int st = 0; assert(!nodes[id].empty());
  for (auto u : nodes[id]) 
    if (!prv[u]) st = u;
  if (!st) puts("0"), exit(0);
  for (; st; st = nxt[st]) p.emplace_back(st);
}
void check_again() {
  for (int i = 1; i <= n; ++i) g[i].clear(), in[i] = 0;
  for (int i = 1; i < n; ++i) g[u[i]].emplace_back(v[i]), ++in[v[i]];
  for (int i = 1; i <= k; ++i) g[x[i]].emplace_back(y[i]), ++in[y[i]];
  int l = 1, r = 0;
  for (int i = 1; i <= n; ++i)
    if (!in[i]) que[++r] = i;
  while (l <= r) {
    int u = que[l++];
    for (auto v : g[u])
      if (!--in[v]) que[++r] = v;
  }
  if (r != n) puts("0"), exit(0);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1, j = 0; i <= n; ++i) {
    scanf("%d", &fa[i]);
    if (fa[i] == 0) rt = i;
    else u[++j] = fa[i], v[j] = i;
  }
  std::iota(pa, pa + n + 1, 0);
  for (int i = 1; i <= k; ++i) {
    scanf("%d%d", &x[i], &y[i]);
    if (nxt[x[i]] || prv[y[i]]) return puts("0"), 0;
    nxt[x[i]] = y[i], prv[y[i]] = x[i];
    unite(x[i], y[i]);
  }
  for (int i = 1; i < n; ++i) {
    int x = find(u[i]), y = find(v[i]);
    if (x != y) g[x].emplace_back(y), ++in[y];
  }
  for (int i = 1; i <= n; ++i) 
    nodes[find(i)].emplace_back(i);
  for (int i = 1; i <= n; ++i) 
    if (!in[i]) que[++r] = i;
  std::vector<int> ord;
  while (l <= r) {
    int u = que[l++];
    if (u == pa[u]) ord.emplace_back(u);
    for (auto v : g[u]) 
      if (!--in[v]) que[++r] = v;
  }
  if (r != n) return puts("0"), 0;
  for (auto i : ord) solve(i);
  check_again();
  for (auto i : p) printf("%d ", i);
  return 0;
}