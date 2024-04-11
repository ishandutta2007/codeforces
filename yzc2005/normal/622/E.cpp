#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, d[N], cnt, ans;
vector<int> g[N];
void dfs(int u, int fa, int dep) {
  if (g[u].size() == 1) d[++cnt] = dep;
  for (int v : g[u]) if (v != fa)
    dfs(v, u, dep + 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
      cin >> u >> v;
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    for (int v : g[1]) {
      cnt = 0, dfs(v, 1, 0);
      sort(d + 1, d + cnt + 1);
      for (int i = 2; i <= cnt; ++i) 
        d[i] = max(d[i], d[i - 1] + 1);
      ans = max(ans, d[cnt]);
    } 
    cout << ans + 1 << "\n";
}