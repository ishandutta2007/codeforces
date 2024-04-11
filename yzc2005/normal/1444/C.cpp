#include <bits/stdc++.h>
const int N = 500005;
int n, m, k, c[N], u[N], v[N];
int fa[N << 1], sz[N << 1];
bool invalid[N];
using pii = std::pair<int, int>;
std::map<pii, std::vector<pii>> edges;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &c[i]);
  }
  std::iota(fa + 1, fa + n * 2 + 1, 1);
  std::fill(sz + 1, sz + n * 2 + 1, 1);
  auto get = [&](int x) {
    while (x != fa[x]) {
      x = fa[x];
    }
    return x;
  };
  auto merge = [&](int u, int v) {
    u = get(u);
    v = get(v);
    if (u != v) {
      if (sz[u] > sz[v]) {
        std::swap(u, v);
      }
      fa[u] = v;
      sz[v] += sz[u];
    }
  };
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &u[i], &v[i]);
    if (c[u[i]] == c[v[i]]) {
      if (get(u[i]) == get(v[i]) || get(u[i] + n) == get(v[i] + n)) {
        invalid[c[u[i]]] = 1;
      }
      merge(u[i], v[i] + n);
      merge(v[i], u[i] + n);
    } else {
      if (c[u[i]] > c[v[i]]) {
        std::swap(u[i], v[i]);
      }
      edges[{c[u[i]], c[v[i]]}].push_back({u[i], v[i]});
    }
  }
  int tot = k;
  for (int i = 1; i <= k; ++i) {
    tot -= invalid[i];
  }
  long long ans = 1ll * tot * (tot - 1) / 2;
  for (auto groups : edges) {
    int a = groups.first.first, b = groups.first.second;
    if (invalid[a] || invalid[b]) {
      continue;
    }
    std::vector<pii> cur = groups.second;
    std::vector<pii> stk;
    bool flag = 0;
    for (auto p : cur) {
      int u = p.first, v = p.second;
      if (get(u) == get(v) || get(u + n) == get(v + n)) {
        flag = 1;
        break;
      } 
      auto merge = [&](int u, int v) {
        u = get(u);
        v = get(v);
        if (u != v) {
          if (sz[u] > sz[v]) {
            std::swap(u, v);
          }
          stk.push_back({u, v});
          fa[u] = v;
          sz[v] += sz[u];
        }
      };
      merge(u, v + n);
      merge(u + n, v);
    }
    ans -= flag;
    std::reverse(stk.begin(), stk.end());
    for (auto p : stk) {
      int u = p.first, v = p.second;
      sz[v] -= sz[u];
      fa[u] = u;
    }
  }
  printf("%lld\n", ans);
  return 0;
}