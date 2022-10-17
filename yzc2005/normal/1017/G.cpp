#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, q, fa[N], sz[N], son[N], top[N], dep[N];
int id[N], dfn, eid[N], rev[N];
vector<int> g[N];

void dfs1(int u) {
  sz[u] = 1;
  for (auto v : g[u]) {
    dep[v] = dep[u] + 1;
    dfs1(v);
    if (sz[v] > sz[son[u]]) son[u] = v;
    sz[u] += sz[v];
  }
}

void dfs2(int u) {
  id[u] = ++dfn;
  rev[dfn] = u;
  if (son[u]) {
    top[son[u]] = top[u];
    dfs2(son[u]);
  }
  for (auto v : g[u]) {
    if (v == son[u]) continue;
    top[v] = v;
    dfs2(v);
  }
  eid[u] = dfn;
}

namespace ST {
  int dat[N << 2], mn[N << 2];
  int add[N << 2], clr[N << 2];
  
  inline void tag(int p, int clr_t, int add_t) {
    if (~clr_t) {
      mn[p] = clr_t + dat[p];
      clr[p] = clr_t;
      add[p] = 0;
    } else {
      mn[p] += add_t;
      if (~clr[p]) clr[p] += add_t;
      else add[p] += add_t;
    }
  }
  
  inline void pushdown(int p) {
    if (~clr[p] || add[p]) {
      tag(p << 1, clr[p], add[p]);
      tag(p << 1 | 1, clr[p], add[p]);
      add[p] = 0, clr[p] = -1; 
    }
  }
  
  inline void pushup(int p) {
    mn[p] = min(mn[p << 1], mn[p << 1 | 1]); 
  }
  
  void build(int p, int l, int r) {
    clr[p] = -1;
    if (l == r) {
      int u = rev[l];
      dat[p] = mn[p] = -dep[u];
      return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
    pushup(p);
    dat[p] = mn[p];
  }
  
  void modify(int p, int l, int r, int ll, int rr, int c, int a) {
    if (l >= ll && r <= rr) {
      tag(p, c, a);
      return;
    }
    int mid = (l + r) >> 1;
    pushdown(p);
    if (mid >= ll) modify(p << 1, l, mid, ll, rr, c, a);
    if (mid < rr) modify(p << 1 | 1, mid + 1, r, ll, rr, c, a);
    pushup(p);
  }
  
  int query(int p, int l, int r, int ll, int rr) {
    if (l >= ll && r <= rr) return mn[p];
    int mid = (l + r) >> 1, res = 0;
    pushdown(p);
    if (mid >= ll) res = min(res, query(p << 1, l, mid, ll, rr));
    if (mid < rr) res = min(res, query(p << 1 | 1, mid + 1, r, ll, rr));
    return res;
  }
}

inline int query(int u) {
  int ans1 = ST::query(1, 1, n, id[u], id[u]) + 1, ans2 = 0;
  for (u = fa[u]; u; u = fa[top[u]])
    ans2 = min(ans2, ST::query(1, 1, n, id[top[u]], id[u]));
  return ans1 - ans2;
}

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 2; i <= n; ++i) {
    scanf("%d", &fa[i]);
    g[fa[i]].emplace_back(i);
  }
  dep[1] = 1, dfs1(1);
  top[1] = 1, dfs2(1);
  ST::build(1, 1, n);
  for (int tt = 0; tt < q; ++tt) {
    int t, u; scanf("%d%d", &t, &u);
    if (t == 1) {
      ST::modify(1, 1, n, id[u], eid[u], -1, 1);
    } else if (t == 2) {
      int val = ST::query(1, 1, n, id[u], id[u]) + dep[u] - max(query(u), 0);
      ST::modify(1, 1, n, id[u], eid[u], val, 0);
    } else {
      puts(query(u) > 0 ? "black" : "white");
    }
  }
  return 0;
}