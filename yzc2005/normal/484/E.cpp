#include <bits/stdc++.h>
const int N = 1e5 + 5, M = 2e6 + 5;
int n, m, h[N], id[N];
int cnt, ls[M], rs[M], rt[N];
struct node {
  int l, r, v;
  bool type;
  inline node operator + (const node &x) {
    if (type && x.type) return (node) {v + x.v, v + x.v, v + x.v, 1};
    else if (type) return (node) {v + x.l, x.r, std::max(v + x.l, x.v), 0};
    else if (x.type) return (node) {l, r + x.v, std::max(v, r + x.v), 0};
    return (node) {l, x.r, std::max(std::max(v, x.v), r + x.l), 0};
  }
} x[M];
void insert(int &p, int q, int l, int r, int pos) {
  p = ++cnt;
  if (l == r) return void(x[p] = (node) {1, 1, 1, 1});
  int mid = l + r >> 1;
  if (mid >= pos) rs[p] = rs[q], insert(ls[p], ls[q], l, mid, pos);
  else ls[p] = ls[q], insert(rs[p], rs[q], mid + 1, r, pos);
  x[p] = x[ls[p]] + x[rs[p]];  
}
node query(int p, int l, int r, int L, int R) {
  if (l >= L && r <= R) return x[p];
  int mid = l + r >> 1;
  if (mid >= L && mid < R) return query(ls[p], l, mid, L, R) + query(rs[p], mid + 1, r, L, R);
  else if (mid >= L) return query(ls[p], l, mid, L, R);
  else return query(rs[p], mid + 1, r, L, R);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &h[i]), id[i] = i;
  std::sort(id + 1, id + n + 1, [&](int i, int j) {
    return h[i] < h[j];
  });
  for (int i = n; i; --i) insert(rt[i], rt[i + 1], 1, n, id[i]); 
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    int L, R, w;
    scanf("%d%d%d", &L, &R, &w);
    int l = 1, r = n, ans;
    while (l <= r) {
      int mid = l + r >> 1;
      if (query(rt[mid], 1, n, L, R).v >= w) l = mid + 1, ans = mid;
      else r = mid - 1;
    }
    printf("%d\n", h[id[ans]]);
  }
  return 0;
}