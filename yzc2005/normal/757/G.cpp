#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 4e5 + 5;
int n, q, rt[N], p[N];
int sz_glb, sz[N], root, par[N];
bool vis_e[N];
vector<pair<int, int>> G[N];
vector<pair<bool, ll>> path[N];

struct node {
  int ls, rs, cnt;
  ll sum;
} t[N * 36];
int tot;

struct edge {
  int to, nxt, val;
} e[N << 1];
int head[N], cnt = 1;
inline void add_e(int u, int v, int w) {
  e[++cnt] = (edge) {v, head[u], w};
  head[u] = cnt;
}
inline void add(int u, int v, int w) {
  add_e(u, v, w);
  add_e(v, u, w);
}

void build(int u, int fa) {
  int last = 0;
  for (auto p : G[u]) {
    int v = p.first, w = p.second;
    if (v == fa) continue;
    if (!last) {
      add(u, v, w);
      last = u;
    } else {
      add(last, ++n, 0);
      add(n, v, w);
      last = n;
    }
    build(v, u);
  } 
}
void find_rt(int u) {
  sz[u] = 1;
  for (int i = head[u]; i; i = e[i].nxt) {
    if (vis_e[i >> 1] || i == par[u]) continue;
    int v = e[i].to; 
    par[v] = i ^ 1;
    find_rt(v);
    sz[u] += sz[v];
  }
  if(!root || max(sz[u], sz_glb - sz[u]) < max(sz[root], sz_glb - sz[root])) root = u;
}
void dfs(bool root, int u, ll dep, int par) {
  path[u].emplace_back(root, dep);
  for (int i = head[u]; i; i = e[i].nxt) {
    if (i == par || vis_e[i >> 1]) continue;
    int v = e[i].to, w = e[i].val;
    dfs(root, v, dep + w, i ^ 1);
  }
}
void solve(int u) {
  if (sz_glb == 1) return; 
  root = par[u] = 0, find_rt(u);
  u = root, vis_e[par[u] >> 1] = true;
  int v = e[par[u]].to, w = e[par[u]].val;
  dfs(0, u, w, 0);
  if (v) dfs(1, v, 0, 0);
  int s1 = sz[u], s2 = sz_glb - sz[u];
  sz_glb = s1, solve(u);
  sz_glb = s2, solve(v);
}

void modify(int &p, int u, int ptr) {
  t[++tot] = t[p], p = tot;
  if (ptr == path[u].size()) return;
  int type; ll val; 
  tie(type, val) = path[u][ptr++];
  if (!type) {
    modify(t[p].ls, u, ptr);
    t[t[p].ls].sum += val;
    ++t[t[p].ls].cnt;
  } else {
    modify(t[p].rs, u, ptr);
    t[t[p].rs].sum += val;
    ++t[t[p].rs].cnt;
  }
}

ll query(int p, int q, int u, int ptr) {
  if (ptr == path[u].size()) return 0;
  int type; ll val;
  tie(type, val) = path[u][ptr++];
  if (!type) {
    ll res = query(t[p].ls, t[q].ls, u, ptr);
    res += 1ll * val * (t[t[p].rs].cnt - t[t[q].rs].cnt) + t[t[p].rs].sum - t[t[q].rs].sum;
    return res;    
  } else {
    ll res = query(t[p].rs, t[q].rs, u, ptr);
    res += 1ll * val * (t[t[p].ls].cnt - t[t[q].ls].cnt) + t[t[p].ls].sum - t[t[q].ls].sum;
    return res;
  }
}

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
  for (int i = 1; i < n; ++i) {
    int u, v, w; scanf("%d%d%d", &u, &v, &w);
    G[u].emplace_back(v, w);
    G[v].emplace_back(u, w);
  }
  int pre_n = n;
  build(1, 0);
  sz_glb = n, solve(1);
  ll ans = 0;
  for (int i = 1; i <= pre_n; ++i) {
    rt[i] = rt[i - 1];
    modify(rt[i], p[i], 0);
  }
  for (int tt = 0; tt < q; ++tt) {
    int t; scanf("%d", &t);
    if (t == 1) {
      int a, b, c; scanf("%d%d%d", &a, &b, &c);
      int l = ans ^ a, r = ans ^ b, u = ans ^ c;
      ans = query(rt[r], rt[l - 1], u, 0);
      printf("%lld\n", ans);
      ans %= (1 << 30);
    } else {
      int x; scanf("%d", &x);
      x = ans ^ x;
      swap(p[x], p[x + 1]);
      rt[x] = rt[x - 1], modify(rt[x], p[x], 0);
    }
  }
  return 0;
}