#include <bits/stdc++.h> 

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

typedef std::pair<int, int> pr;

const int N = 1e5 + 5, inf = 1e9;

int n, k, c[N];
std::vector<int> g[N];
int fa[N], dep[N], sz[N], d[N], son[N], dfn, id[N], rev[N], top[N], ed[N];

namespace DS {
  int tot, rt[N], siz[N], pri[N], val[N], ch[N][2];
  int stk[N], top;
  
  inline int new_node() {
    int cur = top ? stk[top--] : ++tot;
    return siz[cur] = 1, pri[cur] = rnd(), cur;
  }
  
  inline void pushup(int p) {siz[p] = siz[ch[p][0]] + siz[ch[p][1]] + 1;}
  
  void split(int p, int k, int &x, int &y) {
    if (!p) {x = y = 0; return;}
    if (val[p] <= k) x = p, split(ch[p][1], k, ch[x][1], y), pushup(x);
    else y = p, split(ch[p][0], k, x, ch[y][0]), pushup(y);
  }
  
  int merge(int x, int y) {
    if (!x || !y) return x | y;
    if (pri[x] > pri[y]) return ch[x][1] = merge(ch[x][1], y), pushup(x), x;
    return ch[y][0] = merge(x, ch[y][0]), pushup(y), y;
  }
  
  void insert(int &p, int k) {
    int x, y; split(p, k, x, y);
    int cur = new_node(); val[cur] = k;
    p = merge(merge(x, cur), y);
  }
  
  void erase(int &p, int k) {
    int x, y; split(p, k, x, y);
    int a, b; split(x, k - 1, a, b);
    stk[++top] = b; ch[b][0] = ch[b][1] = 0;
    b = merge(ch[b][0], ch[b][1]);
    p = merge(merge(a, b), y);
  }
  
  int rank(int &p, int k) {
    int a, b; split(p, k, a, b); 
    int res = siz[a];
    return p = merge(a, b), res;
  } 
}

void dfs1(int u) {
  sz[u] = 1;
  for (auto v : g[u]) {
    if (v == fa[u]) continue;
    fa[v] = u, dep[v] = dep[u] + 1;
    dfs1(v), sz[u] += sz[v];
    if (sz[v] > sz[son[u]]) son[u] = v;
  }
}

void dfs2(int u) {
  id[u] = ++dfn, rev[dfn] = u;
  ed[top[u]] = u;
  if (son[u]) top[son[u]] = top[u], dfs2(son[u]);
  for (auto v : g[u]) {
    if (v == fa[u] || v == son[u]) continue;
    top[v] = v, dfs2(v);
  }
}

pr t[N << 2], f[N];

bool check(int u, int k, int delta) {
  int r = DS::rank(DS::rt[u], k), b = d[u] - 1 - r;
  return b + delta - r < k;
}

void update(int u, int &k, int delta) {
  while (check(u, k - 1, delta)) --k;
  while (!check(u, k, delta)) ++k;
}

inline pr operator + (const pr &x, const pr &y) {
  return pr(std::min(x.first, std::max(y.first, x.second)), std::min(x.first, std::max(y.second, x.second)));
}

void maintain(int u) {
  update(u, f[u].first, 1);
  update(u, f[u].second, -1);
}

void modify(int p, int l, int r, int pos, pr val) {
  if (l == r) {t[p] = val; return;}
  int mid = l + r >> 1;
  if (mid >= pos) modify(p << 1, l, mid, pos, val);
  else modify(p << 1 | 1, mid + 1, r, pos, val);
  t[p] = t[p << 1] + t[p << 1 | 1];
}

pr query(int p, int l, int r, int ll, int rr) {
  if (l >= ll && r <= rr) return t[p];
  int mid = l + r >> 1;
  if (mid >= ll && mid < rr) return query(p << 1, l, mid, ll, rr) + query(p << 1 | 1, mid + 1, r, ll, rr);
  if (mid >= ll) return query(p << 1, l, mid, ll, rr);
  return query(p << 1 | 1, mid + 1, r, ll, rr);
}

int query(int u) {return query(1, 1, n, id[u], id[ed[top[u]]]).first;}

void build(int p, int l, int r) {
  if (l == r) {
    int u = rev[l];
    if (~c[u]) t[p] = f[u];
    else {
      for (auto v : g[u]) if (v != fa[u] && v != son[u]) 
        DS::insert(DS::rt[u], query(v));
      maintain(u), t[p] = f[u];
    }
    return;
  }
  int mid = l + r >> 1;
  build(p << 1 | 1, mid + 1, r);
  build(p << 1, l, mid);
  t[p] = t[p << 1] + t[p << 1 | 1]; 
}

void modify(int u, int x) {
  if (c[u] == x) return;
  c[u] = x, f[u] = !x ? pr(-inf, -inf) : pr(inf, inf);
  for (; u; u = fa[top[u]]) {
    if (fa[top[u]]) DS::erase(DS::rt[fa[top[u]]], query(top[u]));
    if (c[u] == -1) maintain(u);
    modify(1, 1, n, id[u], f[u]);
    if (fa[top[u]]) DS::insert(DS::rt[fa[top[u]]], query(top[u]));
  }
} 

int main() {
  scanf("%d%d", &n, &k);
  memset(d, -1, sizeof d), d[1] = 0;
  for (int i = 1, u, v; i < n; ++i) scanf("%d%d", &u, &v), ++d[u], ++d[v], g[u].emplace_back(v), g[v].emplace_back(u);
  dfs1(dep[1] = 1), dfs2(top[1] = 1);
  for (int i = 1; i <= n; ++i) 
    if (scanf("%d", &c[i]), ~c[i]) f[i] = !c[i] ? pr(-inf, -inf) : pr(inf, inf);
  build(1, 1, n);
  int q; scanf("%d", &q);
  for (int i = 0, op, x, y; i < q; ++i) {
    scanf("%d%d", &op, &x);
    if (op == 1) puts(query(x) <= k ? "0" : "1");
    else if (op == 2) scanf("%d", &y), modify(x, y);
    else k = x;
  }
  return 0;
}