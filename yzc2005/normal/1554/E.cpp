#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, P = 998244353;
int n, f[N], d[N];
vector<int> g[N];
bool flag, t[N]; 

void dfs(int u, int fa, int k) {
  d[u] = 0;
  for (auto v : g[u]) {
    if (v == fa) continue;
    dfs(v, u, k);
    d[u] += t[v];
  }
  if (d[u] % k == 0) t[u] = true;
  else if ((d[u] + 1) % k == 0) t[u] = false;
  else flag = false;
}

bool check(int k) {
  memset(d + 1, 0, n * 4);
  flag = true, dfs(1, 0, k);
  return flag && t[1];
}

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) g[i].clear(), f[i] = 0;
  for (int i = 1; i < n; ++i) {
    int u, v; scanf("%d%d", &u, &v);
    g[u].push_back(v), g[v].push_back(u);
  } 
  f[1] = 1;
  for (int i = 1; i < n; ++i) f[1] = 1ll * f[1] * 2 % P;
  for (int i = 2; i < n; ++i) {
    if ((n - 1) % i) continue;
    if (check(i)) f[i] = 1; 
  }
  for (int i = n; i; --i)
    for (int j = 2; i * j <= n; ++j)
      f[i] = (f[i] - f[i * j] + P) % P;
  for (int i = 1; i <= n; ++i) printf("%d%c", f[i], " \n"[i == n]);      
}

int main() {
  int t; scanf("%d", &t);
  while (t--) solve();
  return 0;
}