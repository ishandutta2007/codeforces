#include <bits/stdc++.h>
const int N = 5e6 + 5, K = 20, M = 1 << K;
int n, q, tot, ls[N], rs[N], tk[N], t0[N], t1[N], ts[N], tt[N];
inline void pushup(int p) {
  ts[p] = ts[ls[p]] + ts[rs[p]];
  t0[p] = t0[ls[p]] | t0[rs[p]];
  t1[p] = t1[ls[p]] | t1[rs[p]];
} 
inline void tag(int p, int t) {
  if (!p) return; tt[p] ^= t;
  if (~tk[p] && t >> tk[p] & 1) std::swap(ls[p], rs[p]);
  int x = (t0[p] & (~t)) | (t1[p] & t), y = (t1[p] & (~t)) | (t0[p] & t);
  t0[p] = x, t1[p] = y;
}
inline void pushdown(int p) {
  if (tt[p]) {
    tag(ls[p], tt[p]), tag(rs[p], tt[p]);
    tt[p] = 0;
  }
}
void insert(int &p, int s, int k) {
  if (!p) p = ++tot;
  tk[p] = k;
  if (k == -1) {
    t1[p] = s & (M - 1), t0[p] = t1[p] ^ (M - 1);
    ts[p] = 1; 
    return;
  } 
  insert((s >> k & 1) ? rs[p] : ls[p], s, k - 1);
  pushup(p);  
}
void split(int &p, int &q, int l, int r, int x, int y) {
  if (!p || y < l || x > r) {q = 0; return;}
  if (x <= l && r <= y) {q = p, p = 0; return;}
  int mid = l + r >> 1; pushdown(p);
  tk[q = ++tot] = tk[p];
  split(ls[p], ls[q], l, mid, x, y);
  split(rs[p], rs[q], mid + 1, r, x, y); 
  pushup(p), pushup(q);
}
void merge(int &p, int q) {
  if (!p || !q) {p = p | q; return;}
  pushdown(p), pushdown(q);
  merge(ls[p], ls[q]), merge(rs[p], rs[q]);
  if (~tk[p]) pushup(p);
}
void modify(int p, int s) {
  if (!p) return;
  if (!(s & t0[p] & t1[p])) {tag(p, s & t0[p]); return;}
  pushdown(p);
  if (s >> tk[p] & 1) tag(ls[p], 1 << tk[p]), merge(rs[p], ls[p]), ls[p] = 0;
  modify(ls[p], s), modify(rs[p], s);
  pushup(p);
}
int main() {
  scanf("%d%d", &n, &q); int p = 0;
  for (int i = 1; i <= n; ++i) {
    int x; scanf("%d", &x);
    insert(p, x, K - 1);
  }
  for (; q; --q) {
    int t, l, r, q, x; scanf("%d%d%d", &t, &l, &r);
    split(p, q, 0, M - 1, l, r); 
    if (t == 1) scanf("%d", &x), tag(q, M - 1), modify(q, x ^ (M - 1)), tag(q, M - 1);
    else if (t == 2) scanf("%d", &x), modify(q, x);
    else if (t == 3) scanf("%d", &x), tag(q, x);
    else printf("%d\n", ts[q]);
    merge(p, q);
  }
  return 0;
}