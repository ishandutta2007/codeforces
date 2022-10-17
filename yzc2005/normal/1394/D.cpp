#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const long long inf = 1e12;
int n, h[N], w[N], u, v;
long long ans, f[N][2];
vector<int> g[N];
void dfs(int u, int fa) {
  vector<long long> vec;
  long long sum = 0;
  for (auto v : g[u]) {
    if (v ^ fa) {
      dfs(v, u);
      sum += f[v][0];
      vec.push_back(f[v][1] - f[v][0]);
    } 
  }
  sort(vec.begin(), vec.end());
  for (int t = 0; t < 2; ++t) {
    f[u][t] = inf;
    if (u > 1 && ((!t && h[fa] > h[u]) || (t && h[fa] < h[u]))) {
      continue; 
    } 
    int out = vec.size() + t;
    long long cur = sum;
    for (int i = 0; ~out; ++i, --out) {
      if (i && i <= vec.size()) {
        cur += vec[i - 1];
      }
      f[u][t] = min(f[u][t], cur + 1ll * w[u] * max(out, (int)g[u].size() - out)); 
    }
  }
}
int main() {
  scanf("%d", &n); 
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &w[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &h[i]);
  }
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  printf("%lld\n", f[1][0]);
  return 0;
}