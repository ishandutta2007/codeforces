#include <bits/stdc++.h>
const int N = 2005;
int n, a[N][N], md = 2e9;
long long d[N];
bool used[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      scanf("%d", &a[i][j]), a[j][i] = a[i][j], md = std::min(md, a[i][j]);
  for (int i = 1; i <= n; ++i) {
    d[i] = 2e9;
    for (int j = 1; j <= n; ++j) 
      if (i != j) d[i] = std::min(d[i], 2ll * (a[i][j] -= md));
  }
  for (int i = 1; i <= n; ++i) {
    int u = -1; 
    for (int v = 1; v <= n; ++v) 
      if (!used[v] && (u == -1 || d[v] < d[u])) u = v;
    used[u] = 1;
    for (int v = 1; v <= n; ++v) d[v] = std::min(d[v], d[u] + a[u][v]);
  }
  for (int i = 1; i <= n; ++i) printf("%lld\n", d[i] + 1ll * md * (n - 1));
  return 0;
}