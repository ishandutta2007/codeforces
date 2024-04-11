#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 400000 + 10;
vector<int> G[MAXN];
int c[MAXN], pt[MAXN], st[MAXN], ed[MAXN];
int n, m, sz;

void dfs(int u, int f = -1) {
  st[u] = sz; pt[sz] = u; sz ++;
  for (auto &v: G[u]) if (v != f) dfs(v, u);
  ed[u] = sz;
}

LL u[MAXN << 2], ps[MAXN << 2];
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)
void build(int rt, int l, int r) {
  if (l + 1 == r) {
    u[rt] = 1ll << c[pt[l]];
    return;
  }
  build(lson, l, mid);
  build(rson, mid, r);
  u[rt] = u[lson] | u[rson];
}
void psd(int rt){
  if (ps[rt]) {
    u[lson] = u[rson] = ps[rt];
    ps[lson] = ps[rson] = ps[rt];
    ps[rt] = 0;
  }
}
void ins(int rt, int l, int r, int L, int R, int c) {
  if (L <= l && R >= r) {
    u[rt] = ps[rt] = 1ll << c;
    return;
  }
  psd(rt);
  if (L < mid) ins(lson, l, mid, L, R, c);
  if (R > mid) ins(rson, mid, r, L, R, c);
  u[rt] = u[lson] | u[rson];
}
LL ask(int rt, int l, int r, int L, int R) {
  if (L <= l && R >= r) return u[rt];
  psd(rt);
  LL ret(0);
  if (L < mid) ret |= ask(lson, l, mid, L, R);
  if (R > mid) ret |= ask(rson, mid, r, L, R);
  return ret;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++ i) scanf("%d", c + i);
  for (int i = 1; i < n; ++ i) {
    int u, v; scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1);
  build(1, 0, n);
  for (int i = 0; i < m; ++ i) {
    int op; scanf("%d", &op);
    if (op == 1) {
      int v, c; scanf("%d%d", &v, &c);
      ins(1, 0, n, st[v], ed[v], c);
    } else {
      int v; scanf("%d", &v);
      LL ret = ask(1, 0, n, st[v], ed[v]);
      printf("%d\n", __builtin_popcountll(ret));
    }
  }
  return 0;
}