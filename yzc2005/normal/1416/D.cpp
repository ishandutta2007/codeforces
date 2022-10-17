#include <bits/stdc++.h>
inline void read(int &x) {
  x = 0; char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
}
using namespace std;
typedef pair<int, int> pr; 
const int N = 5e5 + 5, K = 19;
int pn, n, m, q, p[N], w[N], dgr[N];
pr op[N];
vector<int> g[N]; 
int dfn, id[N], eid[N], rev[N], pa[K][N], *fa = pa[0];
int par[N];
struct edge {
  int u, v, w;
} e[N];
int get(int x) {return x == par[x] ? x : par[x] = get(par[x]);}
namespace ST {
  int mx[N << 2];
  void build(int p, int l, int r) {
    if (l == r) {
      if (rev[l] <= pn) mx[p] = rev[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
  } 
  void deactivate(int p, int l, int r, int pos) {
    if (l == r) {
      mx[p] = 0;
      return;
    }
    int mid = (l + r) >> 1;
    if (mid >= pos) deactivate(p << 1, l, mid, pos);
    else deactivate(p << 1 | 1, mid + 1, r, pos);
    mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
  }
  int query(int p, int l, int r, int ll, int rr) {
    if (l >= ll && r <= rr) return mx[p];
    int mid = (l + r) >> 1, res = 0;
    if (mid >= ll) res = max(res, query(p << 1, l, mid, ll, rr));
    if (mid < rr) res = max(res, query(p << 1 | 1, mid + 1, r, ll, rr));
    return res;
  }
}
void dfs(int u) {
  id[u] = ++dfn;
  rev[dfn] = u;
  for (auto v : g[u]) {
    for (int k = 1; k < K; ++k) pa[k][v] = pa[k - 1][pa[k - 1][v]];
    dfs(v);
  }
  eid[u] = dfn;
}
inline int query(int u, int x) {
  for (int k = K - 1; ~k; --k)
    if (w[pa[k][u]] >= x) u = pa[k][u];
  return u; 
}
int main() {
  read(n), read(m), read(q), pn = n;
  for (int i = 1; i <= n; ++i) read(p[i]);
  for (int i = 1; i <= m; ++i) {
    int x, y; read(x), read(y);
    e[i].u = p[x], e[i].v = p[y], e[i].w = q + 1; 
  }
  for (int i = 1; i <= q; ++i) {
    read(op[i].first), read(op[i].second);
    if (op[i].first & 1) op[i].second = p[op[i].second];
    else e[op[i].second].w = i;
  }
  sort(e + 1, e + m + 1, [&](edge e1, edge e2) {
    return e1.w > e2.w;
  });
  iota(par + 1, par + n + 1, 1);
  for (int i = 1; i <= m; ++i) {
    int u = get(e[i].u), v = get(e[i].v);
    if (u == v) continue;
    fa[u] = fa[v] = ++n;
    ++dgr[u], ++dgr[v];
    par[v] = par[u] = par[n] = n;
    g[n].emplace_back(u), g[n].emplace_back(v);
    w[n] = e[i].w;
  }
  for (int i = 1; i <= n; ++i) if (!dgr[i]) dfs(i);
  ST::build(1, 1, n);
  for (int i = 1; i <= q; ++i) {
    if (op[i].first & 1) {
      int u = op[i].second;
      u = query(u, i);
      int v = ST::query(1, 1, n, id[u], eid[u]);
      printf("%d\n", v);
      if (v) ST::deactivate(1, 1, n, id[v]);
    }
  }
  return 0;
}