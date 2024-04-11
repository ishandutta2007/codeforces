#include <bits/stdc++.h>
const int N = 1e5 + 5;
int n, m, B, q, ti, c[N], cnt[N], ord[N], ans[N];
struct Modify {
  int x, y;
} mdf[N];
struct Query {
  int l, r, k, t, id;
  inline bool operator < (const Query &x) {
    if (l / B != x.l / B) return l < x.l;
    if (r / B != x.r / B) return r < x.r;
    return (r / B) & 1 ? t < x.t : t > x.t; 
  } 
} qry[N];
struct Segment {
  int l, r;
} bounds[N];
void add(int x) {
  int y = cnt[x]++;
  --bounds[y++].r;
  ord[--bounds[y].l] = y;
}
void del(int x) {
  int y = cnt[x]--;
  ++bounds[y--].l;
  ord[++bounds[y].r] = y;
}
int check(int k) {
  int res = 1e9;
  for (int i = bounds[0].r + 1, j; i <= n; i = bounds[ord[i]].r + 1) {
    for (j = i; j <= n && (j = bounds[ord[j]].r) - i + 1 < k; ++j);
    if (j > n) break; 
    else res = std::min(res, ord[j] - ord[i]); 
  }
  return res == 1e9 ? -1 : res;
}
int main() {
  scanf("%d%d", &n, &m), B = pow(n, 0.66) * 2.87;
  for (int i = 1; i <= n; ++i) scanf("%d", &c[i]);
  for (int i = 1, op; i <= m; ++i) {
    if (scanf("%d", &op), op & 1) qry[++q].t = ti, qry[q].id = q, scanf("%d%d%d", &qry[q].l, &qry[q].r, &qry[q].k);
    else ++ti, scanf("%d%d", &mdf[ti].x, &mdf[ti].y);
  }
  std::sort(qry + 1, qry + q + 1), bounds[0].l = 1, bounds[0].r = n;
  for (int i = 1; i <= n; ++i) bounds[i] = (Segment) {n + 1, n};
  for (int i = 1, l = 1, r = 0, t = 0, x; i <= q; ++i) {
    while (l > qry[i].l) add(c[--l]);
    while (r < qry[i].r) add(c[++r]);
    while (l < qry[i].l) del(c[l++]);
    while (r > qry[i].r) del(c[r--]);
    while (t > qry[i].t) {
      x = mdf[t].x;
      if (l <= x && x <= r) del(c[x]), add(mdf[t].y); 
      std::swap(c[x], mdf[t--].y);
    }
    while (t < qry[i].t) {
      x = mdf[++t].x;
      if (l <= x && x <= r) del(c[x]), add(mdf[t].y);
      std::swap(c[x], mdf[t].y);
    }
    ans[qry[i].id] = check(qry[i].k);
  }
  for (int i = 1; i <= q; ++i) printf("%d\n", ans[i]);
  return 0;
}