#include <bits/stdc++.h>
const int N = 1e5 + 5;
int n, k, max, a[N], p[N], tot[N], cnt[N], f[N], g[N], fre[N], mx[N];
std::vector<int> nodes[N], adj[N];
bool leaf[N], ans[N];
void dfs(int u, int dep) {
  ++tot[dep], max = std::max(max, dep + 1), nodes[dep].push_back(u);
  for (auto v : adj[u]) dfs(v, dep + 1);
}
int main() {
  scanf("%d%d", &n, &k);
  memset(leaf, true, sizeof leaf);
  for (int i = 2; i <= n; ++i) 
    scanf("%d", &p[i]), adj[p[i]].push_back(i), leaf[p[i]] = false;
  dfs(1, 0), memset(f, -1, sizeof(f)), f[0] = 0;
  for (int i = 0; i < max; ++i) ++fre[tot[i]];
  for (int i = 1; i <= n; ++i) if (fre[i]) {
    memset(mx, 0xcf, sizeof(mx));
    for (int j = 0; j <= n; ++j) {
      int rem = j % i, k = mx[rem];    
      if (~f[j]) mx[rem] = j;
      else if (k + i * fre[i] >= j)
        f[j] = i, g[j] = (j - k) / i;
    }
  }
  if (~f[k]) {
    printf("%d\n", max);
    for (int i = k; i; cnt[f[i]] += g[i], i -= f[i] * g[i]);
    for (int i = 0; i < max; ++i) if (cnt[tot[i]]) {
      --cnt[tot[i]]; for (auto u : nodes[i]) ans[u] = 1;
    }
  } else {
    printf("%d\n", max + 1);
    for (int i = 0, m = n; i < max; m -= tot[i++]) {
      if (k >= tot[i]) for (auto u : nodes[i]) ans[u] = 1, --k;
      else if (m - k < tot[i]) {
        std::sort(nodes[i].begin(), nodes[i].end(), [&](int i, int j) {return leaf[i] < leaf[j];});
        if (k <= m - k) std::reverse(nodes[i].begin(), nodes[i].end());
        for (auto it = nodes[i].begin(); k--; ans[*it++] = 1);
      }
    }
  }
  for (int i = 1; i <= n; ++i) printf("%c", ans[i] ? 'a' : 'b');
  return 0;
}