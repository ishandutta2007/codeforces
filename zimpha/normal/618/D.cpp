#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 200000 + 10;

vector<int> G[MAXN];
int f[MAXN], g[MAXN], deg[MAXN];
int n, x, y;

void solve(int u, int fa = -1) {
  int cnt(0), w = -1;
  for (auto &v: G[u]) if (v != fa) {
    solve(v, u);
    cnt += f[v];
    if (w == -1 || g[w] - f[w] > g[v] - f[v]) w = v;
  }
  f[u] = g[u] = cnt + 1;
  for (auto &v: G[u]) if (v != fa) {
    if (v != w) f[u] = min(f[u], cnt - f[v] - f[w] + g[v] + g[w] - 1);
    g[u] = min(g[u], cnt - f[v] + g[v]);
  }
  f[u] = min(f[u], g[u]);
}

int main() {
  scanf("%d%d%d", &n, &x, &y);
  for (int i = 1; i < n; ++ i) {
    int u, v; scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
    deg[u] ++; deg[v] ++;
  }
  if (x >= y) {
    int mx = *max_element(deg + 1, deg + 1 + n);
    if (mx == n - 1) printf("%lld\n", x + 1ll * y * (n - 2));
    else printf("%lld\n", 1ll * y * (n - 1));
  } else {
    solve(1);
    int mx = f[1] - 1;
    printf("%lld\n", 1ll * mx * y + 1ll * (n - mx - 1) * x);
  }
  return 0;
}