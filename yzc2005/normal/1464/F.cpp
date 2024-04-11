#include <bits/stdc++.h>
#define EB emplace_back
typedef std::pair<int, int> pr;
const int N = 2e5 + 5, K = 18;
int n, q, o[N], id[N], eid[N], dfn, p[K][N], *fa = *p, dep[N], cnt[N];
std::vector<int> g[N];
int ID[N], lg[N << 1], tot, st[K + 1][N << 1];
void dfs(int u) {
  o[id[u] = ++dfn] = u, st[0][ID[u] = ++tot] = u;
  for (auto v : g[u]) if (v != fa[u]) {
    fa[v] = u, dep[v] = dep[u] + 1;
    for (int k = 1; k < K; ++k) p[k][v] = p[k - 1][p[k - 1][v]];
    dfs(v), st[0][++tot] = u;
  }
  eid[u] = dfn;
}  
inline int comp(int x, int y) {return dep[x] > dep[y] ? y : x;}
inline void build(int n) {
  for (int i = 2; i <= n; ++i) lg[i] = lg[i >> 1] + 1;
  for (int k = 1; k <= K; ++k)
    for (int i = 1; i <= n - (1 << k) + 1; ++i) 
      st[k][i] = comp(st[k - 1][i], st[k - 1][i + (1 << k - 1)]);
}
inline int LCA(int u, int v) {
  if (id[u] > id[v]) std::swap(u, v);
  u = ID[u], v = ID[v]; int t = lg[v - u + 1];
  return comp(st[t][u], st[t][v - (1 << t) + 1]);
}
inline int dist(int u, int v) {return (u && v) ? dep[u] + dep[v] - 2 * dep[LCA(u, v)] : -1;}
inline int jump(int u, int d) {
  if (dep[u] <= d) return 1;
  for (; d; d &= d - 1) u = p[__builtin_ctz(d)][u];
  return u;
}
struct BIT {
  int sum[N];
  inline void add(int x, int y) {for (; x <= n; x += x & -x) sum[x] += y;}
  inline int query(int x) {int res = 0; for (; x; x -= x & -x) res += sum[x]; return res;}
  inline int query(int l, int r) {return query(r) - query(l - 1);}
} tr;
struct D {
  int x, y, z;
  D(int _x = 0, int _y = 0) {x = _x, y = _y, z = dist(x, y);}
  inline friend bool operator < (const D &A, const D &B) {return A.z < B.z;}
  inline friend D operator & (const D &A, const D &B) {return std::max({A, B, D(A.x, B.x), D(A.x, B.y), D(A.y, B.x), D(A.y, B.y)});}
} diam[N << 2];
void modify(int p, int l, int r, int pos, bool tp) {
  if (l == r) return void(diam[p] = D(tp * o[pos], tp * o[pos]));
  int mid = l + r >> 1; mid >= pos ? modify(p << 1, l, mid, pos, tp) : modify(p << 1 | 1, mid + 1, r, pos, tp);
  diam[p] = diam[p << 1] & diam[p << 1 | 1];
}
D query(int p, int l, int r, int L, int R) {
  if (l >= L && r <= R) return diam[p];
  int mid = l + r >> 1;
  if (mid >= L && mid < R) return query(p << 1, l, mid, L, R) & query(p << 1 | 1, mid + 1, r, L, R);
  if (mid >= L) return query(p << 1, l, mid, L, R);
  return query(p << 1 | 1, mid + 1, r, L, R);
}
std::set<pr> S;
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1, u, v; i < n; ++i) scanf("%d%d", &u, &v), g[u].EB(v), g[v].EB(u);
  dfs(1), build(tot);
  for (int i = 1, op, x, y, c = 0; i <= q; ++i) {
    scanf("%d%d", &op, &x);
    if (op == 3) {
      int v = jump(S.rbegin()->second, x), v1 = jump(v, x);
      if (tr.query(id[v1], eid[v1]) != c) {puts("No"); continue;}
      D tmp = query(1, 1, n, id[v1], eid[v1]);
      puts(std::max(dist(tmp.x, v), dist(tmp.y, v)) > x ? "No" : "Yes"); 
    } else {
      scanf("%d", &y); int z = LCA(x, y);
      if (op == 1) {
        ++c; if (!cnt[z]++) S.insert({dep[z], z}), modify(1, 1, n, id[z], 1);
        tr.add(id[x], 1), tr.add(id[y], 1), tr.add(id[z], -1);
      } else {
        --c; if (!--cnt[z]) S.erase({dep[z], z}), modify(1, 1, n, id[z], 0);
        tr.add(id[x], -1), tr.add(id[y], -1), tr.add(id[z], 1);
      }
    }
  }
  return 0;
}