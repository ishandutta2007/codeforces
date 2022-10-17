#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m, sz[N], b[N], x[N];
vector<int> g[N];
bool ok;
void dfs(int u, int fa) {
  for (auto v : g[u]) {
    if (v == fa) continue;
    dfs(v, u);
    sz[u] += sz[v];
  }
}
void check(int u, int fa) {
  if (x[u] > sz[u] || x[u] < 0) ok = 0;
  int sum = 0;
  for (auto v : g[u]) {
    if (v == fa) continue;
    sum += x[v];
    check(v, u);
  }
  if (sum > x[u]) ok = 0;
}
int main() {
  int T; scanf("%d", &T); while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
      g[i].clear();
    for (int i = 1; i <= n; ++i)
      scanf("%d", &sz[i]);
    for (int i = 1; i <= n; ++i)
      scanf("%d", &b[i]);
    for (int i = 1, u, v; i < n; ++i) {
      scanf("%d%d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfs(1, 0); ok = 1;
    for (int i = 1; i <= n; ++i) {
      if ((b[i] + sz[i]) % 2) ok = 0;
      x[i] = b[i] + sz[i] >> 1;
    }
    check(1, 0);
    puts(ok ? "YES" : "NO");
  } 
  return 0;
}