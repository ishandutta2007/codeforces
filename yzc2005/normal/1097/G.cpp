#include <bits/stdc++.h>
const int mod = 1e9 + 7;
inline void add(int &a, int b) {
  (a += b) >= mod && (a -= mod);
}
inline int Add(int a, int b) {
  return add(a, b), a;
}
inline void sub(int &a, int b) {
  (a -= b) < 0 && (a += mod);
}
inline int Sub(int a, int b) {
  return sub(a, b), a;
}
inline void mul(int &a, int b) {
  a = 1ll * a * b % mod;
}
inline int Mul(int a, int b) {
  return 1ll * a * b % mod;
}
const int N = 1e5 + 5, K = 205;
int n, k, f[N][K], siz[N], res[K], s[K][K];
std::vector<int> g[N];
void dfs(int u, int fa) {
  siz[u] = 1;
  f[u][0] = 1;
  for (auto v : g[u]) {
    if (v != fa) {
      dfs(v, u);
      static int g[K];
      std::memset(g, 0, sizeof(g));
      for (int i = 0; i <= std::min(k, siz[u]); ++i) {
        for (int j = 0; j <= std::min(k - i, siz[v]); ++j) {
          int val = Mul(f[u][i], f[v][j]);
          add(g[i + j], val);
          add(res[i + j], val);
          add(g[i + j + 1], val);
          add(res[i + j + 1], val);
        }
      }
      for (int i = 0; i <= k; ++i) {
        add(f[u][i], g[i]);
        add(f[u][i], Add(f[v][i], i ? f[v][i - 1] : 0));
      }
      siz[u] += siz[v];
    }
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  s[0][0] = 1;
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= i; ++j) {
      s[i][j] = Add(s[i - 1][j - 1], Mul(s[i - 1][j], j));
    }
  }
  dfs(1, 0);  
  int ans = 0, fac = 1;
  for (int i = 1; i <= k; ++i) {
    mul(fac, i);
    add(ans, Mul(res[i], Mul(fac, s[k][i])));
  } 
  printf("%d\n", ans);
  return 0;
}