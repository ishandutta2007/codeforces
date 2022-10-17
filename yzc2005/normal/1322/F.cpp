#include <bits/stdc++.h>

#define id1(x) (((x) << 1))
#define id2(x) (((x) << 1) | 1)
#define rev(x) ((x) ^ 1)

const int N = 5e5 + 5, M = N * 2, LN = 20;

int n, m, p[LN][N], *fa = *p;
int o[N], id[N], eid[N], dep[N], cnt;
int cov[N], tag[N], bel[M];
std::vector<int> g[N];

inline void up(int &x, int y) {if (x < y) x = y;}
inline void down(int &x, int y) {if (x > y) x = y;}

void dfs(int u) {
  o[++cnt] = u, id[u] = cnt;
  for (int i = 0; p[i][u]; ++i) p[i + 1][u] = p[i][p[i][u]];
  for (auto v : g[u]) if (v != fa[u]) p[0][v] = u, dep[v] = dep[u] + 1, dfs(v);
  eid[u] = cnt;
}
int jump(int u, int d) {
  for (int s = dep[u] - d; s; s &= s - 1)
    u = p[__builtin_ctz(s)][u];
  return u;
}

namespace dsu {
  int p[M];
  
  inline int get(int x) {return x == p[x] ? x : p[x] = get(p[x]);}
  inline void merge(int x, int y) {if ((x = get(x)) != (y = get(y))) p[x] = y;}
  inline void equiv(int x, int y) {merge(x, y), merge(rev(x), rev(y));}
  inline void init(int n) {std::iota(p, p + n + 1, 0);}
}

namespace dp {
  int f[N], stamp[N], li[N];
  int l[N], r[N];
  bool rev[N], con[N];
  
  inline bool main(int k) {
    memset(stamp + 1, 0, n * 4);
    for (int _ = n; _; --_) {
      int u = o[_]; int top = 0, l0 = 1, r0 = k;
      for (auto v : g[u]) {
        if (v == fa[u] || !cov[v]) continue;
        int B = bel[id1(v)], idB = B >> 1;
        if (stamp[idB] != _) stamp[idB] = _, l[idB] = 1, r[idB] = k, li[top++] = idB;
        B & 1 ? up(l[idB], f[v] + 1) : down(r[idB], k - f[v]);
      }  
      int S = bel[id1(u)], idS = S >> 1, L = 1, sym = k + 1 >> 1, R = sym;
      for (int i = 0; i < top; ++i) {
        int id = li[i]; con[id] = 0;
        if (l[id] > r[id]) return false;
        if (idS == id) {
          S & 1 ? (up(l0, l[id]), down(r0, r[id])) : (up(l0, k + 1 - r[id]), down(r0, k + 1 - l[id]));
        } else {
          if (l[id] > sym) std::swap(l[id], r[id]), con[id] = 1, l[id] = k + 1 - l[id], r[id] = k + 1 - r[id];
          if (r[id] >= sym) up(l0, std::min(l[id], k + 1 - r[id])), down(r0, std::max(r[id], k + 1 - l[id]));
          else up(L, l[id]), down(R, r[id]);
        }
      }
      if (l0 > r0 || L > R || r0 < L || l0 > k + 1 - L) return false;
      if (l0 <= R) f[u] = std::max(l0, L);
      else if (r0 < k + 1 - R) return false;
      else f[u] = std::max(l0, k + 1 - R);
      for (int i = 0, id; i < top; ++i)
        id = li[i], con[id] ^= (l[id] <= f[u] && f[u] <= r[id]); 
      for (auto v : g[u]) {
        if (v == fa[u]) continue;
        int B = bel[id1(v)], idB = B >> 1;
        rev[v] = (B ^ (idB == idS ? S : con[idB])) & 1;
      }
    }
    return true;
  }
  
  inline void calc(int k) {
    printf("%d\n", k);
    for (int i = 1; i <= n; ++i) {
      int u = o[i]; rev[u] ^= rev[fa[u]];
      if (rev[u]) f[u] = k + 1 - f[u];
    }
    for (int i = 1; i <= n; ++i) printf("%d ", f[i]);
  }
}

int main() {
  scanf("%d%d", &n, &m), dsu::init(id2(n));
  for (int i = 1, u, v; i < n; ++i) scanf("%d%d", &u, &v), g[u].push_back(v), g[v].push_back(u);
  for (dfs(1); m; --m) {
    int a, b; scanf("%d%d", &a, &b);
    if (id[a] > id[b]) std::swap(a, b);
    if (id[b] <= eid[a]) {
      ++cov[b], --cov[a], ++tag[b], --tag[jump(b, dep[a] + 1)];
    } else {
      if (dep[a] > dep[b]) std::swap(a, b);
      int u = a, v = jump(b, dep[a]);
      for (int i = LN - 1; ~i; --i)
        if (p[i][u] != p[i][v]) u = p[i][u], v = p[i][v];
      ++cov[a], ++cov[b], --cov[fa[u]], --cov[fa[v]];
      ++tag[a], ++tag[b], --tag[u], --tag[v], dsu::equiv(id1(u), id2(v)); 
    }
  }
  for (int i = n; i; --i) {
    int u = o[i]; cov[fa[u]] += cov[u], tag[fa[u]] += tag[u];
    if (tag[u]) dsu::equiv(id1(u), id1(fa[u]));
  }
  for (int i = 1; i <= n; ++i) if ((bel[id1(i)] = dsu::get(id1(i))) == (bel[id2(i)] = dsu::get(id2(i)))) return puts("-1"), 0;
  int l = 1, r = n * 2, ans;
  while (l <= r) {
    int mid = l + r >> 1;
    if (dp::main(mid)) ans = mid, r = mid - 1;
    else l = mid + 1;
  }
  dp::main(ans), dp::calc(ans);
  return 0;
}