#include <bits/stdc++.h>
using namespace std;
const int N = 50005, K = 8, B = 1 << K;
int n, q, a[N], dep[N], fa[N], jump[N], f[N][B];
vector<int> g[N];
void dfs(int u) {
  for (auto v : g[u]) {
    if (v ^ fa[u]) {
      fa[v] = u;
      dep[v] = dep[u] + 1;
      dfs(v);
    }
  }
}
inline void ckmax(int &x, int y) {
  if (x < y) {
    x = y;
  }
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dep[1] = 1; 
  dfs(1);
  for (int u = 1; u <= n; ++u) {
    int cnt = 0, v = u;
    while (v && cnt < B) {
      int s = cnt ^ a[v];
      ckmax(f[u][(B - 1) ^ (s >> K)], s | (B - 1 << K));
      v = fa[v];
      ++cnt;
    }
    jump[u] = v;
    for (int i = 0; i < K; ++i) {
      for (int s = 0; s < B; ++s) {
        if (f[u][s ^ (1 << i)]) {
          ckmax(f[u][s], f[u][s ^ (1 << i)] ^ (1 << i + K));
        }
      }
    }
  } 
  while (q--) {
    int u, v;
    scanf("%d%d", &u, &v);
    int x = v;
    int ans = 0, cnt = 0;
    while (dep[u] <= dep[jump[v]]) {
      ckmax(ans, f[v][cnt]);
      v = jump[v];
      ++cnt;
    }
    while (dep[u] <= dep[v]) {
      ckmax(ans, (dep[x] - dep[v]) ^ a[v]);
      v = fa[v];
    }
    printf("%d\n", ans);
  }
  return 0;
}