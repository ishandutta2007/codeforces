#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pr;
typedef long long ll;

const int N = 2e5 + 5, K = 19, M = N * 2;

int n, p1[N], p2[N];
char s[N]; 
ll ans;
int dfn, id[N], dep[N];
int lg[M], st[K][M], *rev = st[0];

struct SAM {
  int n, np, fa[N], len[N], ch[N][26];
  vector<int> g[N];
  
  SAM() {
    n = np = 1;
    len[1] = 1;
  }
  
  int extend(int x) {
    #define q ch[p][x]
    int p = np; 
    len[np = ++n] = len[p] + 1;
    for (; p && !q; q = np, p = fa[p]);
    if (!p) fa[np] = 1;
    else if (len[q] == len[p] + 1) fa[np] = q;
    else {
      int nq = ++n;
      len[nq] = len[p] + 1;
      memcpy(ch[nq], ch[q], 104);
      fa[nq] = fa[q], fa[q] = fa[np] = nq;
      for (int Q = q; p && q == Q; q = nq, p = fa[p]); 
    }
    return np;
    #undef q
  } 
  
  void dfs(int u) {
    id[u] = ++dfn;
    rev[dfn] = u;
    for (auto v : g[u]) {
      dep[v] = dep[u] + 1;
      dfs(v);
      rev[++dfn] = u;
    } 
  }
  
  void init(bool type) {
    for (int i = 2; i <= n; ++i) {
      g[fa[i]].push_back(i);
      if (type) ans += len[i] - len[fa[i]];
    }
    if (!type) dfs(1);
  }
} t1, t2;

inline int cmp(int u, int v) {
  return dep[u] < dep[v] ? u : v;
}

inline int LCA(int u, int v) {
  u = id[u], v = id[v];
  if (u > v) swap(u, v);
  int k = lg[v - u + 1];
  return cmp(st[k][u], st[k][v - (1 << k) + 1]);
}

struct node {
  int ls, rs, l, r;
  ll val; 
} t[6666666];
int tot, rt[N];

inline void pushup(int p) {
  int u = t[t[p].ls].r, v = t[t[p].rs].l;
  t[p].val = t[t[p].ls].val + t[t[p].rs].val;
  if (u && v) t[p].val -= t2.len[LCA(u, v)];
  t[p].l = !u ? t[t[p].rs].l : t[t[p].ls].l;
  t[p].r = !v ? t[t[p].ls].r : t[t[p].rs].r;
}

void insert(int &p, int l, int r, int pos) {
  if (!p) p = ++tot;
  if (l == r) {
    int u = rev[l];
    t[p].l = t[p].r = u;
    t[p].val = t2.len[u];
    return;
  }
  int mid = l + r >> 1;
  if (mid >= pos) insert(t[p].ls, l, mid, pos);
  else insert(t[p].rs, mid + 1, r, pos);
  pushup(p);
}

void merge(int &p, int q, int l, int r) {
  if (!p || !q) {
    p |= q;
    return;
  }
  int mid = l + r >> 1;
  merge(t[p].ls, t[q].ls, l, mid);
  merge(t[p].rs, t[q].rs, mid + 1, r);
  pushup(p);
}

void dfs(int u) {
  for (auto v : t1.g[u]) {
    dfs(v);
    merge(rt[u], rt[v], 1, dfn);
  }
  ans += (t1.len[u] - t1.len[t1.fa[u]]) * t[rt[u]].val;
}

int main() {
  for (int i = 2; i < M; ++i) lg[i] = lg[i / 2] + 1;
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; ++i) p1[i] = t1.extend(s[i] - 'a');
  for (int i = n; i; --i) p2[i] = t2.extend(s[i] - 'a');
  p1[0] = p2[n + 1] = 1;
  t1.init(1), t2.init(0);
  for (int k = 1; k < K; ++k)
    for (int i = 1; i + (1 << k) - 1 <= dfn; ++i)
      st[k][i] = cmp(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
  for (int i = 1; i <= n; ++i) {
    int u = p1[i - 1], v = p2[i + 1];
    insert(rt[u], 1, dfn, id[v]);
  }
  dfs(1);
  printf("%lld\n", ans + 1);
  return 0;
}