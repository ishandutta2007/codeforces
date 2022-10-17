#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, a[N], b[N], in[N], inq[N], cnt;
long long ans, mx[N];
vector<int> p, g[N];
bool vis[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
    if (b[i] != -1) ++in[b[i]];
    g[i].push_back(b[i]);
  }
  queue<int> q; q.push(0);
  for (int i = 1; i <= n; ++i)
    if (!in[i]) in[i] = 1, g[0].push_back(i);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    inq[cnt++] = u;
    for (auto v : g[u]) {
      if (v == -1) continue;
      if (mx[u] > 0) {
        mx[v] += mx[u];
        vis[u] = 1, p.push_back(u);
      }
      if (!(--in[v])) {
        mx[v] += a[v];
        q.push(v);
      }
    }
  }
  for (int i = cnt - 1; i; --i)
    if (!vis[inq[i]]) p.push_back(inq[i]);
  for (int i = 1; i <= n; ++i) 
    ans += mx[i];
  printf("%lld\n", ans);
  for (auto pos : p) 
    printf("%d ", pos);
  return 0;
}