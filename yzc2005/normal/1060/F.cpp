#include <bits/stdc++.h>
const int N = 55;
int n, sz[N];
double f[N][N], h[N], _h[N];
std::vector<int> g[N];
double C[N][N], fac[N]; 
void dfs(int u, int fa = 0) {
  sz[u] = 0; 
  memset(f[u], 0, sizeof f[u]); f[u][0] = 1.;
  for (auto v : g[u]) {
    if (v == fa) continue; dfs(v, u);
    memset(h, 0, sizeof h);
    for (int i = 1; i <= sz[v]; ++i)
      for (int j = 0; j <= sz[v]; ++j)
        h[j] += j < i ? f[v][j] : (.5 * f[v][i - 1]);
    memcpy(_h, f[u], sizeof _h); memset(f[u], 0, sizeof f[u]);
    for (int i = 0; i <= sz[u]; ++i)
      for (int j = 0; j <= sz[v]; ++j)
        f[u][i + j] += _h[i] * h[j] * C[i + j][i] * C[sz[u] + sz[v] - i - j][sz[u] - i]; 
    sz[u] += sz[v];
  }
  ++sz[u];
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cout << std::setprecision(10);
  std::cin >> n;
  for (int i = 1; i < n; ++i) {
    int u, v; std::cin >> u >> v;
    g[u].emplace_back(v), g[v].emplace_back(u);
  } 
  C[0][0] = fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i;
  for (int i = 1; i <= n; ++i) for (int j = 0; j <= i; ++j) C[i][j] = (j ? C[i - 1][j - 1] : 0) + C[i - 1][j];
  for (int i = 1; i <= n; ++i) dfs(i), std::cout << f[i][n - 1] / fac[n - 1] << "\n";
  return 0;
}