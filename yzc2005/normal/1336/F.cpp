#include <bits/stdc++.h>
using namespace std;
const int N = 150005, K = 18;
int n, m, k, l[N], r[N], dep[N], fa[N][K], dfn;
vector<int> g[N], G[N];
vector<int> q2[N];
struct Query {
  int u, v;
}; vector<Query> q1[N];
long long ans;
 
struct BIT {
  int s[N];
  void add(int p, int x) {
    for (; p <= n; p += p & -p)
      s[p] += x;
  }
  void add(int l, int r, int x) {
    add(l, x), add(r + 1, -x);
  }
  int query(int p) {
    int res = 0;
    for (; p; p -= p & -p)
      res += s[p];
    return res;
  }
} bit[2];

int jump(int u, int k) {
  for(int i = K - 1; ~i; --i)
    if(k >> i & 1) u = fa[u][i];
  return u;
}
int LCA(int u, int v) {
  if (dep[u] > dep[v]) swap(u, v);
  v = jump(v, dep[v] - dep[u]);
  if (u == v) return u;
  for(int i = K - 1; ~i; --i) 
    if (fa[u][i] != fa[v][i]) 
      u = fa[u][i], v = fa[v][i];
  return fa[u][0];
}

struct SegT {
  struct node {
    int ls, rs, sum;
  } t[N * 20];
  int stk[N * 20], tp, tot;
  #define mid (l + r >> 1)
  int newnode() {
    int cur = tp ? stk[tp--] : ++tot;
    t[cur] = (node) {0, 0, 0};
    return cur;
  } 
  void update(int &p, int l, int r, int x) {
    if (!p) p = newnode();
    ++t[p].sum;
    if (l == r) return;
    if (mid >= x) update(t[p].ls, l, mid, x);
    else update(t[p].rs, mid + 1, r, x);
  }
  int query(int p, int l, int r, int ql, int qr) {
    if (!p) return 0;
    if (l >= ql && r <= qr) return t[p].sum;
    int res = 0;
    if (mid >= ql) res += query(t[p].ls, l, mid, ql, qr);
    if (mid < qr) res += query(t[p].rs, mid + 1, r, ql, qr);
    return res;
  }
  void merge(int &p, int &q) {
    if (!p || !q) return void(p |= q);
    t[p].sum += t[q].sum;
    merge(t[p].ls, t[q].ls), merge(t[p].rs, t[q].rs);
    stk[++tp] = q, q = 0;
  }
  void del(int &p) {
    if(!p) return;
    del(t[p].ls), del(t[p].rs);
    stk[++tp] = p, p = 0;    
  }
} tr; int rt[N];

int stk[N], tp;
vector<int> in[N];
void solve(int root) {
  vector<int> p, used;
  p.emplace_back(root);
  for (auto it : q1[root]) {
    p.emplace_back(it.u);
    q2[it.u].emplace_back(it.v);
  }
  p.erase(unique(p.begin(), p.end()), p.end());
  for (auto u : p) {
    function<void(int)> ins = [&](int u) {
      if (u == root) return void(stk[tp = 1] = u);
      int lca = LCA(u, stk[tp]);
      if (lca == stk[tp]) return void(stk[++tp] = u);
      for (; tp > 1 && dep[lca] < dep[stk[tp - 1]]; --tp)
        G[stk[tp - 1]].emplace_back(stk[tp]);
      if (lca != stk[tp - 1]) {
        G[lca].emplace_back(stk[tp]);
        stk[tp] = lca;
      } else 
        G[lca].emplace_back(stk[tp--]);
      stk[++tp] = u;   
    }; ins(u);
  }
  for (; tp > 1; --tp) 
    G[stk[tp - 1]].emplace_back(stk[tp]);
  function<void(int)> dfs = [&](int u) {
    used.emplace_back(u); 
    function<int(int)> fly = [&](int v) {
      if (dep[u] - dep[root] >= k) return root;
      int len = dep[u] + dep[v] - 2 * dep[root];
      return len < k ? -1 : jump(v, len - k);
    };
    for(auto v : q2[u]) {
      int w = fly(v);
      if (~w) ans += tr.query(rt[u], 1, n, l[w], r[w]);
      tr.update(rt[u], 1, n, l[v]);
      in[u].emplace_back(v);
    }
    for (auto v : G[u]) {
      function<void(int)> merge = [&](int v) {
        if (in[u].size() < in[v].size()) {
          swap(in[u], in[v]);
          swap(rt[u], rt[v]);
        }
        for (auto w : in[v]) if (~(w = fly(w)))
          ans += tr.query(rt[u], 1, n, l[w], r[w]);
        for (auto w : in[v]) in[u].emplace_back(w);
        in[v].clear(), tr.merge(rt[u], rt[v]);
      }; dfs(v), merge(v);
    }
  }; dfs(root);
  in[root].clear();
  for (auto u : used) {
    G[u].clear();
    q2[u].clear();
    tr.del(rt[u]);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  function<void(int)> pre = [&](int u) {
    l[u] = ++dfn;
    for (auto v : g[u]) {
      if (v == fa[u][0]) continue;
      fa[v][0] = u;
      dep[v] = dep[u] + 1;
      for (int k = 1; k < K; ++k)
        fa[v][k] = fa[fa[v][k - 1]][k - 1];
      pre(v);
    }  
    r[u] = dfn; 
  }; pre(1);
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    if (l[u] > l[v]) swap(u, v);
    q1[LCA(u, v)].emplace_back((Query) {u, v});
  }
  function<void(int)> dfs = [&](int u) {
    for (auto v : g[u]) 
      if (v != fa[u][0]) dfs(v);
    function<void(int, int, int)> work = [&](int v, int x, int op) {
      if (dep[v] - dep[u] < k) return;
      v = jump(v, dep[v] - dep[u] - k);
      bit[op].add(l[v], r[v], x);
    };
    for (auto it : q1[u]) 
      ans += bit[0].query(l[it.u]) + bit[0].query(l[it.v]);
    for (auto it : q1[u]) 
      work(it.u, 1, 0), work(it.v, 1, 0);
    sort(q1[u].begin(), q1[u].end(), [&](Query x, Query y) {return l[x.u] < l[y.u];});
    int delta = ans; 
    for (auto it : q1[u]) {
      ans += bit[1].query(l[it.u]);
      work(it.v, 1, 1);
    }
    for (auto it : q1[u]) 
      work(it.v, -1, 1);
  }; dfs(1); 
  for (int i = 1; i <= n; ++i) 
    if (!q1[i].empty()) solve(i);
  cout << ans << "\n";
  return 0;
}