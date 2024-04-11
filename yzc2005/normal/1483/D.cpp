#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int N = 605;
int n, m, g[N][N], gg[N][N], lim[N];
ll d[N][N], dd[N];
bool f[N][N], vis[N];

void get(int s, ll *dis) {
  dis[s] = 0;
  int cur = s;
  memset(vis, 0, sizeof vis);
  while (cur) {
    vis[cur] = true;
    for (int i = 1; i <= n; ++i) {
      if (!g[cur][i]) continue;
      if (dis[i] > dis[cur] + g[cur][i]) 
        dis[i] = dis[cur] + g[cur][i];
    }
    int nxt = 0;
    for (int i = 1; i <= n; ++i)
      if (!vis[i] && dis[i] < dis[nxt]) nxt = i;  
    cur = nxt;
  }
}

int main() {
  memset(d, 0x3f, sizeof d);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int u, v, w; scanf("%d%d%d", &u, &v, &w);
    g[u][v] = g[v][u] = w;
  }
  for (int i = 1; i <= n; ++i) get(i, d[i]);
  int q; scanf("%d", &q);
  while (q--) {
    int u, v, w; scanf("%d%d%d", &u, &v, &w);
    gg[u][v] = gg[v][u] = w;
  }
  auto solve = [&](int s) {
    for (int i = 1; i <= n; ++i)
      lim[i] = gg[s][i] ? gg[s][i] : 0;
    for (int i = 1; i <= n; ++i) {
      dd[i] = 0;
      for (int j = 1; j <= n; ++j)
        dd[i] = max(dd[i], lim[j] - d[j][i]);
    }
    for (int i = 1; i <= n; ++i)
      for (int j = i + 1; j <= n; ++j) {
        if (!g[i][j]) continue;
        if (d[s][i] + g[i][j] <= dd[j] || d[s][j] + g[i][j] <= dd[i]) f[i][j] = true;
      }
  };
  for (int i = 1; i <= n; ++i) solve(i);
  int ans = 0;
  for (int i = 1; i < n; ++i)
    for (int j = i + 1; j <= n; ++j) 
      if (g[i][j] && f[i][j]) ++ans;
  printf("%d\n", ans);
  return 0;
}