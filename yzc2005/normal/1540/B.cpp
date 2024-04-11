#include <bits/stdc++.h>
const int mod = 1e9 + 7, inv2 = mod + 1 >> 1;
inline void add(int &x, const int y) {(x += y) >= mod && (x -= mod);}
inline int Add(int x, const int y) {return add(x, y), x;}
inline void sub(int &x, const int y) {(x -= y) < 0 && (x += mod);}
inline int Sub(int x, const int y) {return sub(x, y), x;}
inline void mul(int &x, const int y) {x = 1ll * x * y % mod;}
inline int Mul(const int x, const int y) {return 1ll * x * y % mod;}
inline int power(int a, int b, int c = 1) {
  for (; b; b >>= 1, mul(a, a))
    if (b & 1) mul(c, a);
  return c;
}
const int N = 205;
int inv[N], fac[N], ifac[N];
inline void init(int n) {
  for (int i = 0; i < 2; ++i) inv[i] = fac[i] = ifac[i] = 1;
  for (int i = 2; i <= n; ++i) {
    inv[i] = Mul(mod - mod / i, inv[mod % i]);
    fac[i] = Mul(fac[i - 1], i);
    ifac[i] = Mul(ifac[i - 1], inv[i]);
  }
}
inline int binom(int n, int m) {
  if (n < 0 || m < 0 || n < m) return 0;
  return Mul(fac[n], Mul(ifac[m], ifac[n - m]));
}

int n, ans, dep[N], fa[N], dfn, l[N], r[N], c[N][N]; 
std::vector<int> g[N];

void dfs(int u) {
  l[u] = ++dfn;
  for (auto v : g[u]) {
    if (v == fa[u]) continue;
    fa[v] = u, dep[v] = dep[u] + 1, dfs(v);
  }
  r[u] = dfn;
}

inline int calc(int n, int m) {
  int res = 0;
  if (!n) return 1;
  for (int i = 0; i < m; ++i) 
    add(res, power(inv2, n + i, binom(n + i - 1, i)));
  return res;
}
void solve(int rt) {
  dfn = dep[rt] = fa[rt] = 0, dfs(rt);
  for (int v = 1; v <= n; ++v)
    for (int u = v + 1; u <= n; ++u) {
      if (l[u] <= l[v] && l[v] <= r[u]) add(ans, 1);
      else if (l[v] <= l[u] && l[u] <= r[v]) continue;
      else {
        int x = u, y = v;
        while (x != y) {
          if (dep[x] < dep[y]) std::swap(x, y);
          x = fa[x];
        }
        add(ans, c[dep[u] - dep[x]][dep[v] - dep[x]]);
      }
    }
}

int main() {
  scanf("%d", &n), init(N - 1);
  for (int i = 0; i < N; ++i)
    for (int j = 0; i + j < N; ++j)
      c[i][j] = calc(i, j);
  for (int i = 1; i < n; ++i) {
    int u, v; scanf("%d%d", &u, &v);
    g[u].emplace_back(v), g[v].emplace_back(u);
  }
  for (int r = 1; r <= n; ++r) solve(r);
  printf("%d\n", Mul(ans, inv[n]));
  return 0;
}