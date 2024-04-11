#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;
int n, m, a[N], b[N], aa[N], bb[N], dep[N], fa[N];
vector<int> g[N];
bool vis[N];
ll dfs(int u, ll cur) {
  vis[u] = true;
  for (auto v : g[u]) {
    if (v == fa[u]) continue;
    if (a[u] && !a[v]) {
      ll res = 0;
      while (a[u]) {
        res += b[u];
        a[u] = b[u] = 0;
        u = fa[u];
      }
      return res;
    } else if (a[u] && vis[v]) {
      ll res = 0;
      int x = u, y = v;
      while (x != y) {
        if (dep[x] < dep[y]) swap(x, y);
        res += b[x];
        a[x] = b[x] = 0;
        x = fa[x];
      }
      return res;
    } else if (!vis[v]) {
      fa[v] = u, dep[v] = dep[u] + 1; 
      if (cur <= a[v]) continue;
      ll res = dfs(v, cur + b[v]);
      if (~res) return res;
    }
  }
  return -1;
}
inline bool check(ll cur) {
  while (count(a + 1, a + n + 1, 0) < n) {
    memset(vis + 1, false, n);
    memset(fa + 1, 0, n * 4);
    ll tmp = dfs(1, cur);
    if (tmp == -1) {
      memcpy(a + 1, aa + 1, n * 4);
      memcpy(b + 1, bb + 1, n * 4);
      return false;
    }
    cur += tmp;
  }
  memcpy(a + 1, aa + 1, n * 4);
  memcpy(b + 1, bb + 1, n * 4);
  return true;  
}
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) g[i].clear();
  for (int i = 2; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 2; i <= n; ++i) scanf("%d", &b[i]);
  memcpy(aa + 1, a + 1, n * 4);
  memcpy(bb + 1, b + 1, n * 4);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  int l = 0, r = 0x3f3f3f3f, ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) ans = mid, r = mid - 1;
    else l = mid + 1;
  }
  printf("%d\n", ans);  
}
int main() {
  int t; scanf("%d", &t);
  while (t--) solve();
  return 0;
}