#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int T, n, m, a[N], b[N], cnt, fa[N];
vector<int> g[N], w[N];
bool flag, vis[N];
void dfs(int u, int dep) {
  vis[u] = 1;
  w[dep].push_back(u);
  if (w[dep].size() >= 2) {
    a[++cnt] = w[dep].back();
    w[dep].pop_back();
    b[cnt] = w[dep].back();
    w[dep].pop_back();
  }
  if (dep >= (n + 1) / 2 && !flag) {
    printf("PATH\n%d\n", dep);
    for (; u; u = fa[u]) {
      printf("%d%c", u, u ^ 1 ? ' ' : '\n');
    }
    flag = 1;
  }
  for (auto v : g[u]) {
    if (!vis[v]) {
      fa[v] = u;
      dfs(v, dep + 1);
    }
  }
}
int main() {
  for (scanf("%d", &T); T; --T) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      g[i].clear();
      w[i].clear();
      vis[i] = 0;
    }
    for (int i = 1, u, v; i <= m; ++i) {
      scanf("%d%d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
    flag = cnt = 0;
    dfs(1, 1);
    if (!flag) {
      printf("PAIRING\n%d\n", cnt);
      for (int i = 1; i <= cnt; ++i) {
        printf("%d %d\n", a[i], b[i]);
      }
    }
  }
  return 0;
}