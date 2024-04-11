#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int n, m, d[N], cnt = 1, head[N], to[N << 1], nxt[N << 1], ans[N];
bool vis[N], visv[N];
vector<int> cyc;
inline void add(int u, int v) {
  to[++cnt] = v, nxt[cnt] = head[u], head[u] = cnt;
  head[u] = cnt, ++d[u];
}
inline void addE(int u, int v) {
  add(u, v), add(v, u);
}
void dfs(int u) {
  visv[u] = 1;
  for (int &i = head[u]; i; i = nxt[i]) {
    if (vis[i >> 1]) continue; vis[i >> 1] = 1;
    int oi = i >> 1; dfs(to[i]), cyc.emplace_back(oi);
  }
}
int main() {
  scanf("%d", &m), n = 2e5;
  for (int i = 1; i <= m; ++i) {
    int x, y; scanf("%d%d", &x, &y);
    addE(x, y + n);
  }
  for (int i = 1; i <= n; ++i) 
    if (d[i] & 1) addE(i, 2 * n + 1);
  for (int i = n + 1; i <= 2 * n; ++i)
    if (d[i] & 1) addE(i, 2 * n + 2);
  if (d[2 * n + 1] & 1) addE(2 * n + 1, 2 * n + 2);
  for (int i = 1; i <= 2 * n + 2; ++i)
    if (!visv[i]) dfs(i);
  int cur = 0;
  for (auto x : cyc) ans[x] = cur, cur ^= 1;
  for (int i = 1; i <= m; ++i) printf("%c", ans[i] ? 'b' : 'r');
  return 0;
}