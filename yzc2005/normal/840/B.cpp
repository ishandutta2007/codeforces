#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int n, m, c[N], d[N], x[N], y[N];
vector<pair<int, int>> e[N];
set<int> ans;
bool vis[N];
void dfs(int u) {
  vis[u] = 1;
  int fth;
  for (auto edge : e[u]) {
    int v = edge.first, id = edge.second;
    if (!vis[v]) {
      dfs(v);
      if (~d[v] && c[v] ^ d[v]) {
        ans.insert(id);
        c[u] ^= 1;
      } 
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  int sum = 0, s = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &d[i]);
    sum += d[i];
    if (d[i] == -1) {
      s = i;
    }
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &x[i], &y[i]);
    e[x[i]].push_back({y[i], i});
    e[y[i]].push_back({x[i], i});
  }
  if (s) {
    dfs(s);
  } else if (sum % 2) {
    puts("-1");
    return 0;
  } else {
    dfs(1);
  }
  printf("%d\n", (int) ans.size());
  for (auto x : ans) {
    printf("%d\n", x);
  }
  return 0;
}