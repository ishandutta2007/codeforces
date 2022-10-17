#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, sz[N], son[N], fa[N], ans[N];
vector<int> g[N];
multiset<int> all, chain, sub;
void dfs1(int u) {
  sz[u] = 1;
  for (auto v : g[u]) {
    dfs1(v), sz[u] += sz[v];
    if (sz[son[u]] < sz[v]) son[u] = v;
  }
}
void add(int u) {
  sub.insert(sz[u]);
  for (auto v : g[u]) add(v);
}
void update_all(int u, bool del) {
  if (del) all.erase(all.find(sz[u]));
  else all.insert(sz[u]);
  for (auto v : g[u]) update_all(v, del);
}
inline bool has_any(multiset<int> &s, int l, int r) {
  auto it = s.lower_bound(l);
  return it != s.end() && (*it <= r);
}
inline void dfs2(int u, bool is_son) {
  int mx1 = 0, mx2 = 0, mn = n + 1;
  all.erase(all.find(sz[u]));
  chain.insert(sz[u]);
  auto update = [&](int x) {
    if (x > mx1) mx2 = mx1, mx1 = x;
    else if (x > mx2) mx2 = x;
    if (x) mn = min(mn, x);
  };
  for (auto v : g[u]) {
    if (v == son[u]) continue;
    dfs2(v, false), update(sz[v]);
  }
  if (son[u]) dfs2(son[u], true), update(sz[son[u]]);
  for (auto v : g[u]) 
    if (v != son[u]) update_all(v, true);
  update(n - sz[u]);
  if (mx2 == 0) {
    ans[u] = mx1;
  } else {
    ans[u] = mx2;
    if (n - sz[u] == mx1) {
      int l = mn, r = mx1 - 1, res = mx1;
      while (l <= r) {
        int mid = (l + r) >> 1;
        int lp = mx1 - mid, rp = mid - mn;
        if (lp <= rp && (has_any(all, lp, rp) || has_any(chain, lp + sz[u], rp + sz[u]))) res = mid, r = mid - 1;
        else l = mid + 1;
      }
      ans[u] = max(ans[u], res);
    } else {
      assert(sz[son[u]] == mx1);
      int l = mn, r = mx1 - 1, res = mx1;
      while (l <= r) {
        int mid = (l + r) >> 1;
        int lp = mx1 - mid, rp = mid - mn;
        if (lp <= rp && has_any(sub, lp, rp)) res = mid, r = mid - 1;
        else l = mid + 1;
      }
      ans[u] = max(ans[u], res);
    }
  }
  for (auto v : g[u]) 
    if (v != son[u]) add(v);
  sub.insert(sz[u]);
  chain.erase(chain.find(sz[u]));
  if (!is_son) {
    sub.clear();
    update_all(u, false);
  }
}
int main() {
  scanf("%d", &n);
  int root = 0;
  for (int i = 1; i <= n; ++i) {
    int u, v; scanf("%d%d", &u, &v);
    if (!u) root = v;
    else g[u].emplace_back(v), fa[v] = u;
  }
  dfs1(root);
  for (int i = 1; i <= n; ++i) all.insert(sz[i]);
  dfs2(root, false);
  for (int i = 1; i <= n; ++i) printf("%d\n", ans[i]);
  return 0;
}