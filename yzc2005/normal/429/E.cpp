#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int n, d[N], l[N], r[N], p[N], m, ans[N]; 
int cnt = 1, head[N], to[N], nxt[N];
bool vis[N], visv[N];
inline void add(int u, int v) {
  to[++cnt] = v, nxt[cnt] = head[u];
  head[u] = cnt, ++d[u];
}
void dfs(int u) {
  visv[u] = 1;
  for (int &i = head[u]; i; i = nxt[i]) {
    int oi = i >> 1, v = to[i];
    if (vis[oi]) continue;
    vis[oi] = 1, dfs(v);
    ans[oi] = u < v;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> l[i] >> r[i], p[m++] = l[i], p[m++] = ++r[i];
  sort(p, p + m), m = unique(p, p + m) - p;
  for (int i = 1; i <= n; ++i) {
    l[i] = lower_bound(p, p + m, l[i]) - p + 1;
    r[i] = lower_bound(p, p + m, r[i]) - p + 1;
    add(l[i], r[i]), add(r[i], l[i]);
  }
  vector<int> odd;
  for (int i = 1; i <= m; ++i) 
    if (d[i] & 1) odd.emplace_back(i);
  for (int i = 0; i < (int) odd.size(); i += 2)
    add(odd[i], odd[i + 1]), add(odd[i + 1], odd[i]);
  for (int i = 1; i <= m; ++i) assert(d[i] % 2 == 0);
  for (int i = 1; i <= m; ++i) 
    if (!visv[i]) dfs(i);
  for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
  return 0;
}