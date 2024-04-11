#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef bitset<1024> BS;

const int MAXM = 1000 + 10, MAXN = 100000 + 10;
vector<int> G[MAXN];
int vs[MAXM];
int st[MAXN], ed[MAXN], loc[MAXN], sz;
int a[MAXN], n, m;

struct Node {
  BS bs;
  int tag;
  void mark(int v) {
    v %= m;
    tag = (tag + v) % m;
    bs = (bs << v) | (bs >> (m - v));
  }
} T[MAXN << 2];

void sieve() {
  for (int i = 0; i < MAXM; ++i) vs[i] = 1;
  for (int i = 2; i < MAXN; ++i) if (vs[i]) {
    for (int j = i + i; j < MAXN; j += i) vs[j] = 0;
  }
}

#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)
void upd(int rt) {
  T[rt].bs = T[lson].bs | T[rson].bs;
}
void psd(int rt) {
  if (T[rt].tag) {
    T[lson].mark(T[rt].tag);
    T[rson].mark(T[rt].tag);
    T[rt].tag = 0;
  }
}

void build(int rt, int l, int r) {
  T[rt].bs.reset(); T[rt].tag = 0;
  if (l + 1 == r) {
    int x = a[loc[l]] % m;
    T[rt].bs[x] = 1;
    return;
  }
  build(lson, l, mid);
  build(rson, mid, r);
  upd(rt);
}
void ins(int rt, int l, int r, int L, int R, int x) {
  if (L <= l && R >= r) {
    T[rt].mark(x % m);
    return;
  }
  psd(rt);
  if (L < mid) ins(lson, l, mid, L, R, x);
  if (R > mid) ins(rson, mid, r, L, R, x);
  upd(rt);
}
BS ret;
void ask(int rt, int l, int r, int L, int R) {
  if (L <= l && R >= r) {ret |= T[rt].bs; return;}
  psd(rt);
  if (L < mid) ask(lson, l, mid, L, R);
  if (R > mid) ask(rson, mid, r, L, R);
}

void dfs(int u, int f) {
  loc[sz] = u; st[u] = sz++;
  for (auto &v: G[u]) if (v != f) dfs(v, u);
  ed[u] = sz;
}

void run() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int i = 1; i < n; ++i) {
    int u, v; scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1, 0);
  build(1, 0, n);
  int q; scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int op; scanf("%d", &op);
    if (op == 1) {
      int v, x; scanf("%d%d", &v, &x);
      ins(1, 0, n, st[v], ed[v], x);
    } else {
      int v; scanf("%d", &v);
      ret.reset();
      ask(1, 0, n, st[v], ed[v]);
      int cnt = 0;
      for (int i = 2; i < m; ++i) {
        cnt += ret[i] && vs[i];
      }
      printf("%d\n", cnt);
    }
  }
}

int main() {
  sieve();
  run();
  return 0;
}