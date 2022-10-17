#include <bits/stdc++.h>
const int N = 400005, M = N * 40;
int tot = 1, np = 1, fa[N], len[N], ed[N], ch[N][26];
std::vector<int> g[N];
int n, cnt, rt[N], ls[M], rs[M];
int f[N], top[N];
char s[N];
inline void extend(int x) {
  #define q ch[p][x]
  int p = np; len[np = ++tot] = len[p] + 1;
  for (; p && !q; q = np, p = fa[p]);
  if (!p) fa[np] = 1;
  else if (len[q] == len[p] + 1) fa[np] = q;
  else {
    int nq = ++tot; len[nq] = len[p] + 1;
    memcpy(ch[nq], ch[q], 104);
    fa[nq] = fa[q], fa[q] = fa[np] = nq;
    for (int Q = q; p && q == Q; q = nq, p = fa[p]);
  }
  #undef q  
}
void insert(int &p, int l, int r, int pos) {
  p = ++cnt;
  if (l == r) return;
  int mid = l + r >> 1;
  if (mid >= pos) insert(ls[p], l, mid, pos);
  else insert(rs[p], mid + 1, r, pos);
}
bool query(int p, int l, int r, int ll, int rr) {
  if (l >= ll && r <= rr) return true;
  int mid = l + r >> 1; bool res = 0;
  if (mid >= ll && ls[p]) res |= query(ls[p], l, mid, ll, rr);
  if (mid < rr && rs[p]) res |= query(rs[p], mid + 1, r, ll, rr);
  return res;
}
int merge(int p, int q, int l, int r) {
  if (!p || !q) return p | q;
  int mid = l + r >> 1, x = ++cnt;
  ls[x] = merge(ls[p], ls[q], l, mid);
  rs[x] = merge(rs[p], rs[q], mid + 1, r);
  return x;
}
void build(int u) {
  if (ed[u]) insert(rt[u], 1, n, ed[u]);
  for (auto v : g[u]) build(v), ed[u] = ed[v], rt[u] = merge(rt[u], rt[v], 1, n);
}
int ans;
void dfs(int u) {
  ans = std::max(ans, f[u]);  
  for (auto v : g[u]) {
    int t = top[u];
    if (query(rt[t], 1, n, ed[v] - len[v] + len[t], ed[v] - 1)) f[v] = f[u] + 1, top[v] = v;
    else f[v] = f[u], top[v] = top[u];
    dfs(v);
  }
}
int main() {
  scanf("%d%s", &n, s + 1);
  for (int i = 1; i <= n; ++i) extend(s[i] -= 'a');
  for (int p = 1, i = 1; i <= n; ++i) ed[p = ch[p][s[i]]] = i;
  for (int i = tot; i > 1; --i) g[fa[i]].emplace_back(i);
  for (auto v : g[1]) build(v);
  for (auto v : g[1]) top[v] = v, dfs(v); 
  printf("%d\n", ans + 1);
  return 0;
}