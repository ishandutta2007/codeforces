#include <bits/stdc++.h>
typedef long long ll;
inline void up(int &x, int y) {x < y ? x = y : 0;}
const int N = 2e5 + 5, K = 18; 
int n, nn, dep[N], p[K][N], *fa = *p;
std::vector<int> g[N];
ll ans; 
void dfs(int u) {
  for (auto v : g[u]) {
    if (v == fa[u]) continue;
    fa[v] = u, dep[v] = dep[u] + 1;
    for (int k = 1; k < K; ++k) p[k][v] = p[k - 1][p[k - 1][v]];
    dfs(v);
  }
}
inline int jump(int u, int d) {
  for (; d; d &= d - 1) u = p[__builtin_ctz(d)][u];
  return u;
}
inline int LCA(int u, int v) {
  if (dep[u] < dep[v]) std::swap(u, v);
  u = jump(u, dep[u] - dep[v]);
  if (u == v) return u;
  for (int k = K - 1; ~k; --k) if (p[k][u] != p[k][v])
    u = p[k][u], v = p[k][v];
  return fa[u];
}
inline int dist(int u, int v) {return dep[u] + dep[v] - (dep[LCA(u, v)] << 1);}
inline int fly(int u, int v, int d) {
  int w = LCA(u, v), dist = dep[u] - dep[w];
  if (dist >= d) return jump(u, d);
  else return jump(v, dep[v] - dep[w] - (d - dist));
}
namespace cut {
  struct info {int rt, bel, d;};
  std::vector<info> p[N];
  int mx[N], sz[N], S, rt, cur;
  ll s1[N], s2[N], s3[N], s4[N];
  bool vis[N];
  void get(int u, int fa) {
    mx[u] = 0, sz[u] = 1;
    for (auto v : g[u]) if (v != fa && !vis[v])
      get(v, u), sz[u] += sz[v], up(mx[u], sz[v]);
    up(mx[u], S - sz[u]);
    if (mx[u] < mx[rt]) rt = u;
  }
  void dfs(int u, int fa, int d) {
    p[u].push_back({rt, cur, d++});
    for (auto v : g[u]) if (!vis[v] && v != fa) dfs(v, u, d);
  }
  void solve(int u) {
    vis[rt = u] = 1, p[u].push_back((info) {u, 0, 0});
    for (auto v : g[u]) if (!vis[v]) ++cur, dfs(v, u, 1);
    for (auto v : g[u]) if (!vis[v]) S = sz[v], rt = 0, get(v, 0), solve(rt);
  }
  inline void modify(int u, int coef) {
    for (auto x : p[u]) 
      s1[x.rt] += x.d * coef, s3[x.rt] += coef, 
      s2[x.bel] += x.d * coef, s4[x.bel] += coef;
  }
  inline ll query(int u) {
    ll ans = 0;
    for (auto x : p[u]) 
      ans += s1[x.rt] - s2[x.bel], 
      ans += (s3[x.rt] - s4[x.bel]) * x.d;
    return ans;
  }
  inline void init() {mx[0] = 1 << 30, S = nn, get(1, 0), solve(rt);}
}
struct C {
  int u, r;
  C(int center = 0, int radius = 0) : u(center), r(radius) {}
  inline friend C operator & (C C1, C C2) {
    if (C1.r < C2.r) std::swap(C1, C2);
    int dis = dist(C1.u, C2.u);
    if (dis <= C1.r - C2.r) return C1;
    else {
      int nr = (dis + C1.r + C2.r) >> 1;
      return C(fly(C1.u, C2.u, nr - C1.r), nr);
    }
  }
  inline friend int test(C C1, C C2) {
    int coef = C1.r < C2.r ? (std::swap(C1, C2), -1) : 1;
    return (dist(C1.u, C2.u) <= C1.r - C2.r) ? coef : 0;
  }
} c[N];
ll suf[N];
void solve(int l, int r) {
  if (l == r) return;
  int mid = l + r >> 1; solve(l, mid), solve(mid + 1, r);
  c[mid + 1] = C(mid + 1, 0), c[mid] = C(mid, 0);
  for (int i = mid + 1; i < r; ++i) c[i + 1] = c[i] & C(i + 1, 0);
  suf[r + 1] = 0; for (int i = r; i > mid; --i) suf[i] = suf[i + 1] + c[i].r;
  int p1 = mid + 1, p2 = mid + 1;
  for (int i = mid; i >= l; --i) {
    while (p2 <= r && ~test(c[i], c[p2])) cut::modify(c[p2++].u, 1);
    while (p1 < p2 && test(c[i], c[p1]) == 1) cut::modify(c[p1++].u, -1);
    ans += 2ll * c[i].r * (p1 - mid - 1) + 1ll * c[i].r * (p2 - p1) + suf[p1] + suf[p2] + cut::query(c[i].u); 
    if (i > l) c[i - 1] = c[i] & C(i - 1, 0);
  } 
  while (p1 < p2) cut::modify(c[p1++].u, -1);
}
int main() {
  scanf("%d", &n), nn = n;
  for (int i = 1, u, v, w; i < n; ++i) {
    scanf("%d%d", &u, &v), w = ++nn;
    g[u].push_back(w), g[w].push_back(u);
    g[v].push_back(w), g[w].push_back(v);
  }
  dfs(1), cut::init(), solve(1, n);
  printf("%lld\n", ans >> 1);
  return 0;
}