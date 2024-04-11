#include <bits/stdc++.h>
using namespace std;
const int N = 300005, M = N * 20;
int n, q, a[N];
int tot, rt[N], ls[M], rs[M], val[M]; 
void change(int &p, int &q, int l, int r, int pos) {
  p = ++tot;
  val[p] = val[q] + 1;
  if (l == r) {
    return;
  }
  int mid = l + r >> 1;
  if (mid >= pos) {
    rs[p] = rs[q];
    change(ls[p], ls[q], l, mid, pos);
  } else {
    ls[p] = ls[q];
    change(rs[p], rs[q], mid + 1, r, pos);
  }
}
int query(int p, int q, int l, int r, int v) {
  if (val[p] - val[q] <= v) {
    return -1;
  }
  if (l == r) {
    return l;
  }
  int mid = l + r >> 1, res;
  if (~(res = query(ls[p], ls[q], l, mid, v))) {
    return res;
  } else {
    return query(rs[p], rs[q], mid + 1, r, v);
  }
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    change(rt[i], rt[i - 1], 1, n, a[i]);
  }
  for (int i = 1; i <= q; ++i) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    printf("%d\n", query(rt[r], rt[l - 1], 1, n, (r - l + 1) / k));
  }
  return 0;
}